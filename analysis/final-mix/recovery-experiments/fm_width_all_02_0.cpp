#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001688b8(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001d35e0(...);
extern "C" f32 func_0016b558(...);
extern "C" s32 func_0016b740(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_00170240(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00188fe0(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_0016bba8(...);
extern "C" s32 func_00170400(...);
extern "C" u16 func_0016a070(...);
extern "C" u16 func_0016bff0(...);
extern "C" u32 func_00102c18(...);
extern "C" u32 func_00104f58(...);
extern "C" u32 func_0014d358(...);
extern "C" u32 func_00152508(...);
extern "C" u32 func_00167d68(...);
extern "C" u32 func_00167f18(...);
extern "C" u32 func_0016a020(...);
extern "C" u32 func_0016ace0(...);
extern "C" u32 func_0016adc8(...);
extern "C" u32 func_0016aeb8(...);
extern "C" u32 func_0016b010(...);
extern "C" u32 func_0016c018(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_00170c50(...);
extern "C" u32 func_00170e58(...);
extern "C" u32 func_00176db0(...);
extern "C" u32 func_00177998(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017d160(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_00180378(...);
extern "C" u32 func_001846a0(...);
extern "C" u32 func_00185278(...);
extern "C" u32 func_00186a90(...);
extern "C" u32 func_00188b68(...);
extern "C" u32 func_001891b8(...);
extern "C" u32 func_001945a0(...);
extern "C" u32 func_0019a1a0(...);
extern "C" u32 func_0019ae60(...);
extern "C" u32 func_0019fdc0(...);
extern "C" u32 func_001a0710(...);
extern "C" u32 func_001a55a8(...);
extern "C" u32 func_001a7588(...);
extern "C" u32 func_001b0700(...);
extern "C" u32 func_001b0798(...);
extern "C" u32 func_001b2210(...);
extern "C" u32 func_001b6dd0(...);
extern "C" u32 func_001ce300(...);
extern "C" u32 func_001ce328(...);
extern "C" u32 func_001cfac0(...);
extern "C" u32 func_001dc648(...);
extern "C" u32 func_001dc670(...);
extern "C" u32 func_002ba200(...);
extern "C" u32 func_002f8ad0(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_0016bda8(...);
extern "C" u32 func_0017d050(...);
extern "C" u32 func_0017d0e8(...);
extern "C" u32 func_0019b0e8(...);
extern "C" u8 func_0016a040(...);
extern "C" u8 func_001c3618(...);

void func_00152ab8(int param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,u32 param_6,u32 param_7,u32 param_8)

{
  *(u32 *)(param_1 + 0x1b8) = param_5;
  *(u32 *)(param_1 + 0x1c0) = param_7;
  *(u32 *)(param_1 + 0x1bc) = param_6;
  *(u32 *)(param_1 + 0x1b4) = param_3;
  func_00152508(param_1,0x6c,param_3,param_4,param_8);
  return;
}

void func_00167e70(void)

{
  func_00167d68(0x34d6c0);
  func_00167d68(0x34d720);
  return;
}

void func_0016ae18(u32 param_1)

{
  int iVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  iVar1 = (int)param_1;
  uStack_20 = *(u32 *)(iVar1 + 0x890);
  uStack_1c = *(u32 *)(iVar1 + 0x894);
  uStack_18 = *(u32 *)(iVar1 + 0x898);
  uStack_14 = *(u32 *)(iVar1 + 0x89c);
  func_0016adc8(param_1,&uStack_20);
  func_0016aeb8(*(u32 *)(iVar1 + 0x89c),param_1);
  return;
}

u32 func_0016af58(u32 param_1,u32 param_2)

{
  s32 lVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u32 *puVar5;
  u32 uVar6;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  
  lVar1 = func_001c0cd8(param_2);
  iVar4 = (int)param_2;
  puVar5 = (u32 *)param_1;
  if (lVar1 == 0) {
    uVar6 = *(u32 *)(iVar4 + 0x554);
    uVar2 = *(u32 *)(iVar4 + 0x558);
    uVar3 = *(u32 *)(iVar4 + 0x55c);
    *puVar5 = *(u32 *)(iVar4 + 0x550);
    puVar5[1] = uVar6;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
  }
  else {
    uVar6 = func_002f8ad0(-*(float *)(iVar4 + 0x60),-*(float *)(iVar4 + 0x68));
    func_0017d0e8(uVar6,&uStack_30);
    *puVar5 = uStack_30;
    puVar5[1] = uStack_2c;
    puVar5[2] = uStack_28;
    puVar5[3] = uVar6;
  }
  return param_1;
}

void func_0016b518(int param_1,u32 param_2,u32 param_3)

{
  if ((*(u32 *)(param_1 + 0x588) & 4) == 0) {
    func_0016b558(param_1,param_3);
  }
  else {
    func_00176db0();
  }
  return;
}

s32 func_0016b7a0(s32 param_1)

{
  s32 lVar1;
  s32 lVar2;
  
  lVar2 = 0;
  do {
    lVar2 = func_001b9bc8(lVar2);
    if (lVar2 == 0) {
      return 0;
    }
    lVar1 = func_0016bff0(lVar2);
  } while (lVar1 != param_1);
  return lVar2;
}

s32 func_0016b800(s32 param_1)

{
  s32 lVar1;
  s32 lVar2;
  
  lVar2 = 0;
  do {
    lVar2 = func_001b9bc8(lVar2);
    if (lVar2 == 0) {
      return 0;
    }
    lVar1 = func_0016a070(lVar2);
  } while (lVar1 != param_1);
  return lVar2;
}

void func_0016bc20(u32 param_1,u32 param_2,u32 param_3)

{
  s32 lVar1;
  
  lVar1 = 0;
  while( true ) {
    lVar1 = func_0016bba8(param_1,param_2,lVar1);
    if (lVar1 == 0) {
      return;
    }
    if (param_3 == 0xffffffff) break;
    if (*(u8 *)lVar1 == param_3) {
      return;
    }
  }
  return;
}

void func_0016be00(u32 param_1,u32 param_2)

{
  s32 lVar1;
  int iVar2;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_40;
  float fStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  iVar2 = (int)param_1;
  uStack_40 = *(u32 *)(iVar2 + 0x540);
  uStack_38 = *(u32 *)(iVar2 + 0x548);
  uStack_34 = *(u32 *)(iVar2 + 0x54c);
  fStack_3c = *(float *)(iVar2 + 0x544) - *(float *)(iVar2 + 0x5fc);
  func_0016bda8(&uStack_30,param_1);
  lVar1 = func_001d35e0(&uStack_60,&uStack_40,&uStack_30,6);
  if ((lVar1 != 0) && (&uStack_30 != &uStack_60)) {
    uStack_30 = uStack_60;
    uStack_2c = uStack_5c;
    uStack_28 = uStack_58;
    uStack_24 = uStack_54;
  }
  func_001a55a8(&uStack_30,param_2);
  return;
}

u32 func_0016c460(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 *puVar2;
  s32 lVar3;
  u32 uVar4;
  
  uVar4 = *(u32 *)(param_1 + 0x118);
  *param_2 = 3;
  if (((*(u32 *)(param_1 + 0x588) & 4) != 0) &&
     ((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x800) == 0)) {
    uVar1 = func_00177860();
    lVar3 = func_001c3618(uVar1,0);
    if (0 < lVar3) {
      puVar2 = (u32 *)func_001ce300(lVar3);
      uVar4 = *puVar2;
      *param_2 = 0xc9;
    }
  }
  return uVar4;
}

u32 func_0016c508(u32 param_1,u32 param_2)

{
  u32 *puVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  
  puVar1 = (u32 *)func_0016c028(param_2);
  uVar3 = puVar1[1];
  uVar4 = puVar1[2];
  uVar5 = puVar1[3];
  puVar6 = (u32 *)param_1;
  *puVar6 = *puVar1;
  puVar6[1] = uVar3;
  puVar6[2] = uVar4;
  puVar6[3] = uVar5;
  iVar2 = func_001ce328(*(u16 *)(*(int *)((int)param_2 + 8) + 0x4e));
  puVar6[1] = (float)puVar6[1] - *(float *)(iVar2 + 0x30);
  return param_1;
}

void func_0016c5b8(u32 param_1,u32 param_2)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_001b9bc8(lVar2), lVar2 != 0) {
    uVar1 = func_0016a040(lVar2);
    if ((1 << (uVar1 & 0x1f) & param_2) != 0) {
      func_0016c568(0,lVar2,param_1);
    }
  }
  return;
}

void func_0016d920(int *param_1)

{
  u32 *puVar1;
  int iVar2;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)param_1[1];
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  puVar1 = (u32 *)*param_1;
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  iVar2 = func_0017d160(&uStack_20,&uStack_30);
  *param_1 = iVar2;
  return;
}

void func_0016dbe0(u32 *param_1)

{
  int iVar1;
  
  iVar1 = func_00167f18(0);
  *param_1 = (u32)(*(u32 *)(iVar1 + 8) >> (s32)(int)*param_1) & 1;
  return;
}

void func_0016e130(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_00189200(0x32e020,*param_1);
  func_001891b8(uVar1,param_1[1]);
  return;
}

void func_0016e200(u32 *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  puVar2 = (u32 *)func_001dc648(*param_1);
  puVar1 = (u32 *)param_1[1];
  if (puVar2 != puVar1) {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
  }
  return;
}

void func_0016e240(u32 *param_1)

{
  u32 *puVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar1 = (u32 *)func_001dc648(*param_1);
  func_0017d050(&uStack_30,param_1[1]);
  if (puVar1 != &uStack_30) {
    *puVar1 = uStack_30;
    puVar1[1] = uStack_2c;
    puVar1[2] = uStack_28;
    puVar1[3] = uStack_24;
  }
  return;
}

void func_0016e500(u32 *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  puVar2 = (u32 *)func_001dc670(*param_1);
  puVar1 = (u32 *)param_1[1];
  if (puVar2 != puVar1) {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
  }
  return;
}

void func_0016e718(u32 *param_1)

{
  func_00188b68(*param_1,param_1[1],param_1[2] != 0);
  return;
}

s32 func_0016f470(int param_1,s32 param_2)

{
  if (param_2 == 0) {
    param_2 = 0x4f63b0;
  }
  func_002fee78(param_2,0x36c440,param_1 + 8);
  return param_2;
}

u16 func_0016f610(int param_1,s32 param_2)

{
  s32 lVar1;
  u16 uVar2;
  
  uVar2 = 0;
  if (*(short *)(param_1 + 0x4e) != 0) {
    if (((*(short *)(param_1 + 0x4c) == 1) || (*(short *)(param_1 + 0x4c) == 0xe)) && (param_2 == 1)
       ) {
      lVar1 = func_00189200(0x32e020,*(u8 *)(param_1 + 0x57));
      uVar2 = 0;
      if (lVar1 != 0) {
        uVar2 = *(u16 *)lVar1;
      }
    }
    else {
      lVar1 = func_00188fe0(0x32e020);
      uVar2 = 0;
      if (lVar1 != 0) {
        uVar2 = *(u16 *)((int)param_2 * 2 + (int)lVar1);
      }
    }
  }
  return uVar2;
}

void func_0016fa58(void)

{
  func_0014d358(0x1c5c460,0x3000,0x16f9e8,0);
  return;
}

void func_00170530(u32 param_1,u32 param_2,u16 param_3,u32 param_4)

{
  u8 *puVar1;
  
  puVar1 = (u8 *)func_00170400(param_1,param_2,param_4);
  *(u16 *)(puVar1 + 0x38) = param_3;
  *(u16 *)(puVar1 + 0x3a) = 0xffff;
  *puVar1 = 1;
  return;
}

u32 func_001708f8(void)

{
  short sVar1;
  s32 lVar2;
  int iVar3;
  
  lVar2 = func_00170240();
  iVar3 = (int)lVar2;
  if ((lVar2 == 0) || (9999 < *(int *)(iVar3 + 0x28))) {
    func_00170e58();
    sVar1 = *(short *)(iVar3 + 2);
  }
  else {
    sVar1 = *(short *)(iVar3 + 2);
  }
  *(short *)(iVar3 + 2) = sVar1 + 1;
  return *(u32 *)(iVar3 + 0x30);
}

u32 func_00170cd0(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_001688b8();
  if ((lVar1 == 0) && (lVar1 = func_002ba200(), lVar1 == 0)) {
    uVar2 = func_00170c50();
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

void func_00171150(int *param_1)

{
  func_0017f488(param_1[2],0,*param_1 + 0x140,param_1[1]);
  return;
}

void func_001713f0(int *param_1)

{
  func_00186a90(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_00171480(int *param_1)

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
  func_0016adc8(*(u32 *)(*param_1 + 4),&uStack_20);
  return;
}

void func_00171690(int *param_1)

{
  func_00185278(param_1[1],*(u32 *)(*param_1 + 4),param_1[2] != 0);
  return;
}

void func_00171848(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    func_0019ba60(*(u32 *)(*param_1 + 4));
    iVar1 = *param_1;
  }
  if ((*(u32 *)(*(int *)(iVar1 + 4) + 0x588) & 4) != 0) {
    func_00177998();
    return;
  }
  return;
}

void func_00171930(int *param_1)

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
  func_0016b010(*(u32 *)(*param_1 + 4),&uStack_20);
  return;
}

void func_00171a40(int *param_1)

{
  func_001cfac0(param_1[1],param_1[2],param_1[3],param_1[4],*(u32 *)(*param_1 + 4));
  return;
}

void func_00171a70(u32 *param_1)

{
  int iVar1;
  
  iVar1 = func_00177860(*(u32 *)(*param_1 + 4));
  *param_1 = (u32)((*(u32 *)((param_1[1] >> 5) * 4 + iVar1) & 1 << (param_1[1] & 0x1f)) != 0);
  return;
}

void func_00172078(int *param_1)

{
  func_001945a0(param_1[3],*(u32 *)(*param_1 + 4),param_1[1],param_1[2]);
  return;
}

void func_00172158(int *param_1)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar1 = (u32 *)param_1[1];
  iVar2 = *(int *)(*param_1 + 4);
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  func_0017c4c8(iVar2,&uStack_30);
  func_0017f488(param_1[3],0,iVar2 + 0x140,param_1[2]);
  if (param_1[4] != 0) {
    iVar3 = param_1[2];
    *(int *)(iVar2 + 0x104) = iVar3 + 2;
    *(int *)(iVar2 + 0x100) = iVar3 + 1;
  }
  return;
}

void func_00172260(int *param_1)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar1 = (u32 *)param_1[1];
  iVar2 = *(int *)(*param_1 + 4);
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  func_001b2210(param_1[2],param_1[3],iVar2,&uStack_30);
  func_0017f488(param_1[5],0,iVar2 + 0x140,param_1[4]);
  if (param_1[6] != 0) {
    iVar3 = param_1[4];
    *(int *)(iVar2 + 0x104) = iVar3 + 2;
    *(int *)(iVar2 + 0x100) = iVar3 + 1;
  }
  return;
}

void func_001722e8(int *param_1)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar1 = (u32 *)param_1[1];
  iVar2 = *(int *)(*param_1 + 4);
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  func_001b6dd0(iVar2,&uStack_30);
  func_0017f488(param_1[3],0,iVar2 + 0x140,param_1[2]);
  if (param_1[4] != 0) {
    iVar3 = param_1[2];
    *(int *)(iVar2 + 0x104) = iVar3 + 2;
    *(int *)(iVar2 + 0x100) = iVar3 + 1;
  }
  return;
}

void func_00172368(int *param_1)

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
  func_001a0710(param_1[2],*(u32 *)(*param_1 + 4),&uStack_20);
  return;
}

void func_00172440(int *param_1)

{
  int iVar1;
  
  iVar1 = func_00180378(param_1[3],*(int *)(*param_1 + 4) + 0x140,*(u32 *)(param_1[1] + 4),
                       param_1[2]);
  *param_1 = iVar1;
  return;
}

void func_001727c8(int *param_1)

{
  func_001b0798(param_1[2],*(int *)(*param_1 + 4) + 0x4a0,*(u32 *)(param_1[1] + 4),1);
  return;
}

void func_00172830(int *param_1)

{
  func_001b0700(param_1[1],*(int *)(*param_1 + 4) + 0x4a0);
  return;
}

void func_00172928(int *param_1)

{
  u32 uVar1;
  u32 uVar2;
  u8 auStack_30 [16];
  
  uVar1 = *(u32 *)(*param_1 + 4);
  uVar2 = func_0016a020(uVar1);
  func_0019b0e8(param_1[2],param_1[3],auStack_30,uVar2,param_1[1]);
  func_0016ace0(uVar1,auStack_30);
  return;
}

void func_00172a10(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    func_0019ba60(*(u32 *)(*param_1 + 4));
    iVar1 = *param_1;
  }
  func_0016c018(*(u32 *)(iVar1 + 4),param_1[1],param_1[2]);
  return;
}

