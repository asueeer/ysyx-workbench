/*
 * This code is a minimal hardware described in Chisel.
 * 
 * Blinking LED: the FPGA version of Hello World
 */

import chisel3._
import chisel3.util._

class Util {
  def types = Map("I" -> 0.U, "U" -> 1.U, "S" -> 2.U,
    "N" -> 3.U, // none
    "J" -> 4.U,
    "R" -> 5.U,
    "B" -> 6.U
  )

  def opcodes = Map("addi" -> "b0010011".U,
    "ebreak" -> "b1110011".U
  )


  val type_I :: type_U :: type_S :: type_N :: type_J :: type_R :: type_B :: Nil = Enum(7)

}


class Soc extends Module {

  val io = IO(new Bundle() {
    val in_inst = Input(UInt(32.W))

    val out_pc = Output(UInt(64.W))
    val out_regs = Output(Vec(32, UInt(64.W)))
    val out_inst = Output(UInt(32.W))
    val out_ebreak = Output(Bool())
  })
  val pc = RegInit("x80000000".U)
  val inst = Wire(UInt(32.W))
  val IFU = Module(new IFU)
  val IDU = Module(new IDU)
  val IEU = Module(new IEU)
  val inst_type = Wire(UInt(4.W))
  val rd = Wire(UInt(5.W))
  val rs1 = Wire(UInt(5.W))
  val rs2 = Wire(UInt(5.W))
  val opcode = Wire(UInt(7.W))
  val imm = Wire(UInt(64.W))

  // out_inst = IFU(in_inst, pc)
  IFU.io.in_inst := io.in_inst
  IFU.io.pc := pc
  inst := IFU.io.out_inst

  // inst_type, rd, rs1, rs2, opcode = IDU(inst)
  IDU.io.in_inst := inst
  rd := IDU.io.out_rd
  rs1 := IDU.io.out_rs1
  rs2 := IDU.io.out_rs2
  inst_type := IDU.io.out_type
  opcode := IDU.io.out_opcode
  imm := IDU.io.out_imm

  // io.out_regs = IEU(opcode, rd, rs2, rs1, inst_type)
  IEU.io.in_opcode := opcode
  IEU.io.in_rd := rd
  IEU.io.in_rs2 := rs2
  IEU.io.in_rs1 := rs1
  IEU.io.in_type := inst_type
  IEU.io.in_imm := imm
  IEU.io.in_funct3 := 0.U
  IEU.io.in_funct7 := 0.U
  io.out_ebreak := IEU.io.out_ebreak
  io.out_regs := IEU.io.out_regs

  pc := pc + 4.U
  io.out_pc := pc
  io.out_inst := inst
}


// Instruction Fetch Unit
class IFU extends Module {
  val io = IO(new Bundle() {
    val pc = Input(UInt(64.W))
    val in_inst = Input(UInt(32.W))

    val out_inst = Output(UInt(32.W))
  })
  io.out_inst := io.in_inst
}

// Instruction Execution Unit
class IEU extends Module {
  val io = IO(new Bundle() {
    val in_opcode = Input(UInt(7.W))
    val in_type = Input(UInt(4.W))
    val in_funct7 = Input(UInt(7.W))
    val in_rs1 = Input(UInt(5.W))
    val in_rs2 = Input(UInt(5.W))
    val in_rd = Input(UInt(5.W))
    val in_funct3 = Input(UInt(3.W))
    val in_imm = Input(UInt(64.W))

    val out_regs = Output(Vec(32, UInt(64.W)))
    val out_ebreak = Output(Bool())
  })

  val util = new Util()
  val dest = Wire(UInt(64.W))
  val src1 = Wire(UInt(64.W))
  val src2 = Wire(UInt(64.W))
  val reg_file = Module(new RegFile)

  io.out_ebreak := false.B
  src1 := 0.U
  src2 := 0.U
  dest := 0.U

  reg_file.io.in_dest := 0.U
  reg_file.io.in_src := 0.U
  reg_file.io.in_rs2 := 0.U
  reg_file.io.in_rs1 := 0.U
  reg_file.io.wen := false.B

