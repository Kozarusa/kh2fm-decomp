#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00197920(...);
extern "C" bool func_001a6d08(...);
extern "C" bool func_002282f0(...);
extern "C" bool func_002424c0(...);
extern "C" s32 func_00168aa0(...);
extern "C" s32 func_001d56c8(...);
extern "C" s32 func_00227a28(...);
extern "C" s32 func_00227a60(...);
extern "C" s32 func_00236ca8(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_00103500(...);
extern "C" u32 func_00103550(...);
extern "C" u32 func_001037b8(...);
extern "C" u32 func_001039f8(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_001063f0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0014aa58(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_00168388(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001ba028(...);
extern "C" u32 func_00227870(...);
extern "C" u32 func_00227d10(...);
extern "C" u32 func_00227da8(...);
extern "C" u32 func_0023a0d8(...);
extern "C" u32 func_0023d410(...);
extern "C" u32 func_0023f0c8(...);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00240118(...);
extern "C" u32 func_00242088(...);
extern "C" u32 func_00242880(...);
extern "C" u32 func_00246868(...);
extern "C" u32 func_00250fb8(...);
extern "C" u32 func_002513b0(...);
extern "C" u32 func_00251780(...);
extern "C" u32 func_00252020(...);
extern "C" u32 func_00253180(...);
extern "C" u32 func_00253330(...);
extern "C" u32 func_00253578(...);
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(...);
extern "C" u32 func_002539e8(...);
extern "C" u32 func_00257000(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_00276c18(...);
extern "C" u32 func_0027dc08(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287cc0(...);
extern "C" u32 func_00287d68(...);
extern "C" u32 func_00288648(...);
extern "C" u32 func_0028da70(...);
extern "C" u32 func_002ba978(...);
extern "C" u32 func_002bd680(...);
extern "C" u32 func_002bd760(...);
extern "C" u32 func_002f2be0(...);
extern "C" u32 func_002f35e8(...);
extern "C" u32 func_002f3918(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_002ff2e8(...);
extern "C" u32 func_0031acc0(...);
extern "C" u64 func_0022e188(...);
extern "C" u64 func_00232498(...);
extern "C" u8 func_00103b38(...);
extern "C" u8 func_001a6598(...);
extern "C" u8 func_00253918(...);
extern "C" u8 func_00287db0(...);
extern "C" u8 func_002ef7b8(...);

void func_0022e1f8(u64 param_1,u32 param_2)

{
  u32 *puVar1;
  u64 uVar3;
  u64 uVar4;
  u64 uVar2;
  
  uVar2 = func_00227a28();
  puVar1 = (u32 *)uVar2;
  puVar1[3] = param_2;
  *puVar1 = 2;
  puVar1[4] = 0xffffffff;
  func_002ff2e8(puVar1 + 0xc,param_1);
  uVar3 = func_0022e188(param_1);
  uVar4 = func_00227870(uVar3,uVar2,0);
  puVar1[5] = (int)uVar4;
  func_00168388(uVar3,uVar4,0x22e160,uVar2);
  return;
}

void func_0022e6b0(u32 param_1,int param_2,u64 param_3)

{
  int iVar1;
  
  func_001ba028(param_3);
  iVar1 = (int)param_3;
  if (param_2 == 1) {
    *(u32 *)(iVar1 + 0x38) = param_1;
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      *(u32 *)(iVar1 + 0x34) = param_1;
    }
  }
  else if (param_2 == 2) {
    *(u32 *)(iVar1 + 0x30) = param_1;
  }
  return;
}

void func_0022efb8(int param_1)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_002282f0(*(u16 *)(param_1 + 4));
  if (lVar1 == 0) {
    iVar2 = func_00227d10(*(u16 *)(param_1 + 0xc));
    *(int *)(iVar2 + 0xc) = (int)*(short *)(param_1 + 4);
    *(int *)(iVar2 + 0x10) = (int)*(short *)(param_1 + 4) + (int)*(short *)(param_1 + 10);
    *(u8 *)(iVar2 + 0x14) = *(u8 *)(param_1 + 8);
    *(u8 *)(iVar2 + 0x15) = *(u8 *)(param_1 + 9);
  }
  return;
}

void func_0022f528(int param_1)

{
  int iStack_50;
  int iStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u8 uStack_3c;
  u8 uStack_3b;
  u8 uStack_3a;
  u8 auStack_39 [25];
  
  iStack_50 = -1;
  iStack_4c = 0xffffffff;
  uStack_48 = 0;
  uStack_3a = 0;
  auStack_39[0] = 0;
  func_002ff2e8(auStack_39,param_1 + 8);
  uStack_40 = 0xffffffff;
  uStack_44 = 0xffffffff;
  iStack_4c = (int)*(short *)(param_1 + 6);
  iStack_50 = (int)*(short *)(param_1 + 4);
  uStack_48 = 0;
  uStack_3c = 0;
  uStack_3b = 0;
  func_00227da8(&iStack_50);
  return;
}

void func_0022f5a0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  
  func_0016ed50(param_2 | 0x40000000,0xffffffffffffffff,0x1e);
  iVar1 = func_00227d10(param_3);
  *(u8 *)(iVar1 + 0x16) = 1;
  return;
}

void func_00232510(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  
  uVar1 = func_00227a60(param_1,3);
  uVar2 = func_00232498(param_1);
  iVar3 = (int)uVar1 + 0x30;
  func_002ff2e8(iVar3,uVar2);
  uVar2 = func_00227870(iVar3,uVar1,param_2);
  *(int *)((int)uVar1 + 0x14) = (int)uVar2;
  func_00168388(iVar3,uVar2,0x226030,uVar1);
  return;
}

void func_002367a0(void)

{
  u64 uVar1;
  
  uVar1 = func_002f35e8(2);
  func_002f3918(uVar1,0x35e3f0);
  return;
}

void func_002367c8(int param_1)

{
  u64 uVar1;
  
  uVar1 = *(u64 *)(param_1 + 0x30);
  if (((s64)uVar1 >> 0x20 & 1U) == 0) {
    func_002f2be0(param_1 + 0x40,*(u32 *)(param_1 + 0x38));
    uVar1 = *(u64 *)(param_1 + 0x30);
  }
  if ((uVar1 >> 0x21 & 1) != 0) {
    return;
  }
  func_002f2be0(param_1 + 0xa0,*(u32 *)(param_1 + 0x3c));
  return;
}

void func_0023a9c0(int param_1,u32 *param_2,u32 *param_3)

{
  if (*(char *)(param_1 + 0xd4) == '\0') {
    func_0023a0d8();
  }
  *param_2 = *(u32 *)(param_1 + 0xe4);
  *param_3 = *(u32 *)(param_1 + 0xe8);
  return;
}

void func_0023d3d0(void)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  func_002fde18(iVar1 + 0x419c,0,0x1404);
  func_00242880();
  func_0023d410();
  func_00257000();
  return;
}

void func_0023ef50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar2 + 1;
      iVar2 = func_00236ca8(*(u32 *)(param_1 + 0x58),iVar2);
      *(u8 *)(iVar2 + 400) = 1;
      iVar2 = iVar3;
    } while (iVar3 < iVar1);
  }
  return;
}

