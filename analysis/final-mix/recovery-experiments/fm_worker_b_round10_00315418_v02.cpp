#include "../common/types.h"


typedef void (*code)(void);

extern "C" void func_002fd160(...);

void func_00315418(code param_1)
{
  u32 iVar1;
  (*param_1)();
  iVar1 = 0;
  asm volatile ("");
  while (iVar1 == 0) {
    func_003166f0();
  }
  func_002fd160();
}
