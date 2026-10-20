#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0017e310(...);
extern "C" bool func_00186ce8(...);
extern "C" bool func_00186d18(s32);
extern "C" bool func_001883d8(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_0019c400(...);
extern "C" bool func_001a90a8(...);
extern "C" bool func_001dc9e0(s32);
extern "C" f32 func_0017ce10(f32);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00189068(...);
extern "C" s32 func_001a6a20(s32,s32);
extern "C" s32 func_001a8bd0(...);
extern "C" s32 func_001b7818(s32);
extern "C" s32 func_001b9bc8(s32);
extern "C" u16 func_0016a070(...);
extern "C" u32 func_00114580(void*);
extern "C" u32 func_00153e28(...);
extern "C" u32 func_00158920(s64);
extern "C" u32 func_00159130(void*);
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" u32 func_0016ae58(u32,s32);
extern "C" u32 func_0016bc20(u64,u64,u32);
extern "C" u32 func_0016bd60(u64,u64);
extern "C" u32 func_0016c460(s32,void*);
extern "C" u32 func_0016ced0(s32);
extern "C" u32 func_0016f7d0(u64,s64);
extern "C" u32 func_00176a90(s32);
extern "C" u32 func_00177498(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017ee68(...);
extern "C" u32 func_0017f268(u32,u32,u64,s64);
extern "C" u32 func_0017f380(...);
extern "C" u32 func_00180ce0(...);
extern "C" u32 func_00181a70(...);
extern "C" u32 func_00183768(...);
extern "C" u32 func_00184780(...);
extern "C" u32 func_00184a90(s32);
extern "C" u32 func_00187ab8(...);
extern "C" u32 func_00187b30(void*);
extern "C" u32 func_001880b0(...);
extern "C" u32 func_00188398(...);
extern "C" u32 func_00188470(s32,s32,s32);
extern "C" u32 func_0018a818(void*,u64,u32);
extern "C" u32 func_0018c480(s32,u8);
extern "C" u32 func_0018c490(...);
extern "C" u32 func_00190140(s32);
extern "C" u32 func_00190f80(f32,u64,u64);
extern "C" u32 func_00198630(u64,u64,u64);
extern "C" u32 func_00199468(u32,u32,u32,u32);
extern "C" u32 func_0019c5d0(...);
extern "C" u32 func_0019c6f0(u64);
extern "C" u32 func_0019ca90(u64,s64,s64);
extern "C" u32 func_0019d358(void*);
extern "C" u32 func_001a34e0(u64,s64);
extern "C" u32 func_001a3a78(void);
extern "C" u32 func_001a5880(...);
extern "C" u32 func_001a97b8(...);
extern "C" u32 func_001ad990(f32,f32,f32,void*);
extern "C" u32 func_001b1bb8(...);
extern "C" u32 func_001d6ae0(u64);
extern "C" u32 func_001d6b40(s32);
extern "C" u32 func_001dc818(s32);
extern "C" u32 func_002bc398(u64,u64);
extern "C" u32 func_002bc3f0(...);
extern "C" u32 func_002cd290(u64,u64,s32);
extern "C" u32 func_0031cc28(void*);
extern "C" u64 func_0016ac38(s64,u64,u64,u64,s64);
extern "C" u64 func_0016e920(u32);
extern "C" u64 func_0017df70(...);
extern "C" u64 func_001afe70(u64,u64,u64,void*);
extern "C" u64 func_001de168(...);
extern "C" u64 func_002bc420(...);
extern "C" u64 func_002cd1d8(...);
extern "C" u8 func_001a3570(void);

u64 func_0016be98(u64 param_1,u64 param_2)

{
  s64 lVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  u32 *puVar6;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  lVar1 = func_0016bc20(param_2,1,0xffffffffffffffff);
  puVar6 = (u32 *)param_1;
  if (lVar1 == 0) {
    iVar5 = (int)param_2;
    uVar2 = *(u32 *)(iVar5 + 0x544);
    uVar3 = *(u32 *)(iVar5 + 0x548);
    uVar4 = *(u32 *)(iVar5 + 0x54c);
    *puVar6 = *(u32 *)(iVar5 + 0x540);
    puVar6[1] = uVar2;
    puVar6[2] = uVar3;
    puVar6[3] = uVar4;
  }
  else {
    func_0018a818(auStack_40,param_2,lVar1);
    *puVar6 = uStack_30;
    puVar6[1] = uStack_2c;
    puVar6[2] = uStack_28;
    puVar6[3] = uStack_24;
  }
  return param_1;
}

void func_00173e38(int *param_1)

{
  func_00188470(param_1[2],*(int *)(*param_1 + 4) + 0x300,param_1[1]);
  return;
}

void func_00173f68(float *param_1)

{
  u32 uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  uVar1 = *(u32 *)((int)*param_1 + 4);
  fVar4 = (float)func_00184a90(uVar1);
  iVar2 = func_0016c028(uVar1);
  fVar3 = 0.0;
  if (0.0 < fVar4 - *(float *)(iVar2 + 4)) {
    fVar3 = (float)func_00184a90(uVar1);
    iVar2 = func_0016c028(uVar1);
    fVar3 = fVar3 - *(float *)(iVar2 + 4);
  }
  *param_1 = -fVar3;
  return;
}

void func_00174060(int *param_1)

{
  func_00199468(param_1[1],*(u32 *)(*param_1 + 4),param_1[2],param_1[3]);
  return;
}

void func_00174168(int *param_1)

{
  func_00183768(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_00174518(int *param_1)

{
  int iVar1;
  
  iVar1 = func_00184780(*(u32 *)(param_1[1] + 0xc),param_1[2],param_1[3],
                       *(u32 *)(*param_1 + 4));
  *param_1 = iVar1;
  return;
}

void func_00174728(int *param_1)

{
  func_001ad990(param_1[1],param_1[2],param_1[3],*(int *)(*param_1 + 4) + 0x8c8);
  return;
}

void func_00174af8(u32 *param_1)

{
  func_001b1bb8(param_1[4],*param_1,param_1[1],param_1[2],param_1[3],0x80);
  return;
}

void func_00174e10(int *param_1)

{
  u32 *puVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)*param_1;
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  func_00158920(&uStack_20);
  return;
}

u32 func_00176258(int param_1)

{
  int iVar1;
  s64 lVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_1 + 0xaf8);
  iVar4 = 0;
  iVar1 = *piVar3;
  while ((piVar3 = piVar3 + 1, iVar1 == 0 || (lVar2 = func_0019c5d0(iVar1), lVar2 != 0))) {
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return 0;
    }
    iVar1 = *piVar3;
  }
  return 1;
}

void func_00176be0(float param_1,u64 param_2)

{
  u64 uVar1;
  u32 uVar2;
  int iVar3;
  float fVar4;
  
  iVar3 = (int)param_2;
  if (*(int *)(iVar3 + 0xae4) == 0) {
    if ((*(u32 *)(iVar3 + 0x160) & 0x4000) == 0) {
      uVar1 = func_001a3a78();
      uVar2 = func_001de168(uVar1,6,0,1,0x2714,param_2);
      *(float *)(iVar3 + 0xae8) = param_1;
      *(u32 *)(iVar3 + 0xae4) = uVar2;
      return;
    }
    fVar4 = *(float *)(iVar3 + 0xae8);
  }
  else {
    fVar4 = *(float *)(iVar3 + 0xae8);
  }
  if (fVar4 < param_1) {
    *(float *)(iVar3 + 0xae8) = param_1;
  }
  return;
}

void func_00176cd0(int param_1,u64 param_2,u32 param_3)

{
  s64 lVar1;
  u64 uVar2;
  u64 uVar3;
  u32 auStack_30 [4];
  
  if (*(int *)(param_1 + 0x9b8) != 0) {
    auStack_30[0] = param_3;
    lVar1 = func_0019ba60(*(u32 *)(param_1 + 0x9f4));
    uVar3 = 0;
    if ((lVar1 != 0) && (*(int *)(param_1 + 0x9f4) != param_1)) {
      uVar3 = func_0016a070(*(int *)(param_1 + 0x9f4));
    }
    uVar2 = func_0016a070(param_1);
    lVar1 = func_001afe70(uVar2,param_2,uVar3,auStack_30);
    if (-1 < lVar1) {
      func_00198630(param_1,lVar1,auStack_30[0]);
    }
  }
  return;
}

void func_00177460(int param_1,u32 param_2)

{
  func_00177498();
  *(u32 *)(param_1 + 0xaec) = param_2;
  return;
}

void func_00178a50(int param_1,int param_2)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_00190140(*(int *)(param_1 + 0xb44) + 0xc);
  if (lVar1 == 0) {
    return;
  }
  if (*(char *)(param_2 + 0x1d) == '\x01') {
    iVar2 = *(int *)(param_1 + 0xb44) + 0xc;
  }
  else {
    if (*(char *)(param_2 + 0x1d) != '\x03') {
      return;
    }
    if (*(int *)(param_1 + 0xb40) == 0) {
      return;
    }
    lVar1 = func_00190140(*(int *)(param_1 + 0xb40) + 4);
    if (lVar1 == 0) {
      return;
    }
    iVar2 = *(int *)(param_1 + 0xb40) + 4;
  }
  func_00159130(iVar2);
  return;
}

