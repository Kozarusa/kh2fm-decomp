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

void func_00242880(void)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u16 *)(iVar1 + 0x41a0) = 0;
  *(u16 *)(iVar1 + 0x41a2) = 0;
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffff809 | 0x40b;
  func_002fde18(0x35ecd8,0,4);
  return;
}

void func_00262c40(void)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = func_00287bc0();
  uVar2 = func_00257770();
  if (iVar1 - 0xbU < 4) {
    func_0028dac8(uVar2,0x12a);
    func_0028dac8((int)uVar2 + 0xb350,0x133);
    return;
  }
  return;
}

void func_00262f58(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_0028da70(uVar1,0x129);
  func_0028da70((int)uVar1 + 0xb350,0x132);
  return;
}

void func_00262fa0(void)

{
  s64 lVar1;
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

void func_00263188(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_0028da70(iVar1 + 0x198,300);
  return;
}

void func_002631b0(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_0028da70(iVar1 + 0xb350,0x133);
  return;
}

void func_00263688(void)

{
  u16 *puVar1;
  
  puVar1 = (u16 *)func_002632d0();
  func_001a3888(*puVar1);
  return;
}

u32 func_002637e8(s64 param_1)

{
  u64 uVar1;
  s64 lVar2;
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

void func_00263d70(void)

{
  int iVar1;
  
  iVar1 = func_00103eb0();
  func_00102818(*(u32 *)(iVar1 + 4),0,2000,0x263db0,0x1000);
  return;
}

u32 func_00263e18(void)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_00138470();
  if ((lVar2 == 0) && (lVar2 = func_00138440(), lVar2 == 0)) {
    func_001382e0();
  }
  lVar2 = func_00287db0();
  if (lVar2 == 0) {
    lVar2 = func_00138470();
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      func_0017a798();
      func_00287da0();
      uVar1 = 0;
    }
  }
  else {
    func_001039f8();
    uVar1 = 1;
  }
  return uVar1;
}

int func_00264328(u64 param_1)

{
  u16 uVar1;
  int iVar2;
  u16 *puVar3;
  int iVar4;
  
  iVar2 = func_00263ea8();
  puVar3 = (u16 *)(iVar2 + *(int *)(iVar2 + 0xc));
  uVar1 = *puVar3;
  iVar2 = 0;
  while ((puVar3 = puVar3 + 1, uVar1 != param_1 && (iVar4 = iVar2 + 1, iVar2 = -1, iVar4 < 0x80))) {
    uVar1 = *puVar3;
    iVar2 = iVar4;
  }
  return iVar2;
}

bool func_00265740(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  return *(int *)((int)uVar1 + 0x184) == 0x8d;
}

bool func_00265c10(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  return *(int *)((int)uVar1 + 0x184) == 0x141;
}

void func_00266678(u64 param_1,s64 param_2)

{
  if (param_2 == 0x17) {
    func_002657a8();
  }
  func_00266988();
  func_002666a8();
  return;
}

void func_0026dcb8(void)

{
  int iVar1;
  
  func_0026d968();
  func_00287bd0(0,0);
  iVar1 = func_00103eb0();
  func_00102818(*(u32 *)(iVar1 + 4),0,2000,0x26dd40,0x1000);
  return;
}

u32 func_0026e5b8(u64 param_1)

