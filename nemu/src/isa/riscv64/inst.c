#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, // none
  TYPE_J,
  TYPE_R,
  TYPE_B,
};

#define src1R(n) do { *src1 = R(n); } while (0)
#define src2R(n) do { *src2 = R(n); } while (0)
#define destR(n) do { *dest = n; } while (0)
#define src1I(i) do { *src1 = i; } while (0)
#define src2I(i) do { *src2 = i; } while (0)
#define destI(i) do { *dest = i; } while (0)

static word_t immI(uint32_t i) { return SEXT(BITS(i, 31, 20), 12); }
static word_t immU(uint32_t i) { return SEXT(BITS(i, 31, 12), 20) << 12; }
static word_t immS(uint32_t i) { return (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); }

static word_t offsetU(uint32_t i) {
    return SEXT(BITS(i, 31, 31) << 20 | BITS(i, 30, 21) << 1 | BITS(i, 20, 20) << 11 | BITS(i, 19, 12) << 12, 21);
}

static word_t offsetB(uint32_t i) {
    return SEXT(BITS(i, 31, 31) << 12 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1 | BITS(i, 7, 7) << 11, 13);
}

static void decode_operand(Decode *s, word_t *dest, word_t *src1, word_t *src2, int type) {
    uint32_t i = s->isa.inst.val;
    int rd = BITS(i, 11, 7);
    int rs1 = BITS(i, 19, 15);
    int rs2 = BITS(i, 24, 20);
    destR(rd); // let dest = rd.no
    switch (type) {
        case TYPE_I:
            src1R(rs1); // let src1 = x[rs1]
            src2I(immI(i)); // let src2 = sext(imm)
            break;
        case TYPE_U:
            src1I(immU(i));
            break;
        case TYPE_S:
            destI(immS(i));
            src1R(rs1);
            src2R(rs2);
            break;
        case TYPE_J:
            src1I(offsetU(i));
            break;
        case TYPE_R:
            src1R(rs1);
            src2R(rs2);
            break;
        case TYPE_B:
            src1R(rs1);
            src2R(rs2);
            destI(offsetB(i));
            break;
    }
}

static int decode_exec(Decode *s) {
    word_t dest = 0, src1 = 0, src2 = 0;
    s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* body */ ) { \
  decode_operand(s, &dest, &src1, &src2, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

    INSTPAT_START();

    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(dest) = src1 + s->pc);
    INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld, I, R(dest) = Mr(src1 + src2, 8));
    INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd, S, Mw(src1 + dest, 8, src2));

    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0

    // todo add inst exec
    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I, R(dest) = src1 + src2);
    INSTPAT("??????? ????? ????? 000 ????? 00110 11", addiw, I, R(dest) = SEXT(BITS(src1 + src2, 31, 0), 32));
    INSTPAT("0000000 ????? ????? 000 ????? 01110 11", addw, R, R(dest) = SEXT(BITS(src1 + src2, 31, 0), 32));
    INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R, R(dest) = src1 + src2);
    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(dest) = s->pc + 4, s->dnpc = s->pc + src1);
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, s->dnpc = (src1 + src2) & ~1, R(dest) = s->pc + 4);
    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I, R(dest) = SEXT(Mr(src1 + src2, 4), 32));
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S, Mw(src1 + dest, 4, src2));
    INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, s->dnpc = src1 == src2 ? s->dnpc : s->pc + dest);
    INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, s->dnpc = src1 == src2 ? s->pc + dest : s->dnpc);
    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(dest) = src1);
    INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R, R(dest) = src1 - src2);
    INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I, R(dest) = src1 < src2);
    INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S, Mw(src1 + dest, 2, src2));
    INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai, I, R(dest) = ((sword_t) src1) >> BITS(src2, 5, 0));

    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
    INSTPAT_END();

    R(0) = 0; // reset $zero to 0

    return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
