#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00197920(...);
extern "C" bool func_001a6d08(...);
extern "C" bool func_002282f0(...);
extern "C" bool func_002424c0(...);
extern "C" s32 func_00168aa0(...);
extern "C" s32 func_001d56c8(...);
extern "C" s32 func_00227a28(...);
extern "C" s32 func_00227a60(...);
extern "C" s32 func_00236ca8(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_00103500(...);
extern "C" u32 func_00103550(...);
extern "C" u32 func_001037b8(...);
extern "C" u32 func_001039f8(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_001063f0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0014aa58(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_00168388(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001ba028(...);
extern "C" u32 func_00227870(...);
extern "C" u32 func_00227d10(...);
extern "C" u32 func_00227da8(...);
extern "C" u32 func_0023a0d8(...);
extern "C" u32 func_0023d410(...);
extern "C" u32 func_0023f0c8(...);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00240118(...);
extern "C" u32 func_00242088(...);
extern "C" u32 func_00242880(...);
extern "C" u32 func_00246868(...);
extern "C" u32 func_00250fb8(...);
extern "C" u32 func_002513b0(...);
extern "C" u32 func_00251780(...);
extern "C" u32 func_00252020(...);
extern "C" u32 func_00253180(...);
extern "C" u32 func_00253330(...);
extern "C" u32 func_00253578(...);
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(...);
extern "C" u32 func_002539e8(...);
extern "C" u32 func_00257000(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_00276c18(...);
extern "C" u32 func_0027dc08(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287cc0(...);
extern "C" u32 func_00287d68(...);
extern "C" u32 func_00288648(...);
extern "C" u32 func_0028da70(...);
extern "C" u32 func_002ba978(...);
extern "C" u32 func_002bd680(...);
extern "C" u32 func_002bd760(...);
extern "C" u32 func_002f2be0(...);
extern "C" u32 func_002f35e8(...);
extern "C" u32 func_002f3918(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_002ff2e8(...);
extern "C" u32 func_0031acc0(...);
extern "C" u32 func_0022e188(...);
extern "C" u32 func_00232498(...);
extern "C" u8 func_00103b38(...);
extern "C" u8 func_001a6598(...);
extern "C" u8 func_00253918(...);
extern "C" u8 func_00287db0(...);
extern "C" u8 func_002ef7b8(...);

void func_0023fa08(int param_1,u32 param_2)

{
  u32 uVar1;
  
  *(int *)(param_1 + 4) = (int)param_2;
  uVar1 = func_00168aa0(param_2,0x1c);
  *(u32 *)(param_1 + 8) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x1d);
  *(u32 *)(param_1 + 0x10) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x19);
  *(u32 *)(param_1 + 0xc) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x18);
  *(u32 *)(param_1 + 0x14) = uVar1;
  return;
}
