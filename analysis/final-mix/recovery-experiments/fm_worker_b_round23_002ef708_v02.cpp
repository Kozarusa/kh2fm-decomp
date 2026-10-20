#include "../common/types.h"

extern "C" void func_00103748(void);
extern "C" void func_00170c00(u32);
extern "C" void func_00103bb0(u32);
extern "C" u32 DAT_003638c4;
asm(".globl DAT_003638c4
	DAT_003638c4 = 0x3638c4
");
extern "C" volatile u8 DAT_003638c0;
asm(".globl DAT_003638c0
	DAT_003638c0 = 0x3638c0
");
extern "C" volatile u8 DAT_003638c8;
asm(".globl DAT_003638c8
	DAT_003638c8 = 0x3638c8
");

void func_002ef708(void)
{
  func_00103748();
  func_00170c00(DAT_003638c4);
  DAT_003638c4 = 0;
  func_00103bb0(-1);
  DAT_003638c0 = 0;
  asm volatile ("" ::: "memory");
  DAT_003638c8 = 0;
  return;
}
