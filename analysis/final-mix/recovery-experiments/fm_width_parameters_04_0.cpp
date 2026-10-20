#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001805a8(...);
extern "C" bool func_00180cd0(...);
extern "C" bool func_00187e20(...);
extern "C" bool func_00187e58(...);
extern "C" bool func_00197c28(...);
extern "C" bool func_0019a9e0(...);
extern "C" bool func_0019f060(...);
extern "C" bool func_001c0cd8(...);
extern "C" f32 func_0018a970(...);
extern "C" s32 func_00168b88(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_0017ec98(...);
extern "C" s32 func_001801b0(...);
extern "C" s32 func_001947c0(...);
extern "C" s32 func_0019ad58(...);
extern "C" s32 func_0019b260(...);
extern "C" s32 func_001a6a20(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_002fd248(...);
extern "C" s64 func_0017edf0(...);
extern "C" u32 func_00158f90(...);
extern "C" u32 func_00169f98(...);
extern "C" u32 func_0016a9b8(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_0017f380(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_00186378(...);
extern "C" u32 func_001863a8(...);
extern "C" u32 func_00186740(...);
extern "C" u32 func_00187018(...);
extern "C" u32 func_00187ab8(...);
extern "C" u32 func_00187b90(...);
extern "C" u32 func_0018c8b8(...);
extern "C" u32 func_0018c960(...);
extern "C" u32 func_0018eb98(...);
extern "C" u32 func_0018ee10(...);
extern "C" u32 func_001902a8(...);
extern "C" u32 func_001903d0(...);
extern "C" u32 func_00192800(...);
extern "C" u32 func_00192868(...);
extern "C" u32 func_00195430(...);
extern "C" u32 func_00195700(...);
extern "C" u32 func_00196e88(...);
extern "C" u32 func_00197930(...);
extern "C" u32 func_00198660(...);
extern "C" u32 func_00198bd0(...);
extern "C" u32 func_00198ee8(...);
extern "C" u32 func_00199810(...);
extern "C" u32 func_0019ab80(...);
extern "C" u32 func_0019ad00(...);
extern "C" u32 func_0019ae60(...);
extern "C" u32 func_0019ef70(...);
extern "C" u32 func_0019f070(...);
extern "C" u32 func_001a49a0(...);
extern "C" u32 func_001a4d40(...);
extern "C" u32 func_001ad990(...);
extern "C" u32 func_001b50e0(...);
extern "C" u32 func_001b58f0(...);
extern "C" u32 func_001ce2d8(...);
extern "C" u32 func_001ce328(...);
extern "C" u32 func_001d30f8(...);
extern "C" u32 func_001d5770(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_001dc670(...);
extern "C" u32 func_001dc920(...);
extern "C" u32 func_001dcb98(...);
extern "C" u32 func_0031cc28(...);
extern "C" u64 func_001de168(...);
extern "C" u8 func_00227118(...);

void func_00180378(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u32 uVar1;
  u64 uVar2;
  int iVar3;
  u32 *puVar4;
  
  iVar3 = (int)param_3;
  func_0017f380(iVar3 + 0x140);
  uVar2 = func_0017ec98(param_2,param_4);
  uVar2 = func_0017edf0(param_2,uVar2);
  puVar4 = (u32 *)param_2;
  func_001801b0(param_1,puVar4[2],uVar2,puVar4[0x3c],param_3,puVar4[2] + 0x488);
  uVar1 = *puVar4;
  *(int *)(iVar3 + 0x154) = (int)param_4;
  *(u32 *)(iVar3 + 0x240) = uVar1;
  return;
}

void func_001843d8(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  iVar3 = iVar2 + 0x140;
  if (((*(u32 *)(iVar2 + 0x168) & 0x10) == 0) && (lVar1 = func_001805a8(iVar3,5), lVar1 != 0)) {
    func_0017f488(0,0,iVar3,5);
    func_0017f5e0(0,0,iVar3,0,0);
  }
  func_0016bd60(param_1,0);
  *(u32 *)(iVar2 + 0x108) = *(u32 *)(iVar2 + 0x108) | 0x8000000;
  return;
}

void func_001882a8(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 auStack_2c [3];
  
  iVar2 = (int)param_1;
  lVar1 = func_00187ab8(*(u32 *)(iVar2 + 0x8c));
  if (lVar1 != 0) {
    func_00187b90(param_1);
    iVar3 = *(int *)(iVar2 + 4) + 0xf;
    auStack_2c[0] = 0;
    iVar4 = *(int *)(iVar2 + 4) + 0x1e;
    if (-1 < iVar3) {
      iVar4 = iVar3;
    }
    iVar3 = iVar3 + (iVar4 >> 4) * -0x10;
    *(int *)(iVar2 + 4) = iVar3;
    iVar4 = iVar2 + iVar3 * 8;
    func_0031cc28(auStack_2c);
    *(int *)(iVar4 + 8) = (int)lVar1;
    *(u32 *)(iVar4 + 0xc) = auStack_2c[0];
    *(u32 *)(iVar2 + 0x98) = 0;
  }
  return;
}

u32 func_00188758(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  
  iVar2 = (int)param_1;
  uVar3 = 0;
  if ((*(int *)(iVar2 + 0x8c) != 0) && (uVar3 = 0, (*(u32 *)(iVar2 + 0x9c) & 1) == 0)) {
    lVar1 = func_00187e20();
    uVar3 = 0;
    if (lVar1 == 0) {
      if (*(int *)(iVar2 + 0x98) < 300) {
        lVar1 = func_00187e58(param_1);
        uVar3 = 0;
        if (lVar1 == 0) {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

u64 func_0018c8f0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u64 uVar1;
  
  uVar1 = func_0018c8b8();
  func_0018c960(uVar1,param_1,param_2,param_3,param_4);
  return uVar1;
}

u64 func_0018d808(u32 param_1,int param_2)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 *puVar5;
  
  puVar1 = (u32 *)func_0016c028(*(u32 *)(param_2 + 8));
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  puVar5 = (u32 *)param_1;
  *puVar5 = *puVar1;
  puVar5[1] = uVar2;
  puVar5[2] = uVar3;
  puVar5[3] = uVar4;
  return param_1;
}

u32 func_0018eaf8(int *param_1,int *param_2)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  func_0018eb98();
  iVar1 = *param_1;
  uVar2 = 0;
  if (iVar1 < 0x100) {
    *param_1 = iVar1 + 1;
    param_1[iVar1 * 0xc + 4] = *param_2;
    iVar3 = param_2[4];
    iVar5 = param_2[5];
    iVar4 = param_2[6];
    param_1[iVar1 * 0xc + 0xb] = param_2[7];
    param_1[iVar1 * 0xc + 8] = iVar3;
    param_1[iVar1 * 0xc + 9] = iVar5;
    param_1[iVar1 * 0xc + 10] = iVar4;
    if (param_1 + iVar1 * 0xc + 0xc != param_2 + 8) {
      iVar3 = param_2[9];
      iVar4 = param_2[10];
      iVar5 = param_2[0xb];
      param_1[iVar1 * 0xc + 0xc] = param_2[8];
      param_1[iVar1 * 0xc + 0xd] = iVar3;
      param_1[iVar1 * 0xc + 0xe] = iVar4;
      param_1[iVar1 * 0xc + 0xf] = iVar5;
    }
    uVar2 = 1;
  }
  return uVar2;
}

void func_0018ef98(int param_1,u32 param_2)

{
  s64 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_0018ee10(lVar1), lVar1 != 0) {
    if (*(int *)((int)lVar1 + 0xc) == param_1) {
      *(u32 *)((int)lVar1 + 0xc) = param_2;
    }
  }
  return;
}

void func_0018f248(int *param_1)

{
  func_00186740(param_1[4],param_1[5],*(u32 *)(*param_1 + 4),param_1[1],param_1[2],param_1[3])
  ;
  return;
}

void func_0018f2a8(int *param_1)

{
  func_001863a8(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_0018f2d0(int *param_1)

{
  func_00186378(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_0018f9b8(u32 *param_1)

{
  func_001a4d40(param_1[3],param_1[4],*param_1,param_1[1],param_1[2]);
  return;
}

void func_0018fb70(u32 *param_1)

{
  func_001a49a0(*param_1,param_1[1],param_1[2]);
  return;
}

void func_0018fd10(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001a6a20(*param_1,param_1[1]);
  *param_1 = uVar1;
  return;
}

void func_0018fd40(u32 *param_1)

{
  func_00187018(param_1[4],*param_1,param_1[1],param_1[2],param_1[3]);
  return;
}

void func_0018fde0(u32 *param_1)

{
  func_001b50e0(param_1[2],*param_1,param_1[1],param_1[3] != 0);
  return;
}

void func_0018fe48(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001b58f0(*param_1,param_1[1],param_1[2],0);
  *param_1 = uVar1;
  return;
}

void func_0018fe80(u32 *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  s64 lVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  lVar3 = func_001b58f0(*param_1,param_1[1],param_1[3],0);
  if (lVar3 != 0) {
    puVar2 = (u32 *)func_001dc5f8(lVar3);
    puVar1 = (u32 *)param_1[2];
    if (puVar2 == puVar1) {
      *param_1 = (int)lVar3;
      return;
    }
    uVar4 = puVar1[1];
    uVar5 = puVar1[2];
    uVar6 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar4;
    puVar2[2] = uVar5;
    puVar2[3] = uVar6;
  }
  *param_1 = (int)lVar3;
  return;
}

void func_0018fee8(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001b58f0(*param_1,param_1[1],param_1[3],*(u32 *)(param_1[2] + 4));
  *param_1 = uVar1;
  return;
}

u64 func_00190388(u32 param_1,u32 param_2)

{
  u32 *puVar1;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  func_001902a8(param_2,auStack_40);
  puVar1 = (u32 *)param_1;
  *puVar1 = uStack_30;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1[3] = uStack_24;
  return param_1;
}

u64 func_001904a8(u32 param_1,u32 param_2)

{
  u32 *puVar1;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  func_001903d0(param_2,auStack_40);
  puVar1 = (u32 *)param_1;
  *puVar1 = uStack_30;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1[3] = uStack_24;
  return param_1;
}

void func_001906f0(u32 param_1,u32 *param_2)

{
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_34 = 0;
  func_001902a8(param_1,auStack_40);
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0018a970(auStack_40);
  return;
}

int func_00191f20(int param_1,u32 param_2)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_002fd248(param_2 & 0xffffffffffff7fff,param_1 + 8,*(u32 *)(param_1 + 4),8,
                       0x31eec8);
  iVar2 = 0;
  if (lVar1 != 0) {
    iVar2 = param_1 + *(int *)((int)lVar1 + 4);
  }
  return iVar2;
}

void func_00192818(u32 param_1,u32 param_2,u32 *param_3)

{
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_1c = param_3[5];
  uStack_2c = param_3[1];
  uStack_28 = param_3[2];
  uStack_24 = param_3[3];
  uStack_20 = param_3[4];
  uStack_30 = *param_3;
  func_00192800(param_1,param_2,&uStack_30);
  return;
}

void func_00192940(u32 param_1,u32 param_2,u32 *param_3)

{
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_1c = param_3[5];
  uStack_2c = param_3[1];
  uStack_28 = param_3[2];
  uStack_24 = param_3[3];
  uStack_20 = param_3[4];
  uStack_30 = *param_3;
  func_00192868(param_1,param_2,&uStack_30);
  return;
}

void func_001940b8(u32 param_1,u32 param_2,int param_3,u8 param_4,
                 u8 param_5,u8 param_6)

{
  *(u8 *)(param_3 + 0x680) = param_4;
  *(u8 *)(param_3 + 0x681) = param_5;
  *(u8 *)(param_3 + 0x682) = param_6;
  func_001ad990(*(u32 *)(param_3 + 0x8c0),param_1,param_2,param_3 + 0x8c0);
  return;
}

void func_00194218(float param_1,u32 param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = param_3 * 4 + (int)param_2;
  if (0.0 < param_1) {
    if (*(int *)(iVar2 + 0x7b8) == 0) {
      uVar1 = func_001de168((int)param_2 + 0x9c,param_3,0,1,0,param_2);
      *(u32 *)(iVar2 + 0x7b8) = uVar1;
    }
    iVar2 = func_001dc670(*(u32 *)(iVar2 + 0x7b8));
    *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) * param_1;
  }
  else if (*(int *)(iVar2 + 0x7b8) != 0) {
    func_001dc920(*(int *)(iVar2 + 0x7b8));
    *(u32 *)(iVar2 + 0x7b8) = 0;
  }
  return;
}

void func_001942b8(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 0x7b8);
  iVar3 = 0xf;
  iVar1 = *piVar2;
  while( true ) {
    piVar2 = piVar2 + 1;
    if (iVar1 != 0) {
      func_001dcb98(iVar1,param_1 + 0x758);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar1 = *piVar2;
  }
  return;
}

u64 func_001943e8(u32 param_1)

{
  s64 lVar1;
  u64 uVar2;
  int iVar3;
  float *pfVar4;
  u64 uVar5;
  float fVar6;
  
  pfVar4 = (float *)((int)param_1 + 0x30);
  iVar3 = 2;
  uVar5 = 0;
  fVar6 = *pfVar4;
  while( true ) {
    pfVar4 = pfVar4 + 1;
    if (fVar6 < 0.0) {
      uVar5 = uVar5 ^ 1;
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    fVar6 = *pfVar4;
  }
  lVar1 = func_001c0cd8(param_1);
  if (lVar1 != 0) {
    uVar2 = func_001943e8(*(u32 *)((int)param_1 + 0x570));
    uVar5 = (u64)(uVar5 != uVar2);
  }
  return uVar5;
}

bool func_00194830(u32 param_1,u32 param_2,u32 param_3)

{
  bool bVar1;
  s64 lVar2;
  
  lVar2 = func_001947c0();
  if (lVar2 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = (*(u32 *)lVar2 & 1 << (param_3 & 0x1f)) != 0;
  }
  return bVar1;
}

void func_00195558(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  do {
    func_00195430(iVar1);
    iVar1 = iVar1 + 0x208;
  } while (iVar1 < param_1 + 0x820);
  *(u32 *)(param_1 + 0x824) = 0;
  return;
}

void func_00195858(u32 *param_1,u32 param_2)

{
  u32 *puVar1;
  u32 uVar2;
  
  uVar2 = func_001ce328(param_2);
  param_1[7] = uVar2;
  uVar2 = func_001ce2d8(param_2);
  param_1[8] = uVar2;
  puVar1 = (u32 *)param_1[7];
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  param_1[5] = puVar1[8];
  param_1[6] = puVar1[10];
  return;
}

void func_00195c58(u32 param_1,int param_2)

{
  if ((*(u32 *)(param_2 + 0x588) & 0x80) != 0) {
    func_00158f90();
    return;
  }
  return;
}

void func_00196e98(int param_1,s32 param_2)

{
  s64 lVar1;
  u32 uVar2;
  
  if (param_2 != 0) {
    lVar1 = func_00227118(*(u32 *)(param_1 + 4));
    uVar2 = 3;
    if (lVar1 != 2) {
      uVar2 = 2;
    }
    func_001d30f8(param_1 + 0x40,uVar2,param_2);
    return;
  }
  return;
}

void func_00197318(u32 param_1)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar3;
  
  func_00170320(2000);
  puVar3 = (u32 *)param_1;
  uVar1 = *puVar3;
  uVar2 = 3;
  *puVar3 = uVar1 | 1;
  if ((*(u16 *)(puVar3[0xf] + 2) >> 1 & 1) == 0) {
    *puVar3 = uVar1 | 3;
    uVar2 = 4;
  }
  func_00196e88(0,param_1,uVar2,0);
  return;
}

void func_00197390(u32 param_1)

{
  s64 lVar1;
  u32 *puVar2;
  
  lVar1 = func_00197c28();
  puVar2 = (u32 *)param_1;
  if (lVar1 != 0) {
    puVar2[0xd] = 1;
    return;
  }
  *puVar2 = *puVar2 | 2;
  func_00196e88(0,param_1,4,0);
  return;
}

void func_001973f0(int param_1)

{
  u64 uVar1;
  
  if ((*(u16 *)(*(int *)(param_1 + 0x3c) + 2) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  func_00196e88(0,param_1,6,uVar1);
  return;
}

void func_00198450(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  
  iVar2 = (int)param_1 + 0x140;
  lVar1 = func_00180cd0(iVar2);
  if ((lVar1 != 0) && (lVar1 = func_001805a8(iVar2,0), lVar1 != 0)) {
    func_0017f488(0,0,iVar2,0);
  }
  func_00169f98(param_1);
  return;
}

void func_00198690(u32 param_1)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  func_00198660();
  puVar1 = (u32 *)func_0016c028(param_1);
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  iVar2 = (int)param_1 + 0x9dc;
  iVar3 = 1;
  do {
    func_001d5770(iVar2,&uStack_30);
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 0xc;
  } while (-1 < iVar3);
  func_0016a9b8(param_1);
  return;
}

void func_00198700(s32 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 1) == 0);
  return;
}

u32 func_00198738(int param_1,char *param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  if (*(int *)(param_1 + 0x7b0) == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = func_00168b88(*(int *)(param_1 + 0x7b0),0x16,
                         (s64)*param_2 | (s64)((int)param_2[3] << 0x18) |
                         (s64)((int)param_2[2] << 0x10 | (int)param_2[1] << 8),0);
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(u32 *)((int)lVar2 + 8);
    }
  }
  return uVar1;
}

void func_00198dc0(u32 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffff;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0;
  param_1[7] = 0;
  *(u16 *)((int)param_1 + 0x2e) = 0;
  *(u8 *)(param_1 + 0xc) = 0;
  *(u8 *)(param_1 + 0xe) = 0xff;
  *(u8 *)((int)param_1 + 0x3a) = 0xff;
  *(u8 *)((int)param_1 + 0x39) = 0xff;
  *(u16 *)(param_1 + 0x10) = 0xffff;
  *(u16 *)(param_1 + 0xf) = 0xffff;
  *(u16 *)((int)param_1 + 0x3e) = 0xffff;
  func_0031cc28(param_1 + 0x15);
  func_0019ef70(param_1 + 0xd);
  return;
}

u64 func_00199030(int param_1)

{
  u64 uVar1;
  
  if (*(char *)(param_1 + 0x30) == '\0') {
    if (*(int *)(param_1 + 0x10) == 0) {
      func_0019f070(param_1 + 0x34,0);
      uVar1 = func_0019f060(param_1 + 0x34);
      return uVar1;
    }
    func_00197930(*(int *)(param_1 + 0x10),*(u32 *)(param_1 + 0x14),param_1 + 0x34);
  }
  return 1;
}

u64 * func_00199098(u64 *param_1,u32 param_2)

{
  u64 uVar1;
  u64 uVar2;
  u64 *puVar3;
  u64 *puVar4;
  
  uVar1 = func_00198bd0(param_2,0xffffffffffffffff);
  func_00198ee8(uVar1);
  puVar4 = (u64 *)((int)uVar1 + 0x34);
  puVar3 = param_1;
  do {
    uVar2 = puVar4[1];
    *puVar3 = *puVar4;
    puVar3[1] = uVar2;
    puVar4 = puVar4 + 2;
    puVar3 = puVar3 + 2;
  } while (puVar4 != (u64 *)((int)uVar1 + 0x54));
  *(u32 *)puVar3 = *(u32 *)puVar4;
  return param_1;
}

void func_00199d38(int param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (*(short *)(iVar2 + 4) != 0) {
    iVar3 = 0;
    do {
      iVar4 = iVar4 + 1;
      lVar1 = func_00199810(iVar2 + iVar3 + 0x2c);
      if (lVar1 != 0) {
        func_0016ed50(*(u32 *)(iVar3 + *(int *)(param_1 + 8) + 0x2c),0xffffffffffffffff,0x1e);
      }
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = iVar4 * 0x40;
    } while (iVar4 < (int)(u32)*(u16 *)(iVar2 + 4));
  }
  return;
}

void func_0019aa00(u32 param_1,int param_2)

{
  s64 lVar1;
  
  if ((((*(u32 *)((int)param_1 + 4) & 1) == 0) && ((*(u32 *)(param_2 + 0x588) & 0x800) != 0)) &&
     (lVar1 = func_0019a9e0(), lVar1 == 0)) {
    func_0019ab80(param_1);
    return;
  }
  return;
}

bool func_0019ab30(int param_1)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_00195700(0x34f250);
  if (lVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x18) = iVar2;
    *(int *)(param_1 + 0x1c) = iVar2;
  }
  return lVar1 == 0;
}

u32 func_0019ac80(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((*(u8 *)(iVar2 + 0x20) < 200) &&
     (lVar1 = func_0019ad58(), lVar1 <= (s64)(u64)*(u8 *)(*(int *)(iVar2 + 8) + 0x22))) {
    do {
      func_0019ae60(param_1);
      lVar1 = func_0019ad00(param_1,*(u8 *)(iVar2 + 0x20));
      if (lVar1 != 0) {
        return 1;
      }
    } while (*(u8 *)(iVar2 + 0x20) < 200);
  }
  return 0;
}

void func_0019b2d8(void)

{
  int iVar1;
  
  iVar1 = func_0019b260();
  *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) & 0xfffffffe;
  return;
}

bool func_0019bad8(int param_1)

{
  bool bVar1;
  s64 lVar2;
  
  bVar1 = false;
  if (((*(u32 *)(param_1 + 0x7f8) & 1) != 0) && ((*(u32 *)(param_1 + 0x108) & 1) == 0)) {
    lVar2 = func_001c0cd8();
    bVar1 = lVar2 == 0;
  }
  return bVar1;
}