void func_0023f070(u64 param_1,u32 param_2,u64 param_3)

{
  func_00139d78();
  *(u32 *)((int)param_1 + 0x98) = param_2;
  *(u32 *)((int)param_1 + 0x8c) = param_2;
  func_0023f0c8(param_1,param_3);
  return;
}

void func_0023f5b8(int param_1,int param_2)

{
  u32 uVar1;
  
  func_00139d78();
  if ((-1 < param_2) && (param_2 != *(int *)(param_1 + 0x24))) {
    uVar1 = func_00192048(param_2);
    *(u32 *)(param_1 + 0x20) = uVar1;
    *(int *)(param_1 + 0x24) = param_2;
  }
  return;
}

void func_0023f628(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x40) = param_2;
  return;
}

void func_0023f688(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x28) = param_2;
  return;
}

void func_0023f6c0(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x48) = param_2;
  return;
}

void func_0023f740(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x44) = param_2;
  return;
}

void func_0023f8c8(int param_1)

{
  if (*(char *)(param_1 + 0x18) != '\0') {
    func_0023fad0();
  }
  *(u32 *)(param_1 + 4) = 0;
  return;
}

void func_0023fa08(int param_1,u64 param_2)

{
  u32 uVar1;
  
  *(int *)(param_1 + 4) = (int)param_2;
  uVar1 = func_00168aa0(param_2,0x1c);
  *(u32 *)(param_1 + 8) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x1d);
  *(u32 *)(param_1 + 0x10) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x19);
  *(u32 *)(param_1 + 0xc) = uVar1;
  uVar1 = func_00168aa0(*(u32 *)(param_1 + 4),0x18);
  *(u32 *)(param_1 + 0x14) = uVar1;
  return;
}

