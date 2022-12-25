module IFU(
  input  [31:0] io_in_inst,
  output [31:0] io_out_inst
);
  assign io_out_inst = io_in_inst; // @[Hello.scala 90:15]
endmodule
module TypeDecoder(
  input  [6:0] io_in_opcode,
  output [3:0] io_out_type
);
  wire [2:0] _GEN_0 = 7'h13 == io_in_opcode ? 3'h0 : 3'h3; // @[Hello.scala 244:15 245:24 247:19]
  assign io_out_type = {{1'd0}, _GEN_0};
endmodule
module Sext(
  input  [63:0] io_in_imm,
  input  [4:0]  io_in_len,
  output [63:0] io_out_imm
);
  wire [63:0] _io_out_imm_T_2 = {63'h7fffffffffffffff,io_in_imm[0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_0 = io_in_imm[0] ? _io_out_imm_T_2 : io_in_imm; // @[Hello.scala 225:14 231:38 232:20]
  wire [63:0] _GEN_1 = io_in_len == 5'h1 ? _GEN_0 : io_in_imm; // @[Hello.scala 225:14 230:29]
  wire [63:0] _io_out_imm_T_5 = {62'h3fffffffffffffff,io_in_imm[1:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_2 = io_in_imm[1] ? _io_out_imm_T_5 : _GEN_1; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_3 = io_in_len == 5'h2 ? _GEN_2 : _GEN_1; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_8 = {61'h1fffffffffffffff,io_in_imm[2:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_4 = io_in_imm[2] ? _io_out_imm_T_8 : _GEN_3; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_5 = io_in_len == 5'h3 ? _GEN_4 : _GEN_3; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_11 = {60'hfffffffffffffff,io_in_imm[3:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_6 = io_in_imm[3] ? _io_out_imm_T_11 : _GEN_5; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_7 = io_in_len == 5'h4 ? _GEN_6 : _GEN_5; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_14 = {59'h7ffffffffffffff,io_in_imm[4:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_8 = io_in_imm[4] ? _io_out_imm_T_14 : _GEN_7; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_9 = io_in_len == 5'h5 ? _GEN_8 : _GEN_7; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_17 = {58'h3ffffffffffffff,io_in_imm[5:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_10 = io_in_imm[5] ? _io_out_imm_T_17 : _GEN_9; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_11 = io_in_len == 5'h6 ? _GEN_10 : _GEN_9; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_20 = {57'h1ffffffffffffff,io_in_imm[6:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_12 = io_in_imm[6] ? _io_out_imm_T_20 : _GEN_11; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_13 = io_in_len == 5'h7 ? _GEN_12 : _GEN_11; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_23 = {56'hffffffffffffff,io_in_imm[7:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_14 = io_in_imm[7] ? _io_out_imm_T_23 : _GEN_13; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_15 = io_in_len == 5'h8 ? _GEN_14 : _GEN_13; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_26 = {55'h7fffffffffffff,io_in_imm[8:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_16 = io_in_imm[8] ? _io_out_imm_T_26 : _GEN_15; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_17 = io_in_len == 5'h9 ? _GEN_16 : _GEN_15; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_29 = {54'h3fffffffffffff,io_in_imm[9:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_18 = io_in_imm[9] ? _io_out_imm_T_29 : _GEN_17; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_19 = io_in_len == 5'ha ? _GEN_18 : _GEN_17; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_32 = {53'h1fffffffffffff,io_in_imm[10:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_20 = io_in_imm[10] ? _io_out_imm_T_32 : _GEN_19; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_21 = io_in_len == 5'hb ? _GEN_20 : _GEN_19; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_35 = {52'hfffffffffffff,io_in_imm[11:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_22 = io_in_imm[11] ? _io_out_imm_T_35 : _GEN_21; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_23 = io_in_len == 5'hc ? _GEN_22 : _GEN_21; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_38 = {51'h7ffffffffffff,io_in_imm[12:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_24 = io_in_imm[12] ? _io_out_imm_T_38 : _GEN_23; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_25 = io_in_len == 5'hd ? _GEN_24 : _GEN_23; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_41 = {50'h3ffffffffffff,io_in_imm[13:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_26 = io_in_imm[13] ? _io_out_imm_T_41 : _GEN_25; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_27 = io_in_len == 5'he ? _GEN_26 : _GEN_25; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_44 = {49'h1ffffffffffff,io_in_imm[14:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_28 = io_in_imm[14] ? _io_out_imm_T_44 : _GEN_27; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_29 = io_in_len == 5'hf ? _GEN_28 : _GEN_27; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_47 = {48'hffffffffffff,io_in_imm[15:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_30 = io_in_imm[15] ? _io_out_imm_T_47 : _GEN_29; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_31 = io_in_len == 5'h10 ? _GEN_30 : _GEN_29; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_50 = {47'h7fffffffffff,io_in_imm[16:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_32 = io_in_imm[16] ? _io_out_imm_T_50 : _GEN_31; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_33 = io_in_len == 5'h11 ? _GEN_32 : _GEN_31; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_53 = {46'h3fffffffffff,io_in_imm[17:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_34 = io_in_imm[17] ? _io_out_imm_T_53 : _GEN_33; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_35 = io_in_len == 5'h12 ? _GEN_34 : _GEN_33; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_56 = {45'h1fffffffffff,io_in_imm[18:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_36 = io_in_imm[18] ? _io_out_imm_T_56 : _GEN_35; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_37 = io_in_len == 5'h13 ? _GEN_36 : _GEN_35; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_59 = {44'hfffffffffff,io_in_imm[19:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_38 = io_in_imm[19] ? _io_out_imm_T_59 : _GEN_37; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_39 = io_in_len == 5'h14 ? _GEN_38 : _GEN_37; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_62 = {43'h7ffffffffff,io_in_imm[20:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_40 = io_in_imm[20] ? _io_out_imm_T_62 : _GEN_39; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_41 = io_in_len == 5'h15 ? _GEN_40 : _GEN_39; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_65 = {42'h3ffffffffff,io_in_imm[21:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_42 = io_in_imm[21] ? _io_out_imm_T_65 : _GEN_41; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_43 = io_in_len == 5'h16 ? _GEN_42 : _GEN_41; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_68 = {41'h1ffffffffff,io_in_imm[22:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_44 = io_in_imm[22] ? _io_out_imm_T_68 : _GEN_43; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_45 = io_in_len == 5'h17 ? _GEN_44 : _GEN_43; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_71 = {40'hffffffffff,io_in_imm[23:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_46 = io_in_imm[23] ? _io_out_imm_T_71 : _GEN_45; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_47 = io_in_len == 5'h18 ? _GEN_46 : _GEN_45; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_74 = {39'h7fffffffff,io_in_imm[24:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_48 = io_in_imm[24] ? _io_out_imm_T_74 : _GEN_47; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_49 = io_in_len == 5'h19 ? _GEN_48 : _GEN_47; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_77 = {38'h3fffffffff,io_in_imm[25:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_50 = io_in_imm[25] ? _io_out_imm_T_77 : _GEN_49; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_51 = io_in_len == 5'h1a ? _GEN_50 : _GEN_49; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_80 = {37'h1fffffffff,io_in_imm[26:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_52 = io_in_imm[26] ? _io_out_imm_T_80 : _GEN_51; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_53 = io_in_len == 5'h1b ? _GEN_52 : _GEN_51; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_83 = {36'hfffffffff,io_in_imm[27:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_54 = io_in_imm[27] ? _io_out_imm_T_83 : _GEN_53; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_55 = io_in_len == 5'h1c ? _GEN_54 : _GEN_53; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_86 = {35'h7ffffffff,io_in_imm[28:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_56 = io_in_imm[28] ? _io_out_imm_T_86 : _GEN_55; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_57 = io_in_len == 5'h1d ? _GEN_56 : _GEN_55; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_89 = {34'h3ffffffff,io_in_imm[29:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_58 = io_in_imm[29] ? _io_out_imm_T_89 : _GEN_57; // @[Hello.scala 231:38 232:20]
  wire [63:0] _GEN_59 = io_in_len == 5'h1e ? _GEN_58 : _GEN_57; // @[Hello.scala 230:29]
  wire [63:0] _io_out_imm_T_92 = {33'h1ffffffff,io_in_imm[30:0]}; // @[Cat.scala 31:58]
  wire [63:0] _GEN_60 = io_in_imm[30] ? _io_out_imm_T_92 : _GEN_59; // @[Hello.scala 231:38 232:20]
  assign io_out_imm = io_in_len == 5'h1f ? _GEN_60 : _GEN_59; // @[Hello.scala 230:29]
endmodule
module IDU(
  input  [63:0] io_in_inst,
  output [6:0]  io_out_opcode,
  output [3:0]  io_out_type,
  output [4:0]  io_out_rs1,
  output [4:0]  io_out_rd,
  output [63:0] io_out_imm
);
  wire [6:0] type_decoder_io_in_opcode; // @[Hello.scala 189:28]
  wire [3:0] type_decoder_io_out_type; // @[Hello.scala 189:28]
  wire [63:0] sext_io_in_imm; // @[Hello.scala 192:20]
  wire [4:0] sext_io_in_len; // @[Hello.scala 192:20]
  wire [63:0] sext_io_out_imm; // @[Hello.scala 192:20]
  wire [3:0] inst_type = type_decoder_io_out_type; // @[Hello.scala 190:23 206:13]
  wire [11:0] _GEN_0 = 4'h0 == inst_type ? io_in_inst[31:20] : 12'h0; // @[Hello.scala 193:18 207:21 209:22]
  wire [3:0] _GEN_1 = 4'h0 == inst_type ? 4'hc : 4'h0; // @[Hello.scala 194:18 207:21 210:22]
  TypeDecoder type_decoder ( // @[Hello.scala 189:28]
    .io_in_opcode(type_decoder_io_in_opcode),
    .io_out_type(type_decoder_io_out_type)
  );
  Sext sext ( // @[Hello.scala 192:20]
    .io_in_imm(sext_io_in_imm),
    .io_in_len(sext_io_in_len),
    .io_out_imm(sext_io_out_imm)
  );
  assign io_out_opcode = io_in_inst[6:0]; // @[Hello.scala 204:23]
  assign io_out_type = type_decoder_io_out_type; // @[Hello.scala 190:23 206:13]
  assign io_out_rs1 = io_in_inst[19:15]; // @[Hello.scala 198:27]
  assign io_out_rd = io_in_inst[11:7]; // @[Hello.scala 202:26]
  assign io_out_imm = 4'h0 == inst_type ? sext_io_out_imm : 64'h0; // @[Hello.scala 201:14 207:21 211:18]
  assign type_decoder_io_in_opcode = io_in_inst[6:0]; // @[Hello.scala 204:23]
  assign sext_io_in_imm = {{52'd0}, _GEN_0};
  assign sext_io_in_len = {{1'd0}, _GEN_1};
endmodule
module RegFile(
  input         clock,
  input         reset,
  input  [4:0]  io_in_dest,
  input  [63:0] io_in_src,
  input         io_wen,
  input  [4:0]  io_in_rs1,
  output [63:0] io_out_regs_0,
  output [63:0] io_out_regs_1,
  output [63:0] io_out_regs_2,
  output [63:0] io_out_regs_3,
  output [63:0] io_out_regs_4,
  output [63:0] io_out_regs_5,
  output [63:0] io_out_regs_6,
  output [63:0] io_out_regs_7,
  output [63:0] io_out_regs_8,
  output [63:0] io_out_regs_9,
  output [63:0] io_out_regs_10,
  output [63:0] io_out_regs_11,
  output [63:0] io_out_regs_12,
  output [63:0] io_out_regs_13,
  output [63:0] io_out_regs_14,
  output [63:0] io_out_regs_15,
  output [63:0] io_out_regs_16,
  output [63:0] io_out_regs_17,
  output [63:0] io_out_regs_18,
  output [63:0] io_out_regs_19,
  output [63:0] io_out_regs_20,
  output [63:0] io_out_regs_21,
  output [63:0] io_out_regs_22,
  output [63:0] io_out_regs_23,
  output [63:0] io_out_regs_24,
  output [63:0] io_out_regs_25,
  output [63:0] io_out_regs_26,
  output [63:0] io_out_regs_27,
  output [63:0] io_out_regs_28,
  output [63:0] io_out_regs_29,
  output [63:0] io_out_regs_30,
  output [63:0] io_out_regs_31,
  output [63:0] io_out_src1
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [63:0] _RAND_13;
  reg [63:0] _RAND_14;
  reg [63:0] _RAND_15;
  reg [63:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [63:0] _RAND_18;
  reg [63:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [63:0] _RAND_24;
  reg [63:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] regs_0; // @[Hello.scala 161:21]
  reg [63:0] regs_1; // @[Hello.scala 161:21]
  reg [63:0] regs_2; // @[Hello.scala 161:21]
  reg [63:0] regs_3; // @[Hello.scala 161:21]
  reg [63:0] regs_4; // @[Hello.scala 161:21]
  reg [63:0] regs_5; // @[Hello.scala 161:21]
  reg [63:0] regs_6; // @[Hello.scala 161:21]
  reg [63:0] regs_7; // @[Hello.scala 161:21]
  reg [63:0] regs_8; // @[Hello.scala 161:21]
  reg [63:0] regs_9; // @[Hello.scala 161:21]
  reg [63:0] regs_10; // @[Hello.scala 161:21]
  reg [63:0] regs_11; // @[Hello.scala 161:21]
  reg [63:0] regs_12; // @[Hello.scala 161:21]
  reg [63:0] regs_13; // @[Hello.scala 161:21]
  reg [63:0] regs_14; // @[Hello.scala 161:21]
  reg [63:0] regs_15; // @[Hello.scala 161:21]
  reg [63:0] regs_16; // @[Hello.scala 161:21]
  reg [63:0] regs_17; // @[Hello.scala 161:21]
  reg [63:0] regs_18; // @[Hello.scala 161:21]
  reg [63:0] regs_19; // @[Hello.scala 161:21]
  reg [63:0] regs_20; // @[Hello.scala 161:21]
  reg [63:0] regs_21; // @[Hello.scala 161:21]
  reg [63:0] regs_22; // @[Hello.scala 161:21]
  reg [63:0] regs_23; // @[Hello.scala 161:21]
  reg [63:0] regs_24; // @[Hello.scala 161:21]
  reg [63:0] regs_25; // @[Hello.scala 161:21]
  reg [63:0] regs_26; // @[Hello.scala 161:21]
  reg [63:0] regs_27; // @[Hello.scala 161:21]
  reg [63:0] regs_28; // @[Hello.scala 161:21]
  reg [63:0] regs_29; // @[Hello.scala 161:21]
  reg [63:0] regs_30; // @[Hello.scala 161:21]
  reg [63:0] regs_31; // @[Hello.scala 161:21]
  wire [63:0] _GEN_65 = 5'h1 == io_in_rs1 ? regs_1 : regs_0; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_66 = 5'h2 == io_in_rs1 ? regs_2 : _GEN_65; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_67 = 5'h3 == io_in_rs1 ? regs_3 : _GEN_66; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_68 = 5'h4 == io_in_rs1 ? regs_4 : _GEN_67; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_69 = 5'h5 == io_in_rs1 ? regs_5 : _GEN_68; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_70 = 5'h6 == io_in_rs1 ? regs_6 : _GEN_69; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_71 = 5'h7 == io_in_rs1 ? regs_7 : _GEN_70; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_72 = 5'h8 == io_in_rs1 ? regs_8 : _GEN_71; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_73 = 5'h9 == io_in_rs1 ? regs_9 : _GEN_72; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_74 = 5'ha == io_in_rs1 ? regs_10 : _GEN_73; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_75 = 5'hb == io_in_rs1 ? regs_11 : _GEN_74; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_76 = 5'hc == io_in_rs1 ? regs_12 : _GEN_75; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_77 = 5'hd == io_in_rs1 ? regs_13 : _GEN_76; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_78 = 5'he == io_in_rs1 ? regs_14 : _GEN_77; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_79 = 5'hf == io_in_rs1 ? regs_15 : _GEN_78; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_80 = 5'h10 == io_in_rs1 ? regs_16 : _GEN_79; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_81 = 5'h11 == io_in_rs1 ? regs_17 : _GEN_80; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_82 = 5'h12 == io_in_rs1 ? regs_18 : _GEN_81; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_83 = 5'h13 == io_in_rs1 ? regs_19 : _GEN_82; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_84 = 5'h14 == io_in_rs1 ? regs_20 : _GEN_83; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_85 = 5'h15 == io_in_rs1 ? regs_21 : _GEN_84; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_86 = 5'h16 == io_in_rs1 ? regs_22 : _GEN_85; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_87 = 5'h17 == io_in_rs1 ? regs_23 : _GEN_86; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_88 = 5'h18 == io_in_rs1 ? regs_24 : _GEN_87; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_89 = 5'h19 == io_in_rs1 ? regs_25 : _GEN_88; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_90 = 5'h1a == io_in_rs1 ? regs_26 : _GEN_89; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_91 = 5'h1b == io_in_rs1 ? regs_27 : _GEN_90; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_92 = 5'h1c == io_in_rs1 ? regs_28 : _GEN_91; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_93 = 5'h1d == io_in_rs1 ? regs_29 : _GEN_92; // @[Hello.scala 168:{15,15}]
  wire [63:0] _GEN_94 = 5'h1e == io_in_rs1 ? regs_30 : _GEN_93; // @[Hello.scala 168:{15,15}]
  assign io_out_regs_0 = regs_0; // @[Hello.scala 170:15]
  assign io_out_regs_1 = regs_1; // @[Hello.scala 170:15]
  assign io_out_regs_2 = regs_2; // @[Hello.scala 170:15]
  assign io_out_regs_3 = regs_3; // @[Hello.scala 170:15]
  assign io_out_regs_4 = regs_4; // @[Hello.scala 170:15]
  assign io_out_regs_5 = regs_5; // @[Hello.scala 170:15]
  assign io_out_regs_6 = regs_6; // @[Hello.scala 170:15]
  assign io_out_regs_7 = regs_7; // @[Hello.scala 170:15]
  assign io_out_regs_8 = regs_8; // @[Hello.scala 170:15]
  assign io_out_regs_9 = regs_9; // @[Hello.scala 170:15]
  assign io_out_regs_10 = regs_10; // @[Hello.scala 170:15]
  assign io_out_regs_11 = regs_11; // @[Hello.scala 170:15]
  assign io_out_regs_12 = regs_12; // @[Hello.scala 170:15]
  assign io_out_regs_13 = regs_13; // @[Hello.scala 170:15]
  assign io_out_regs_14 = regs_14; // @[Hello.scala 170:15]
  assign io_out_regs_15 = regs_15; // @[Hello.scala 170:15]
  assign io_out_regs_16 = regs_16; // @[Hello.scala 170:15]
  assign io_out_regs_17 = regs_17; // @[Hello.scala 170:15]
  assign io_out_regs_18 = regs_18; // @[Hello.scala 170:15]
  assign io_out_regs_19 = regs_19; // @[Hello.scala 170:15]
  assign io_out_regs_20 = regs_20; // @[Hello.scala 170:15]
  assign io_out_regs_21 = regs_21; // @[Hello.scala 170:15]
  assign io_out_regs_22 = regs_22; // @[Hello.scala 170:15]
  assign io_out_regs_23 = regs_23; // @[Hello.scala 170:15]
  assign io_out_regs_24 = regs_24; // @[Hello.scala 170:15]
  assign io_out_regs_25 = regs_25; // @[Hello.scala 170:15]
  assign io_out_regs_26 = regs_26; // @[Hello.scala 170:15]
  assign io_out_regs_27 = regs_27; // @[Hello.scala 170:15]
  assign io_out_regs_28 = regs_28; // @[Hello.scala 170:15]
  assign io_out_regs_29 = regs_29; // @[Hello.scala 170:15]
  assign io_out_regs_30 = regs_30; // @[Hello.scala 170:15]
  assign io_out_regs_31 = regs_31; // @[Hello.scala 170:15]
  assign io_out_src1 = 5'h1f == io_in_rs1 ? regs_31 : _GEN_94; // @[Hello.scala 168:{15,15}]
  always @(posedge clock) begin
    if (reset) begin // @[Hello.scala 161:21]
      regs_0 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h0 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_0 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_1 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_1 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_2 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h2 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_2 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_3 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h3 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_3 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_4 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h4 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_4 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_5 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h5 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_5 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_6 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h6 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_6 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_7 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h7 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_7 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_8 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h8 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_8 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_9 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h9 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_9 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_10 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'ha == io_in_dest) begin // @[Hello.scala 166:22]
        regs_10 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_11 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'hb == io_in_dest) begin // @[Hello.scala 166:22]
        regs_11 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_12 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'hc == io_in_dest) begin // @[Hello.scala 166:22]
        regs_12 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_13 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'hd == io_in_dest) begin // @[Hello.scala 166:22]
        regs_13 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_14 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'he == io_in_dest) begin // @[Hello.scala 166:22]
        regs_14 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_15 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'hf == io_in_dest) begin // @[Hello.scala 166:22]
        regs_15 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_16 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h10 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_16 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_17 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h11 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_17 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_18 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h12 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_18 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_19 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h13 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_19 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_20 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h14 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_20 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_21 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h15 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_21 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_22 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h16 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_22 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_23 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h17 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_23 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_24 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h18 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_24 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_25 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h19 == io_in_dest) begin // @[Hello.scala 166:22]
        regs_25 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_26 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1a == io_in_dest) begin // @[Hello.scala 166:22]
        regs_26 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_27 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1b == io_in_dest) begin // @[Hello.scala 166:22]
        regs_27 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_28 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1c == io_in_dest) begin // @[Hello.scala 166:22]
        regs_28 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_29 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1d == io_in_dest) begin // @[Hello.scala 166:22]
        regs_29 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_30 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1e == io_in_dest) begin // @[Hello.scala 166:22]
        regs_30 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
    if (reset) begin // @[Hello.scala 161:21]
      regs_31 <= 64'h0; // @[Hello.scala 161:21]
    end else if (io_in_dest > 5'h0 & io_wen) begin // @[Hello.scala 165:47]
      if (5'h1f == io_in_dest) begin // @[Hello.scala 166:22]
        regs_31 <= io_in_src; // @[Hello.scala 166:22]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  regs_0 = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  regs_1 = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  regs_2 = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  regs_3 = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  regs_4 = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  regs_5 = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  regs_6 = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  regs_7 = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  regs_8 = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  regs_9 = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  regs_10 = _RAND_10[63:0];
  _RAND_11 = {2{`RANDOM}};
  regs_11 = _RAND_11[63:0];
  _RAND_12 = {2{`RANDOM}};
  regs_12 = _RAND_12[63:0];
  _RAND_13 = {2{`RANDOM}};
  regs_13 = _RAND_13[63:0];
  _RAND_14 = {2{`RANDOM}};
  regs_14 = _RAND_14[63:0];
  _RAND_15 = {2{`RANDOM}};
  regs_15 = _RAND_15[63:0];
  _RAND_16 = {2{`RANDOM}};
  regs_16 = _RAND_16[63:0];
  _RAND_17 = {2{`RANDOM}};
  regs_17 = _RAND_17[63:0];
  _RAND_18 = {2{`RANDOM}};
  regs_18 = _RAND_18[63:0];
  _RAND_19 = {2{`RANDOM}};
  regs_19 = _RAND_19[63:0];
  _RAND_20 = {2{`RANDOM}};
  regs_20 = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  regs_21 = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  regs_22 = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  regs_23 = _RAND_23[63:0];
  _RAND_24 = {2{`RANDOM}};
  regs_24 = _RAND_24[63:0];
  _RAND_25 = {2{`RANDOM}};
  regs_25 = _RAND_25[63:0];
  _RAND_26 = {2{`RANDOM}};
  regs_26 = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  regs_27 = _RAND_27[63:0];
  _RAND_28 = {2{`RANDOM}};
  regs_28 = _RAND_28[63:0];
  _RAND_29 = {2{`RANDOM}};
  regs_29 = _RAND_29[63:0];
  _RAND_30 = {2{`RANDOM}};
  regs_30 = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  regs_31 = _RAND_31[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module IEU(
  input         clock,
  input         reset,
  input  [6:0]  io_in_opcode,
  input  [3:0]  io_in_type,
  input  [4:0]  io_in_rs1,
  input  [4:0]  io_in_rd,
  input  [63:0] io_in_imm,
  output [63:0] io_out_regs_0,
  output [63:0] io_out_regs_1,
  output [63:0] io_out_regs_2,
  output [63:0] io_out_regs_3,
  output [63:0] io_out_regs_4,
  output [63:0] io_out_regs_5,
  output [63:0] io_out_regs_6,
  output [63:0] io_out_regs_7,
  output [63:0] io_out_regs_8,
  output [63:0] io_out_regs_9,
  output [63:0] io_out_regs_10,
  output [63:0] io_out_regs_11,
  output [63:0] io_out_regs_12,
  output [63:0] io_out_regs_13,
  output [63:0] io_out_regs_14,
  output [63:0] io_out_regs_15,
  output [63:0] io_out_regs_16,
  output [63:0] io_out_regs_17,
  output [63:0] io_out_regs_18,
  output [63:0] io_out_regs_19,
  output [63:0] io_out_regs_20,
  output [63:0] io_out_regs_21,
  output [63:0] io_out_regs_22,
  output [63:0] io_out_regs_23,
  output [63:0] io_out_regs_24,
  output [63:0] io_out_regs_25,
  output [63:0] io_out_regs_26,
  output [63:0] io_out_regs_27,
  output [63:0] io_out_regs_28,
  output [63:0] io_out_regs_29,
  output [63:0] io_out_regs_30,
  output [63:0] io_out_regs_31,
  output        io_out_ebreak
);
  wire  reg_file_clock; // @[Hello.scala 113:24]
  wire  reg_file_reset; // @[Hello.scala 113:24]
  wire [4:0] reg_file_io_in_dest; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_in_src; // @[Hello.scala 113:24]
  wire  reg_file_io_wen; // @[Hello.scala 113:24]
  wire [4:0] reg_file_io_in_rs1; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_0; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_1; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_2; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_3; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_4; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_5; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_6; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_7; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_8; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_9; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_10; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_11; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_12; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_13; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_14; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_15; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_16; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_17; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_18; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_19; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_20; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_21; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_22; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_23; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_24; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_25; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_26; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_27; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_28; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_29; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_30; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_regs_31; // @[Hello.scala 113:24]
  wire [63:0] reg_file_io_out_src1; // @[Hello.scala 113:24]
  wire [63:0] src1 = 4'h0 == io_in_type ? reg_file_io_out_src1 : 64'h0; // @[Hello.scala 126:22 130:12 116:8]
  wire [63:0] src2 = 4'h0 == io_in_type ? io_in_imm : 64'h0; // @[Hello.scala 126:22 131:12 117:8]
  wire [63:0] _reg_file_io_in_src_T_1 = src1 + src2; // @[Hello.scala 139:34]
  wire [4:0] _GEN_5 = 7'h13 == io_in_opcode ? io_in_rd : 5'h0; // @[Hello.scala 135:24 137:12 118:8]
  wire [63:0] dest = {{59'd0}, _GEN_5}; // @[Hello.scala 110:18]
  wire [63:0] _GEN_6 = 7'h13 == io_in_opcode ? dest : 64'h0; // @[Hello.scala 120:23 135:24 138:27]
  RegFile reg_file ( // @[Hello.scala 113:24]
    .clock(reg_file_clock),
    .reset(reg_file_reset),
    .io_in_dest(reg_file_io_in_dest),
    .io_in_src(reg_file_io_in_src),
    .io_wen(reg_file_io_wen),
    .io_in_rs1(reg_file_io_in_rs1),
    .io_out_regs_0(reg_file_io_out_regs_0),
    .io_out_regs_1(reg_file_io_out_regs_1),
    .io_out_regs_2(reg_file_io_out_regs_2),
    .io_out_regs_3(reg_file_io_out_regs_3),
    .io_out_regs_4(reg_file_io_out_regs_4),
    .io_out_regs_5(reg_file_io_out_regs_5),
    .io_out_regs_6(reg_file_io_out_regs_6),
    .io_out_regs_7(reg_file_io_out_regs_7),
    .io_out_regs_8(reg_file_io_out_regs_8),
    .io_out_regs_9(reg_file_io_out_regs_9),
    .io_out_regs_10(reg_file_io_out_regs_10),
    .io_out_regs_11(reg_file_io_out_regs_11),
    .io_out_regs_12(reg_file_io_out_regs_12),
    .io_out_regs_13(reg_file_io_out_regs_13),
    .io_out_regs_14(reg_file_io_out_regs_14),
    .io_out_regs_15(reg_file_io_out_regs_15),
    .io_out_regs_16(reg_file_io_out_regs_16),
    .io_out_regs_17(reg_file_io_out_regs_17),
    .io_out_regs_18(reg_file_io_out_regs_18),
    .io_out_regs_19(reg_file_io_out_regs_19),
    .io_out_regs_20(reg_file_io_out_regs_20),
    .io_out_regs_21(reg_file_io_out_regs_21),
    .io_out_regs_22(reg_file_io_out_regs_22),
    .io_out_regs_23(reg_file_io_out_regs_23),
    .io_out_regs_24(reg_file_io_out_regs_24),
    .io_out_regs_25(reg_file_io_out_regs_25),
    .io_out_regs_26(reg_file_io_out_regs_26),
    .io_out_regs_27(reg_file_io_out_regs_27),
    .io_out_regs_28(reg_file_io_out_regs_28),
    .io_out_regs_29(reg_file_io_out_regs_29),
    .io_out_regs_30(reg_file_io_out_regs_30),
    .io_out_regs_31(reg_file_io_out_regs_31),
    .io_out_src1(reg_file_io_out_src1)
  );
  assign io_out_regs_0 = reg_file_io_out_regs_0; // @[Hello.scala 145:15]
  assign io_out_regs_1 = reg_file_io_out_regs_1; // @[Hello.scala 145:15]
  assign io_out_regs_2 = reg_file_io_out_regs_2; // @[Hello.scala 145:15]
  assign io_out_regs_3 = reg_file_io_out_regs_3; // @[Hello.scala 145:15]
  assign io_out_regs_4 = reg_file_io_out_regs_4; // @[Hello.scala 145:15]
  assign io_out_regs_5 = reg_file_io_out_regs_5; // @[Hello.scala 145:15]
  assign io_out_regs_6 = reg_file_io_out_regs_6; // @[Hello.scala 145:15]
  assign io_out_regs_7 = reg_file_io_out_regs_7; // @[Hello.scala 145:15]
  assign io_out_regs_8 = reg_file_io_out_regs_8; // @[Hello.scala 145:15]
  assign io_out_regs_9 = reg_file_io_out_regs_9; // @[Hello.scala 145:15]
  assign io_out_regs_10 = reg_file_io_out_regs_10; // @[Hello.scala 145:15]
  assign io_out_regs_11 = reg_file_io_out_regs_11; // @[Hello.scala 145:15]
  assign io_out_regs_12 = reg_file_io_out_regs_12; // @[Hello.scala 145:15]
  assign io_out_regs_13 = reg_file_io_out_regs_13; // @[Hello.scala 145:15]
  assign io_out_regs_14 = reg_file_io_out_regs_14; // @[Hello.scala 145:15]
  assign io_out_regs_15 = reg_file_io_out_regs_15; // @[Hello.scala 145:15]
  assign io_out_regs_16 = reg_file_io_out_regs_16; // @[Hello.scala 145:15]
  assign io_out_regs_17 = reg_file_io_out_regs_17; // @[Hello.scala 145:15]
  assign io_out_regs_18 = reg_file_io_out_regs_18; // @[Hello.scala 145:15]
  assign io_out_regs_19 = reg_file_io_out_regs_19; // @[Hello.scala 145:15]
  assign io_out_regs_20 = reg_file_io_out_regs_20; // @[Hello.scala 145:15]
  assign io_out_regs_21 = reg_file_io_out_regs_21; // @[Hello.scala 145:15]
  assign io_out_regs_22 = reg_file_io_out_regs_22; // @[Hello.scala 145:15]
  assign io_out_regs_23 = reg_file_io_out_regs_23; // @[Hello.scala 145:15]
  assign io_out_regs_24 = reg_file_io_out_regs_24; // @[Hello.scala 145:15]
  assign io_out_regs_25 = reg_file_io_out_regs_25; // @[Hello.scala 145:15]
  assign io_out_regs_26 = reg_file_io_out_regs_26; // @[Hello.scala 145:15]
  assign io_out_regs_27 = reg_file_io_out_regs_27; // @[Hello.scala 145:15]
  assign io_out_regs_28 = reg_file_io_out_regs_28; // @[Hello.scala 145:15]
  assign io_out_regs_29 = reg_file_io_out_regs_29; // @[Hello.scala 145:15]
  assign io_out_regs_30 = reg_file_io_out_regs_30; // @[Hello.scala 145:15]
  assign io_out_regs_31 = reg_file_io_out_regs_31; // @[Hello.scala 145:15]
  assign io_out_ebreak = 7'h13 == io_in_opcode ? 1'h0 : 7'h73 == io_in_opcode; // @[Hello.scala 115:17 135:24]
  assign reg_file_clock = clock;
  assign reg_file_reset = reset;
  assign reg_file_io_in_dest = _GEN_6[4:0];
  assign reg_file_io_in_src = 7'h13 == io_in_opcode ? _reg_file_io_in_src_T_1 : 64'h0; // @[Hello.scala 121:22 135:24 139:26]
  assign reg_file_io_wen = 4'h0 == io_in_type; // @[Hello.scala 126:22]
  assign reg_file_io_in_rs1 = 4'h0 == io_in_type ? io_in_rs1 : 5'h0; // @[Hello.scala 123:22 126:22 128:26]
endmodule
module Soc(
  input         clock,
  input         reset,
  input  [31:0] io_in_inst,
  output [63:0] io_out_pc,
  output [63:0] io_out_regs_0,
  output [63:0] io_out_regs_1,
  output [63:0] io_out_regs_2,
  output [63:0] io_out_regs_3,
  output [63:0] io_out_regs_4,
  output [63:0] io_out_regs_5,
  output [63:0] io_out_regs_6,
  output [63:0] io_out_regs_7,
  output [63:0] io_out_regs_8,
  output [63:0] io_out_regs_9,
  output [63:0] io_out_regs_10,
  output [63:0] io_out_regs_11,
  output [63:0] io_out_regs_12,
  output [63:0] io_out_regs_13,
  output [63:0] io_out_regs_14,
  output [63:0] io_out_regs_15,
  output [63:0] io_out_regs_16,
  output [63:0] io_out_regs_17,
  output [63:0] io_out_regs_18,
  output [63:0] io_out_regs_19,
  output [63:0] io_out_regs_20,
  output [63:0] io_out_regs_21,
  output [63:0] io_out_regs_22,
  output [63:0] io_out_regs_23,
  output [63:0] io_out_regs_24,
  output [63:0] io_out_regs_25,
  output [63:0] io_out_regs_26,
  output [63:0] io_out_regs_27,
  output [63:0] io_out_regs_28,
  output [63:0] io_out_regs_29,
  output [63:0] io_out_regs_30,
  output [63:0] io_out_regs_31,
  output [31:0] io_out_inst,
  output        io_out_ebreak
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] IFU_io_in_inst; // @[Hello.scala 40:19]
  wire [31:0] IFU_io_out_inst; // @[Hello.scala 40:19]
  wire [63:0] IDU_io_in_inst; // @[Hello.scala 41:19]
  wire [6:0] IDU_io_out_opcode; // @[Hello.scala 41:19]
  wire [3:0] IDU_io_out_type; // @[Hello.scala 41:19]
  wire [4:0] IDU_io_out_rs1; // @[Hello.scala 41:19]
  wire [4:0] IDU_io_out_rd; // @[Hello.scala 41:19]
  wire [63:0] IDU_io_out_imm; // @[Hello.scala 41:19]
  wire  IEU_clock; // @[Hello.scala 42:19]
  wire  IEU_reset; // @[Hello.scala 42:19]
  wire [6:0] IEU_io_in_opcode; // @[Hello.scala 42:19]
  wire [3:0] IEU_io_in_type; // @[Hello.scala 42:19]
  wire [4:0] IEU_io_in_rs1; // @[Hello.scala 42:19]
  wire [4:0] IEU_io_in_rd; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_in_imm; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_0; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_1; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_2; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_3; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_4; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_5; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_6; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_7; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_8; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_9; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_10; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_11; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_12; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_13; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_14; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_15; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_16; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_17; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_18; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_19; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_20; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_21; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_22; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_23; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_24; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_25; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_26; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_27; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_28; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_29; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_30; // @[Hello.scala 42:19]
  wire [63:0] IEU_io_out_regs_31; // @[Hello.scala 42:19]
  wire  IEU_io_out_ebreak; // @[Hello.scala 42:19]
  reg [31:0] pc; // @[Hello.scala 38:19]
  wire [31:0] _pc_T_1 = pc + 32'h4; // @[Hello.scala 76:12]
  wire [31:0] inst = IFU_io_out_inst; // @[Hello.scala 39:18 53:8]
  IFU IFU ( // @[Hello.scala 40:19]
    .io_in_inst(IFU_io_in_inst),
    .io_out_inst(IFU_io_out_inst)
  );
  IDU IDU ( // @[Hello.scala 41:19]
    .io_in_inst(IDU_io_in_inst),
    .io_out_opcode(IDU_io_out_opcode),
    .io_out_type(IDU_io_out_type),
    .io_out_rs1(IDU_io_out_rs1),
    .io_out_rd(IDU_io_out_rd),
    .io_out_imm(IDU_io_out_imm)
  );
  IEU IEU ( // @[Hello.scala 42:19]
    .clock(IEU_clock),
    .reset(IEU_reset),
    .io_in_opcode(IEU_io_in_opcode),
    .io_in_type(IEU_io_in_type),
    .io_in_rs1(IEU_io_in_rs1),
    .io_in_rd(IEU_io_in_rd),
    .io_in_imm(IEU_io_in_imm),
    .io_out_regs_0(IEU_io_out_regs_0),
    .io_out_regs_1(IEU_io_out_regs_1),
    .io_out_regs_2(IEU_io_out_regs_2),
    .io_out_regs_3(IEU_io_out_regs_3),
    .io_out_regs_4(IEU_io_out_regs_4),
    .io_out_regs_5(IEU_io_out_regs_5),
    .io_out_regs_6(IEU_io_out_regs_6),
    .io_out_regs_7(IEU_io_out_regs_7),
    .io_out_regs_8(IEU_io_out_regs_8),
    .io_out_regs_9(IEU_io_out_regs_9),
    .io_out_regs_10(IEU_io_out_regs_10),
    .io_out_regs_11(IEU_io_out_regs_11),
    .io_out_regs_12(IEU_io_out_regs_12),
    .io_out_regs_13(IEU_io_out_regs_13),
    .io_out_regs_14(IEU_io_out_regs_14),
    .io_out_regs_15(IEU_io_out_regs_15),
    .io_out_regs_16(IEU_io_out_regs_16),
    .io_out_regs_17(IEU_io_out_regs_17),
    .io_out_regs_18(IEU_io_out_regs_18),
    .io_out_regs_19(IEU_io_out_regs_19),
    .io_out_regs_20(IEU_io_out_regs_20),
    .io_out_regs_21(IEU_io_out_regs_21),
    .io_out_regs_22(IEU_io_out_regs_22),
    .io_out_regs_23(IEU_io_out_regs_23),
    .io_out_regs_24(IEU_io_out_regs_24),
    .io_out_regs_25(IEU_io_out_regs_25),
    .io_out_regs_26(IEU_io_out_regs_26),
    .io_out_regs_27(IEU_io_out_regs_27),
    .io_out_regs_28(IEU_io_out_regs_28),
    .io_out_regs_29(IEU_io_out_regs_29),
    .io_out_regs_30(IEU_io_out_regs_30),
    .io_out_regs_31(IEU_io_out_regs_31),
    .io_out_ebreak(IEU_io_out_ebreak)
  );
  assign io_out_pc = {{32'd0}, pc}; // @[Hello.scala 77:13]
  assign io_out_regs_0 = IEU_io_out_regs_0; // @[Hello.scala 74:15]
  assign io_out_regs_1 = IEU_io_out_regs_1; // @[Hello.scala 74:15]
  assign io_out_regs_2 = IEU_io_out_regs_2; // @[Hello.scala 74:15]
  assign io_out_regs_3 = IEU_io_out_regs_3; // @[Hello.scala 74:15]
  assign io_out_regs_4 = IEU_io_out_regs_4; // @[Hello.scala 74:15]
  assign io_out_regs_5 = IEU_io_out_regs_5; // @[Hello.scala 74:15]
  assign io_out_regs_6 = IEU_io_out_regs_6; // @[Hello.scala 74:15]
  assign io_out_regs_7 = IEU_io_out_regs_7; // @[Hello.scala 74:15]
  assign io_out_regs_8 = IEU_io_out_regs_8; // @[Hello.scala 74:15]
  assign io_out_regs_9 = IEU_io_out_regs_9; // @[Hello.scala 74:15]
  assign io_out_regs_10 = IEU_io_out_regs_10; // @[Hello.scala 74:15]
  assign io_out_regs_11 = IEU_io_out_regs_11; // @[Hello.scala 74:15]
  assign io_out_regs_12 = IEU_io_out_regs_12; // @[Hello.scala 74:15]
  assign io_out_regs_13 = IEU_io_out_regs_13; // @[Hello.scala 74:15]
  assign io_out_regs_14 = IEU_io_out_regs_14; // @[Hello.scala 74:15]
  assign io_out_regs_15 = IEU_io_out_regs_15; // @[Hello.scala 74:15]
  assign io_out_regs_16 = IEU_io_out_regs_16; // @[Hello.scala 74:15]
  assign io_out_regs_17 = IEU_io_out_regs_17; // @[Hello.scala 74:15]
  assign io_out_regs_18 = IEU_io_out_regs_18; // @[Hello.scala 74:15]
  assign io_out_regs_19 = IEU_io_out_regs_19; // @[Hello.scala 74:15]
  assign io_out_regs_20 = IEU_io_out_regs_20; // @[Hello.scala 74:15]
  assign io_out_regs_21 = IEU_io_out_regs_21; // @[Hello.scala 74:15]
  assign io_out_regs_22 = IEU_io_out_regs_22; // @[Hello.scala 74:15]
  assign io_out_regs_23 = IEU_io_out_regs_23; // @[Hello.scala 74:15]
  assign io_out_regs_24 = IEU_io_out_regs_24; // @[Hello.scala 74:15]
  assign io_out_regs_25 = IEU_io_out_regs_25; // @[Hello.scala 74:15]
  assign io_out_regs_26 = IEU_io_out_regs_26; // @[Hello.scala 74:15]
  assign io_out_regs_27 = IEU_io_out_regs_27; // @[Hello.scala 74:15]
  assign io_out_regs_28 = IEU_io_out_regs_28; // @[Hello.scala 74:15]
  assign io_out_regs_29 = IEU_io_out_regs_29; // @[Hello.scala 74:15]
  assign io_out_regs_30 = IEU_io_out_regs_30; // @[Hello.scala 74:15]
  assign io_out_regs_31 = IEU_io_out_regs_31; // @[Hello.scala 74:15]
  assign io_out_inst = IFU_io_out_inst; // @[Hello.scala 39:18 53:8]
  assign io_out_ebreak = IEU_io_out_ebreak; // @[Hello.scala 73:17]
  assign IFU_io_in_inst = io_in_inst; // @[Hello.scala 51:18]
  assign IDU_io_in_inst = {{32'd0}, inst}; // @[Hello.scala 56:18]
  assign IEU_clock = clock;
  assign IEU_reset = reset;
  assign IEU_io_in_opcode = IDU_io_out_opcode; // @[Hello.scala 47:20 61:10]
  assign IEU_io_in_type = IDU_io_out_type; // @[Hello.scala 43:23 60:13]
  assign IEU_io_in_rs1 = IDU_io_out_rs1; // @[Hello.scala 45:17 58:7]
  assign IEU_io_in_rd = IDU_io_out_rd; // @[Hello.scala 44:16 57:6]
  assign IEU_io_in_imm = IDU_io_out_imm; // @[Hello.scala 48:17 62:7]
  always @(posedge clock) begin
    if (reset) begin // @[Hello.scala 38:19]
      pc <= 32'h80000000; // @[Hello.scala 38:19]
    end else begin
      pc <= _pc_T_1; // @[Hello.scala 76:6]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pc = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