u32 func_00179b68(u64 param_1)

{
  int iVar1;
  s64 lVar2;
  
  iVar1 = func_001a6a20(0x10002,0xc);
  if ((*(int *)(iVar1 + 4) == 0) && (lVar2 = func_00176a90(param_1), lVar2 == 0)) {
    return 0;
  }
  return 1;
}

void func_0017a418(int param_1,s64 param_2)

{
  if (param_2 == 1) {
    func_001d6ae0(*(u32 *)(param_1 + 0xb3c));
    *(u8 *)(param_1 + 0xb64) = 1;
  }
  else if (param_2 == 2) {
    func_001d6b40(*(u32 *)(param_1 + 0xb3c));
    *(u8 *)(param_1 + 0xb64) = 2;
  }
  else {
    *(char *)(param_1 + 0xb64) = (char)param_2;
  }
  return;
}

bool func_0017a538(int param_1)

{
  s64 lVar1;
  bool bVar2;
  
  lVar1 = func_0016a070();
  bVar2 = false;
  if (lVar1 == 1) {
    bVar2 = *(int *)(param_1 + 0xb50) != 0 && *(int *)(param_1 + 0xb50) < 7;
  }
  return bVar2;
}

void func_0017a600(u64 param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  iVar3 = iVar2 + 0x9f4;
  lVar1 = func_00190140(iVar3);
  if (lVar1 == 0) {
    func_00190f80(0,iVar3,param_1);
    lVar1 = func_00190140(iVar3);
    if (lVar1 != 0) {
      func_0019ca90(*(u32 *)(iVar2 + 0xb40),1,iVar3);
      func_0019d358(*(u32 *)(iVar2 + 0xb40));
      return;
    }
  }
  return;
}

