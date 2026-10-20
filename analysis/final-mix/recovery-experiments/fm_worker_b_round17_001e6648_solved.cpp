#include "../common/types.h"

asm(".globl DAT_001dae6b4
	DAT_001dae6b4 = 0x1dae6b4
");
asm(".globl DAT_001dae6b0
	DAT_001dae6b0 = 0x1dae6b0
");
extern "C" u32 DAT_001dae6b4;
extern "C" u8 DAT_001dae6b0;
extern "C" void func_001e65d0(void);
extern "C" void func_001e6630(void);
extern "C" void func_0021c9b0(void);

void func_001e6648(void)
{
  func_001e65d0();
  func_001e6630();
  func_0021c9b0();
  DAT_001dae6b4 = 0;
  DAT_001dae6b0 = 0;
  return;
}
