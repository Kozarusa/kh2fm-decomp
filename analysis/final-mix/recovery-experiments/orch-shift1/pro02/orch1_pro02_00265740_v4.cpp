#include "../common/types.h"
extern "C" s32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265740() {
  s32 got=func_00257770();
  // why: keeps the helper result live in v0 so the argument copy uses v0 like the original
  u32 object=(u32)got;
  func_00139d78((u32)got);
  return *(s32*)(object+0x184)==141; }