  switch(io.in_type) {
    is(util.type_I) {
      reg_file.io.in_rs1 := io.in_rs1
      reg_file.io.wen := true.B
      src1 := reg_file.io.out_src1
      src2 := io.in_imm
    }
  }

  switch(io.in_opcode) {
    is(util.opcodes("addi")) {
      dest := io.in_rd
      reg_file.io.in_dest := dest
      reg_file.io.in_src := src1 + src2
    }
    is(util.opcodes("ebreak")) {
      io.out_ebreak := true.B
    }
  }
  io.out_regs := reg_file.io.out_regs
}

class RegFile extends Module {
  val io = IO(new Bundle() {
    val in_dest = Input(UInt(5.W))
    val in_src = Input(UInt(64.W))
    val wen = Input(Bool())

    val in_rs1 = Input(UInt(5.W))
    val in_rs2 = Input(UInt(5.W))

    val out_regs = Output(Vec(32, UInt(64.W)))
    val out_src1 = Output(UInt(64.W))
    val out_src2 = Output(UInt(64.W))
  })
  val regs = RegInit(VecInit(Seq.fill(32)(0.U(64.W))))

  io.out_src1 := 0.U
  io.out_src2 := 0.U
  when(io.in_dest > 0.U && io.wen === true.B) {
    regs(io.in_dest) := io.in_src
  }
  io.out_src1 := regs(io.in_rs1)
  io.out_src2 := regs(io.in_rs2)
  io.out_regs := regs
}

// Instruction Decode Unit
class IDU extends Module {
  val io = IO(new Bundle() {
    val in_inst = Input(UInt(64.W))

    val out_opcode = Output(UInt(7.W))
    val out_type = Output(UInt(4.W))
    val out_funct7 = Output(UInt(7.W))
    val out_rs1 = Output(UInt(5.W))
    val out_rs2 = Output(UInt(5.W))
    val out_rd = Output(UInt(5.W))
    val out_funct3 = Output(UInt(3.W))
    val out_imm = Output(UInt(64.W))
  })
  val util = new Util()
  val opcode = Wire(UInt(7.W))
  val type_decoder = Module(new TypeDecoder)
  val inst_type = Wire(UInt(4.W))

  val sext = Module(new Sext)
  sext.io.in_imm := 0.U
  sext.io.in_len := 0.U

  io.out_funct7 := io.in_inst(31, 25)
  io.out_funct3 := io.in_inst(14, 12)
  io.out_rs1 := io.in_inst(19, 15)
  io.out_rs2 := io.in_inst(24, 20)
  io.out_funct3 := 0.U
  io.out_imm := 0.U
  io.out_rd := io.in_inst(11, 7)

  opcode := io.in_inst(6, 0)
  type_decoder.io.in_opcode := opcode
  inst_type := type_decoder.io.out_type
  switch(inst_type) {
    is(util.type_I) {
      sext.io.in_imm := io.in_inst(31, 20)
      sext.io.in_len := 12.U
      io.out_imm := sext.io.out_imm
    }
  }
  io.out_opcode := opcode
  io.out_type := inst_type
}

class Sext extends Module {
  val io = IO(new Bundle() {
    val in_imm = Input(UInt(64.W))
    val in_len = Input(UInt(5.W))
    val out_imm = Output(UInt(64.W))
  })

  io.out_imm := io.in_imm
  val all_one = Wire(UInt(64.W))
  all_one := ("x" + "f" * 16).U

  for (i <- 1 until 32) {
    when(io.in_len === i.U) {
      when(io.in_imm(i - 1) === 1.U) {
        io.out_imm := Cat(all_one(63, i), io.in_imm(i - 1, 0))
      }
    }
  }
}

class TypeDecoder extends Module {
  val io = IO(new Bundle() {
    val in_opcode = Input(UInt(7.W))
    val out_type = Output(UInt(4.W))
  })
  val util = new Util()
  io.out_type := util.type_N
  switch(io.in_opcode) {
    is(util.opcodes("addi")) {
      io.out_type := util.type_I
    }
    // todo add more
  }
}

/**
 * An object extending App to generate the Verilog code.
 */
object Hello extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Soc())
}
