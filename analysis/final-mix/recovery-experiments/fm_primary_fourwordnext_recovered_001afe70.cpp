#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001b58a8(...);
extern "C" bool func_001bb4a0(...);
extern "C" bool func_001bd590(...);
extern "C" bool func_001bd918(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001c8db8(...);
extern "C" bool func_001d1ca8(...);
extern "C" bool func_001d1f08(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001a8bd0(...);
extern "C" s32 func_001affe0(...);
extern "C" s32 func_001b8420(...);
extern "C" s32 func_001bc780(...);
extern "C" s32 func_001bd418(...);
extern "C" s32 func_001bd570(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u16 func_001a36e0(...);
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00105110(...);
extern "C" u32 func_00165768(...);
extern "C" u32 func_0016bc20(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016f7d0(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_001819c0(...);
extern "C" u32 func_001a17c8(...);
extern "C" u32 func_001a1910(...);
extern "C" u32 func_001a1a50(...);
extern "C" u32 func_001a1cc0(...);
extern "C" u32 func_001a34e0(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a8110(...);
extern "C" u32 func_001abba8(...);
extern "C" u32 func_001ac310(...);
extern "C" u32 func_001ac7c8(...);
extern "C" u32 func_001acdc0(...);
extern "C" u32 func_001ad0f8(...);
extern "C" u32 func_001afee8(...);
extern "C" u32 func_001aff90(...);
extern "C" u32 func_001b1be0(...);
extern "C" u32 func_001b6dd0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u32 func_001ba598(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001bc720(...);
extern "C" u32 func_001bc778(...);
extern "C" u32 func_001bc990(...);
extern "C" u32 func_001bd370(...);
extern "C" u32 func_001bd3a0(...);
extern "C" u32 func_001bd668(...);
extern "C" u32 func_001bdf68(...);
extern "C" u32 func_001bdff0(...);
extern "C" u32 func_001c9df8(...);
extern "C" u32 func_001d1d68(...);
extern "C" u32 func_001d20a8(...);
extern "C" u32 func_001d2180(...);
extern "C" u32 func_001d48b0(...);
extern "C" u32 func_001d4fa8(...);
extern "C" u32 func_001d5370(...);
extern "C" u32 func_001d6da8(...);
extern "C" u32 func_001db610(...);
extern "C" u32 func_001db710(...);
extern "C" u32 func_001db7d0(...);
extern "C" u32 func_001dc920(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023acd8(...);
extern "C" u32 func_0023ade0(...);
extern "C" u32 func_002534e0(...);
extern "C" u32 func_002ba2e8(...);
extern "C" u32 func_003201e8(...);
extern "C" u32 func_003204c8(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_001a8bf8(...);

u32 func_001afe70(u32 param_1,u32 param_2,u32 param_3,u32 *param_4)

{
  s32 lVar1;
  register u32 object asm("$16") = param_1;
  register u32 value asm("$17") = param_3;
  u32 uVar2;
  
  lVar1 = func_001aff90();
  asm volatile("" : : "r"(object), "r"(value));
  if (lVar1 != 0) {
    *param_4 = (u32)*(u8 *)((int)lVar1 + 2);
    uVar2 = func_001affe0(lVar1,object,value);
    return uVar2;
  }
  return 0xffffffffffffffff;
}
