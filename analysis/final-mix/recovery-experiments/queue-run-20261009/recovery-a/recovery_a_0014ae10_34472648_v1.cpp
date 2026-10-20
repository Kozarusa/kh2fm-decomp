#include "../common/types.h"
extern "C" u32 func_00102c18(...);
extern "C" u32 func_0014a988(...);
extern "C" u32 func_0014ad58(...);
extern "C" char D_003495c0;
extern "C" char D_003496d0;
extern "C" char D_003497e0;
extern "C" char D_003498f0;
extern "C" char D_00349a00;
extern "C" char D_003494b0;
extern "C" char func_0014ac48;
extern "C" char func_0014ac68;
extern "C" char func_0014ac90;
extern "C" char func_0014acb0;

void func_0014ae10(void)

{
  func_0014a988((s32)(long)&D_003495c0);
  func_0014a988((s32)(long)&D_003496d0);
  func_0014a988((s32)(long)&D_003497e0);
  func_0014a988((s32)(long)&D_003498f0);
  func_0014a988((s32)(long)&D_00349a00);
  func_0014a988((s32)(long)&D_003494b0);
  func_0014ad58();
  func_00102c18(0,80000,(s32)(long)&func_0014ac48);
  func_00102c18(0,80000,(s32)(long)&func_0014ac68);
  func_00102c18(0,0x19640,(s32)(long)&func_0014ac90);
  func_00102c18(0,0x19a28,(s32)(long)&func_0014acb0);
  return;
}