void func_0017a8f8(u64 param_1,u64 param_2,u32 *param_3)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_3;
  uStack_1c = param_3[1];
  uStack_18 = param_3[2];
  uStack_14 = param_3[3];
  func_0017c4c8(param_2,&uStack_20);
  func_0016bd60(param_2,1);
  return;
}

u32 * func_0017c030(u32 *param_1,u64 param_2,u64 param_3,char param_4)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  
  iVar4 = (int)param_2;
  if (param_1 != (u32 *)(iVar4 + 0x10)) {
    uVar1 = *(u32 *)(iVar4 + 0x14);
    uVar2 = *(u32 *)(iVar4 + 0x18);
    uVar3 = *(u32 *)(iVar4 + 0x1c);
    *param_1 = *(u32 *)(iVar4 + 0x10);
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
  }
  uVar1 = func_0016c460(param_2,param_3);
  param_1[1] = uVar1;
  if (param_4 != '\0') {
    *(u32 *)(iVar4 + 0x108) = *(u32 *)(iVar4 + 0x108) | 0x10000;
  }
  return param_1;
}

void func_0017ce80(float param_1,float param_2,float param_3)

{
  float fVar1;
  
  param_2 = param_2 - param_1;
  fVar1 = (float)func_0017ce10(param_2);
  if (fVar1 < -param_3) {
    param_1 = param_1 - param_3;
  }
  else {
    fVar1 = (float)func_0017ce10(param_2);
    if (param_3 < fVar1) {
      param_1 = param_1 + param_3;
    }
    else {
      fVar1 = (float)func_0017ce10(param_2);
      param_1 = param_1 + fVar1;
    }
  }
  func_0017ce10(param_1);
  return;
}