void func_00172a80(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 0x818);
  if ((iVar1 != 0) && ((*(u32 *)(iVar1 + 4) & 1) == 0)) {
    func_0019ae60(iVar1);
    func_0019a1a0(iVar1,0);
    return;
  }
  return;
}

void func_00172ba8(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  uVar2 = func_0016b740(param_1[1]);
  *(u32 *)(iVar1 + 4) = uVar2;
  return;
}

void func_00172fb0(u8 *param_1)

{
  u8 uStack_20;
  u8 uStack_1f;
  u8 uStack_1e;
  u16 uStack_1c;
  u16 uStack_1a;
  u16 uStack_18;
  
  uStack_1f = *param_1;
  uStack_1e = param_1[4];
  uStack_18 = 0xffff;
  uStack_20 = 0xff;
  uStack_1c = 0xffff;
  uStack_1a = 0xffff;
  func_00104f58(&uStack_20,*(u32 *)(param_1 + 8),0,0,0);
  return;
}

void func_001732c8(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001a7588(*param_1,param_1[1],param_1[2],param_1[3]);
  *param_1 = uVar1;
  return;
}

void func_00173518(u32 *param_1)

{
  int iVar1;
  
  iVar1 = func_00102c18(1,0x36b2,0x1734b0);
  *(u32 *)(iVar1 + 4) = 0;
  *(u32 *)(iVar1 + 8) = *param_1;
  return;
}

void func_00173808(int *param_1)

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
  func_0019fdc0(param_1[2],*(u32 *)(*param_1 + 4),&uStack_20);
  return;
}

void func_00173e10(int *param_1)

{
  func_001846a0(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}