{
  u32 uVar1;
  s64 lVar2;
  s64 lVar3;
  
  lVar2 = func_00287bc0();
  lVar3 = func_00287db0();
  if (lVar3 == 0) {
    if (lVar2 == 0) {
      func_0026e638(param_1);
      uVar1 = 0;
    }
    else if (lVar2 == 1) {
      func_0026e8a0();
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    func_001039f8();
    uVar1 = 1;
  }
  return uVar1;
}

void func_0026ec70(void)

{
  u64 uVar1;
  
  uVar1 = func_002537c8(0);
  func_0023fa08(0x35f3a8,uVar1);
  return;
}

u16 func_00271870(s64 param_1)

{
  u16 uVar1;
  s64 lVar2;
  u16 *puVar3;
  s64 lVar4;
  
  uVar1 = 0;
  lVar4 = 0;
  if (param_1 != 0) {
    do {
      lVar4 = func_001a8110(lVar4);
      if (lVar4 == 0) {
        return 0;
      }
      puVar3 = (u16 *)lVar4;
    } while (((*(char *)(puVar3 + 1) != '\x12') && (*(char *)(puVar3 + 1) != '\0')) ||
            (lVar2 = func_001a3820(*puVar3), lVar2 != param_1));
    uVar1 = *puVar3;
  }
  return uVar1;
}

void func_00272a00(void)

{
  u64 uVar1;
  int iVar2;
  u16 *puVar3;
  u32 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = func_00257770();
  iVar2 = iVar2 + 0x60a4;
  do {
    uVar1 = func_00257140(0);
    func_00138c10(iVar2,uVar1);
    puVar3 = (u16 *)func_00273180(3,iVar5);
    iVar5 = iVar5 + 1;
    uVar4 = func_00192048(*puVar3);
    *(u32 *)(iVar2 + 0x198) = uVar4;
    iVar2 = iVar2 + 0x1b4;
  } while (iVar5 < 6);
  return;
}

void func_00272a70(void)

{
  u64 uVar1;
  int iVar2;
  u16 *puVar3;
  u32 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = func_00257770();
  iVar2 = iVar2 + 0x60a4;
  do {
    uVar1 = func_00257140(0);
    func_00138c10(iVar2,uVar1);
    puVar3 = (u16 *)func_00273180(4,iVar5);
    iVar5 = iVar5 + 1;
    uVar4 = func_00192048(*puVar3);
    *(u32 *)(iVar2 + 0x198) = uVar4;
    iVar2 = iVar2 + 0x1b4;
  } while (iVar5 < 3);
  return;
}

void func_00276410(void)

{
  u64 uVar1;
  
  uVar1 = func_002537c8(3);
  func_0023fa08(0x35f3a8,uVar1);
  return;
}

void func_0027aed8(int param_1,u32 *param_2,int *param_3)

{
  s64 lVar1;
  int iVar2;
  
  if (param_1 == 0) {
    *param_2 = 0;
    *param_3 = 0;
  }
  else {
    lVar1 = func_0027ae20();
    iVar2 = param_1 - (int)lVar1;
    if ((lVar1 == 0) || ((int)lVar1 + 1 <= param_1)) {
      *param_2 = 0;
    }
    else {
      iVar2 = param_1 + -1;
      *param_2 = 1;
    }
    *param_3 = iVar2;
  }
  return;
}

void func_0027b4e8(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_0028dac8(iVar1 + 0xb350,0x112);
  return;
}

void func_0027d450(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  func_0028da70(uVar1,0xea);
  return;
}

void func_002806c8(void)

{
  u64 uVar1;
  
  uVar1 = func_002537c8(5);
  func_0023fa08(0x35f3a8,uVar1);
  return;
}

void func_00281008(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 0x14);
  iVar3 = 3;
  iVar1 = *piVar2;
  while( true ) {
    piVar2 = piVar2 + 5;
    if (iVar1 != 0) {
      func_001a17c8(iVar1);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar1 = *piVar2;
  }
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

void func_002865d0(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002859a0();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0xcc);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_00287430(int param_1,int param_2)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar1 = func_002859a0();
  if (param_1 == 7) {
    param_1 = 6;
  }
  uVar4 = (param_1 + -1) * 0x30 + param_2;
  puVar2 = (u32 *)((uVar4 >> 5) * 4 + iVar1 + 0xa4);
  uVar3 = 1 << (uVar4 & 0x1f);
  uVar4 = *puVar2;
  if ((uVar4 & uVar3) == 0) {
    *puVar2 = uVar4 | uVar3;
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

void func_00288e08(int param_1,int param_2,s64 param_3,s64 param_4)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  
  iVar1 = *(int *)(param_2 * 4 + *(int *)(param_1 + 0x28));
  lVar3 = func_0023aa98(iVar1 + 0x18);
  iVar2 = (int)lVar3;
  if (param_4 == -1) {
    param_4 = lVar3;
  }
  if (param_3 != -1) {
    iVar2 = (int)param_3;
  }
  func_00138c68(iVar1,iVar2 * param_2,(int)param_4 * param_2);
  return;
}

void func_0028a908(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  sVar1 = *(short *)(param_1 + 4);
  if (0 < sVar1) {
    iVar3 = *(int *)(param_1 + 0x28);
    while( true ) {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      iVar3 = *(int *)(iVar2 + iVar3);
      if (iVar3 != 0) {
        func_00139570(iVar3);
        sVar1 = *(short *)(param_1 + 4);
      }
      if (sVar1 <= iVar4) break;
      iVar3 = *(int *)(param_1 + 0x28);
    }
  }
  return;
}

void func_0028afd0(u64 param_1,short param_2)

{
  s64 lVar1;
  short *psVar2;
  
  psVar2 = (short *)param_1;
  psVar2[9] = param_2;
  if (*(char *)((int)psVar2 + 0x25) == '\0') {
    lVar1 = func_0028b1c0(param_1,(int)param_2 + (int)*psVar2);
    if (lVar1 != 0) {
      func_00289b30(param_1,param_1,psVar2 + 9);
      return;
    }
  }
  return;
}

void func_0028b078(u64 param_1,u16 param_2,u16 param_3)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u8 *)(iVar1 + 0x26) = 0;
  *(u16 *)(iVar1 + 0x18) = param_2;
  *(u8 *)(iVar1 + 0x25) = 1;
  *(u16 *)(iVar1 + 0x1a) = param_3;
  func_00288f48(param_1,0x10,0x20,0x40,0x80);
  func_0028af18(param_1,0x7f);
  func_0028b1b0(param_1,0);
  return;
}

