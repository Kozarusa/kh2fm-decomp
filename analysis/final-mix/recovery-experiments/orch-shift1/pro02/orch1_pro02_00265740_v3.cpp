#include "../common/types.h"
extern "C" s32 func_00257770(void);
extern "C" void func_00139d78(u32);
bool func_00265740() {
  u32 object=func_00257770();
  // why: ties the saved register-16 lifetime to the helper result without emitting code
  asm volatile("" : "+r"(object));
  func_00139d78(object); return *(s32*)(object+0x184)==141; }