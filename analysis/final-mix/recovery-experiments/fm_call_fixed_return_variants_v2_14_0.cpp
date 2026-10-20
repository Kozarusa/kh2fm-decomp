#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0030edb0(void);
extern "C" bool func_0030ee00(void);
extern "C" s32 func_00102210(...);
extern "C" s32 func_0010fa28(s32);
extern "C" s32 func_0010fa58(s32);
extern "C" s32 func_003071d0(void*,u32,u32,void*,void*);
extern "C" s32 func_00308dc0(...);
extern "C" s32 func_0030a8f8(...);
extern "C" s32 func_0030ab88(...);
extern "C" s64 func_00305168(void*,u64,u64,u64);
extern "C" u32 func_00102080(...);
extern "C" u32 func_001031b0(...);
extern "C" u32 func_00105c30(void);
extern "C" u32 func_0010c7e8(s32);
extern "C" u32 func_00110500(u64);
extern "C" u32 func_00110618(s32);
extern "C" u32 func_00114438(...);
extern "C" u32 func_0011a408(...);
extern "C" u32 func_0011a938(f32,f32,s32,u64);
extern "C" u32 func_0011cdf0(...);
extern "C" u32 func_0016bd60(u64,u64);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0017c030(void*,u64,u64,s8);
extern "C" u32 func_0017c430(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017f488(u32,u32,u64,u64);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_0017f5f8(...);
extern "C" u32 func_00180c88(...);
extern "C" u32 func_0018a008(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_0019bc38(u64);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_0023a918(s32);
extern "C" u32 func_0023cc18(s32);
extern "C" u32 func_002bc1e8(u64);
extern "C" u32 func_002e95a0(u32,u32,s32);
extern "C" u32 func_002e9610(void*,void*);
extern "C" u32 func_002eaf40(s32);
extern "C" u32 func_002ee730(void*);
extern "C" u32 func_002ee840(...);
extern "C" u32 func_002ef618(void);
extern "C" u32 func_002f25a0(...);
extern "C" u32 func_002f3c28(void*);
extern "C" u32 func_002f3f88(...);
extern "C" u32 func_002f40a0(f32);
extern "C" u32 func_002f4148(...);
extern "C" u32 func_002f41f0(...);
extern "C" u32 func_002fd220(u64);
extern "C" u32 func_002feac0(...);
extern "C" u32 func_003032d0(...);
extern "C" u32 func_00305110(void*,u64,u64,u64);
extern "C" u32 func_00306e80(...);
extern "C" u32 func_003080d0(...);
extern "C" u32 func_0030af40(u64,u64,u64);
extern "C" u32 func_0030f468(s32);
extern "C" u32 func_0030ffd8(void);
extern "C" u32 func_00316d08(void);

void func_002e8c28(u32 *param_1)

{
  u32 *puVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)param_1[1];
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  func_002e9610(*param_1,&uStack_20);
  return;
}

void func_002e8c58(u32 *param_1)

{
  func_002e95a0(param_1[1],param_1[2],*param_1);
  return;
}

u64 func_002e9c58(int param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 0xc) != 2) && ((*(u32 *)((int)param_2 + 0x588) & 4) == 0)) {
    uVar1 = func_0019bc38(param_2);
  }
  return uVar1;
}

void func_002eaab0(u64 param_1,u32 *param_2)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0017c4c8(param_1,&uStack_20);
  func_0016bd60(param_1,0x2c);
  return;
}

void func_002eb460(u64 param_1,u32 *param_2)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0017c4c8(param_1,&uStack_20);
  *(u32 *)((int)param_1 + 0x100) = 0x100;
  *(u32 *)((int)param_1 + 0x104) = 0x101;
  func_0016bd60(param_1,0x31);
  return;
}

void func_002eb6f8(u32 param_1,u64 param_2,s64 param_3)

{
  int iVar1;
  
  if (-1 < param_3) {
    func_00180c88((int)param_2 + 0x140);
    func_002eaf40(param_2);
    iVar1 = func_002eaf40(param_2);
    func_0017f488(param_1,0,iVar1 + 0x140,(int)param_3 + -0x65);
    return;
  }
  return;
}

void func_002eb7f0(u32 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  
  func_0017f5f8(param_1,0,(int)param_2 + 0x140,param_3,0);
  iVar1 = func_002eaf40(param_2);
  func_0017f5e0(param_1,0,iVar1 + 0x140,(int)param_3 + -0x65,0);
  return;
}

