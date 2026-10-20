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

bool func_00265740(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  return *(int *)((int)uVar1 + 0x184) == 0x8d;
}

void func_00265780(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_0028da70(uVar1,0x8d);
  return;
}

bool func_00265c10(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_00139d78(uVar1);
  return *(int *)((int)uVar1 + 0x184) == 0x141;
}

void func_00265c50(void)

{
  u64 uVar1;
  
  uVar1 = func_00257770();
  func_0028da70(uVar1,0x141);
  return;
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

void func_002691c8(void)

{
  func_00257388(0x846a,0);
  func_002571e0(1);
  func_00287cc0(0);
  return;
}

void func_00269378(void)

{
  func_00257388(0xc22e,0);
  func_002571e0(0);
  func_00287cc0(0);
  return;
}

void func_0026b448(void)

{
  func_0026b470();
  func_0026b508();
  func_0026b5a0(0xffffffffffffffff);
  return;
}

void func_0026c9c8(void)

{
  func_0026bc10();
  func_00257708(0);
  func_0026ceb0();
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

void func_00276c50(s64 param_1,u8 param_2)

{
  u64 uVar1;
  
  uVar1 = 0;
  if (-1 < param_1) {
    uVar1 = func_00192048();
  }
  func_00276c88(uVar1,param_2);
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

void func_0027d598(u64 param_1)

{
  u64 uVar1;
  
  func_0027d008();
  func_0027d540();
  func_0027d5d8();
  uVar1 = func_0028b040(param_1);
  func_0027d810(uVar1);
  return;
}

void func_0027f9b0(void)

{
  func_00280148();
  func_002800d0();
  func_00287cc0(0);
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

int func_002811f8(int *param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  iVar1 = *param_1;
  iVar3 = 0;
  if (0 < iVar1) {
    param_1 = param_1 + 1;
    sVar4 = (short)*param_1;
    while ((param_1 = param_1 + 5, sVar4 != param_2 && (iVar3 = iVar3 + 1, iVar3 < iVar1))) {
      sVar4 = (short)*param_1;
    }
  }
  iVar2 = -1;
  if (iVar3 < iVar1) {
    iVar2 = iVar3;
  }
  return iVar2;
}

void func_00281e88(u64 param_1)

{
  func_00281f40(param_1,0);
  func_00281f48(param_1);
  func_00281f70(param_1);
  func_00281f90(param_1);
  return;
}

void func_00281ec8(u64 param_1)

{
  func_00281f40(param_1,0);
  func_00281f48(param_1);
  func_00281f70(param_1);
  func_00281f90(param_1);
  return;
}

void func_002827f0(u64 param_1,u64 param_2,u64 param_3)

{
  func_00281f70();
  if (*(int *)((int)param_1 + 0x1008) == 0) {
    func_00282858();
    return;
  }
  func_00282b00(param_1,param_2,param_3);
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

void func_00288fd8(int param_1,int param_2,u16 param_3,u64 param_4)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  u16 *puVar4;
  
  iVar2 = param_2 << 3;
  iVar1 = 3;
  do {
    iVar1 = iVar1 + -1;
    *(u16 *)(iVar2 + *(int *)(param_1 + 0x2c)) = param_3;
    iVar2 = iVar2 + 2;
  } while (-1 < iVar1);
  param_2 = param_2 << 3;
  iVar1 = 3;
  do {
    puVar4 = (u16 *)(param_2 + *(int *)(param_1 + 0x30));
    param_2 = param_2 + 2;
    uVar3 = param_4;
    if (param_4 == 0) {
      uVar3 = (u64)param_3;
    }
    iVar1 = iVar1 + -1;
    *puVar4 = (short)uVar3;
  } while (-1 < iVar1);
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

int func_0028b160(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  sVar1 = *(short *)(param_1 + 4);
  iVar4 = 0;
  if (0 < sVar1) {
    piVar3 = *(int **)(param_1 + 0x28);
    iVar2 = *piVar3;
    while ((piVar3 = piVar3 + 1, param_2 != iVar2 && (iVar4 = iVar4 + 1, iVar4 < sVar1))) {
      iVar2 = *piVar3;
    }
  }
  iVar2 = -1;
  if (iVar4 < sVar1) {
    iVar2 = iVar4;
  }
  return iVar2;
}

void func_0028b218(int param_1,char param_2)

{
  u32 uVar1;
  
  *(char *)(param_1 + 0x27) = param_2;
  if (param_2 == '\0') {
    uVar1 = *(u32 *)(param_1 + 0x34) & 0xffffcfff;
  }
  else {
    uVar1 = *(u32 *)(param_1 + 0x34) | 0x3000;
  }
  *(u32 *)(param_1 + 0x34) = uVar1;
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

void func_0028c170(u64 param_1)

{
  func_00139d78();
  func_00139510(param_1);
  return;
}

void func_0028d708(u64 param_1)

{
  func_00138d48();
  func_001395f8(param_1);
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

u8 func_0028e6c0(int param_1,int param_2)

{
  u8 uVar1;
  int iVar2;
  
  func_00139d78();
  iVar2 = *(int *)(param_1 + 0x38) + param_2 * 0x17c;
  uVar1 = func_00239d30(iVar2,*(u32 *)(iVar2 + 0x114));
  return uVar1;
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

void func_0028fb28(u64 param_1,s64 param_2)

{
  u64 uVar1;
  
  uVar1 = 0;
  if (-1 < param_2) {
    uVar1 = func_00192048(param_2);
  }
  func_0028fb68(param_1,uVar1);
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

void func_002908a8(int param_1)

{
  int iVar1;
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
      iVar1 = iVar1 + 1;
      *(u32 *)(iVar2 + iVar3) = 0;
      if (*(int *)(param_1 + 0xc) <= iVar1) break;
      iVar3 = *(int *)(param_1 + 0x14);
    }
  }
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

void func_00290a10(u64 param_1,u64 param_2,u64 param_3)

{
  u64 uVar1;
  
  uVar1 = func_001708f8(param_2,0xffffffffffffffff);
  func_00290960(param_1,uVar1,param_3);
  *(u8 *)((int)param_1 + 0x10) = 1;
  return;
}

int func_002924d0(int param_1,s64 param_2)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = param_1 + 0x2b3c;
  if (param_2 != 0) {
    uVar2 = func_001a80c8(param_2);
    iVar1 = func_001a8190(uVar2);
  }
  if (iVar1 == 0) {
    iVar1 = param_1 + 0x2b3c;
  }
  return iVar1;
}

void func_00293350(u32 param_1,u32 param_2,u32 param_3)

{
  int iVar1;
  
  iVar1 = func_00103eb0();
  iVar1 = func_00102818(*(u32 *)(iVar1 + 4),0,140000,0x2933b8,0x1000);
  *(u32 *)(iVar1 + 0xc) = param_3;
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 8) = param_2;
  return;
}

void func_00293b70(void)

{
  int iVar1;
  
  iVar1 = func_00103eb0();
  func_00102a38(*(u32 *)(iVar1 + 4),0x293b08);
  return;
}

u64 func_00294208(char param_1)

{
  int *piVar1;
  char *pcVar2;
  u64 uVar3;
  int iVar4;
  
  pcVar2 = (char *)func_00294000(0);
  piVar1 = (int *)(pcVar2 + 8);
  iVar4 = 0;
  if (0 < *piVar1) {
    do {
      pcVar2 = pcVar2 + 0x10;
      iVar4 = iVar4 + 1;
      if (*pcVar2 == param_1) {
        uVar3 = func_002941d8();
        return uVar3;
      }
    } while (iVar4 < *piVar1);
  }
  return 0;
}

bool func_00294408(u16 *param_1)

{
  s64 lVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(char *)(param_1 + 3) == '\x02') {
    lVar1 = func_001a3570(*param_1);
    bVar2 = 0 < lVar1;
  }
  else {
    lVar1 = func_00181500(*param_1);
    if (lVar1 != 0) {
      bVar2 = true;
    }
  }
  if ((param_1[1] != 0) && (lVar1 = func_00181500(param_1[1]), lVar1 != 0)) {
    bVar2 = false;
  }
  return bVar2;
}

bool func_00294480(u16 *param_1)

{
  s64 lVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(char *)(param_1 + 3) == '\x02') {
    lVar1 = func_001a3570(*param_1);
    bVar2 = 0 < lVar1;
  }
  else {
    lVar1 = func_00181500(*param_1);
    if (lVar1 != 0) {
      bVar2 = true;
    }
  }
  return bVar2;
}

u8 func_00295228(u64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_00294000(0);
  iVar2 = func_00295158(param_1);
  return *(u8 *)(iVar2 * 0x10 + iVar1 + 0x10);
}

int func_002953c8(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_00294000(0);
  iVar3 = 0;
  if (*(int *)(iVar1 + 8) < 1) {
    iVar2 = 0;
  }
  else {
    do {
      iVar2 = iVar3 * 0x10;
      iVar3 = iVar3 + 1;
      if (*(char *)(iVar2 + iVar1 + 0x10) == param_1) break;
      iVar2 = iVar3 * 0x10;
    } while (iVar3 < *(int *)(iVar1 + 8));
  }
  return iVar1 + 0x10 + iVar2;
}

void func_002956c0(u64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_00294000(0);
  iVar2 = func_00295158(param_1);
  func_002941a8(iVar1 + 0x10 + iVar2 * 0x10);
  return;
}

void func_00299238(void)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028dac8(iVar1 + 0x4398,3);
  return;
}

void func_0029df98(void)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028dac8(iVar1 + 0x4398,3);
  return;
}

void func_0029e050(void)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028dac8(iVar1 + 0x4860,6);
  return;
}

void func_0029e0d0(void)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_00139d78(iVar1 + 0x4860);
  return;
}

