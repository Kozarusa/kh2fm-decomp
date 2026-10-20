#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102818(...);
extern "C" u64 func_00102a38(...);
extern "C" u64 func_001039f8(...);
extern "C" u64 func_00103eb0(...);
extern "C" u64 func_001058e8(...);
extern "C" u64 func_00106450(...);
extern "C" u64 func_00138c10(...);
extern "C" u64 func_00138c68(...);
extern "C" u64 func_00138d48(...);
extern "C" u64 func_00139510(...);
extern "C" u64 func_00139570(...);
extern "C" u64 func_001395f8(...);
extern "C" u64 func_00139660(...);
extern "C" u64 func_00139688(...);
extern "C" u64 func_001396b0(...);
extern "C" u64 func_00139d78(...);
extern "C" u64 func_00167f18(...);
extern "C" u64 func_00170518(...);
extern "C" u64 func_001708f8(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00192048(...);
extern "C" u64 func_00192e50(...);
extern "C" u64 func_001a17c8(...);
extern "C" u64 func_001a3570(...);
extern "C" u64 func_001a80c8(...);
extern "C" u64 func_001a8190(...);
extern "C" u64 func_001d56c8(...);
extern "C" u64 func_00239870(...);
extern "C" u64 func_00239d30(...);
extern "C" u64 func_0023aa18(...);
extern "C" u64 func_0023aa38(...);
extern "C" u64 func_0023aa98(...);
extern "C" u64 func_0023fa08(...);
extern "C" u64 func_002537c8(...);
extern "C" u64 func_00253b30(...);
extern "C" u64 func_00257140(...);
extern "C" u64 func_002571e0(...);
extern "C" u64 func_00257388(...);
extern "C" u64 func_00257708(...);
extern "C" u64 func_00257770(...);
extern "C" u64 func_002657a8(...);
extern "C" u64 func_002666a8(...);
extern "C" u64 func_00266988(...);
extern "C" u64 func_0026b470(...);
extern "C" u64 func_0026b508(...);
extern "C" u64 func_0026b5a0(...);
extern "C" u64 func_0026bc10(...);
extern "C" u64 func_0026ceb0(...);
extern "C" u64 func_0026d968(...);
extern "C" u64 func_0026e638(...);
extern "C" u64 func_0026e8a0(...);
extern "C" u64 func_00273180(...);
extern "C" u64 func_002766d0(...);
extern "C" u64 func_00276c88(...);
extern "C" u64 func_0027ae20(...);
extern "C" u64 func_0027d008(...);
extern "C" u64 func_0027d540(...);
extern "C" u64 func_0027d5d8(...);
extern "C" u64 func_0027d810(...);
extern "C" u64 func_002800d0(...);
extern "C" u64 func_00280148(...);
extern "C" u64 func_00281f40(...);
extern "C" u64 func_00281f48(...);
extern "C" u64 func_00281f70(...);
extern "C" u64 func_00281f90(...);
extern "C" u64 func_00282858(...);
extern "C" u64 func_00282b00(...);
extern "C" u64 func_002859a0(...);
extern "C" u64 func_00287bc0(...);
extern "C" u64 func_00287bd0(...);
extern "C" u64 func_00287cc0(...);
extern "C" u64 func_00287db0(...);
extern "C" u64 func_00288be8(...);
extern "C" u64 func_00288f48(...);
extern "C" u64 func_00289b30(...);
extern "C" u64 func_0028af18(...);
extern "C" u64 func_0028b040(...);
extern "C" u64 func_0028b1b0(...);
extern "C" u64 func_0028b1c0(...);
extern "C" u64 func_0028be58(...);
extern "C" u64 func_0028da70(...);
extern "C" u64 func_0028dac8(...);
extern "C" u64 func_0028e4c8(...);
extern "C" u64 func_0028e510(...);
extern "C" u64 func_0028e560(...);
extern "C" u64 func_0028fb68(...);
extern "C" u64 func_00290060(...);
extern "C" u64 func_00290580(...);
extern "C" u64 func_00290960(...);
extern "C" u64 func_00290a60(...);
extern "C" u64 func_00294000(...);
extern "C" u64 func_002941a8(...);
extern "C" u64 func_002941d8(...);
extern "C" u64 func_00295158(...);
extern "C" u64 func_002a9d68(...);
extern "C" u64 func_002aa5b8(...);
extern "C" u64 func_002abf40(...);
extern "C" u64 func_002b64c8(...);
extern "C" u64 func_002b6708(...);
extern "C" u64 func_0031a260(...);

void func_002908a8(int param_1)

{
  register s32 iVar1 asm("$13");
  int iVar2;
  int iVar3;
  
  *(u32 *)(param_1 + 4) = 0;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 8) = 0;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar3 = *(int *)(param_1 + 0x14);
    while( true ) {
      iVar2 = iVar1 * 4;
      asm("addiu %0,%0,1" : "+r"(iVar1), "+r"(iVar2));
      *(u32 *)(iVar2 + iVar3) = 0;
      if (*(int *)(param_1 + 0xc) <= iVar1) break;
      iVar3 = *(int *)(param_1 + 0x14);
    }
  }
  return;
}
