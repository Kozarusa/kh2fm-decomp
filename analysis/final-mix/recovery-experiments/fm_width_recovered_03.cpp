#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001688b8(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001d35e0(...);
extern "C" f32 func_0016b558(...);
extern "C" s32 func_0016b740(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_00170240(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00188fe0(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_0016bba8(...);
extern "C" s32 func_00170400(...);
extern "C" u16 func_0016a070(...);
extern "C" u16 func_0016bff0(...);
extern "C" u32 func_00102c18(...);
extern "C" u32 func_00104f58(...);
extern "C" u32 func_0014d358(...);
extern "C" u32 func_00152508(...);
extern "C" u32 func_00167d68(...);
extern "C" u32 func_00167f18(...);
extern "C" u32 func_0016a020(...);
extern "C" u32 func_0016ace0(...);
extern "C" u32 func_0016adc8(...);
extern "C" u32 func_0016aeb8(...);
extern "C" u32 func_0016b010(...);
extern "C" u32 func_0016c018(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_00170c50(...);
extern "C" u32 func_00170e58(...);
extern "C" u32 func_00176db0(...);
extern "C" u32 func_00177998(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017d160(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_00180378(...);
extern "C" u32 func_001846a0(...);
extern "C" u32 func_00185278(...);
extern "C" u32 func_00186a90(...);
extern "C" u32 func_00188b68(...);
extern "C" u32 func_001891b8(...);
extern "C" u32 func_001945a0(...);
extern "C" u32 func_0019a1a0(...);
extern "C" u32 func_0019ae60(...);
extern "C" u32 func_0019fdc0(...);
extern "C" u32 func_001a0710(...);
extern "C" u32 func_001a55a8(...);
extern "C" u32 func_001a7588(...);
extern "C" u32 func_001b0700(...);
extern "C" u32 func_001b0798(...);
extern "C" u32 func_001b2210(...);
extern "C" u32 func_001b6dd0(...);
extern "C" u32 func_001ce300(...);
extern "C" u32 func_001ce328(...);
extern "C" u32 func_001cfac0(...);
extern "C" u32 func_001dc648(...);
extern "C" u32 func_001dc670(...);
extern "C" u32 func_002ba200(...);
extern "C" u32 func_002f8ad0(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_0016bda8(...);
extern "C" u32 func_0017d050(...);
extern "C" u32 func_0017d0e8(...);
extern "C" u32 func_0019b0e8(...);
extern "C" u8 func_0016a040(...);
extern "C" u8 func_001c3618(...);

void func_0016bc20(u32 param_1,u32 param_2,u32 param_3)

{
  s32 lVar1;
  
  lVar1 = 0;
  while( true ) {
    lVar1 = func_0016bba8(param_1,param_2,lVar1);
    if (lVar1 == 0) {
      return;
    }
    if (param_3 == 0xffffffff) break;
    if (*(u8 *)lVar1 == param_3) {
      return;
    }
  }
  return;
}
