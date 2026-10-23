#include "../common/types.h"

// Preserve original registry aliases.
void func_00174d98(u32 *param_1) asm("_ZN2YS14trap_camera_atEP8BD_VALUE");

extern "C" u32 func_00106a60(u32);
extern "C" void func_00107478(u32,u32);
extern "C" char func_01c5f480;

void func_00174d98(u32 *param_1)
{
  u32 uVar1;
  uVar1 = func_00106a60(1);
  func_00107478(uVar1, (u32)(long)&func_01c5f480);
  *param_1 = (u32)(long)&func_01c5f480;
  return;
}
