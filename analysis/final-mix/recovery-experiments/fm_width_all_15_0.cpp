#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_002ff3fc(...);
extern "C" s32 func_0030ff08(...);
extern "C" s32 func_00310518(...);
extern "C" u32 func_00101ce0(...);
extern "C" u32 func_00108698(...);
extern "C" u32 func_0014b9a8(...);
extern "C" u32 func_001ddd10(...);
extern "C" u32 func_002f3500(...);
extern "C" u32 func_003032d0(...);
extern "C" u32 func_00310090(...);
extern "C" u32 func_00310180(...);
extern "C" u32 func_00310230(...);
extern "C" u32 func_00310330(...);
extern "C" u32 func_00310670(...);
extern "C" u32 func_00311af0(...);
extern "C" u32 func_00313e80(...);
extern "C" u32 func_00313f40(...);
extern "C" u32 func_00314640(...);
extern "C" u32 func_00314698(...);
extern "C" u32 func_003147a0(...);
extern "C" u32 func_003149e8(...);
extern "C" u32 func_00314b90(...);
extern "C" u32 func_00316e10(...);
extern "C" u32 func_00100350(...);
extern "C" u32 func_00138988(...);
extern "C" u32 func_00138de0(...);
extern "C" u32 func_00311aa0(...);
extern "C" u32 func_00313c58(...);
extern "C" u32 func_00314330(...);
extern "C" u32 func_003146c8(...);

bool func_002f3bf0(int param_1,u32 param_2,int param_3,u32 param_4)

{
  bool bVar1;
  
  if (param_3 == 1) {
    bVar1 = *(u32 *)(param_1 + 0x10) < param_2;
  }
  else {
    func_002f3500(param_1,param_2,param_4);
    bVar1 = false;
  }
  return bVar1;
}

u32 func_00310130(u32 param_1)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310090(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u32 func_003101d0(u32 param_1,u32 param_2)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310180(param_1,param_2);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u32 func_003102e0(u32 param_1)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310230(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u32 func_003103f8(u32 param_1)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310330(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u32 func_00310560(u32 param_1)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310518(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

s32 func_003105b0(u32 param_1)

{
  s32 lVar1;
  s32 lVar2;
  int iVar3;
  
  iVar3 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar3 + 8))) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(s32 *)(iVar3 + 0x18);
    if ((*(u32 *)(iVar3 + 0xc) & 1) != 0) {
      lVar1 = func_0030ff08();
      lVar2 = lVar2 + (lVar1 - *(s32 *)(iVar3 + 0x10));
    }
  }
  return lVar2;
}

