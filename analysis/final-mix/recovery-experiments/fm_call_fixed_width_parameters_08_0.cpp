#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001bb4a0(void);
extern "C" bool func_002282f0(...);
extern "C" s32 func_00102180(void*);
extern "C" s32 func_001e0cc8(...);
extern "C" s32 func_001e0ce8(s32);
extern "C" s32 func_001e3650(...);
extern "C" s64 func_001dba18(...);
extern "C" s8 func_00225b00(s32);
extern "C" u32 func_001024a8(void*);
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" u32 func_00102c80(void);
extern "C" u32 func_00104190(void);
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_001391a8(s32,void*);
extern "C" u32 func_00143fc8(u64,u64);
extern "C" u32 func_0015c958(s32,u8,u8,u8,s32,s32);
extern "C" u32 func_001671e8(s32,u8);
extern "C" u32 func_00167218(void);
extern "C" u32 func_001bbcb0(void);
extern "C" u32 func_001d1b60(u64,s32);
extern "C" u32 func_001db950(...);
extern "C" u32 func_001dc700(s32,s8);
extern "C" u32 func_001dc840(s32);
extern "C" u32 func_001dc978(f32,s32);
extern "C" u32 func_001dca20(...);
extern "C" u32 func_001dde40(void*);
extern "C" u32 func_001de4b0(s32,u64,s32);
extern "C" u32 func_001de8a8(u64,u64,u64,u64);
extern "C" u32 func_001e0058(s64);
extern "C" u32 func_001e0158(...);
extern "C" u32 func_001e01b8(u64);
extern "C" u32 func_001e02f8(u32);
extern "C" u32 func_001e03b0(void*);
extern "C" u32 func_001e17b8(...);
extern "C" u32 func_001e18d8(...);
extern "C" u32 func_001e1988(...);
extern "C" u32 func_001e3468(s32);
extern "C" u32 func_001e3660(u64,s32);
extern "C" u32 func_001e38f8(void*,s32,s16,s16);
extern "C" u32 func_001e3a88(void*,s32,s16,s16);
extern "C" u32 func_001e3c98(void*,s32);
extern "C" u32 func_001e3e48(void*,s32);
extern "C" u32 func_001e4028(void*,s32);
extern "C" u32 func_001e6000(...);
extern "C" u32 func_001fa950(...);
extern "C" u32 func_001fab48(...);
extern "C" u32 func_001facf8(...);
extern "C" u32 func_00209178(s32,void*);
extern "C" u32 func_0020e2e8(...);
extern "C" u32 func_0021fa10(void*);
extern "C" u32 func_0021fbc0(...);
extern "C" u32 func_0021fe28(...);
extern "C" u32 func_00220070(...);
extern "C" u32 func_002223e0(void*);
extern "C" u32 func_002247e8(void);
extern "C" u32 func_002248f8(s32);
extern "C" u32 func_002249b8(void);
extern "C" u32 func_002251c8(u64);
extern "C" u32 func_00227ca8(void*);
extern "C" u32 func_00229b28(u32,s32,s32,u64,u64);
extern "C" u32 func_002f1460(u32,u32,u32,u32,void*,u32);
extern "C" u32 func_002f1670(s32);
extern "C" u32 func_002f3f88(void*,void*);
extern "C" u32 func_002fd348(u64);
extern "C" u32 func_002fdfc8(...);
extern "C" u32 func_002fe0a0(...);
extern "C" u32 func_00313b80(u32);
extern "C" u32 func_00321cb0(void*,s32);
extern "C" u32 func_00321ce8(void*,s32);
extern "C" u64 func_0022b688(u64);

void func_001d8718(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0();
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0();
    param_2 = param_2 * 0x38;
    if ((*(u32 *)(iVar1 + param_2 + 0xf4) & 1) != 0) {
      iVar1 = func_001bbcb0();
      iVar2 = func_001bbcb0();
      func_001d1b60(iVar1 + param_2 + 0xe8,*(int *)(param_2 + iVar2 + 0x114) + param_1);
      return;
    }
  }
  return;
}

u32 func_001d87b8(int param_1)

