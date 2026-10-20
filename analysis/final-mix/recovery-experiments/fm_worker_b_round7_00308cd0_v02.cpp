#include "../common/types.h"

asm(".globl DAT_003660dc
	DAT_003660dc = 0x3660dc
");

extern "C" volatile u32 DAT_003660dc;
extern "C" void func_00308650();

void func_00308cd0(void)
{
  func_00308650();
  DAT_003660dc = 0;
}