void func_002ee850(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_002ee730(0x1e2c088);
    return;
  }
  return;
}

void func_002eee68(int param_1)

{
  func_0011cdf0(*(u32 *)(param_1 + 0x44),param_1 + 0x50,param_1 + 0x150,param_1 + 400,0);
  func_002f25a0(0,0);
  return;
}

void func_002ef180(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0xc);
  if (iVar1 != 0) {
    func_0018a008(iVar1,0x2ef1b8,param_1);
    return;
  }
  return;
}

void func_002ef1b8(int param_1)

{
  if (*(char *)(param_1 + 2) == '\b') {
    func_002bc1e8((u32)*(u16 *)(param_1 + 4) * 1000 + (u32)*(u16 *)(param_1 + 6));
  }
  return;
}

void func_002ef340(int param_1)

{
  func_0023cc18(param_1 + 0x40);
  func_002ef618();
  return;
}

u64 func_002ef660(u64 param_1,int param_2)

{
  u32 uVar1;
  u8 *puVar2;
  
  uVar1 = func_0023a918(param_2 + 0x1d4);
  puVar2 = (u8 *)param_1;
  *puVar2 = (char)uVar1;
  puVar2[3] = (char)((u32)uVar1 >> 0x18);
  puVar2[1] = (char)((u32)uVar1 >> 8);
  puVar2[2] = (char)((u32)uVar1 >> 0x10);
  return param_1;
}

u32 func_002ef988(void)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_00105c30();
  uVar2 = 0x5355;
  if (lVar1 != 2) {
    if (lVar1 < 3) {
      uVar2 = 0x504a;
      if (lVar1 != 1) {
        uVar2 = 0x5545;
      }
    }
    else if (lVar1 == 8) {
      uVar2 = 0x504a;
    }
    else {
      uVar2 = 0x5545;
    }
  }
  return uVar2;
}

u32 func_002efbb8(void)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_00105c30();
  uVar2 = 0x5355;
  if (lVar1 != 2) {
    if (lVar1 < 3) {
      uVar2 = 0x504a;
      if (lVar1 != 1) {
        uVar2 = 0x5545;
      }
    }
    else if (lVar1 == 8) {
      uVar2 = 0x504a;
    }
    else {
      uVar2 = 0x5545;
    }
  }
  return uVar2;
}

void func_002f0598(u64 param_1,u32 *param_2)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0017c4c8(param_1,&uStack_20);
  func_0016bd60(param_1,0x3f);
  return;
}

void func_002f0640(u64 param_1,u64 param_2,u8 param_3)

{
  int iVar1;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 auStack_20 [4];
  
  func_0017c030(&uStack_40,param_2,auStack_20,param_3);
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  func_0017c4c8(param_2);
  iVar1 = (int)param_2;
  *(u8 *)(iVar1 + 0x514) = 9;
  func_0017f488(0,0,iVar1 + 0x140,auStack_20[0]);
  *(u32 *)(iVar1 + 0x104) = 5;
  *(u32 *)(iVar1 + 0x100) = 4;
  return;
}

void func_002f0948(int *param_1)