{
  int iVar1;
  u32 uVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0();
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0();
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + param_1 * 0x38 + 0xf4) & 1) != 0) {
      iVar1 = func_001bbcb0();
      uVar2 = *(u32 *)(param_1 * 0x38 + iVar1 + 0x114);
    }
  }
  return uVar2;
}

s64 func_001db9a8(u32 param_1,u32 param_2,u32 param_3)

{
  s64 lVar1;
  
  lVar1 = func_001dba18();
  if (lVar1 == 0) {
    lVar1 = func_001050d8(0xa00);
    func_001db950(lVar1,param_1,param_2,param_3);
  }
  return lVar1;
}

u64 func_001dccc8(int param_1,char param_2)

{
  u64 uVar1;
  
  uVar1 = 0;
  if (((*(u32 *)(param_1 + 8) & 0x1000000) == 0) && (uVar1 = 0, param_2 != '\0')) {
    uVar1 = func_001e3468(*(u32 *)(param_1 + 0x1c));
    uVar1 = func_00143fc8(0x352b00,uVar1);
  }
  return uVar1;
}

void func_001ddd88(u32 param_1)

{
  s64 lVar1;
  
  lVar1 = func_00321cb0(0x1d9e348,param_1);
  if (lVar1 != 0) {
    func_001dde40(param_1);
    return;
  }
  return;
}

void func_001de508(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  do {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return;
    }
    iVar2 = *(int *)(iVar1 + 0x60);
  } while (*(int *)(iVar1 + 0x40) != param_2);
  *(u32 *)(iVar1 + 0x48) = 0;
  *(u32 *)(iVar1 + 0x5c) = *(u32 *)(iVar1 + 0x5c) & 0xfffffffe;
  func_001dc700(param_2,0);
  return;
}

void func_001de610(int param_1)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x60);
    if ((*(int *)(*(int *)(iVar2 + 0x40) + 8) >> 0x1a & 1U) == 0) {
      lVar3 = func_001dca20();
      if (lVar3 != 0) {
        func_00321ce8(param_1 + 0xc,iVar2);
        func_001e0058(iVar2);
      }
    }
  }
  return;
}

void func_001de808(void)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u64 uVar6;
  int aiStack_30 [4];
  
  iVar2 = func_00102c80();
  iVar3 = func_00104190();
  func_00102180(aiStack_30);
  if (aiStack_30[0] == iVar2) {
    func_001e02f8(1);
    uVar1 = *(u32 *)(aiStack_30[0] + 4);
    uVar4 = 9;
    uVar5 = 0x4f4c;
    uVar6 = 92000;
  }
  else {
    if (aiStack_30[0] != iVar3) {
      return;
    }
    func_001e02f8(2);
    uVar1 = *(u32 *)(iVar3 + 4);
    uVar4 = 1;
    uVar5 = 31000;
    uVar6 = 72000;
  }
  func_001de8a8(uVar1,uVar4,uVar5,uVar6);
  return;
}

void func_001ded98(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(u32 *)(param_1 + 0x5c) & 4) == 0) {
    if ((*(u32 *)(param_1 + 0x5c) & 8) != 0) {
      func_001e01b8(*(u32 *)(param_1 + 0x58));
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
    if (iVar2 != 0) {
      iVar3 = iVar2 + 0x40;
      if (iVar2 != -0x20) {
        do {
          bVar1 = iVar2 + 0x20 != iVar3;
          iVar3 = iVar3 + -0x10;
        } while (bVar1);
      }
      func_001e0158();
    }
  }
  return;
}

void func_001dee10(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(u32 *)(param_1 + 0x5c) & 4) == 0) {
    if ((*(u32 *)(param_1 + 0x5c) & 8) != 0) {
      func_001e01b8(*(u32 *)(param_1 + 0x58));
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
    if (iVar2 != 0) {
      iVar3 = iVar2 + 0x40;
      if (iVar2 != -0x20) {
        do {
          bVar1 = iVar2 + 0x20 != iVar3;
          iVar3 = iVar3 + -0x10;
        } while (bVar1);
      }
      func_001e0158();
    }
  }
  return;
}

void func_001df9c8(int param_1)

