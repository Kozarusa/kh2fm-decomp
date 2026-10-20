#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00138470(...);
extern "C" bool func_00263660(...);
extern "C" bool func_0028b1c0(...);
extern "C" s32 func_00168aa0(...);
extern "C" s32 func_002570a0(...);
extern "C" s32 func_00273180(...);
extern "C" s32 func_0027ae20(...);
extern "C" s32 func_002859a0(...);
extern "C" u32 func_00102818(...);
extern "C" u32 func_001039f8(...);
extern "C" u32 func_00103eb0(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_00106450(...);
extern "C" u32 func_001382e0(...);
extern "C" u32 func_001386e0(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00138c68(...);
extern "C" u32 func_00139570(...);
extern "C" u32 func_00139660(...);
extern "C" u32 func_00139688(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00167f18(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0017a798(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_001a17c8(...);
extern "C" u32 func_001a3888(...);
extern "C" u32 func_001a8110(...);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_00239870(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023aa18(...);
extern "C" u32 func_0023aa38(...);
extern "C" u32 func_0023aa98(...);
extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_002632d0(...);
extern "C" u32 func_002635d8(...);
extern "C" u32 func_00263ea8(...);
extern "C" u32 func_002657a8(...);
extern "C" u32 func_002666a8(...);
extern "C" u32 func_00266988(...);
extern "C" u32 func_0026d968(...);
extern "C" u32 func_0026e638(...);
extern "C" u32 func_0026e8a0(...);
extern "C" u32 func_0027e6e0(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287bd0(...);
extern "C" u32 func_00287da0(...);
extern "C" u32 func_00288be8(...);
extern "C" u32 func_00288f48(...);
extern "C" u32 func_00289b30(...);
extern "C" u32 func_0028b1b0(...);
extern "C" u32 func_0028be58(...);
extern "C" u32 func_0028d6e8(...);
extern "C" u32 func_0028da70(...);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_0028e4c8(...);
extern "C" u32 func_0028e510(...);
extern "C" u32 func_0028e560(...);
extern "C" u32 func_00290060(...);
extern "C" u32 func_00290580(...);
extern "C" u32 func_00290740(...);
extern "C" u32 func_00290a60(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_0031a260(...);
extern "C" u64 func_00138440(...);
extern "C" u64 func_001a3820(...);
extern "C" u64 func_00257140(...);
extern "C" u64 func_0028af18(...);
extern "C" u8 func_00287db0(...);

void func_002631b0(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_0028da70(iVar1 + 0xb350,0x133);
  return;
}

void func_0027b4e8(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_0028dac8(iVar1 + 0xb350,0x112);
  return;
}

void func_00285f50(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002859a0();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2);
  uVar4 = 1 << (param_1 & 0x1f);
  uVar1 = *puVar3;
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

bool func_00288088(void)

{
  int iVar1;
  
  iVar1 = func_00167f18(0);
  return *(s64 *)(iVar1 + 8) != 0;
}

void func_00288c58(int param_1,int param_2)

{
  u32 uVar1;
  
  uVar1 = func_00288be8(param_2 << 2);
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar1 = func_00288be8(param_2 << 3);
  *(u32 *)(param_1 + 0x2c) = uVar1;
  uVar1 = func_00288be8(param_2 << 3);
  *(u32 *)(param_1 + 0x30) = uVar1;
  return;
}

void func_0028eab8(int param_1,int param_2)

{
  u32 uVar1;
  
  uVar1 = func_0023aa18(param_2 + 0x18);
  *(u32 *)(param_1 + 0x24) = uVar1;
  uVar1 = func_0023aa38(param_2 + 0x18);
  *(u32 *)(param_1 + 0x28) = uVar1;
  return;
}