void func_0028b0e0(u64 param_1)

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

void func_0028bdb8(u32 *param_1)

{
  short sVar1;
  s64 lVar2;
  
  lVar2 = func_0028be58();
  if (lVar2 != 0) {
    sVar1 = func_0028e4c8(*param_1,0);
    if (sVar1 != *(short *)(param_1 + 4)) {
      func_0028e560(*param_1,param_1 + 4,4,0xffffffffffffffff);
      return;
    }
  }
  return;
}

void func_0028d660(u64 param_1,int param_2)

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

void func_0028dcc0(u64 param_1,u32 param_2)

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

void func_0028e350(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 != 0) {
    iVar3 = iVar2 + *(int *)(iVar2 + -4) * 0x17c;
    while (bVar1 = iVar2 != iVar3, iVar3 = iVar3 + -0x17c, bVar1) {
      func_00239870(iVar3);
      iVar2 = *(int *)(param_1 + 0x38);
    }
    func_00106450(iVar2 + -4);
    *(u32 *)(param_1 + 0x38) = 0;
  }
  return;
}

void func_0028e438(int param_1,int param_2,int param_3,u32 param_4)

{
  int iVar1;
  
  func_00139d78();
  iVar1 = *(int *)(param_1 + 0x38);
  param_2 = param_2 * 0x17c;
  if (*(int *)(param_2 + iVar1 + 0x158) != param_3) {
    *(int *)(param_2 + iVar1 + 0x158) = param_3;
    func_00239bf8(*(int *)(param_1 + 0x38) + param_2,param_3);
    iVar1 = *(int *)(param_1 + 0x38);
  }
  *(u32 *)(param_2 + iVar1 + 0x15c) = param_4;
  *(u8 *)(param_2 + *(int *)(param_1 + 0x38) + 0x160) = 0;
  return;
}

void func_0028e5e0(u64 param_1,u16 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  func_00139d78();
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar2 = iVar1 + 1;
      func_0028e510(param_1,iVar1,*param_2);
      param_2 = param_2 + 1;
      iVar1 = iVar2;
    } while (iVar2 < param_3);
  }
  return;
}

void func_0028e710(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x30) = param_2;
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

void func_0028eb88(u32 param_1,u32 param_2,int param_3,int param_4)

{
  func_00139d78();
  *(u32 *)(param_4 * 0x17c + *(int *)(param_3 + 0x38) + 0x170) = param_1;
  *(u32 *)(param_4 * 0x17c + *(int *)(param_3 + 0x38) + 0x174) = param_2;
  return;
}

void func_0028ff18(int *param_1)

{
  func_00290060();
  if ((s64)*(int *)(*param_1 + 0x184) != (s64)(short)param_1[3]) {
    func_00138c10(*param_1,(s64)(short)param_1[3]);
    *(u32 *)(*param_1 + 0x188) = 0xffffffff;
  }
  return;
}

void func_00290438(int *param_1)

{
  func_00290580();
  if ((s64)*(int *)(*param_1 + 0x184) != (s64)(short)param_1[3]) {
    func_00138c10(*param_1,(s64)(short)param_1[3]);
    *(u32 *)(*param_1 + 0x188) = 0xffffffff;
  }
  return;
}

void func_00290668(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  int iVar2;
  
  func_00290740();
  iVar2 = (int)param_1;
  iVar1 = iVar2 + 0x1a0;
  func_002362b0(iVar1,param_3);
  func_002367c8(iVar1);
  func_001386e0(param_1,*(u32 *)(iVar2 + 0x198),param_2,iVar1,param_4,0);
  *(u32 *)(iVar2 + 0xd0) = *(u32 *)(iVar2 + 0xd0) | 8;
  *(u8 *)(iVar2 + 0x195) = 1;
  return;
}

void func_002908f0(int param_1)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    func_00290a60();
  }
  *(u32 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    func_00106450(*(int *)(param_1 + 0x14));
    *(u32 *)(param_1 + 0x14) = 0;
  }
  return;
}

void func_00290960(int param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  s64 lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(int *)(param_1 + 4) = (int)param_2;
  iVar5 = 0;
  lVar2 = func_00168aa0(param_2,param_3);
  *(int *)(param_1 + 8) = (int)lVar2;
  if (0 < lVar2) {
    iVar3 = *(int *)(param_1 + 0x14);
    while( true ) {
      iVar4 = iVar5 * 4;
      iVar1 = func_00168b38(*(u32 *)(param_1 + 4),param_3,iVar5);
      iVar5 = iVar5 + 1;
      *(u32 *)(iVar4 + iVar3) = *(u32 *)(iVar1 + 8);
      if (*(int *)(param_1 + 8) <= iVar5) break;
      iVar3 = *(int *)(param_1 + 0x14);
    }
  }
  return;
}
