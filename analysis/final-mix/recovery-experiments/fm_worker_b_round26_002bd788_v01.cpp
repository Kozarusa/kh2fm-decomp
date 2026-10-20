#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_003617ec;
asm(".globl DAT_003617ec
	DAT_003617ec = 0x3617ec
");
extern "C" volatile u32 DAT_003617f4;
asm(".globl DAT_003617f4
	DAT_003617f4 = 0x3617f4
");
extern "C" volatile u32 DAT_003617f8;
asm(".globl DAT_003617f8
	DAT_003617f8 = 0x3617f8
");
extern "C" volatile u32 DAT_0032b924;
asm(".globl DAT_0032b924
	DAT_0032b924 = 0x32b924
");
extern "C" void func_002b871c(void);
extern "C" u32 func_00102788(u32,u32,u32,u32);

void func_002bd788(u32 param_1)
{
  u32 uVar1;
  DAT_003617ec = param_1;
  func_002b871c();
  DAT_003617f8 = 0;
  uVar1 = func_00102788(DAT_0032b924, 0, 0xcc65, 0x2bd870);
  DAT_003617f4 = uVar1;
  return;
}
