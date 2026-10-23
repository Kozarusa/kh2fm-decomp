#include "../common/types.h"

/* 00160ac0 - v01
 * lui t7,0x4f ; lw a0,0x3b30(t7) => 0x4f3b30 exactly, no page ambiguity.
 * The vtable entry is an address, so the assembler %hi rounding applies:
 * 0x160a90 + 0x8000 >> 16 == 0x16, which is what the target emits. */

extern "C" u32 func_00102788(u32, u32, u32, u32);
extern "C" u32 D_004f3b30;
extern "C" char func_00160a90;
extern "C" char func_001609e0;

void func_00160ac0(u32 param_1, u32 param_2)
{
  u32 iVar1 = func_00102788(D_004f3b30, 0, param_2, (u32)(long)&func_001609e0);
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 48) = (u32)(long)&func_00160a90;
  return;
}