u32 func_00310768(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310670(param_1,param_2,param_3,param_4);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

float func_00310900(u32 param_1)

{
  float fVar1;
  
  if ((s32)param_1 < 0) {
    fVar1 = (float)func_00311af0(param_1 & 1 | param_1 >> 1);
    fVar1 = fVar1 + fVar1;
  }
  else {
    fVar1 = (float)func_00311af0();
  }
  return 1.47456e+08 / fVar1;
}

u32 func_00313bc0(u32 param_1)

{
  u32 uVar1;
  u32 uStack_30;
  int iStack_2c;
  int iStack_28;
  u32 uStack_24;
  u32 auStack_20 [4];
  
  auStack_20[0] = param_1;
  func_00314640(auStack_20,&uStack_30);
  uVar1 = 0;
  if ((((uStack_30 != 2) && (1 < uStack_30)) && (iStack_2c == 0)) &&
     (uVar1 = 0xffffffff, uStack_30 != 4)) {
    uVar1 = 0;
    if ((-1 < iStack_28) && (uVar1 = 0xffffffff, iStack_28 < 0x20)) {
      if (iStack_28 < 0x1f) {
        uVar1 = uStack_24 >> (0x1eU - iStack_28 & 0x1f);
      }
      else {
        uVar1 = uStack_24 << (iStack_28 - 0x1eU & 0x1f);
      }
    }
  }
  return uVar1;
}

void func_00313ed8(u32 param_1,u32 param_2)

{
  u32 uVar1;
  u8 auStack_80 [32];
  u8 auStack_60 [4];
  u32 uStack_5c;
  u8 auStack_40 [32];
  u32 uStack_20;
  u32 uStack_18;
  
  uStack_20 = param_1;
  uStack_18 = param_2;
  func_003147a0(&uStack_20,auStack_80);
  func_003147a0(&uStack_18,auStack_60);
  uStack_5c = uStack_5c ^ 1;
  uVar1 = func_00313c58(auStack_80,auStack_60,auStack_40);
  func_003146c8(uVar1);
  return;
}

int func_003143e0(u32 param_1)

{
  int iVar1;
  u32 uStack_40;
  int iStack_3c;
  int iStack_38;
  u32 uStack_30;
  u32 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  if (uStack_40 == 2) {
    return 0;
  }
  if (uStack_40 < 2) {
    return 0;
  }
  if (uStack_40 != 4) {
    if (iStack_38 < 0) {
      return 0;
    }
    if (iStack_38 < 0x1f) {
      iVar1 = (int)(uStack_30 >> (s32)(0x3c - iStack_38));
      if (iStack_3c == 0) {
        return iVar1;
      }
      return -iVar1;
    }
  }
  iVar1 = -0x80000000;
  if (iStack_3c == 0) {
    iVar1 = 0x7fffffff;
  }
  return iVar1;
}

void func_003144b0(u32 param_1)

{
  u32 uVar1;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  uVar1 = (s32)(uStack_30 << 2) >> 0x20;
  if ((uStack_30 & 0x3fffffff) != 0) {
    uVar1 = uVar1 | 1;
  }
  func_00314698(uStack_40,uStack_3c,uStack_38,uVar1);
  return;
}

u32 func_00314508(u32 param_1)

{
  u32 uVar1;
  u32 uStack_40;
  int iStack_3c;
  int iStack_38;
  u32 uStack_30;
  u32 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  uVar1 = 0;
  if ((((uStack_40 != 2) && (1 < uStack_40)) && (iStack_3c == 0)) &&
     (uVar1 = 0xffffffff, uStack_40 != 4)) {
    uVar1 = 0;
    if ((-1 < iStack_38) && (uVar1 = 0xffffffff, iStack_38 < 0x20)) {
      if (iStack_38 < 0x3d) {
        uVar1 = (u32)(uStack_30 >> (s32)(0x3c - iStack_38));
      }
      else {
        uVar1 = (u32)(uStack_30 << (s32)(iStack_38 + -0x3c));
      }
    }
  }
  return uVar1;
}

void func_003145a8(s32 param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = func_00314330(param_1 >> 0x20);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar2 = func_00314330((int)param_1);
  if ((int)param_1 < 0) {
    uVar2 = func_00313e80(uVar2,0x41f0000000000000);
  }
  func_00313e80(uVar1,uVar2);
  return;
}

u32 func_00314dd8(int param_1,u32 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 auStack_30 [4];
  
  uVar1 = func_003149e8(*(u8 *)(param_1 + 0x14));
  iVar2 = func_00311aa0(param_2,uVar1);
  func_00314b90(*(u8 *)(param_1 + 0x14),*(u32 *)(param_1 + 8),
               *(int *)(param_1 + 0xc) - iVar2,auStack_30);
  return auStack_30[0];
}

u32 func_00316c68(int *param_1,s32 param_2)

{
  int *piVar1;
  s32 lVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = (int *)func_00316e10();
  lVar2 = func_0030edb0();
  while ((*piVar1 != 0 || (param_2 == 0))) {
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 1;
    if (7 < iVar3) {
      if (lVar2 != 0) {
        func_0030ee00();
      }
      return 0xffffffff;
    }
  }
  *piVar1 = 1;
  if (lVar2 != 0) {
    func_0030ee00();
  }
  *param_1 = iVar3;
  return 0;
}

void func_00316d18(u32 param_1,u32 param_2)

{
  u32 *puStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_20 = param_1;
  uStack_28 = func_002ff3fc();
  puStack_30 = &uStack_20;
  uStack_2c = 1;
  uStack_1c = uStack_28;
  func_003032d0(param_2,&puStack_30);
  return;
}

void func_00319788(void)

{
  func_00100350();
  func_00101ce0();
  return;
}

void func_0031c068(u32 param_1)

{
  func_00138988();
  func_0014b9a8((int)param_1 + 0x1c0);
  func_00138de0(param_1);
  func_0014b9a8((int)param_1 + 0x1e0);
  return;
}

void func_00322ba8(int param_1)

{
  func_00108698(param_1 + 0x38);
  func_001ddd10(param_1 + 0xc0);
  return;
}