void func_0029e148(void)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028da70(iVar1 + 0x4860,5);
  return;
}

void func_0029e258(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028dac8(iVar1 + (param_1 + 1) * 0x198 + 0x4398,9);
  return;
}

void func_0029e2f8(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_00139d78(iVar1 + (param_1 + 1) * 0x198 + 0x4398);
  return;
}

void func_0029e3a0(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0();
  func_0028da70(iVar1 + (param_1 + 1) * 0x198 + 0x4398,8);
  return;
}

int func_002a01c8(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(4);
  return iVar1 + 0x10 + param_1 * 8;
}

u32 func_002a43f0(void)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0;
  if ((lVar1 == 7) || (lVar1 == 0x1a)) {
    uVar2 = 1;
  }
  return uVar2;
}

int func_002a6368(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(6);
  return iVar1 + 0x10 + param_1 * 8;
}

u32 func_002a74c0(void)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar1 = func_001058e8();
  uVar2 = 0;
  uVar4 = 0;
  while( true ) {
    uVar3 = uVar2 & 0x1f;
    uVar2 = uVar2 + 1;
    if ((*(u32 *)(uVar4 * 4 + iVar1 + 0x49f4) & 1 << uVar3) != 0) {
      return 1;
    }
    if (0x3f < (int)uVar2) break;
    uVar4 = uVar2 >> 5;
  }
  return 0;
}

