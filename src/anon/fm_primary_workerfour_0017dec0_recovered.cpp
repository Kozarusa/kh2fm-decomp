#include "../common/types.h"

// Preserve original registry aliases.
void func_0017dec0(void) asm("_ZN2YS6FRIEND4InitEv");

asm(".globl DAT_01c60528\n\tDAT_01c60528 = 0x1c60528\n"
    ".globl DAT_01c6052c\n\tDAT_01c6052c = 0x1c6052c\n");

extern "C" u32 DAT_01c60528;
extern "C" u32 DAT_01c6052c;
extern "C" void func_001c9770(void);

void func_0017dec0(void)
{
  u32 *puVar1 = &DAT_01c60528;
  *puVar1 = 0;
  puVar1[1] = 0;
  func_001c9770();
}
