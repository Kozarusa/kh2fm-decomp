#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001917c0(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_0019c898(...);
extern "C" bool func_0019d4a8(...);
extern "C" bool func_001a2478(...);
extern "C" bool func_001a9758(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001d35e0(...);
extern "C" bool func_00239d10(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_0019f7d0(...);
extern "C" u16 func_0016a070(...);
extern "C" u16 func_0016bff0(...);
extern "C" u16 func_001a3958(...);
extern "C" u16 func_001a67b0(...);
extern "C" u32 func_00102c18(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00138190(...);
extern "C" u32 func_0013dad0(...);
extern "C" u32 func_00154b40(...);
extern "C" u32 func_0015a638(...);
extern "C" u32 func_0016a0a0(...);
extern "C" u32 func_0016cbc8(...);
extern "C" u32 func_00170e58(...);
extern "C" u32 func_00177998(...);
extern "C" u32 func_00181858(...);
extern "C" u32 func_00185118(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_001902a8(...);
extern "C" u32 func_00190878(...);
extern "C" u32 func_00192f78(...);
extern "C" u32 func_001956d0(...);
extern "C" u32 func_00195700(...);
extern "C" u32 func_0019c6f0(...);
extern "C" u32 func_0019cbe8(...);
extern "C" u32 func_0019d228(...);
extern "C" u32 func_0019d480(...);
extern "C" u32 func_0019da68(...);
extern "C" u32 func_0019e848(...);
extern "C" u32 func_0019ec88(...);
extern "C" u32 func_0019ed48(...);
extern "C" u32 func_001a0e78(...);
extern "C" u32 func_001a1db8(...);
extern "C" u32 func_001a4df0(...);
extern "C" u32 func_001a7a48(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a84b0(...);
extern "C" u32 func_001a9218(...);
extern "C" u32 func_001a9350(...);
extern "C" u32 func_001ab260(...);
extern "C" u32 func_001abb78(...);
extern "C" u32 func_001abbf0(...);
extern "C" u32 func_001ac728(...);
extern "C" u32 func_001acdc0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u32 func_001bc688(...);
extern "C" u32 func_001c0150(...);
extern "C" u32 func_001c70e8(...);
extern "C" u32 func_001c8ab0(...);
extern "C" u32 func_001c9db0(...);
extern "C" u32 func_001d22a8(...);
extern "C" u32 func_001d45a0(...);
extern "C" u32 func_001d5af8(...);
extern "C" u32 func_001d96c0(...);
extern "C" u32 func_001db5a8(...);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023acd8(...);
extern "C" u32 func_0023ade0(...);
extern "C" u32 func_002ba2e8(...);
extern "C" u32 func_002c0688(...);
extern "C" u32 func_00143928(...);
extern "C" u32 func_0016e920(...);
extern "C" u32 func_001a0ee0(...);
extern "C" u32 func_001a7da8(...);
extern "C" u32 func_001ab750(...);
extern "C" u8 func_001a8bf8(...);

void func_0019cc20(u32 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  if (*piVar1 != 0) {
    func_0019d228();
    func_0019cbe8(param_1);
    if (*piVar1 == 2) {
      func_0019d480(param_1);
    }
    *piVar1 = 0;
    func_00190128(piVar1 + 1);
    return;
  }
  return;
}