{
  func_0016c568(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_002f0a38(int *param_1)

{
  func_0017f5f8(param_1[2],0,*param_1 + 0x140,param_1[1],0);
  return;
}

void func_002f0af0(int *param_1)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  iVar1 = *(int *)(*param_1 + 4);
  func_00110500(iVar1);
  puVar2 = (u32 *)func_0010fa28(iVar1);
  if ((u32 *)(iVar1 + 0x10) != puVar2) {
    uVar3 = puVar2[1];
    uVar4 = puVar2[2];
    uVar5 = puVar2[3];
    *(u32 *)(iVar1 + 0x10) = *puVar2;
    *(u32 *)(iVar1 + 0x14) = uVar3;
    *(u32 *)(iVar1 + 0x18) = uVar4;
    *(u32 *)(iVar1 + 0x1c) = uVar5;
  }
  puVar2 = (u32 *)func_0010fa58(iVar1);
  if ((u32 *)(iVar1 + 0x20) != puVar2) {
    uVar3 = puVar2[1];
    uVar4 = puVar2[2];
    uVar5 = puVar2[3];
    *(u32 *)(iVar1 + 0x20) = *puVar2;
    *(u32 *)(iVar1 + 0x24) = uVar3;
    *(u32 *)(iVar1 + 0x28) = uVar4;
    *(u32 *)(iVar1 + 0x2c) = uVar5;
  }
  return;
}

void func_002f0b60(int *param_1)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  iVar1 = *(int *)(*param_1 + 4);
  func_00110618(iVar1);
  puVar2 = (u32 *)func_0010fa28(iVar1);
  if ((u32 *)(iVar1 + 0x10) != puVar2) {
    uVar3 = puVar2[1];
    uVar4 = puVar2[2];
    uVar5 = puVar2[3];
    *(u32 *)(iVar1 + 0x10) = *puVar2;
    *(u32 *)(iVar1 + 0x14) = uVar3;
    *(u32 *)(iVar1 + 0x18) = uVar4;
    *(u32 *)(iVar1 + 0x1c) = uVar5;
  }
  puVar2 = (u32 *)func_0010fa58(iVar1);
  if ((u32 *)(iVar1 + 0x20) != puVar2) {
    uVar3 = puVar2[1];
    uVar4 = puVar2[2];
    uVar5 = puVar2[3];
    *(u32 *)(iVar1 + 0x20) = *puVar2;
    *(u32 *)(iVar1 + 0x24) = uVar3;
    *(u32 *)(iVar1 + 0x28) = uVar4;
    *(u32 *)(iVar1 + 0x2c) = uVar5;
  }
  return;
}

void func_002f10c0(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_0011a938(param_1[2],param_1[3],uVar1,param_1[1]);
  return;
}

u32 func_002f2020(void)

{
  char cVar1;
  u32 uVar2;
  s64 lVar3;
  char *pcVar4;
  u8 auStack_149 [9];
  char acStack_140 [256];
  
  pcVar4 = acStack_140;
  lVar3 = func_0030a8f8(0x3762c8,1);
  uVar2 = 0;
  if (lVar3 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    for (; uVar2 < 0x100; uVar2 = uVar2 + 1) {
      func_0030af40(lVar3,pcVar4,1);
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 == '\0') break;
    }
    func_0030ab88(lVar3);
    lVar3 = func_002fd220(auStack_149 + uVar2);
    uVar2 = (u32)(0x1315670 < lVar3);
  }
  return uVar2;
}

void func_002f3490(u64 param_1)

{
  int iVar1;
  
  if ((*(u32 *)param_1 & 0x100) != 0) {
    iVar1 = 0xffffff;
    do {
      if (iVar1 < 0) {
        func_003080d0(0x3767d0);
        func_002f3c28(param_1);
      }
      iVar1 = iVar1 + -1;
    } while ((*(u32 *)param_1 & 0x100) != 0);
  }
  return;
}

void func_002f3500(u64 param_1,u32 param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = 0x1000000;
  if (param_3 != 0) {
    iVar2 = param_3;
  }
  uVar1 = *(u32 *)((int)param_1 + 0x10);
  while (uVar1 < param_2) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      func_003080d0(0x3767d0);
      func_002f3c28(param_1);
    }
    uVar1 = *(u32 *)((int)param_1 + 0x10);
  }
  return;
}

void func_002f4298(u64 param_1,u64 param_2,u32 *param_3)

{
  func_002f40a0(param_3[2]);
  func_002f41f0(param_3[1],param_1,param_1);
  func_002f4148(*param_3,param_1,param_1);
  return;
}

void func_002f4480(int param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  func_002f3f88();
  func_002f3f88(param_1 + 0x10,param_3);
  func_002f3f88(param_1 + 0x20,param_4);
  func_002f3f88(param_1 + 0x30,param_5);
  return;
}

u32 func_002feb28(u32 *param_1,u64 param_2,u32 param_3)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  if (param_2 < 0x20) {
    iVar2 = param_1[0x75];
    if (iVar2 == 0) {
      lVar1 = func_002feac0();
      if (lVar1 != 0) {
        return 0xffffffff;
      }
      iVar2 = param_1[0x75];
    }
    puVar4 = (u32 *)((int)param_2 * 4 + iVar2);
    uVar3 = *puVar4;
    *puVar4 = param_3;
  }
  else {
    uVar3 = 0xffffffff;
    *param_1 = 0x16;
  }
  return uVar3;
}