void func_002a7588(void)

{
  u64 uVar1;
  u8 auStack_90 [128];
  
  uVar1 = func_002b64c8();
  func_00253b30(auStack_90,uVar1);
  func_00170518(auStack_90,0x13ee,0);
  return;
}

int func_002a7f20(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(7);
  return iVar1 + 0x10 + param_1 * 8;
}

bool func_002a8920(void)

{
  u8 *pbVar1;
  
  pbVar1 = (u8 *)func_001d56c8();
  return 1 < *pbVar1;
}

int func_002a92a0(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(8);
  return iVar1 + 0x10 + param_1 * 0x10;
}

void func_002aa048(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2);
  uVar4 = 1 << (param_1 & 0x1f);
  uVar1 = *puVar3;
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002aa450(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x13c);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002aa8e0(u64 param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  iVar2 = func_002a9d68();
  uVar3 = func_002aa5b8(param_1,param_2);
  puVar4 = (u32 *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0x44);
  uVar1 = *puVar4;
  uVar3 = 1 << (uVar3 & 0x1f);
  if ((uVar1 & uVar3) == 0) {
    *puVar4 = uVar1 | uVar3;
  }
  return;
}

void func_002aab90(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x84);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002aae30(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x94);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002ab258(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68();
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x88);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002abdc8(void)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  iVar1 = func_002a9d68();
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar4 = 1 << (uVar3 & 0x1f);
    puVar2 = (u32 *)(uVar5 * 4 + iVar1 + 0x140);
    uVar3 = uVar3 + 1;
    uVar5 = *puVar2;
    if ((uVar5 & uVar4) == 0) {
      *puVar2 = uVar5 | uVar4;
    }
    uVar5 = uVar3 >> 5;
  } while ((int)uVar3 < 4);
  return;
}

void func_002ac268(u64 param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  iVar2 = func_002a9d68();
  uVar3 = func_002abf40(param_1,param_2);
  puVar4 = (u32 *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0xac);
  uVar1 = *puVar4;
  uVar3 = 1 << (uVar3 & 0x1f);
  if ((uVar1 & uVar3) == 0) {
    *puVar4 = uVar1 | uVar3;
  }
  return;
}

void func_002b6338(u64 param_1,u64 param_2,u64 param_3,s64 param_4)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar2 = 0xb7d4;
  if (param_4 != 0) {
    uVar2 = 0xb7d5;
  }
  uVar1 = func_00192048(param_3);
  uVar2 = func_00192048(uVar2);
  func_00192e50(uVar1,param_1,param_2,uVar2);
  return;
}

u64 func_002b6ab8(void)

{
  return 0;
}

u64 func_002b6adc(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,6,param_2,param_1);
  return uVar1;
}

u64
func_002b6b24(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(6,7,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

u64 func_002b6b84(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,8,param_1);
  return uVar1;
}

u64 func_002b6bc4(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,9,param_1);
  return uVar1;
}

u64 func_002b6c04(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,10,param_1);
  return uVar1;
}

u64 func_002b6f28(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0xe,param_1,param_2,param_3);
  return uVar1;
}

u64
func_002b7010(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5,u32 param_6)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(7,0xf,param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar1;
}

u64 func_002b7078(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x10,param_1);
  return uVar1;
}

u64 func_002b70b8(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x11,param_1,param_2,param_3);
  return uVar1;
}
