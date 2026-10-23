#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00143fc8(...);
extern "C" u64 func_0014f688(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016ed50(...);
extern "C" u64 func_00176cd0(...);
extern "C" u64 func_00178280(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00190920(...);
extern "C" u64 func_00198450(...);
extern "C" u64 func_00198970(...);
extern "C" u64 func_0019aa00(...);
extern "C" u64 func_0019cc20(...);
extern "C" u64 func_001a3188(...);
extern "C" u64 func_001a3570(...);
extern "C" u64 func_001a35f8(...);
extern "C" u64 func_001a6d08(...);
extern "C" u64 func_001ada38(...);
extern "C" u64 func_001b40e0(...);
extern "C" u64 func_001b8958(...);
extern "C" u64 func_001ba158(...);
extern "C" u64 func_001bb4a0(...);
extern "C" u64 func_001bb4b0(...);
extern "C" u64 func_001bbcb0(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_001d16f8(...);
extern "C" u64 func_001d1950(...);
extern "C" u64 func_001d2110(...);
extern "C" u64 func_001d2248(...);
extern "C" u64 func_001d2710(...);
extern "C" u64 func_001d3350(...);
extern "C" u64 func_001d3388(...);
extern "C" u64 func_001d4f40(...);
extern "C" u64 func_001d5f30(...);
extern "C" u64 func_001d6cc8(...);
extern "C" u64 func_001d7b10(...);
extern "C" u64 func_001d8718(...);
extern "C" u64 func_001da3d8(...);
extern "C" u64 func_001db200(...);
extern "C" u64 func_001db250(...);
extern "C" u64 func_001db950(...);
extern "C" u64 func_001dba18(...);
extern "C" u64 func_001dc700(...);
extern "C" u64 func_001dc738(...);
extern "C" u64 func_001dc840(...);
extern "C" u64 func_001dc978(...);
extern "C" u64 func_001dc9e0(...);
extern "C" u64 func_001dca20(...);
extern "C" u64 func_001dde40(...);
extern "C" u64 func_001ddef0(...);
extern "C" u64 func_001e0058(...);
extern "C" u64 func_001e0158(...);
extern "C" u64 func_001e01b8(...);
extern "C" u64 func_001e03b0(...);
extern "C" u64 func_001e0cc8(...);
extern "C" u64 func_001e0ce8(...);
extern "C" u64 func_001e1728(...);
extern "C" u64 func_001e17b8(...);
extern "C" u64 func_001e1988(...);
extern "C" u64 func_001e2c00(...);
extern "C" u64 func_001e2c78(...);
extern "C" u64 func_001e3468(...);
extern "C" u64 func_001e3650(...);
extern "C" u64 func_001e3660(...);
extern "C" u64 func_001e38f8(...);
extern "C" u64 func_001e3a88(...);
extern "C" u64 func_001e3c98(...);
extern "C" u64 func_001e3e48(...);
extern "C" u64 func_001e4028(...);
extern "C" u64 func_001e4248(...);
extern "C" u64 func_001e4320(...);
extern "C" u64 func_001e4e18(...);
extern "C" u64 func_001e6000(...);
extern "C" u64 func_001e6c00(...);
extern "C" u64 func_001e6cd8(...);
extern "C" u64 func_001e6ce8(...);
extern "C" u64 func_001e6cf8(...);
extern "C" u64 func_001e6d08(...);
extern "C" u64 func_001e7070(...);
extern "C" u64 func_001e7088(...);
extern "C" u64 func_001fa950(...);
extern "C" u64 func_001fab48(...);
extern "C" u64 func_001facf8(...);
extern "C" u64 func_00209178(...);
extern "C" u64 func_0020e2e8(...);
extern "C" u64 func_0021fa10(...);
extern "C" u64 func_0021fbc0(...);
extern "C" u64 func_0021fe28(...);
extern "C" u64 func_00220070(...);
extern "C" u64 func_002223e0(...);
extern "C" u64 func_002bea60(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002fd348(...);
extern "C" u64 func_002fe0a0(...);
extern "C" u64 func_00321728(...);
extern "C" u64 func_00321cb0(...);
extern "C" u64 func_00321ce8(...);

void func_001e0958(int param_1)

{
  int iVar1;
  register int iVar2 asm("$15");
  
  iVar1 = 0;
  do {
    iVar2 = 0;
    asm volatile("" : "+r"(iVar2));
    do {
      iVar2 = iVar2 + 1;
      *(char *)(param_1 + 0x18) = (char)iVar1;
      *(char *)(param_1 + 0x19) = (char)iVar2;
      param_1 = param_1 + 0x40;
    } while (iVar2 < 3);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}
