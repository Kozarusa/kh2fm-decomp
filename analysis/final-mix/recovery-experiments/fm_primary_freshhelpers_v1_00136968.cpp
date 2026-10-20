#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
extern "C" void func_001369d0(void);
extern "C" void func_001369f0(void);
extern "C" void func_00136a50(void);
extern "C" u32 D_00347d20;
extern "C" u16 D_003b8b22;
extern "C" u32 D_003b8b38;
extern "C" u16 D_003b8b20;
extern "C" u32 D_00347d24;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_00136968(void)

{
  func_001369d0();
  func_001369f0();
  D_00347d20 = 0xffffffff;
  D_003b8b22 = 0xffff;
  D_003b8b38 = 0xffffffff;
  D_003b8b20 = 0xffff;
  D_00347d24 = 0xffffffff;
  func_00136a50();
  return;
}

