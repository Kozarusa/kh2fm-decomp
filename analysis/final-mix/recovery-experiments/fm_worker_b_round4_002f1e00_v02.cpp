#include "../common/types.h"

asm(".globl uRamffffe2e0\n\tuRamffffe2e0 = 0xffffe2e0\n");

extern "C" u32 uRamffffe2e0;
extern "C" void func_00305650(u32);

void func_002f1e00(void)
{
  func_00305650(uRamffffe2e0);
}