void func_00240240(int param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  u8 auStack_80 [80];
  
  func_002ff2e8(auStack_80,0x371698);
  iVar2 = 1;
  iVar1 = func_002ff3fc(auStack_80);
  func_00240118(auStack_80 + iVar1,param_2,param_3);
  iVar1 = func_002ff3fc(auStack_80);
  do {
    func_002ff2e8(param_1,auStack_80);
    iVar2 = iVar2 + -1;
    param_1 = param_1 + iVar1;
  } while (-1 < iVar2);
  return;
}

void func_00241fd0(u64 param_1,u32 param_2)

{
  u32 uVar1;
  
  *(u32 *)param_1 = param_2;
  uVar1 = func_001063f0(0x400);
  ((u32 *)param_1)[1] = uVar1;
  func_00242088(param_1);
  return;
}

u32 func_00242500(int param_1)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_002424c0();
  if (lVar2 == 0) {
    iVar1 = func_001058e8();
    param_1 = 999999;
  }
  else {
    iVar1 = func_001058e8();
    param_1 = *(int *)(iVar1 + 0x2440) + param_1;
  }
  *(int *)(iVar1 + 0x2440) = param_1;
  iVar1 = func_001058e8();
  return *(u32 *)(iVar1 + 0x2440);
}

void func_00242740(s64 param_1)

{
  s64 lVar1;
  
  if (param_1 < 0) {
    lVar1 = func_00197920();
    param_1 = 1;
    if (lVar1 == 0) {
      param_1 = 2;
    }
  }
  func_002ba978(param_1);
  lVar1 = func_002ef7b8();
  if (lVar1 != 0) {
    func_002bd680();
    return;
  }
  return;
}

void func_00242980(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *param_1 = (int)*(short *)(iVar1 + 0x41a0);
  *param_2 = (int)*(short *)(iVar1 + 0x41a2);
  return;
}

void func_002429c0(u16 param_1,u16 param_2)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u16 *)(iVar1 + 0x41a0) = param_1;
  *(u16 *)(iVar1 + 0x41a2) = param_2;
  return;
}

void func_00242a28(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffffffe | (u32)(param_1 != '\0');
  return;
}

void func_00242a90(s64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_001058e8();
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = 2, param_1 != 2)) {
    iVar2 = 1;
  }
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffffff9 | iVar2 << 1;
  return;
}

void func_00242b10(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffffff7 | (u32)(param_1 != '\0') << 3;
  return;
}

void func_00242b88(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xffffffef | (u32)(param_1 == '\0') << 4;
  return;
}

void func_00242ca0(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xffffffbf | (u32)(param_1 == '\0') << 6;
  return;
}

void func_00242d10(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xffffff7f | (u32)(param_1 != '\0') << 7;
  return;
}

void func_00242d80(char param_1)

{
  int iVar1;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffffeff | (u32)(param_1 != '\0') << 8;
  return;
}

void func_00242df0(s64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_001058e8();
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = 2, param_1 != 2)) {
    iVar2 = 1;
  }
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xfffff9ff | iVar2 << 9;
  return;
}

