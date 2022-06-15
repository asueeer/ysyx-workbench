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

enum {
    auipc, ld, sd,
    ebreak,
    add, addi, addw, addiw, sub, subw,
    lw, lbu, lh, lhu,
    sraw, sraiw, srliw, srai, srli, srlw,
    slli, sllw, slliw,
    sltiu, slti, sltu, slt,
    jal, jalr,
    bne, beq, bge, bgeu, blt, bltu,
    sh, sw_,
    lui, andi, and,
    xori, or, sb,
    mul, mulw, divw, remw,
    inv,
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

static uint32_t w(word_t i) { // i[31:0]
    return BITS(i, 31, 0);
}

static int32_t sw(word_t i) { // signed i[32:0]
    return (int32_t) BITS(i, 31, 0);
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
    s->dest = *dest;
    s->src1 = *src1;
    s->src2 = *src2;
}

// 代码是自动生成的！
static void decode_operand_name(Decode *s, int type_name) {
    s->type_name = type_name;
    switch (s->type_name) {
        case auipc:
            sprintf(&s->operand_name[0], "auipc");
            sprintf(&s->cmd[0], "(pc加立即数) -> %s %s, 0x%lx", s->operand_name, regs[s->dest], s->src1);
            break;
        case ld:
            sprintf(&s->operand_name[0], "ld");
            sprintf(&s->cmd[0], "(双字加载) -> %s %s, 0x%lx(0x%lx)", s->operand_name, regs[s->dest], s->src2, s->src1);
            break;
        case sd:
            sprintf(&s->operand_name[0], "sd");
            sprintf(&s->cmd[0], "(存双字) -> %s %lx, 0x%lx(0x%lx)", s->operand_name, s->src2, s->dest, s->src1);
            break;
        case ebreak:
            sprintf(&s->operand_name[0], "ebreak");
            sprintf(&s->cmd[0], "(环境断点) -> %s", s->operand_name);
            break;
        case add:
            sprintf(&s->operand_name[0], "add");
            break;
        case addi:
            sprintf(&s->operand_name[0], "addi");
            break;
        case addw:
            sprintf(&s->operand_name[0], "addw");
            break;
        case addiw:
            sprintf(&s->operand_name[0], "addiw");
            break;
        case sub:
            sprintf(&s->operand_name[0], "sub");
            break;
        case subw:
            sprintf(&s->operand_name[0], "subw");
            break;
        case lw:
            sprintf(&s->operand_name[0], "lw");
            break;
        case lbu:
            sprintf(&s->operand_name[0], "lbu");
            break;
        case lh:
            sprintf(&s->operand_name[0], "lh");
            break;
        case lhu:
            sprintf(&s->operand_name[0], "lhu");
            break;
        case sraw:
            sprintf(&s->operand_name[0], "sraw");
            break;
        case sraiw:
            sprintf(&s->operand_name[0], "sraiw");
            break;
        case srliw:
            sprintf(&s->operand_name[0], "srliw");
            break;
        case srai:
            sprintf(&s->operand_name[0], "srai");
            break;
        case srli:
            sprintf(&s->operand_name[0], "srli");
            break;
        case srlw:
            sprintf(&s->operand_name[0], "srlw");
            break;
        case slli:
            sprintf(&s->operand_name[0], "slli");
            break;
        case sllw:
            sprintf(&s->operand_name[0], "sllw");
            break;
        case slliw:
            sprintf(&s->operand_name[0], "slliw");
            break;
        case sltiu:
            sprintf(&s->operand_name[0], "sltiu");
            break;
        case slti:
            sprintf(&s->operand_name[0], "slti");
            break;
        case sltu:
            sprintf(&s->operand_name[0], "sltu");
            break;
        case slt:
            sprintf(&s->operand_name[0], "slt");
            break;
        case jal:
            sprintf(&s->operand_name[0], "jal");
            break;
        case jalr:
            sprintf(&s->operand_name[0], "jalr");
            break;
        case bne:
            sprintf(&s->operand_name[0], "bne");
            break;
        case beq:
            sprintf(&s->operand_name[0], "beq");
            break;
        case bge:
            sprintf(&s->operand_name[0], "bge");
            break;
        case bgeu:
            sprintf(&s->operand_name[0], "bgeu");
            break;
        case blt:
            sprintf(&s->operand_name[0], "blt");
            break;
        case bltu:
            sprintf(&s->operand_name[0], "bltu");
            break;
        case sh:
            sprintf(&s->operand_name[0], "sh");
            break;
        case sw_:
            sprintf(&s->operand_name[0], "sw_");
            break;
        case lui:
            sprintf(&s->operand_name[0], "lui");
            break;
        case andi:
            sprintf(&s->operand_name[0], "andi");
            break;
        case and:
            sprintf(&s->operand_name[0], "and");
            break;
        case xori:
            sprintf(&s->operand_name[0], "xori");
            break;
        case or:
            sprintf(&s->operand_name[0], "or");
            break;
        case sb:
            sprintf(&s->operand_name[0], "sb");
            break;
        case mul:
            sprintf(&s->operand_name[0], "mul");
            break;
        case mulw:
            sprintf(&s->operand_name[0], "mulw");
            break;
        case divw:
            sprintf(&s->operand_name[0], "divw");
            break;
        case remw:
            sprintf(&s->operand_name[0], "remw");
            break;
        case inv:
            sprintf(&s->operand_name[0], "inv");
            break;
        default:
            sprintf(&s->operand_name[0], "unkown");
            break;
    }
    printf("%s: %s\n", s->operand_name, s->cmd);
}

static int decode_exec(Decode *s) {
    word_t dest = 0, src1 = 0, src2 = 0;
    s->dnpc = s->snpc;
#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, type_name, type, ... /* body */ ) { \
  decode_operand(s, &dest, &src1, &src2, concat(TYPE_, type)); \
  decode_operand_name(s, type_name); \
  __VA_ARGS__ ; \
}