{
  u32 uVar1;
  
  if ((*(u32 *)(param_1 + 0x5c) & 0x20) == 0) {
    *(u32 *)(param_1 + 0x5c) = *(u32 *)(param_1 + 0x5c) | 0x20;
    uVar1 = *(u32 *)(*(int *)(param_1 + 0x44) + 0x10);
    if ((uVar1 & 0x80) != 0) {
      func_001dc840(*(u32 *)(param_1 + 0x40));
      return;
    }
    if ((uVar1 & 0x40) != 0) {
      func_001dc978((float)*(u8 *)(*(int *)(param_1 + 0x44) + 5),*(u32 *)(param_1 + 0x40));
      return;
    }
  }
  return;
}

void func_001e0750(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_001e03b0(0x352b60);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    return;
  }
  return;
}

void func_001e0de8(s32 param_1)

{
  u32 *puVar1;
  s64 lVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  
  lVar2 = func_001e0cc8();
  puVar1 = (u32 *)lVar2;
  puVar6 = (u32 *)param_1;
  if (param_1 == lVar2) {
    puVar6[3] = 0;
  }
  else {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar6 = *puVar1;
    puVar6[1] = uVar3;
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    puVar6[3] = 0;
  }
  puVar1 = (u32 *)func_001e0ce8(param_1);
  if (puVar6 + 4 != puVar1) {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    puVar6[4] = *puVar1;
    puVar6[5] = uVar3;
    puVar6[6] = uVar4;
    puVar6[7] = uVar5;
  }
  return;
}

void func_001e1ce0(int param_1)

{
  func_001e1988();
  *(u32 *)(param_1 + 0xdc0) = 1;
  *(u32 *)(param_1 + 0xdec) = *(u32 *)(param_1 + 0xdcc);
  *(u32 *)(param_1 + 0xde4) = 0;
  *(u32 *)(param_1 + 0xde8) = 0;
  return;
}

void func_001e2788(int param_1)

{
  *(u32 *)(param_1 + 0xdc0) = 0;
  *(u32 *)(param_1 + 0xe00) = 0xffffffff;
  *(u32 *)(param_1 + 0xdc4) = 0;
  *(u32 *)(param_1 + 0xdcc) = 0;
  *(u32 *)(param_1 + 0xdd0) = 0;
  *(u32 *)(param_1 + 0xde4) = 0;
  *(u32 *)(param_1 + 0xdec) = 0;
  func_001e17b8();
  return;
}

void func_001e27c0(int param_1)

{
  *(u32 *)(param_1 + 0xdc0) = 0;
  *(u32 *)(param_1 + 0xe00) = 0xffffffff;
  *(u32 *)(param_1 + 0xdc4) = 0;
  *(u32 *)(param_1 + 0xdcc) = 0;
  *(u32 *)(param_1 + 0xdd0) = 0;
  *(u32 *)(param_1 + 0xde4) = 0;
  *(u32 *)(param_1 + 0xdec) = 0;
  func_001e17b8();
  return;
}

void func_001e2898(int param_1)

{
  bool bVar1;
  int iVar2;
  
  func_001e18d8();
  iVar2 = param_1 + 0xdc0;
  if (param_1 != -0x140) {
    do {
      bVar1 = param_1 + 0x140 != iVar2;
      iVar2 = iVar2 + -0x10;
    } while (bVar1);
  }
  iVar2 = param_1 + 0x140;
  if (param_1 != -0xa0) {
    do {
      bVar1 = param_1 + 0xa0 != iVar2;
      iVar2 = iVar2 + -0x10;
    } while (bVar1);
  }
  iVar2 = param_1 + 0xa0;
  if (param_1 != 0) {
    do {
      bVar1 = param_1 != iVar2;
      iVar2 = iVar2 + -0x10;
    } while (bVar1);
  }
  return;
}

void func_001e3898(u32 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)func_001e3650();
  iVar2 = 4;
  iVar3 = *piVar1;
  while( true ) {
    piVar1 = piVar1 + 1;
    if (0 < iVar3) {
      do {
        iVar3 = iVar3 + -1;
        *piVar1 = *piVar1 + param_2;
        piVar1 = piVar1 + 1;
      } while (iVar3 != 0);
    }
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) break;
    iVar3 = *piVar1;
  }
  return;
}