s64 func_0017dfc8(void)

{
  s64 lVar1;
  u64 uVar2;
  u64 uVar3;
  
  lVar1 = func_0017df70();
  if (((lVar1 != 0) && (uVar2 = func_0016e920(lVar1), *(short *)((int)uVar2 + 0x4c) == 8)) &&
     (uVar3 = func_0016f7d0(lVar1,uVar2), uVar3 < 2)) {
    lVar1 = 0x81d;
  }
  return lVar1;
}

u32 func_0017e280(int param_1)

{
  s64 lVar1;
  s64 lVar2;
  
  lVar1 = func_0019ba60();
  if ((lVar1 != 0) && ((*(u32 *)(param_1 + 0x160) & 0x4000) == 0)) {
    lVar1 = func_0019c6f0(param_1);
    lVar2 = 0;
    if (lVar1 == 0) {
      do {
        lVar2 = func_001b9bc8(lVar2);
        if (lVar2 == 0) {
          return 1;
        }
      } while (((*(u32 *)((int)lVar2 + 0x588) & 0x40) != 0) ||
              (*(int *)((int)lVar2 + 0x570) != param_1));
    }
  }
  return 0;
}

s64 func_0017edf0(int *param_1,s64 param_2)

{
  s64 lVar1;
  
  if ((param_2 < 0) || (*param_1 == 0)) {
    lVar1 = 0;
  }
  else if ((param_1[1] == 0) || (lVar1 = func_001a97b8(param_1[1]), lVar1 == 0)) {
    lVar1 = func_001a97b8(*param_1,param_2);
    return lVar1;
  }
  return lVar1;
}

void func_0017f488(u32 param_1,u32 param_2,u64 param_3,u64 param_4)

{
  func_0017f380();
  func_0017f268(param_1,param_2,param_3,param_4);
  return;
}

u32 func_00180408(u64 param_1,s64 param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = func_00168b38(param_2,9,0);
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(u32 *)((int)lVar2 + 8);
    }
  }
  return uVar1;
}

void func_00180b98(int param_1)

{
  s64 lVar1;
  u32 *puVar2;
  int iVar3;
  int iVar4;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar2 = (u32 *)func_0016c028(*(u32 *)(param_1 + 8));
  if (&uStack_30 != puVar2) {
    uStack_30 = *puVar2;
    uStack_2c = puVar2[1];
    uStack_28 = puVar2[2];
    uStack_24 = puVar2[3];
  }
  iVar3 = param_1 + 0x100;
  iVar4 = 7;
  do {
    if (*(int *)(iVar3 + 8) != 0) {
      lVar1 = func_002bc420(*(int *)(iVar3 + 8));
      if (lVar1 == 0) {
        *(u32 *)(iVar3 + 8) = 0;
      }
      else {
        lVar1 = func_0019c6f0(*(u32 *)(param_1 + 8));
        if (lVar1 == 0) {
          func_002bc398(*(u32 *)(iVar3 + 8),&uStack_30);
        }
        else {
          func_002bc3f0(*(u32 *)(iVar3 + 8));
        }
      }
    }
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + 8;
  } while (-1 < iVar4);
  return;
}

void func_001835a0(float param_1,u64 param_2)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  
  lVar1 = func_0019c400();
  if (lVar1 == 0) {
    iVar2 = (int)param_2;
    func_0016ae58(*(float *)(iVar2 + 0x55c) + param_1,param_2);
    uVar3 = func_0017ce10(*(float *)(iVar2 + 0x66c) + param_1);
    *(u32 *)(iVar2 + 0x66c) = uVar3;
  }
  return;
}