u64 func_002ffc08(u64 param_1,int param_2)

{
  u64 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(u32 *)(param_2 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = func_003032d0();
    *(u32 *)(param_2 + 4) = 0;
    *(u32 *)(param_2 + 8) = 0;
  }
  return uVar1;
}

void func_00304de8(int param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  
  iVar1 = func_00305168(*(u32 *)(param_1 + 0x54),*(u16 *)(param_1 + 0xe),param_2,
                       param_3);
  if (iVar1 < 0) {
    *(u16 *)(param_1 + 0xc) = *(u16 *)(param_1 + 0xc) & 0xefff;
  }
  else {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + iVar1;
  }
  return;
}

void func_00304ec8(int param_1,u64 param_2,u64 param_3)

{
  s64 lVar1;
  u16 uVar2;
  
  lVar1 = func_00305110(*(u32 *)(param_1 + 0x54),*(u16 *)(param_1 + 0xe),param_2,
                       param_3);
  if (lVar1 == -1) {
    uVar2 = *(u16 *)(param_1 + 0xc) & 0xefff;
  }
  else {
    *(int *)(param_1 + 0x50) = (int)lVar1;
    uVar2 = *(u16 *)(param_1 + 0xc) | 0x1000;
  }
  *(u16 *)(param_1 + 0xc) = uVar2;
  return;
}

u32 func_00305ce0(void)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_00316d08();
  *puVar1 = 5;
  return 0xffffffff;
}

u64 func_00305df8(int param_1,u64 param_2)

{
  if (param_1 == 1) {
    func_0030f468(param_2);
  }
  return 0;
}

u32 func_00305e20(void)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_00316d08();
  *puVar1 = 5;
  return 0xffffffff;
}

u32 func_00305e48(void)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_00316d08();
  *puVar1 = 5;
  return 0xffffffff;
}

u32 func_00307f40(u64 param_1,u64 param_2,s64 param_3)

{
  if (param_3 != 0) {
    func_00306e80();
  }
  return 1;
}

void func_00307f90(u64 param_1,u64 param_2,int *param_3,u64 param_4,
                 u64 param_5,u64 param_6,u64 param_7,u64 param_8)

{
  int iVar1;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  iVar1 = func_003071d0(param_1,param_2,*param_3,param_4,&uStack_20);
  *param_3 = *param_3 - iVar1;
  return;
}

void func_00307fe0(u32 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u32 auStack_20 [4];
  
  auStack_20[0] = param_1;
  func_003071d0(0x307ee8,auStack_20,param_2,param_3,param_4);
  return;
}

void func_00308018(u32 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6,u64 param_7,u64 param_8)

{
  u32 auStack_90 [4];
  u64 uStack_28;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  auStack_90[0] = param_1;
  uStack_28 = param_4;
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  func_003071d0(0x307ee8,auStack_90,param_2,param_3,&uStack_28);
  return;
}

void func_00308060(u64 param_1,u64 param_2)

{
  s64 lVar1;
  u32 auStack_50 [4];
  
  auStack_50[0] = 0;
  lVar1 = func_0030edb0();
  func_003071d0(0x307f40,auStack_50,0xffffffffffffffff,param_1,param_2);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return;
}

void func_00308150(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6,u64 param_7,u64 param_8)

{
  s64 lVar1;
  u32 auStack_c0 [4];
  u64 uStack_38;
  u64 uStack_30;
  u64 uStack_28;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  auStack_c0[0] = 0;
  uStack_38 = param_2;
  uStack_30 = param_3;
  uStack_28 = param_4;
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  lVar1 = func_0030edb0();
  func_003071d0(0x307f68,auStack_c0,0xffffffffffffffff,param_1,&uStack_38);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return;
}

int func_00308df0(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x20) <= param_2)) {
    iVar1 = func_00308dc0();
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + param_2 * 0x40;
  }
  return iVar1;
}

int func_00309988(int param_1)

{
  int iVar1;
  u32 uVar2;
  
  func_0030edb0();
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    *(u32 *)(param_1 + 4) = 0;
  }
  else {
    uVar2 = *(u32 *)(iVar1 + 0x3c);
    *(u32 *)(param_1 + 4) = 1;
    *(u32 *)(param_1 + 0xc) = uVar2;
  }
  func_0030ee00();
  return iVar1;
}

u64 func_00310048(void)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_0030ffd8();
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}
