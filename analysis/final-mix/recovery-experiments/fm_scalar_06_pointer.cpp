#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_001024a8(...);
extern "C" u64 func_00102818(...);
extern "C" u64 func_00102c18(...);
extern "C" u64 func_00103500(...);
extern "C" u64 func_00103550(...);
extern "C" u64 func_001037b8(...);
extern "C" u64 func_001039f8(...);
extern "C" u64 func_00103b38(...);
extern "C" u64 func_00103eb0(...);
extern "C" u64 func_001058e8(...);
extern "C" u64 func_001063f0(...);
extern "C" u64 func_001382e0(...);
extern "C" u64 func_00138440(...);
extern "C" u64 func_00138470(...);
extern "C" u64 func_001390f0(...);
extern "C" u64 func_001391a8(...);
extern "C" u64 func_00139d78(...);
extern "C" u64 func_0014aa58(...);
extern "C" u64 func_0014aba8(...);
extern "C" u64 func_0014abd8(...);
extern "C" u64 func_0015c958(...);
extern "C" u64 func_001671e8(...);
extern "C" u64 func_00167218(...);
extern "C" u64 func_00168388(...);
extern "C" u64 func_00168aa0(...);
extern "C" u64 func_0016ed50(...);
extern "C" u64 func_00170518(...);
extern "C" u64 func_0017a798(...);
extern "C" u64 func_00192048(...);
extern "C" u64 func_00197920(...);
extern "C" u64 func_001a3888(...);
extern "C" u64 func_001a6d08(...);
extern "C" u64 func_001ba028(...);
extern "C" u64 func_001d56c8(...);
extern "C" u64 func_001de4b0(...);
extern "C" u64 func_001de750(...);
extern "C" u64 func_002247e8(...);
extern "C" u64 func_002248f8(...);
extern "C" u64 func_002249b8(...);
extern "C" u64 func_002251c8(...);
extern "C" u64 func_00226030(...);
extern "C" u64 func_00226e60(...);
extern "C" u64 func_00227870(...);
extern "C" u64 func_00227a60(...);
extern "C" u64 func_00227ca8(...);
extern "C" u64 func_00227d10(...);
extern "C" u64 func_00227da8(...);
extern "C" u64 func_002282f0(...);
extern "C" u64 func_00229b28(...);
extern "C" u64 func_0022ac60(...);
extern "C" u64 func_0022b688(...);
extern "C" u64 func_0022c4b8(...);
extern "C" u64 func_00232498(...);
extern "C" u64 func_002340f0(...);
extern "C" u64 func_00234188(...);
extern "C" u64 func_00234348(...);
extern "C" u64 func_00234400(...);
extern "C" u64 func_00234460(...);
extern "C" u64 func_002344c0(...);
extern "C" u64 func_00236ca8(...);
extern "C" u64 func_0023a0d8(...);
extern "C" u64 func_0023c598(...);
extern "C" u64 func_0023c728(...);
extern "C" u64 func_0023d410(...);
extern "C" u64 func_0023f0c8(...);
extern "C" u64 func_0023fad0(...);
extern "C" u64 func_00240be0(...);
extern "C" u64 func_00242088(...);
extern "C" u64 func_002424c0(...);
extern "C" u64 func_00242880(...);
extern "C" u64 func_00246868(...);
extern "C" u64 func_00253180(...);
extern "C" u64 func_00253330(...);
extern "C" u64 func_00253578(...);
extern "C" u64 func_002538f8(...);
extern "C" u64 func_00253918(...);
extern "C" u64 func_00253928(...);
extern "C" u64 func_002539e8(...);
extern "C" u64 func_00257000(...);
extern "C" u64 func_002570a0(...);
extern "C" u64 func_00257770(...);
extern "C" u64 func_00258d40(...);
extern "C" u64 func_00258d58(...);
extern "C" u64 func_00259460(...);
extern "C" u64 func_002595b8(...);
extern "C" u64 func_002632d0(...);
extern "C" u64 func_002635d8(...);
extern "C" u64 func_00263660(...);
extern "C" u64 func_00263a90(...);
extern "C" u64 func_00263ea8(...);
extern "C" u64 func_0026d808(...);
extern "C" u64 func_00276c18(...);
extern "C" u64 func_0027dc08(...);
extern "C" u64 func_0027e6e0(...);
extern "C" u64 func_00287bc0(...);
extern "C" u64 func_00287cc0(...);
extern "C" u64 func_00287da0(...);
extern "C" u64 func_00287db0(...);
extern "C" u64 func_00288648(...);
extern "C" u64 func_0028da70(...);
extern "C" u64 func_0028dac8(...);
extern "C" u64 func_0028f4d8(...);
extern "C" u64 func_002b4b00(...);
extern "C" u64 func_002ba978(...);
extern "C" u64 func_002bd680(...);
extern "C" u64 func_002bd760(...);
extern "C" u64 func_002ef7a0(...);
extern "C" u64 func_002ef7b8(...);
extern "C" u64 func_002ef938(...);
extern "C" u64 func_002f1670(...);
extern "C" u64 func_002f2be0(...);
extern "C" u64 func_002f35e8(...);
extern "C" u64 func_002f3918(...);
extern "C" u64 func_002fde18(...);
extern "C" u64 func_002ff2e8(...);
extern "C" u64 func_0031acc0(...);

void func_0023c6f8(u8* param_1)

{
  func_0023c728();
  *(u32 *)((int)param_1 + 0x38) = 1;
  func_0023c598(param_1);
  return;
}

void func_0023f070(u8* param_1,u32 param_2,u64 param_3)

{
  func_00139d78();
  *(u32 *)((int)param_1 + 0x98) = param_2;
  *(u32 *)((int)param_1 + 0x8c) = param_2;
  func_0023f0c8(param_1,param_3);
  return;
}