void func_00185050(u64 param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)((int)param_1 + 0x508);
  if (iVar1 == 0) {
    uVar2 = func_002cd1d8();
    *(u32 *)((int)param_1 + 0x508) = uVar2;
    return;
  }
  func_002cd290(iVar1,param_1,param_2);
  return;
}

void func_00185988(u64 param_1)

{
  s64 lVar1;
  u32 uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x9f8) == 0) {
    lVar1 = func_0019c5d0();
    if ((lVar1 == 0) && ((*(u32 *)(iVar3 + 0x160) & 0x800) != 0)) {
      uVar2 = func_0016ac38(param_1,10,1,0,0);
      *(u32 *)(iVar3 + 0x9f8) = uVar2;
    }
  }
  else {
    lVar1 = func_001dc9e0(*(int *)(iVar3 + 0x9f8));
    if (lVar1 != 0) {
      lVar1 = func_0019c5d0(param_1);
      if ((lVar1 == 0) && ((*(u32 *)(iVar3 + 0x160) & 0x800) != 0)) {
        return;
      }
      func_001dc818(*(u32 *)(iVar3 + 0x9f8));
    }
    *(u32 *)(iVar3 + 0x9f8) = 0;
  }
  return;
}

void func_00185da8(s64 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 0x10) == 0);
  return;
}

void func_00186078(s64 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 2) == 0);
  return;
}

void func_00187a18(u64 param_1,u32 param_2,u64 param_3,u16 param_4,
                 u16 *param_5)

{
  u32 *puVar1;
  s64 lVar2;
  int iVar3;
  u16 *puVar4;
  
  lVar2 = func_00187ab8();
  puVar1 = (u32 *)lVar2;
  if (lVar2 == 0) {
    puVar1 = (u32 *)func_00187b30(param_1);
    *puVar1 = param_2;
  }
  *(u16 *)(puVar1 + 2) = param_4;
  *(short *)((int)puVar1 + 6) = (short)((u64)param_3 >> 0x10);
  puVar4 = (u16 *)((int)puVar1 + 10);
  *(short *)(puVar1 + 1) = (short)param_3;
  iVar3 = 10;
  do {
    iVar3 = iVar3 + -1;
    *puVar4 = *param_5;
    param_5 = param_5 + 2;
    puVar4 = puVar4 + 1;
  } while (-1 < iVar3);
  return;
}

void func_00187b90(u64 param_1)

{
  int iVar1;
  u32 auStack_20 [4];
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x94) != 0) {
    auStack_20[0] = *(u32 *)(iVar1 + 0x88);
    func_00188398(param_1,*(u16 *)(*(int *)(iVar1 + 0x90) + 10),auStack_20,1);
    func_0016ced0(*(u32 *)(iVar1 + 0x94));
    *(u32 *)(iVar1 + 0x90) = 0;
    *(u32 *)(iVar1 + 0x94) = 0;
  }
  return;
}

bool func_00187e58(int param_1)

{
  bool bVar1;
  s64 lVar2;
  int iVar3;
  
  if ((*(u32 *)(param_1 + 0x9c) & 1) != 0) {
    return false;
  }
  if ((*(u32 *)(*(int *)(*(int *)(param_1 + 0x88) + 4) + 0x588) & 2) == 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  }
  else {
    lVar2 = func_00186ce8();
    if (lVar2 != 0) {
      return true;
    }
    lVar2 = func_00186d18(*(u32 *)(*(int *)(param_1 + 0x88) + 4));
    if (lVar2 != 0) {
      return true;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  }
  if ((*(u32 *)(iVar3 + 0x588) & 8) == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(iVar3 + 0x154) == 0x32;
  }
  return bVar1;
}

void func_00187ef0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int aiStack_2c [3];
  
  iVar1 = *param_1;
  iVar2 = iVar1 + 1;
  iVar5 = iVar1 + 0x10;
  if (-1 < iVar2) {
    iVar5 = iVar2;
  }
  iVar3 = (iVar1 - param_1[1]) + 0x10;
  iVar4 = (iVar1 - param_1[1]) + 0x1f;
  if (-1 < iVar3) {
    iVar4 = iVar3;
  }
  if (iVar3 + (iVar4 >> 4) * -0x10 < 0xf) {
    *param_1 = iVar2 + (iVar5 >> 4) * -0x10;
    aiStack_2c[0] = 0;
    func_0031cc28(aiStack_2c);
    param_1[iVar1 * 2 + 2] = param_2;
    param_1[iVar1 * 2 + 3] = aiStack_2c[0];
  }
  return;
}

