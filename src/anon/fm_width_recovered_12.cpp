#include "../common/types.h"

// Preserve original registry aliases.
void func_00262c40(void) asm("_ZN2Tz6CmItem11FadeOutWarnEv");
void func_00262fa0(void) asm("_ZN2Tz6CmItem12FadeOutStockEv");
void func_0028b0e0(u32 param_1) asm("_ZN2Tz6Select11Reset2DModeEv");
void func_0028dcc0(u32 param_1,u32 param_2) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");

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
extern "C" u32 func_00138440(...);
extern "C" u32 func_001a3820(...);
extern "C" u32 func_00257140(...);
extern "C" u32 func_0028af18(...);
extern "C" u8 func_00287db0(...);

void func_00262c40(void)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = func_00287bc0();
  uVar2 = func_00257770();
  if (iVar1 - 0xbU < 4) {
    func_0028dac8(uVar2,0x12a);
    func_0028dac8((int)uVar2 + 0xb350,0x133);
    return;
  }
  return;
}

void func_00262fa0(void)

{
  s32 lVar1;
  int iVar2;
  
  lVar1 = func_00287bc0();
  iVar2 = func_00257770();
  if (lVar1 == 0xc) {
    func_0028dac8(iVar2 + 0x198,0x12d);
    func_0027e6e0();
    return;
  }
  return;
}

u32 func_002637e8(s32 param_1)

{
  u32 uVar1;
  s32 lVar2;
  u32 uVar3;
  
  uVar1 = func_002570a0(10);
  if (param_1 == 0) {
    lVar2 = func_002635d8(uVar1);
    uVar3 = (u32)(lVar2 == 0);
  }
  else {
    uVar3 = 1;
  }
  if ((uVar3 == 1) && (lVar2 = func_00263660(uVar1), lVar2 == 0)) {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

void func_0028b0e0(u32 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u8 *)(iVar1 + 0x25) = 0;
  *(u8 *)(iVar1 + 0x26) = 0;
  *(u16 *)(iVar1 + 0x18) = 0;
  *(u16 *)(iVar1 + 0x1a) = 0;
  func_0028af18(param_1,0x73);
  func_0028b1b0(param_1,0);
  return;
}

void func_0028d660(u32 param_1,int param_2)

{
  int iVar1;
  
  func_0028d6e8();
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x18c) != param_2) {
    *(int *)(iVar1 + 0x18c) = param_2;
    *(u8 *)(iVar1 + 0x19d) = 1;
    func_001396b0(param_1);
    if (*(int *)(iVar1 + 0x18c) != 0) {
      *(u32 *)(iVar1 + 400) = 0;
      func_001396b0(param_1);
      if (*(int *)(iVar1 + 400) != 0) {
        func_0031a260(param_1,0);
        return;
      }
    }
  }
  return;
}

void func_0028dcc0(u32 param_1,u32 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x18c) = param_2;
  func_001396b0();
  if (*(int *)(iVar1 + 0x18c) != 0) {
    *(u32 *)(iVar1 + 400) = 0;
    func_001396b0(param_1);
    if (*(int *)(iVar1 + 400) != 0) {
      func_0031a260(param_1,0);
    }
  }
  func_00139660(param_1);
  func_00139688(param_1);
  func_001396b0(param_1);
  return;
}

void func_0028ff18(int *param_1)

{
  func_00290060();
  if ((s32)*(int *)(*param_1 + 0x184) != (s32)(short)param_1[3]) {
    func_00138c10(*param_1,(s32)(short)param_1[3]);
    *(u32 *)(*param_1 + 0x188) = 0xffffffff;
  }
  return;
}

void func_00290438(int *param_1)

{
  func_00290580();
  if ((s32)*(int *)(*param_1 + 0x184) != (s32)(short)param_1[3]) {
    func_00138c10(*param_1,(s32)(short)param_1[3]);
    *(u32 *)(*param_1 + 0x188) = 0xffffffff;
  }
  return;
}