    INSTPAT_START();

    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(dest) = src1 + s->pc);
    INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld, I, R(dest) = Mr(src1 + src2, 8));
    INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd, S, Mw(src1 + dest, 8, src2));

    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0

    // todo add inst exec
    INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R, R(dest) = src1 + src2);
    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I, R(dest) = src1 + src2);
    INSTPAT("0000000 ????? ????? 000 ????? 01110 11", addw, R, R(dest) = SEXT(w(src1 + src2), 32));
    INSTPAT("??????? ????? ????? 000 ????? 00110 11", addiw, I, R(dest) = SEXT(w(src1 + src2), 32));
    INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R, R(dest) = src1 - src2);
    INSTPAT("0100000 ????? ????? 000 ????? 01110 11", subw, R, R(dest) = SEXT(w(src1 - src2), 32));

    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I, R(dest) = SEXT(Mr(src1 + src2, 4), 32));
    INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I, R(dest) = Mr(src1 + src2, 1)); // load byte, unsigned
    INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I, R(dest) = SEXT(Mr(src1 + src2, 2), 16));
    INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I, R(dest) = Mr(src1 + src2, 2));


    INSTPAT("0100000 ????? ????? 101 ????? 01110 11", sraw, R,
            R(dest) = SEXT(sw(src1) >> BITS(src2, 4, 0), 32)); // >>_s
    INSTPAT("010000? ????? ????? 101 ????? 00110 11", sraiw, I,
            R(dest) = SEXT(sw(src1) >> BITS(src2, 5, 0), 32)); // >>_s
    INSTPAT("000000? ????? ????? 101 ????? 00110 11", srliw, I,
            R(dest) = SEXT(w(src1) >> BITS(src2, 5, 0), 32)); // >>_u
    INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai, I, R(dest) = (sword_t) src1 >> BITS(src2, 5, 0)); // >>_s
    INSTPAT("000000? ????? ????? 101 ????? 00100 11", srli, I, R(dest) = src1 >> BITS(src2, 5, 0)); // >>_u
    INSTPAT("0000000 ????? ????? 101 ????? 01110 11", srlw, R, R(dest) = SEXT(w(src1) >> BITS(src2, 4, 0), 32)); // >>_u

    INSTPAT("000000? ????? ????? 001 ????? 00100 11", slli, I, R(dest) = src1 << BITS(src2, 5, 0));
    INSTPAT("0000000 ????? ????? 001 ????? 01110 11", sllw, R, R(dest) = SEXT(w(src1 << BITS(src2, 4, 0)), 32));
    INSTPAT("000000? ????? ????? 001 ????? 00110 11", slliw, I, R(dest) = SEXT(src1 << BITS(src2, 5, 0), 32));

    INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I, R(dest) = src1 < src2); // <_u
    INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti, I, R(dest) = (sword_t) src1 < (sword_t) src2); // <_s
    INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, R, R(dest) = src1 < src2); // <_u
    INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, R, R(dest) = (sword_t) src1 < (sword_t) src2); // <_s

    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(dest) = s->pc + 4, s->dnpc = s->pc + src1);
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, s->dnpc = (src1 + src2) & ~1, R(dest) = s->pc + 4);

    INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, s->dnpc = src1 == src2 ? s->dnpc : s->pc + dest);
    INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, s->dnpc = src1 == src2 ? s->pc + dest : s->dnpc);
    INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B,
            s->dnpc = (sword_t) src1 >= (sword_t) src2 ? s->pc + dest : s->dnpc); // >=_s
    INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B, s->dnpc = src1 >= src2 ? s->pc + dest : s->dnpc);
    INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B,
            s->dnpc = (sword_t) src1 < (sword_t) src2 ? s->pc + dest : s->dnpc);
    INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B, s->dnpc = src1 < src2 ? s->pc + dest : s->dnpc);

    INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S, Mw(src1 + dest, 2, src2));
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw_, S, Mw(src1 + dest, 4, src2));

    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(dest) = src1);
    INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I, R(dest) = src1 & src2);
    INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and, R, R(dest) = src1 & src2);

    INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I, R(dest) = src1 ^ src2);
    INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R, R(dest) = src1 | src2);
    INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S, Mw(src1 + dest, 1, src2));

    INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, R, R(dest) = src1 * src2);
    INSTPAT("0000001 ????? ????? 000 ????? 01110 11", mulw, R, R(dest) = SEXT(w(src1 * src2), 32));
    INSTPAT("0000001 ????? ????? 100 ????? 01110 11", divw, R,
            R(dest) = SEXT(sw(src1) / sw(src2), 32)); /* /_s */
    INSTPAT("0000001 ????? ????? 110 ????? 01110 11", remw, R,
            R(dest) = SEXT(sw(src1) % sw(src2), 32)); /* %_s */

    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
    INSTPAT_END();

    R(0) = 0; // reset $zero to 0

    return 0;
}

int isa_exec_once(Decode *s) {
    s->isa.inst.val = inst_fetch(&s->snpc, 4);
    return decode_exec(s);
}
