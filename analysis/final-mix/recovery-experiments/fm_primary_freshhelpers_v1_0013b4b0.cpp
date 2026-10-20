#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
extern "C" void func_00139858(s32);
extern "C" void func_00139ab0(s32);
extern "C" u32 D_003484a0;

void func_0013b4b0(void)

{
  if ((D_003484a0 != 0) && (*(char *)(D_003484a0 + 0x2a8) != '\0')) {
    func_00139858(2);
    func_00139858(1);
    func_00139ab0(2);
    func_00139ab0(1);
    return;
  }
  return;
}