void func_001e3c18(int param_1)

{
  u16 uVar1;
  u16 uVar2;
  u64 uVar3;
  
  uVar1 = *(u16 *)(param_1 + 0x9c);
  uVar2 = *(u16 *)(param_1 + 0x9e);
  uVar3 = func_001e3650(*(u32 *)(param_1 + 0x88));
  uVar3 = func_001e3660(uVar3,2);
  uVar3 = func_001e38f8(uVar3,*(int *)(param_1 + 0x8c) + 0xc0,uVar1,uVar2);
  func_001e3a88(uVar3,*(int *)(param_1 + 0x8c) + 0xd0,uVar1,uVar2);
  return;
}

void func_001e41e0(int param_1)

{
  u64 uVar1;
  
  uVar1 = func_001e3650(*(u32 *)(param_1 + 0x88));
  uVar1 = func_001e3660(uVar1,2);
  uVar1 = func_001e3c98(uVar1,*(int *)(param_1 + 0x8c) + 0xc0);
  uVar1 = func_001e3e48(uVar1,*(int *)(param_1 + 0x8c) + 0xd0);
  func_001e4028(uVar1,*(int *)(param_1 + 0x8c) + 0xe0);
  return;
}

void func_001f4e18(int param_1,int param_2)

{
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  func_002223e0(param_1 + 0xa0);
  *(u32 *)(param_1 + 0x10c) = 0;
  *(u64 *)(param_1 + 0x110) = 0;
  *(u64 *)(param_1 + 0x118) = 0;
  *(u64 *)(param_1 + 0x120) = 0;
  *(u64 *)(param_1 + 0x128) = 0;
  *(u32 *)(param_1 + 0xdc) = 0;
  *(u32 *)(param_1 + 0xbc) = 0;
  *(u32 *)(param_1 + 0xd4) = 0;
  return;
}

void func_001fab08(int param_1,int param_2)

{
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  func_0021fa10(param_1 + 0xa0);
  *(u8 *)(param_1 + 0xa8) = 4;
  return;
}

void func_001fb720(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  func_001fa950();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xe4) = param_2[3];
    *(float *)(iVar1 + 0xe0) = (float)*(u16 *)(param_2 + 5);
  }
  return;
}

void func_001fb870(int param_1,int param_2)

{
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  func_0021fa10(param_1 + 0xa0);
  *(u8 *)(param_1 + 0xa8) = 4;
  return;
}

void func_001fb928(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  func_001fab48();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xc0) = param_2[3];
    *(float *)(iVar1 + 200) = (float)*(u16 *)(param_2 + 4);
    *(float *)(iVar1 + 0xcc) = (float)*(u16 *)((int)param_2 + 0x12);
  }
  return;
}

void func_001fbb20(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  func_001facf8();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xc0) = param_2[3];
    *(float *)(iVar1 + 200) = (float)*(u16 *)(param_2 + 4);
    *(u16 *)(iVar1 + 0xcc) = *(u16 *)((int)param_2 + 0x12);
  }
  return;
}

void func_002006b0(int param_1,int param_2)

{
  param_1 = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  func_002f3f88(param_1 + 0xa0,0x354bc0);
  func_002f3f88(param_1 + 0xb0,0x354be0);
  return;
}

void func_002007e0(int param_1,int param_2)

{
  param_1 = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  func_002f3f88(param_1 + 0xa0,0x354bc0);
  func_002f3f88(param_1 + 0xb0,0x354be0);
  return;
}

void func_002092e0(int param_1,u32 param_2,int param_3)

{
  if (*(int *)param_2 == *(int *)(param_1 + 0xc)) {
    func_00209178(param_2,param_1 + *(int *)(*(int *)(param_3 + 0xc) + 8) + 0xa0);
  }
  return;
}

void func_00209e80(int param_1,int param_2)

{
  param_1 = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  func_002f3f88(param_1 + 0xe0,0x354bc0);
  func_002f3f88(param_1 + 0xf0,0x354be0);
  return;
}

void func_0020e548(int param_1,u32 param_2,u32 param_3)

