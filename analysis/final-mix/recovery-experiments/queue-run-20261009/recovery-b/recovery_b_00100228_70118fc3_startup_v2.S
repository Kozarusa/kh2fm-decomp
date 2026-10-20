.section .text._Z13func_00100228v,"ax",@progbits
.align 2
.global _Z13func_00100228v
.type _Z13func_00100228v,@function
.set noreorder
_Z13func_00100228v:
.Lclear_align:
  andi $4,$2,15
  beq $4,$0,.Lclear_bulk_init
  nop
  sb $0,0($2)
  addiu $2,$2,1
  nop
  j .Lclear_align
  nop
.Lclear_bulk_init:
  lui $4,0xffff
  ori $4,$4,0xfff0
  and $4,$3,$4
.Lclear_bulk:
  beq $2,$4,.Lclear_tail
  nop
  sq $0,0($2)
  addiu $2,$2,16
  nop
  nop
  j .Lclear_bulk
  nop
.Lclear_tail:
  beq $2,$3,.Lclear_done
  nop
  sb $0,0($2)
  addiu $2,$2,1
  nop
  nop
  j .Lclear_tail
  nop
.Lclear_done:
  jr $31
  nop
.size _Z13func_00100228v,.-_Z13func_00100228v
.set reorder