void func_00243230(int param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_001058e8();
  uVar4 = param_1 * 8 + param_2;
  puVar3 = (u32 *)((uVar4 >> 5) * 4 + iVar2 + 0x49d8);
  uVar1 = *puVar3;
  uVar4 = 1 << (uVar4 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

u64 func_00244938(s64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  uVar2 = 1;
  if (param_1 == 0) {
    lVar1 = func_001a6d08(1);
    uVar2 = 0x76;
    if (lVar1 == 0) {
      return 1;
    }
  }
  uVar2 = func_001a6d08(uVar2);
  return uVar2;
}

u32 func_00244a10(void)

{
  u8 *pbVar1;
  s64 lVar2;
  
  pbVar1 = (u8 *)func_001d56c8(8);
  if ((*pbVar1 < 2) && (lVar2 = func_00276c18(), lVar2 == 0)) {
    return 0;
  }
  return 1;
}

void func_00246968(int param_1)

{
  int iVar1;
  
  iVar1 = func_00246868();
  func_001a6d08(*(u8 *)(param_1 * 0x24 + iVar1 + 0x1c));
  return;
}

u32 func_00249480(int param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = param_1 * 0x24 + 0x371d90;
  iVar2 = iVar4;
  while( true ) {
    iVar3 = iVar3 + 1;
    if (*(char *)(iVar2 + 0x20) < '\0') {
      return 1;
    }
    lVar1 = func_001a6d08(*(char *)(iVar2 + 0x20));
    if (lVar1 != 0) break;
    iVar2 = iVar4 + iVar3;
    if (3 < iVar3) {
      return 1;
    }
  }
  return 0;
}

u32 func_0024ad50(void)

{
  u8 *pbVar1;
  s64 lVar2;
  
  pbVar1 = (u8 *)func_001d56c8(10);
  if ((*pbVar1 < 2) && (lVar2 = func_00276c18(), lVar2 == 0)) {
    return 0;
  }
  return 1;
}

u32 func_00251318(void)

{
  u32 uVar1;
  s64 lVar2;
  s64 lVar3;
  
  lVar2 = func_00287bc0();
  func_00287d68();
  func_00252020();
  lVar3 = func_00287db0();
  if (lVar3 == 0) {
    if (lVar2 == 0) {
      func_002513b0();
      uVar1 = 0;
    }
    else if (lVar2 == 1) {
      func_00251780();
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    lVar2 = func_00250fb8();
    uVar1 = 0;
    if (lVar2 == 0) {
      func_00252020();
      func_001039f8();
      uVar1 = 1;
    }
  }
  return uVar1;
}

void func_002534e0(void)

{
  s64 lVar1;
  s64 lVar2;
  
  func_0027dc08();
  lVar1 = func_00103550();
  lVar2 = func_00103b38();
  if ((lVar2 != 0) && (lVar1 == 0x32)) {
    return;
  }
  func_00253180(0xe,0xffffffffffffffff);
  return;
}

void func_00253538(void)

{
  int iVar1;
  
  func_00288648();
  iVar1 = func_00253330(10);
  func_00103500(*(u16 *)(iVar1 + 2));
  func_001037b8();
  return;
}

void func_00256ef0(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_00139d78(iVar1 + 0xb7c);
  return;
}

u8 func_00257158(s64 param_1,s64 param_2,char param_3)

{
  int iVar1;
  s64 lVar2;
  u8 uVar3;
  
  uVar3 = 0;
  if (param_1 != 0) {
    iVar1 = func_001a80c8();
    if (*(char *)(iVar1 + 2) == '\0') {
      if (param_3 == '\0') {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        if (param_2 == 0) {
          uVar3 = 3;
        }
      }
    }
    else if (*(char *)(iVar1 + 2) == '\x12') {
      lVar2 = func_001a6598(*(u16 *)(iVar1 + 4));
      uVar3 = lVar2 == 2 && param_3 != '\0';
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

void func_00258158(u64 param_1)

{
  func_0031acc0((int)param_1 + 0x368);
  func_0031acc0((int)param_1 + 0x1b4);
  func_0031acc0(param_1);
  return;
}

bool func_00259350(u64 param_1)

{
  s64 lVar1;
  bool bVar2;
  
  lVar1 = func_002538f8();
  bVar2 = true;
  if (lVar1 == 0) {
    lVar1 = func_00253928(param_1);
    bVar2 = true;
    if (lVar1 == 0) {
      lVar1 = func_00253918();
      bVar2 = false;
      if (lVar1 == 0) {
        lVar1 = func_002539e8(param_1,0);
        bVar2 = lVar1 == 0;
      }
    }
  }
  return bVar2;
}

void func_0025cd40(void)

{
  u64 uVar1;
  
  uVar1 = func_0014aba8();
  func_0014aa58(uVar1,0xf,0);
  func_002bd760(0x3c);
  func_00287cc0(0);
  return;
}

u64 func_0025d620(s64 param_1)

{
  s64 lVar1;
  
  lVar1 = func_00287bc0();
  if (lVar1 != 1) {
    if (lVar1 < 2) {
      if (lVar1 != 0) {
        return 0;
      }
      if (param_1 == 0) {
        return 1;
      }
      lVar1 = func_00253578();
      if (lVar1 == 0) {
        return 1;
      }
      return 0;
    }
    if (lVar1 != 0xc) {
      return 0;
    }
  }
  return 1;
}

s64 func_00262650(void)

{
  int iVar1;
  s64 lVar2;
  s64 lVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = func_00257770();
  lVar2 = func_00139d78(iVar1 + 0x9c8);
  if (lVar2 == 0) {
    iVar5 = 0;
    iVar4 = iVar1 + 0xd30;
    do {
      lVar3 = func_00139d78(iVar4);
      iVar5 = iVar5 + 1;
      if (lVar3 != 0) {
        lVar2 = 1;
        break;
      }
      iVar4 = iVar4 + 0x1b4;
    } while (iVar5 < 5);
    if (lVar2 == 0) {
      lVar2 = func_00139d78(iVar1 + 0x330);
    }
  }
  return lVar2;
}

void func_00262730(void)

{
  int iVar1;
  
  iVar1 = func_00257770();
  func_00139d78(iVar1 + 0x9c8);
  func_0028da70(iVar1 + 0x9c8,0xf2);
  return;
}
