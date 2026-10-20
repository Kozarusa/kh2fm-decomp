#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102080(...);
extern "C" u64 func_00102210(...);
extern "C" u64 func_001031b0(...);
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00105c30(...);
extern "C" u64 func_00106450(...);
extern "C" u64 func_0010c7b0(...);
extern "C" u64 func_0010c7e8(...);
extern "C" u64 func_0010fa28(...);
extern "C" u64 func_0010fa58(...);
extern "C" u64 func_00110500(...);
extern "C" u64 func_00110618(...);
extern "C" u64 func_00114438(...);
extern "C" u64 func_00117808(...);
extern "C" u64 func_00117aa8(...);
extern "C" u64 func_00118d10(...);
extern "C" u64 func_00119830(...);
extern "C" u64 func_00119e60(...);
extern "C" u64 func_0011a408(...);
extern "C" u64 func_0011a918(...);
extern "C" void func_0011a938(f32,f32,u64,s32);
extern "C" u64 func_0011cdf0(...);
extern "C" u64 func_00136158(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c568(...);
extern "C" u64 func_0016e920(...);
extern "C" u64 func_00176fb0(...);
extern "C" u64 func_00177008(...);
extern "C" u64 func_0017c030(...);
extern "C" u64 func_0017c430(...);
extern "C" u64 func_0017c4c8(...);
extern "C" u64 func_0017f488(...);
extern "C" u64 func_0017f5e0(...);
extern "C" u64 func_0017f5f8(...);
extern "C" u64 func_00180c88(...);
extern "C" u64 func_0018a008(...);
extern "C" u64 func_00190128(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_001906f0(...);
extern "C" u64 func_0019bc38(...);
extern "C" u64 func_001b2210(...);
extern "C" u64 func_001b8228(...);
extern "C" u64 func_001b8258(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_0023a918(...);
extern "C" u64 func_0023cc18(...);
extern "C" u64 func_002bc1e8(...);
extern "C" u64 func_002e7670(...);
extern "C" u64 func_002e76b0(...);
extern "C" u64 func_002e77a8(...);
extern "C" u64 func_002e95a0(...);
extern "C" u64 func_002e9610(...);
extern "C" u64 func_002e9cb8(...);
extern "C" u64 func_002e9d08(...);
extern "C" u64 func_002e9fe0(...);
extern "C" u64 func_002eac70(...);
extern "C" u64 func_002eaf40(...);
extern "C" u64 func_002eb990(...);
extern "C" u64 func_002ed300(...);
extern "C" u64 func_002ee730(...);
extern "C" u64 func_002ee840(...);
extern "C" u64 func_002ef618(...);
extern "C" u64 func_002ef7b8(...);
extern "C" u64 func_002efa98(...);
extern "C" u64 func_002efb08(...);
extern "C" u64 func_002f25a0(...);
extern "C" u64 func_002f3500(...);
extern "C" u64 func_002f3c28(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002f40a0(...);
extern "C" u64 func_002f4148(...);
extern "C" u64 func_002f41f0(...);
extern "C" u64 func_002ff014(...);
extern "C" u64 func_002ffbb0(...);
extern "C" u64 func_002ffd78(...);
extern "C" u64 func_003032d0(...);
extern "C" u64 func_00305110(...);
extern "C" u64 func_00305168(...);
extern "C" u64 func_00306e48(...);
extern "C" u64 func_00306e80(...);
extern "C" u64 func_003071d0(...);
extern "C" u64 func_003080d0(...);
extern "C" u64 func_00308780(...);
extern "C" u64 func_00308dc0(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_0030f468(...);
extern "C" u64 func_0030ffd8(...);
extern "C" u64 func_00310090(...);
extern "C" u64 func_00310180(...);
extern "C" u64 func_00310230(...);
extern "C" u64 func_00310330(...);
extern "C" u64 func_00316d08(...);

void func_002f10c0(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  register u64 object asm("$4");
  register s32 integer asm("$5");
  register f32 first asm("$f12");
  register f32 second asm("$f13");
  asm volatile("lw %1,4(%4); move %0,%5; lwc1 %3,12(%4); lwc1 %2,8(%4)"
      : "=r"(object), "=r"(integer), "=f"(first), "=f"(second)
      : "r"(param_1), "r"(uVar1) : "memory");
  func_0011a938(first,second,object,integer);
  return;
}
