#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102080(...);
extern "C" u64 func_00102210(...);
extern "C" u64 func_001031b0(...);
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00105c30(...);
extern "C" u64 func_00106450(...);
extern "C" u64 func_0010c7b0(...);
extern "C" u64 func_0010c7e8(...);
extern "C" u64 func_0010fa28(...);
extern "C" u64 func_0010fa58(...);
extern "C" u64 func_00110500(...);
extern "C" u64 func_00110618(...);
extern "C" u64 func_00114438(...);
extern "C" u64 func_00117808(...);
extern "C" u64 func_00117aa8(...);
extern "C" u64 func_00118d10(...);
extern "C" u64 func_00119830(...);
extern "C" u64 func_00119e60(...);
extern "C" u64 func_0011a408(...);
extern "C" u64 func_0011a918(...);
extern "C" u64 func_0011a938(...);
extern "C" u64 func_0011cdf0(...);
extern "C" u64 func_00136158(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c568(...);
extern "C" u64 func_0016e920(...);
extern "C" u64 func_00176fb0(...);
extern "C" u64 func_00177008(...);
extern "C" u64 func_0017c030(...);
extern "C" u64 func_0017c430(...);
extern "C" u64 func_0017c4c8(...);
extern "C" u64 func_0017f488(...);
extern "C" u64 func_0017f5e0(...);
extern "C" u64 func_0017f5f8(...);
extern "C" u64 func_00180c88(...);
extern "C" u64 func_0018a008(...);
extern "C" u64 func_00190128(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_001906f0(...);
extern "C" u64 func_0019bc38(...);
extern "C" u64 func_001b2210(...);
extern "C" u64 func_001b8228(...);
extern "C" u64 func_001b8258(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_0023a918(...);
extern "C" u64 func_0023cc18(...);
extern "C" u64 func_002bc1e8(...);
extern "C" u64 func_002e7670(...);
extern "C" u64 func_002e76b0(...);
extern "C" u64 func_002e77a8(...);
extern "C" u64 func_002e95a0(...);
extern "C" u64 func_002e9610(...);
extern "C" u64 func_002e9cb8(...);
extern "C" u64 func_002e9d08(...);
extern "C" u64 func_002e9fe0(...);
extern "C" u64 func_002eac70(...);
extern "C" u64 func_002eaf40(...);
extern "C" u64 func_002eb990(...);
extern "C" u64 func_002ed300(...);
extern "C" u64 func_002ee730(...);
extern "C" u64 func_002ee840(...);
extern "C" u64 func_002ef618(...);
extern "C" u64 func_002ef7b8(...);
extern "C" u64 func_002efa98(...);
extern "C" u64 func_002efb08(...);
extern "C" u64 func_002f25a0(...);
extern "C" u64 func_002f3500(...);
extern "C" u64 func_002f3c28(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002f40a0(...);
extern "C" u64 func_002f4148(...);
extern "C" u64 func_002f41f0(...);
extern "C" u64 func_002ff014(...);
extern "C" u64 func_002ffbb0(...);
extern "C" u64 func_002ffd78(...);
extern "C" u64 func_003032d0(...);
extern "C" u64 func_00305110(...);
extern "C" u64 func_00305168(...);
extern "C" u64 func_00306e48(...);
extern "C" u64 func_00306e80(...);
extern "C" u64 func_003071d0(...);
extern "C" u64 func_003080d0(...);
extern "C" u64 func_00308780(...);
extern "C" u64 func_00308dc0(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_0030f468(...);
extern "C" u64 func_0030ffd8(...);
extern "C" u64 func_00310090(...);
extern "C" u64 func_00310180(...);
extern "C" u64 func_00310230(...);
extern "C" u64 func_00310330(...);
extern "C" u64 func_00316d08(...);

void func_002e7058(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    iVar3 = iVar2 + *(int *)(iVar2 + -4) * 0x40;
    do {
      bVar1 = iVar2 != iVar3;
      iVar3 = iVar3 + -0x40;
    } while (bVar1);
    func_00106450(iVar2 + -0x10);
    return;
  }
  return;
}

void func_002e70b0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    iVar3 = iVar2 + *(int *)(iVar2 + -4) * 0x40;
    do {
      bVar1 = iVar2 != iVar3;
      iVar3 = iVar3 + -0x40;
    } while (bVar1);
    func_00106450(iVar2 + -0x10);
    return;
  }
  return;
}

void func_002e76c8(u8 *param_1)

{
  int iVar1;
  u8 *puVar2;
  
  param_1[1] = 0;
  param_1[0x8c] = 1;
  *param_1 = 1;
  iVar1 = 0xf;
  param_1[2] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 1;
  puVar2 = param_1;
  do {
    puVar2[0x9a] = 0;
    iVar1 = iVar1 + -1;
    puVar2[0xaa] = 0;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  param_1 = param_1 + 0xba;
  iVar1 = 0x7f;
  do {
    *param_1 = 0;
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 1;
  } while (-1 < iVar1);
  return;
}

void func_002e7738(u64 param_1)

{
  func_002e7670();
  func_002e76b0((int)param_1 + 4);
  func_002e77a8(param_1);
  return;
}

void func_002e7768(u64 param_1)

{
  func_002e7670();
  func_002e76b0((int)param_1 + 4);
  func_002e77a8(param_1);
  return;
}

void func_002e7b88(u32 *param_1)

{
  func_002eac70(*param_1,param_1[1],param_1[2],param_1[3]);
  return;
}

void func_002e7c18(u32 *param_1)

{
  u64 *puVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u64 *)param_1[3];
  uStack_28 = *(u32 *)(puVar1 + 1);
  uStack_24 = *(u32 *)((int)puVar1 + 0xc);
  uStack_30 = (u32)*puVar1;
  uStack_2c = (u32)((u64)*puVar1 >> 0x20);
  puVar1 = (u64 *)param_1[2];
  uStack_18 = *(u32 *)(puVar1 + 1);
  uStack_14 = *(u32 *)((int)puVar1 + 0xc);
  uStack_20 = (u32)*puVar1;
  uStack_1c = (u32)((u64)*puVar1 >> 0x20);
  func_002e9d08(*param_1,param_1[1],&uStack_20,&uStack_30,param_1[4] != 0,param_1[5] != 0,
               param_1[6] != 0);
  return;
}

void func_002e7c78(int *param_1)

{
  func_0016c568(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_002e7f80(u32 *param_1)

{
  u64 *puVar1;
  u32 uVar2;
  u8 auStack_60 [32];
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  func_00190128(auStack_60);
  puVar1 = (u64 *)param_1[2];
  uVar2 = *param_1;
  uStack_38 = *(u32 *)(puVar1 + 1);
  uStack_34 = *(u32 *)((int)puVar1 + 0xc);
  uStack_40 = (u32)*puVar1;
  uStack_3c = (u32)((u64)*puVar1 >> 0x20);
  puVar1 = (u64 *)param_1[1];
  uStack_28 = *(u32 *)(puVar1 + 1);
  uStack_24 = *(u32 *)((int)puVar1 + 0xc);
  uStack_30 = (u32)*puVar1;
  uStack_2c = (u32)((u64)*puVar1 >> 0x20);
  func_002e9d08(uVar2,auStack_60,&uStack_30,&uStack_40,1,param_1[3] != 0,0);
  *param_1 = (u32)*(u8 *)(uVar2 + 5);
  return;
}

void func_002e7ff8(u32 *param_1)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)param_1[1];
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  uVar2 = func_001906f0(*param_1,&uStack_20);
  *param_1 = uVar2;
  return;
}

void func_002e8038(u32 *param_1)

{
  u32 *puVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)param_1[2];
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  func_002e9fe0(*param_1,*(u32 *)(param_1[1] + 4),&uStack_20);
  return;
}

void func_002e8070(u32 *param_1)

{
  func_002e9cb8(*param_1,param_1[1],param_1[2]);
  return;
}

void func_002e8220(int *param_1)

{
  func_002eb990(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_002e8390(int *param_1)

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
  func_001b2210(param_1[2],param_1[3],*(u32 *)(*param_1 + 4),&uStack_20);
  func_0016bd60(*(u32 *)(*param_1 + 4),9);
  return;
}

void func_002e8770(int *param_1)

{
  int iVar1;
  u64 uVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if ((*(u32 *)(iVar1 + 0x588) & 0x80) != 0) {
    iVar3 = *(int *)(iVar1 + 0xb40) + 4;
    func_00190140(iVar3);
    uVar2 = func_00176fb0(iVar1,param_1[1]);
    func_00177008(iVar1,uVar2,iVar3);
  }
  return;
}

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

void func_002e9b10(int *param_1)

{
  u8 bVar1;
  
  bVar1 = (char)param_1[1] + 1;
  *(u8 *)(param_1 + 1) = bVar1;
  if (*param_1 <= (int)(u32)bVar1) {
    do {
      bVar1 = bVar1 - (char)*param_1;
    } while (*param_1 <= (int)(u32)bVar1);
    *(u8 *)(param_1 + 1) = bVar1;
  }
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

void func_002e9fb8(int param_1,char param_2)

{
  *(u32 *)(param_1 + 4) = *(u32 *)(param_1 + 4) & 0xfffeffff | (u32)(param_2 != '\0') << 0x10;
  return;
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

void func_002eaaf0(u64 param_1)

{
  func_0017c430();
  func_0016bd60(param_1,0x2c);
  return;
}

u32 func_002eb068(int param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 4);
  uVar2 = 0;
  if ((iVar1 == 0x3d) || (iVar1 == 0x33)) {
    uVar2 = 1;
  }
  return uVar2;
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

void func_002eb4b0(u64 param_1)

{
  func_0017c430();
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

void func_002ed438(void)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar1 = func_001050d8(0xa00);
  uVar2 = func_0016e920(0x5c3);
  func_002ed300(uVar1,uVar2,0x100);
  return;
}

void func_002ed508(u64 param_1,int param_2,u32 param_3,u64 param_4,
                 u64 param_5)

{
  int iVar1;
  
  func_001c1748(param_1,*(u32 *)(param_2 + 0x9f4),param_4,param_5);
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x50) = param_3;
  func_00190128(iVar1 + 100);
  *(u32 *)(iVar1 + 0x78) = 0;
  return;
}

void func_002ed558(u64 param_1,int param_2,u32 param_3,u64 param_4,
                 u64 param_5)

{
  int iVar1;
  
  func_001c1748(param_1,*(u32 *)(param_2 + 0x9f4),param_4,param_5);
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x50) = param_3;
  func_00190128(iVar1 + 100);
  *(u32 *)(iVar1 + 0x78) = 0;
  return;
}

void func_002ee778(u64 param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_00102210();
  *(u32 *)((int)param_1 + 0x2c) = uVar1;
  func_00102080(param_1);
  iVar2 = func_002ee840();
  uVar1 = func_001031b0();
  *(u32 *)(iVar2 + 4) = uVar1;
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

void func_002ef7c8(void)

{
  s64 lVar1;
  
  lVar1 = func_002ef7b8();
  if (lVar1 != 0) {
    func_001b8228();
    return;
  }
  func_001b8258();
  return;
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

void func_002efb60(u64 param_1)

{
  func_002efb08();
  func_002efa98(param_1);
  return;
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

void func_002f05d8(u64 param_1)

{
  func_0017c430();
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

void func_002f0708(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00117808(uVar1,param_1[1]);
  return;
}

void func_002f08d8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00119e60(uVar1,param_1[1]);
  return;
}

void func_002f0948(int *param_1)

{
  func_0016c568(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_002f09d8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00119830(uVar1,param_1[1]);
  return;
}

void func_002f0a38(int *param_1)

{
  func_0017f5f8(param_1[2],0,*param_1 + 0x140,param_1[1],0);
  return;
}

void func_002f0a68(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00117aa8(uVar1,param_1[1]);
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

void func_002f0c58(int *param_1)

{
  u64 uVar1;
  int iVar2;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  iVar2 = func_0011a408(uVar1);
  *param_1 = iVar2;
  return;
}

void func_002f0da8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00118d10(uVar1,param_1[1]);
  return;
}

void func_002f0e60(int *param_1)

{
  u64 uVar1;
  int iVar2;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  iVar2 = func_00114438(uVar1,param_1[1]);
  *param_1 = iVar2;
  return;
}

void func_002f10c0(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_0011a938(param_1[2],param_1[3],uVar1,param_1[1]);
  return;
}

void func_002f1130(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7b0(*(u32 *)(*param_1 + 4));
  func_00136158(uVar1,param_1[1]);
  return;
}

void func_002f1230(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_0011a918(uVar1,param_1[1]);
  return;
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

u32 func_002f3588(u32 param_1)

{
  if (param_1 >> 0x1c == 7) {
    param_1 = param_1 & 0xfffffff | 0x80000000;
  }
  return param_1;
}

void func_002f35b0(u8 *param_1,s64 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2 + -1;
  if (param_2 != 0) {
    do {
      *param_1 = 0;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}

bool func_002f3bf0(int param_1,u32 param_2,int param_3,u64 param_4)

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

u64 func_002f83f0(u64 param_1)

{
  return param_1 & 0xffffffff | ((s64)param_1 >> 0x20 & 0x7fffffffU) << 0x20;
}

u32 func_002fb900(u32 param_1,u32 param_2)

{
  return param_1 & 0x7fffffff | param_2 & 0x80000000;
}

u32 func_002fd220(u64 param_1)

{
  u32 uVar1;
  
  uVar1 = func_002ffbb0(param_1,0,10);
  return uVar1;
}

s64 func_002ff8b0(int param_1,s64 param_2)

{
  s64 lVar1;
  s64 lVar2;
  
  lVar2 = 0;
  if (param_2 == 0) {
    lVar2 = func_002ff014();
  }
  else {
    while (lVar1 = func_002ff014(param_1,param_2), lVar1 != 0) {
      param_1 = (int)lVar1 + 1;
      lVar2 = lVar1;
    }
  }
  return lVar2;
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

void func_003015a8(u32 param_1,u8 *param_2)

{
  u8 *apuStack_70 [2];
  u32 uStack_68;
  u16 uStack_64;
  u8 *puStack_60;
  u32 uStack_5c;
  u32 uStack_1c;
  
  uStack_5c = 0x7fffffff;
  uStack_64 = 0x208;
  uStack_68 = 0x7fffffff;
  apuStack_70[0] = param_2;
  puStack_60 = param_2;
  uStack_1c = param_1;
  func_002ffd78(param_1,apuStack_70);
  *apuStack_70[0] = 0;
  return;
}

int func_00304468(int param_1,int param_2)

{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 0x10);
  iVar4 = *(int *)(param_1 + 0x10) - iVar1;
  if (iVar4 == 0) {
    puVar3 = (u32 *)(param_1 + 0x14) + iVar1;
    puVar2 = (u32 *)(param_2 + 0x14 + iVar1 * 4);
    do {
      puVar3 = puVar3 + -1;
      puVar2 = puVar2 + -1;
      iVar1 = -1;
      if (*puVar2 <= *puVar3) {
        iVar1 = 1;
      }
      if (*puVar3 != *puVar2) {
        return iVar1;
      }
    } while ((u32 *)(param_1 + 0x14) < puVar3);
    iVar4 = 0;
  }
  return iVar4;
}

u32 func_00304db0(u64 param_1)

{
  return 0x7ff00000 -
         ((u32)((u64)param_1 >> 0x20) & 0x7fffffff | ((u32)param_1 | -(u32)param_1) >> 0x1f) >>
         0x1f;
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

void func_00306928(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3];
  param_1[1] = param_1[1] + 1;
  param_1[3] = iVar1 + 1;
  if (iVar1 + 1 == (int)param_1 + *param_1 + 0x10) {
    param_1[3] = (int)(param_1 + 4);
  }
  return;
}

void func_00306968(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[1] = param_1[1] + -1;
  param_1[2] = iVar1 + 1;
  if (iVar1 + 1 == (int)param_1 + *param_1 + 0x10) {
    param_1[2] = (int)(param_1 + 4);
  }
  return;
}

void func_00306f30(s64 param_1)

{
  if (param_1 == 10) {
    func_00306e48(0xd);
    func_00306e48(10);
    return;
  }
  func_00306e48();
  return;
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

void func_003088b8(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6)

{
  func_00308780(param_1,0,param_2,param_3,param_4,param_5,param_6);
  return;
}

void func_003088f8(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6)

{
  func_00308780(param_1,1,param_2,param_3,param_4,param_5,param_6);
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

u32 func_003096b8(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((iVar1 != 0) && (param_1[1] == *(int *)(iVar1 + 0x18))) &&
     ((*(u32 *)(iVar1 + 0x10) & 1) != 0)) {
    return 1;
  }
  return 0;
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

u64 func_00310130(u64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310090(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u64 func_003101d0(u64 param_1,u64 param_2)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310180(param_1,param_2);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u64 func_003102e0(u64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310230(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

u64 func_003103f8(u64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310330(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

s64 func_00310518(u32 param_1)

{
  int iVar1;
  
  iVar1 = (param_1 >> 10) * 0x40;
  if ((-1 < (int)param_1) && ((param_1 & 0x3ff) == *(u32 *)(iVar1 + 8))) {
    if ((*(u32 *)(iVar1 + 0xc) & 1) != 0) {
      return *(s64 *)(iVar1 + 0x10) - *(s64 *)(iVar1 + 0x18);
    }
    return 0;
  }
  return -1;
}