u64 func_00188340(int param_1,int param_2,u32 *param_3,u64 param_4)

{
  u64 uVar1;
  u32 auStack_20 [4];
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x90) != 0) && ((*(u32 *)(param_1 + 0x9c) & 4) == 0)) {
    if (param_3 == (u32 *)0x0) {
      auStack_20[0] = *(u32 *)(param_1 + 0x88);
      param_4 = 1;
      param_3 = auStack_20;
    }
    uVar1 = func_00188398(param_1,*(u16 *)(param_2 * 2 + *(int *)(param_1 + 0x90) + 10),
                         param_3,param_4);
  }
  return uVar1;
}

void func_001888c8(int param_1)

{
  int iVar1;
  u16 *puVar2;
  
  *(u8 *)(param_1 + 9) = 0;
  *(u8 *)(param_1 + 7) = 100;
  *(u8 *)(param_1 + 0x11) = 1;
  puVar2 = (u16 *)(param_1 + 0x54);
  *(u8 *)(param_1 + 4) = 100;
  iVar1 = 0x4f;
  *(u8 *)(param_1 + 5) = 100;
  *(u8 *)(param_1 + 6) = 100;
  *(u8 *)(param_1 + 10) = 0;
  *(u8 *)(param_1 + 0xb) = 0;
  *(u8 *)(param_1 + 0xc) = 0;
  *(u8 *)(param_1 + 0xd) = 0;
  *(u8 *)(param_1 + 0xe) = 0;
  *(u8 *)(param_1 + 0xf) = 1;
  *(u8 *)(param_1 + 0x10) = 1;
  *(u8 *)(param_1 + 0x12) = 0;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  func_00114580(param_1 + 0xf4);
  return;
}

void func_00188ac8(int param_1)

{
  u8 bVar1;
  s64 lVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar3 = (u32)*(u8 *)(param_1 + 0x12);
  iVar4 = param_1;
  if (uVar3 != 0) {
    do {
      if ((*(short *)(iVar4 + 0x44) != 0) && (*(short *)(iVar4 + 0x34) == 0)) {
        lVar2 = func_001a3570();
        if (lVar2 < 1) {
          bVar1 = *(u8 *)(param_1 + 0x12);
        }
        else {
          func_001a34e0(*(u16 *)(iVar4 + 0x44),1);
          bVar1 = *(u8 *)(param_1 + 0x12);
          *(u16 *)(iVar4 + 0x34) = *(u16 *)(iVar4 + 0x44);
        }
        uVar3 = (u32)bVar1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 2;
    } while (iVar5 < (int)uVar3);
  }
  return;
}

int func_00188fe0(int param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_001b7818(param_2);
  if (lVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + (int)lVar2 * 0x114 + -0x114;
  }
  return iVar1;
}

void func_0018b200(int param_1)

{
  s64 lVar1;
  
  if ((*(char *)(*(int *)(param_1 + 8) + 4) == '\x0f') &&
     (lVar1 = func_001883d8(param_1 + 0x300,0x36cbb0), lVar1 != 0)) {
    func_001880b0(param_1 + 0x300,0x36cbb0);
    return;
  }
  return;
}

s64 func_0018bbf8(int param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = 0;
  if (*(char *)(param_1 + 0xa70) == '\0') {
    uVar2 = func_0016c028();
    lVar1 = func_0018c490(param_1 + 0xa40,uVar2);
    if (lVar1 != 0) {
      func_0018c480(param_1 + 0xa40,1);
    }
  }
  return lVar1;
}
