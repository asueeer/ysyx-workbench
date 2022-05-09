import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class HelloTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Hello"
  it should "pass" in {
    val util = new Util()
    test(new Soc) { c =>
      val addi_x1_10 = "b000000001010" + "00001" + "000" + "00001" + "0010011"
      val ebreak = "b000000000001" + "00000" + "000" + "00000" + "1110011"
      c.io.out_pc.expect("x80000000".U)
      c.io.in_inst.poke(addi_x1_10.U)
      c.clock.step(1)
      c.io.out_pc.expect("x80000004".U)
      c.io.out_regs(1).expect(10.U)

      c.io.in_inst.poke(addi_x1_10.U)
      c.clock.step(1)
      c.io.out_regs(1).expect(20.U)

      c.io.in_inst.poke(addi_x1_10.U)
      c.clock.step(1)
      c.io.out_regs(1).expect(30.U)

      c.io.in_inst.poke(ebreak.U)
      c.clock.step(1)
      c.io.out_ebreak.expect(true.B)
    }

    test(new TypeDecoder) { c =>
      c.io.in_opcode.poke("b0010011".U)
      c.io.out_type.expect(util.type_I)
    }

    test(new Sext) { c =>
      c.io.in_imm.poke(1.U)
      c.io.out_imm.expect(1.U)

      c.io.in_imm.poke("xf".U)
      c.io.in_len.poke(4.U)
      c.io.out_imm.expect("xffffffffffffffff".U)
    }

    test(new RegFile) { c =>
      c.io.wen.poke(true.B)
      c.io.in_dest.poke(1.U)
      c.io.in_src.poke(10.U)
      c.clock.step(1)
      c.io.out_regs(1).expect(10.U)
    }

    test(new IEU) { c =>
      c.io.in_rd.poke(1.U)
      c.io.in_imm.poke(10.U)
      c.io.in_rs1.poke(1.U)
      c.io.in_type.poke(util.type_I)
      c.io.in_opcode.poke(util.opcodes("addi"))
      c.clock.step(1)
      c.io.out_regs(1).expect(10.U)

      c.io.in_rd.poke(1.U)
      c.io.in_imm.poke(10.U)
      c.io.in_rs1.poke(1.U)
      c.io.in_type.poke(util.type_I)
      c.io.in_opcode.poke(util.opcodes("addi"))
      c.clock.step(1)
      c.io.out_regs(1).expect(20.U)
    }
  }
}