{
  if (*(int *)(param_1 + 4) == 0) {
    func_002fe0a0(0x370748,param_2,param_3,param_2);
    func_002fd348(1);
  }
  func_0020e2e8();
  return;
}

void func_00223608(u32 param_1,u32 *param_2)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  
  uVar1 = func_00313b80(*param_2);
  uVar2 = func_00313b80(param_2[1]);
  uVar3 = func_00313b80(param_2[2]);
  uVar4 = func_00313b80(param_2[3]);
  func_002fdfc8(0x370c68,param_1,uVar1,uVar2,uVar3,uVar4);
  return;
}

void func_00229d40(int param_1)

{
  func_00229b28((float)*(int *)(param_1 + 0xb9c),param_1,1,200,0);
  return;
}

u64 func_0022ae98(u32 *param_1)

{
  u64 uVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uVar1 = func_0022b688(0x8e);
  uStack_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  func_001391a8(uVar1,&uStack_30);
  func_002251c8(0x2f45);
  return uVar1;
}

u64 func_0022aef0(u32 *param_1)

{
  u64 uVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uVar1 = func_0022b688(0x8d);
  uStack_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  func_001391a8(uVar1,&uStack_30);
  func_002251c8(0x2f46);
  return uVar1;
}

u64 func_0022af48(u32 *param_1)

{
  u64 uVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uVar1 = func_0022b688(0x8c);
  uStack_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  func_001391a8(uVar1,&uStack_30);
  func_002251c8(0x2f47);
  return uVar1;
}

int func_0022b028(int param_1)

{
  s64 lVar1;
  
  func_002247e8();
  lVar1 = func_002249b8();
  if (lVar1 != 3) {
    lVar1 = func_002249b8();
    if (lVar1 != 5) {
      return 0;
    }
    if (-param_1 < 1) {
      return -param_1;
    }
  }
  func_002248f8(-param_1);
  return -param_1;
}

void func_0022cea0(int param_1)

{
  char cVar1;
  s64 lVar2;
  u64 uVar3;
  
  lVar2 = func_002282f0(*(u16 *)(param_1 + 4));
  if (lVar2 != 0) {
    return;
  }
  if (*(char *)(param_1 + 6) != '\0') {
    func_00167218();
    return;
  }
  cVar1 = *(char *)(param_1 + 7);
  uVar3 = func_00227ca8(param_1 + 8);
  func_001671e8(uVar3,cVar1 == '\0');
  return;
}

void func_0022cf18(u32 param_1)

{
  s64 lVar1;
  
  lVar1 = func_002f1670(0x1dad990);
  if (lVar1 == 0) {
    func_001024a8(param_1);
    return;
  }
  return;
}

void func_0022cf60(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_002282f0(*(u16 *)(param_1 + 4));
  if ((lVar1 == 0) && (lVar1 = func_00225b00(*(u16 *)(param_1 + 4)), lVar1 == 0)) {
    func_002f1460((float)(int)*(short *)(param_1 + 6),(float)(int)*(short *)(param_1 + 8),
                 (float)(int)*(short *)(param_1 + 10),
                 (float)(int)*(short *)(param_1 + 0xc) + (float)(int)*(short *)(param_1 + 0xc),
                 0x1dad990,*(u16 *)(param_1 + 0xe));
    func_00102c18(1,29999,0x22cf18);
    return;
  }
  return;
}

void func_0022d1d8(int param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_002282f0(*(u16 *)(param_1 + 4));
  if (lVar1 == 0) {
    uVar2 = func_00227ca8(param_1 + 8);
    func_0015c958(uVar2,*(u8 *)(param_1 + 0xc),*(u8 *)(param_1 + 0xd),
                 *(u8 *)(param_1 + 0xe),*(u8 *)(param_1 + 6),
                 *(u8 *)(param_1 + 7));
    return;
  }
  return;
}

void func_0022dd40(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_002282f0(*(u16 *)(param_1 + 4));
  if (lVar1 == 0) {
    func_00102c18(1,95000,0x22dc30);
    return;
  }
  return;
}

u32 func_0022e0a8(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = func_001de4b0(param_1 + 0x10,0,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  } while (*(int *)(param_1 + 0xc) != iVar1);
  return 1;
}
