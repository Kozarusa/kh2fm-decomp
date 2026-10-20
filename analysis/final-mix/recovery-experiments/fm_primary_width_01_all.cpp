#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_001058e8(...);
extern "C" u32 func_001064a8(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_001390f0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_0016a9a0(...);
extern "C" u32 func_001708f8(...);
extern "C" u32 func_00170950(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0018a958(...);
extern "C" u32 func_00192048(...);
extern "C" int func_001b9bc8(...);
extern "C" u32 func_001d5800(...);
extern "C" u32 func_001d5868(...);
extern "C" bool func_001d58f0(...);
extern "C" u32 func_001d7980(...);
extern "C" u8 func_001dc018(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_001dc790(...);
extern "C" u32 func_001dc920(...);
extern "C" bool func_001dc9e0(...);
extern "C" bool func_001dcc60(...);
extern "C" u32 func_001e0058(...);
extern "C" u32 func_00229d40(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_002368e8(...);
extern "C" u32 func_0023fa08(...);
extern "C" u32 func_00242740(...);
extern "C" u32 func_00242b58(...);
extern "C" u32 func_00242b88(...);
extern "C" u32 func_00242bd0(...);
extern "C" u32 func_00253180(...);
extern "C" u32 func_002535d0(...);
extern "C" u32 func_002537c8(...);
extern "C" u32 func_00258b00(...);
extern "C" u32 func_002637e8(...);
extern "C" u32 func_00276568(...);
extern "C" u32 func_002766d0(...);
extern "C" u32 func_00276c50(...);
extern "C" u32 func_00280ef8(...);
extern "C" u32 func_00281008(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00288ce0(...);
extern "C" int func_0028c198(...);
extern "C" u32 func_0028e438(...);
extern "C" u32 func_00294000(...);
extern "C" u32 func_002941a8(...);
extern "C" u32 func_002941d8(...);
extern "C" u32 func_00294288(...);
extern "C" int func_00295158(...);
extern "C" int func_002953c8(...);
extern "C" u32 func_002b7078(...);
extern "C" u32 func_002b726c(...);
extern "C" u32 func_002b72e4(...);
extern "C" u32 func_002b73ac(...);
extern "C" u32 func_002b78ec(...);
extern "C" u32 func_002b7fbc(...);
extern "C" u32 func_002b83b4(...);
extern "C" u32 func_002b9b78(...);
extern "C" u32 func_002b9ed0(...);
extern "C" u32 func_002ba390(...);
extern "C" u32 func_002baa60(...);
extern "C" u32 func_002bb1c8(...);
extern "C" u32 func_002bb310(...);
extern "C" u32 func_002bc158(...);
extern "C" u32 func_002bc398(...);
extern "C" u32 func_002bc3f0(...);
extern "C" u32 func_002bce40(...);
extern "C" u32 func_002bce50(...);
extern "C" s32 func_002be908(...);
extern "C" u32 func_002bf8f0(...);
extern "C" u32 func_002c1cb0(...);
extern "C" u32 func_002d0bd8(...);
extern "C" u32 func_002db610(...);
extern "C" u32 func_002eb6f8(...);
extern "C" u32 func_002f3490(...);
extern "C" u32 func_002f3588(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00306f30(...);
extern "C" int func_003071d0(...);
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_003105b0(...);
extern "C" u32 func_00313b80(...);
extern "C" u32 func_003142e0(...);
extern "C" u32 func_00321ce8(...);

void func_001d5960(u32 param_1)

{
  s32 lVar1;
  
  lVar1 = func_001d5868();
  if ((lVar1 == 0) && (lVar1 = func_001d58f0(param_1), lVar1 != 0)) {
    func_001d5800(param_1);
    return;
  }
  return;
}

void func_001d7b10(u16 *param_1)

{
  int iVar1;
  u16 *puVar2;
  int iVar3;
  
  *param_1 = 0;
  puVar2 = param_1 + 2;
  iVar3 = 3;
  iVar1 = *(int *)puVar2;
  while( true ) {
    puVar2 = puVar2 + 4;
    if (iVar1 != 0) {
      iVar1 = func_001d7980(iVar1);
      *param_1 = *param_1 | *(u16 *)(iVar1 + 2);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar1 = *(int *)puVar2;
  }
  return;
}

s32 func_001dba18(int param_1)

{
  s32 lVar1;
  
  lVar1 = 0;
  do {
    lVar1 = func_001b9bc8(lVar1);
    if (lVar1 == 0) {
      return 0;
    }
  } while (((*(u32 *)((int)lVar1 + 0x588) & 0x10000000) == 0) ||
          (*(int *)((int)lVar1 + 8) != param_1));
  return lVar1;
}

bool func_001dc4e8(int param_1,u32 param_2,u32 param_3,u32 param_4)

{
  s32 lVar1;
  
  lVar1 = func_001dc018(param_2,param_3,param_1 + 0x14,param_1 + 0x18);
  if (lVar1 != 0) {
    *(u32 *)(param_1 + 0x10) = param_4;
  }
  return lVar1 != 0;
}

void func_001e00b0(int param_1)

{
  u32 uVar1;
  s32 lVar2;
  u32 uVar3;
  
  if (*(int *)(param_1 + 0x54) < 0) {
    return;
  }
  lVar2 = func_001dc790(*(u32 *)(param_1 + 0x40));
  if (lVar2 == 0) {
    lVar2 = func_001dcc60(*(u32 *)(param_1 + 0x40));
    if (lVar2 != 0) {
      uVar3 = func_001dc5f8(*(u32 *)(param_1 + 0x40));
      func_002bc398(*(u32 *)(param_1 + 0x54),uVar3);
      return;
    }
    uVar1 = *(u32 *)(param_1 + 0x54);
  }
  else {
    uVar1 = *(u32 *)(param_1 + 0x54);
  }
  func_002bc3f0(uVar1);
  return;
}

void func_00236bb8(u32 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_2 + 0x10)) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      func_002368e8(param_1,*(int *)(param_2 + 0x14) + iVar1);
      func_002367c8(*(int *)(param_2 + 0x14) + iVar1);
      iVar1 = iVar1 + 0x1a0;
    } while (iVar2 < *(int *)(param_2 + 0x10));
  }
  return;
}

void func_0023f0c8(int param_1,u32 param_2)

{
  func_00139d78();
  *(u32 *)(param_1 + 0x90) = param_2;
  return;
}

void func_0023fa90(u32 param_1,u32 param_2)

{
  u32 uVar1;
  
  uVar1 = func_001708f8(param_2,0xffffffffffffffff);
  func_0023fa08(param_1,uVar1);
  *(u8 *)((int)param_1 + 0x18) = 1;
  return;
}

void func_00242c00(char param_1)

{
  int iVar1;
  s32 lVar2;
  
  iVar1 = func_001058e8();
  *(u32 *)(iVar1 + 0x41a4) = *(u32 *)(iVar1 + 0x41a4) & 0xffffffdf | (u32)(param_1 == '\0') << 5;
  lVar2 = func_00242bd0();
  if ((lVar2 == 0) && (lVar2 = func_00242b58(), lVar2 == 0)) {
    func_00242b88(1);
    return;
  }
  return;
}

void func_00253410(u32 param_1,u32 param_2)

{
  u32 uVar1;
  int iVar2;
  
  if (((*(u8 *)((int)param_1 + 0x25) ^ 1) & 1) == 0) {
    iVar2 = func_0014aba8();
    *(u32 *)(iVar2 + 0xfc) = 0;
  }
  func_00258b00(param_1,param_2);
  uVar1 = func_002535d0(8);
  func_00242740(uVar1);
  func_00253180(8,0xffffffffffffffff);
  return;
}

void func_00256b40(void)

{
  u32 uVar1;
  
  uVar1 = func_002537c8(2);
  func_0023fa08(0x35f3a8,uVar1);
  return;
}

u32 func_002638e0(s32 param_1)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = func_00287bc0();
  if (lVar2 != 10) {
    if (10 < lVar2) {
      if (lVar2 != 0xb) {
        return 1;
      }
      if (param_1 < 0) {
        return 0;
      }
      uVar1 = func_002637e8(param_1);
      return ~uVar1 >> 0x1f;
    }
    if (lVar2 == 1) {
      return 1;
    }
  }
  return 1;
}

void func_00281f90(int param_1)

{
  u32 *puVar1;
  int iVar2;
  
  *(u32 *)(param_1 + 0x100c) = 0xffffffff;
  puVar1 = (u32 *)(param_1 + 0x1010);
  *(u32 *)(param_1 + 0x1008) = 0xffffffff;
  iVar2 = 4;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  func_002fde18(param_1 + 0x1024,0,0x40);
  return;
}

void func_00288d80(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,u32 param_6,u32 param_7,u32 param_8)

{
  u32 uVar1;
  
  uVar1 = func_0028c198(*(u16 *)param_7,param_3,param_4,param_5,param_6,0);
  *(int *)((int)uVar1 + 0x188) = (int)(short)((u16 *)param_7)[2];
  *(u32 *)((int)uVar1 + 0x1ac) = 1;
  func_00288ce0(param_1,uVar1,param_2,param_7,param_8);
  return;
}

u32 func_0028acc8(int param_1)

{
  s32 lVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  sVar2 = *(short *)(param_1 + 4);
  if (0 < sVar2) {
    iVar4 = *(int *)(param_1 + 0x28);
    while( true ) {
      iVar3 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      iVar4 = *(int *)(iVar3 + iVar4);
      if (iVar4 != 0) {
        lVar1 = func_00139d78(iVar4);
        if (lVar1 != 0) {
          return 1;
        }
        sVar2 = *(short *)(param_1 + 4);
      }
      if (sVar2 <= iVar5) break;
      iVar4 = *(int *)(param_1 + 0x28);
    }
  }
  return 0;
}

bool func_0028b1c0(int param_1,u32 param_2)

{
  return *(u32 *)(param_1 + 0x20) != 0 && (*(u32 *)(param_1 + 0x20) & 1 << (param_2 & 0x1f)) != 0;
}

void func_0028da70(u32 param_1,int param_2)

{
  s32 lVar1;
  
  lVar1 = func_00139d78();
  if ((lVar1 != 0) && (*(int *)((int)param_1 + 0x184) != param_2)) {
    func_00138c10(param_1,param_2);
    *(u32 *)((int)param_1 + 0x188) = 0xffffffff;
  }
  return;
}

void func_0028e560(u32 param_1,u16 *param_2,int param_3,u32 param_4)

{
  int iVar1;
  int iVar2;
  
  func_00139d78();
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar2 = iVar1 + 1;
      func_0028e438(param_1,iVar1,*param_2,param_4);
      param_2 = param_2 + 1;
      iVar1 = iVar2;
    } while (iVar2 < param_3);
  }
  return;
}

void func_00290a60(int param_1)

{
  func_00170950(*(u32 *)(param_1 + 4));
  *(u8 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 4) = 0;
  return;
}

u16 func_00295270(u32 param_1,char param_2)

{
  u16 uVar1;
  int iVar2;
  int iVar3;
  s32 lVar4;
  
  iVar2 = func_00294000(0);
  iVar3 = func_00295158(param_1);
  iVar2 = iVar2 + 0x10 + iVar3 * 0x10;
  if (param_2 == '\0') {
    lVar4 = func_002941d8(iVar2);
    if (lVar4 == 0) {
      uVar1 = *(u16 *)(iVar2 + 4);
    }
    else {
      uVar1 = *(u16 *)(iVar2 + 10);
    }
  }
  else {
    lVar4 = func_002941d8(iVar2);
    if (lVar4 == 0) {
      uVar1 = *(u16 *)(iVar2 + 6);
    }
    else {
      uVar1 = *(u16 *)(iVar2 + 0xc);
    }
  }
  return uVar1;
}

void func_002954e0(void)

{
  u32 uVar1;
  
  uVar1 = func_002953c8();
  func_002941a8(uVar1);
  return;
}

void func_002960d0(void)

{
  int iVar1;
  u8 *puVar2;
  u32 uVar3;
  u32 uStack_40;
  u32 auStack_3c [3];
  
  iVar1 = func_002766d0();
  puVar2 = (u8 *)func_00276568();
  func_00294288(*puVar2,&uStack_40,auStack_3c);
  uVar3 = func_00192048(uStack_40);
  *(u32 *)(iVar1 + 0x7f8) = uVar3;
  uVar3 = func_00192048(0x3253);
  *(u32 *)(iVar1 + 0x9ac) = uVar3;
  uVar3 = func_00192048(auStack_3c[0]);
  *(u32 *)(iVar1 + 0xb60) = uVar3;
  uVar3 = func_00192048(0x3254);
  *(u32 *)(iVar1 + 0xd14) = uVar3;
  return;
}

void func_00299260(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48d8;
  if (lVar1 != 4) {
    uVar2 = 0x48d9;
  }
  func_00276c50(uVar2,0);
  return;
}

void func_002a03a0(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48ec;
  if (lVar1 != 0x18) {
    uVar2 = 0x48ed;
  }
  func_00276c50(uVar2,0);
  return;
}

void func_002a65a0(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48f8;
  if (lVar1 != 0x25) {
    uVar2 = 0x4b00;
  }
  func_00276c50(uVar2,0);
  return;
}

void func_002b8a70(int param_1)

{
  func_002b78ec(param_1 + 0x8000);
  *(u32 *)(param_1 + 0x48000) = 0;
  return;
}

void func_002b9e80(void)

{
  func_002b7fbc(0);
  func_002bce40(0x1e2a410);
  func_002bce50(0x1e2a410);
  func_002b9b78();
  func_002ba390();
  func_002b9ed0();
  return;
}

u32 func_002bc188(u32 param_1,u32 param_2)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb1c8(lVar2,param_1,param_2);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,param_1,param_2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}

void func_002bf978(void)

{
  s32 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_002be908(lVar1), lVar1 != 0) {
    if ((*(u32 *)((int)lVar1 + 0x588) & 0x80000000) != 0) {
      func_002bf8f0(lVar1);
    }
  }
  return;
}

void func_002c1b60(int param_1,char *param_2)

{
  u32 uVar1;
  
  if ((*param_2 == '\x01') || (*param_2 == '\x02')) {
    uVar1 = *(u32 *)(param_1 + 0x108) & 0xffffff9d;
  }
  else {
    uVar1 = *(u32 *)(param_1 + 0x108) | 0x62;
  }
  *(u32 *)(param_1 + 0x108) = uVar1;
  func_002c1cb0(*(u32 *)(param_1 + 0xae4),*param_2);
  *(char *)(param_1 + 0xae8) = *param_2;
  return;
}

void func_002db7d0(u32 param_1)

{
  u32 uVar1;
  
  func_0016a9a0();
  uVar1 = 0xffffffffffffffff;
  if ((*(u8 *)((int)param_1 + 0x238) & 1) != 0) {
    uVar1 = 0;
  }
  func_002db610(param_1,uVar1);
  return;
}

void func_002dc140(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  u32 *puVar16;
  
  puVar16 = (u32 *)(param_1 + 0xb20);
  if ((u32 *)(param_1 + 0xb60) != puVar16) {
    *(u32 *)(param_1 + 0xb60) = *puVar16;
    *(u32 *)(param_1 + 0xb64) = *(u32 *)(param_1 + 0xb24);
    *(u32 *)(param_1 + 0xb68) = *(u32 *)(param_1 + 0xb28);
    *(u32 *)(param_1 + 0xb6c) = *(u32 *)(param_1 + 0xb2c);
    *(u32 *)(param_1 + 0xb70) = *(u32 *)(param_1 + 0xb30);
    *(u32 *)(param_1 + 0xb74) = *(u32 *)(param_1 + 0xb34);
    *(u32 *)(param_1 + 0xb78) = *(u32 *)(param_1 + 0xb38);
    *(u32 *)(param_1 + 0xb7c) = *(u32 *)(param_1 + 0xb3c);
    *(u32 *)(param_1 + 0xb80) = *(u32 *)(param_1 + 0xb40);
    *(u32 *)(param_1 + 0xb84) = *(u32 *)(param_1 + 0xb44);
    *(u32 *)(param_1 + 0xb88) = *(u32 *)(param_1 + 0xb48);
    *(u32 *)(param_1 + 0xb8c) = *(u32 *)(param_1 + 0xb4c);
    *(u32 *)(param_1 + 0xb90) = *(u32 *)(param_1 + 0xb50);
    *(u32 *)(param_1 + 0xb94) = *(u32 *)(param_1 + 0xb54);
    *(u32 *)(param_1 + 0xb98) = *(u32 *)(param_1 + 0xb58);
    *(u32 *)(param_1 + 0xb9c) = *(u32 *)(param_1 + 0xb5c);
  }
  if (puVar16 != param_2) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    uVar4 = param_2[4];
    uVar5 = param_2[5];
    uVar6 = param_2[6];
    uVar7 = param_2[7];
    uVar8 = param_2[8];
    uVar9 = param_2[9];
    uVar10 = param_2[10];
    uVar11 = param_2[0xb];
    uVar12 = param_2[0xc];
    uVar13 = param_2[0xd];
    uVar14 = param_2[0xe];
    uVar15 = param_2[0xf];
    *puVar16 = *param_2;
    *(u32 *)(param_1 + 0xb24) = uVar1;
    *(u32 *)(param_1 + 0xb28) = uVar2;
    *(u32 *)(param_1 + 0xb2c) = uVar3;
    *(u32 *)(param_1 + 0xb30) = uVar4;
    *(u32 *)(param_1 + 0xb34) = uVar5;
    *(u32 *)(param_1 + 0xb38) = uVar6;
    *(u32 *)(param_1 + 0xb3c) = uVar7;
    *(u32 *)(param_1 + 0xb40) = uVar8;
    *(u32 *)(param_1 + 0xb44) = uVar9;
    *(u32 *)(param_1 + 0xb48) = uVar10;
    *(u32 *)(param_1 + 0xb4c) = uVar11;
    *(u32 *)(param_1 + 0xb50) = uVar12;
    *(u32 *)(param_1 + 0xb54) = uVar13;
    *(u32 *)(param_1 + 0xb58) = uVar14;
    *(u32 *)(param_1 + 0xb5c) = uVar15;
  }
  func_002d0bd8();
  return;
}

void func_002e34d8(u32 param_1,int param_2)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

void func_002e95a0(u32 param_1,u32 param_2,int param_3)

{
  u32 uVar1;
  s32 lVar2;
  
  *(u32 *)(param_3 + 0x38) = param_2;
  *(u32 *)(param_3 + 0x34) = param_1;
  uVar1 = func_00313b80(param_2);
  lVar2 = func_003142e0(0,uVar1);
  uVar1 = 0;
  if (-1 < lVar2) {
    uVar1 = 3;
    param_2 = param_1;
  }
  func_0018a958(param_1,param_2,param_3 + 0x10,uVar1);
  return;
}

void func_002e9610(u32 *param_1,u32 *param_2)

{
  int iVar1;
  s32 lVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  if (param_1 != param_2) {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar4;
    param_1[2] = uVar5;
    param_1[3] = uVar6;
  }
  if (param_1 + 8 == param_2) {
    iVar1 = param_1[0xf];
  }
  else {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    param_1[8] = *param_2;
    param_1[9] = uVar4;
    param_1[10] = uVar5;
    param_1[0xb] = uVar6;
    iVar1 = param_1[0xf];
  }
  if (((iVar1 != 0) && (lVar2 = func_001dc9e0(iVar1), lVar2 != 0)) &&
     (puVar3 = (u32 *)func_001dc5f8(param_1[0xf]), puVar3 != param_2)) {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    *puVar3 = *param_2;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
  }
  return;
}

void func_002eb778(int param_1,int param_2,char param_3)

{
  u32 uVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == '\0') {
    uVar1 = *(u32 *)(param_1 + 0x160);
    if ((((uVar1 & 4) != 0) || ((uVar1 & 8) != 0)) || (bVar3 = false, (uVar1 & 0x10) != 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      iVar2 = *(int *)(param_1 + 0x154);
    }
    else {
      if ((uVar1 & 0x10) == 0) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x154);
    }
    if (iVar2 == param_2) {
      return;
    }
  }
  func_002eb6f8();
  return;
}

void func_002eb9d8(u32 param_1,int param_2,int param_3)

{
  if ((((*(u32 *)(param_2 + 0x160) & 4) != 0) ||
      (((*(u32 *)(param_2 + 0x160) & 0x10) != 0 && (param_3 != 0xfc)))) &&
     (*(int *)(param_2 + 0x154) != param_3)) {
    func_002eb6f8();
    return;
  }
  return;
}

void func_002ec9d0(u32 param_1,u32 *param_2,u32 param_3)

{
  int iVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_30 = *param_2;
  uStack_2c = param_2[1];
  uStack_28 = param_2[2];
  uStack_24 = param_2[3];
  func_0017c4c8(param_1,&uStack_30);
  iVar1 = (int)param_1;
  *(u8 *)(iVar1 + 0x514) = 8;
  func_002eb6f8(0,param_1,param_3);
  *(int *)(iVar1 + 0x104) = (int)param_3 + 2;
  *(int *)(iVar1 + 0x100) = (int)param_3 + 1;
  return;
}

void func_002f3918(u32 param_1,u32 param_2)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = func_002f3588(param_2);
  func_002f3490(param_1);
  puVar2 = (u32 *)param_1;
  if (puVar2[0xc] != 0xffffffff) {
    puVar2[0xc] = uVar1;
  }
  puVar2[8] = 0;
  *puVar2 = *puVar2 & 0xfffffff3 | 0x105;
  return;
}

void func_002f3980(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = func_002f3588(param_2);
  func_002f3490(param_1);
  puVar2 = (u32 *)param_1;
  if (puVar2[4] != 0xffffffff) {
    puVar2[4] = uVar1;
  }
  puVar2[8] = param_3;
  *puVar2 = *puVar2 & 0xfffffff3 | 0x101;
  return;
}

void func_002f39f8(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = func_002f3588(param_2);
  func_002f3490(param_1);
  puVar2 = (u32 *)param_1;
  if (puVar2[4] != 0xffffffff) {
    puVar2[4] = uVar1;
  }
  puVar2[8] = param_3;
  *puVar2 = *puVar2 & 0xfffffff3 | 0x109;
  return;
}

void func_002f3a70(u32 *param_1)

{
  func_002f3490();
  param_1[8] = 0;
  *param_1 = *param_1 & 0xfffffff2 | 0x104;
  return;
}

void func_002f3ab8(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = func_002f3588(param_2);
  func_002f3490(param_1);
  puVar2 = (u32 *)param_1;
  if (puVar2[4] != 0xffffffff) {
    puVar2[4] = uVar1;
  }
  puVar2[8] = param_3;
  *puVar2 = *puVar2 & 0xfffffff2 | 0x100;
  return;
}

void func_002f3b38(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = func_002f3588(param_2);
  func_002f3490(param_1);
  puVar2 = (u32 *)param_1;
  if (puVar2[4] != 0xffffffff) {
    puVar2[4] = uVar1;
  }
  puVar2[8] = param_3;
  *puVar2 = *puVar2 & 0xfffffff2 | 0x108;
  return;
}

u32 func_002f3bb8(u32 *param_1,s32 param_2)

{
  u32 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *param_1 >> 8 & 1;
  }
  else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}

u32 func_00307f68(u32 param_1,u32 param_2,s32 param_3)

{
  if (param_3 != 0) {
    func_00306f30();
  }
  return 1;
}

void func_003080d0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,u32 param_6,u32 param_7,u32 param_8)

{
  s32 lVar1;
  u32 auStack_c0 [4];
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_8;
  
  auStack_c0[0] = 0;
  uStack_38 = param_2;
  uStack_30 = param_3;
  uStack_28 = param_4;
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  lVar1 = func_0030edb0();
  func_003071d0(0x307f40,auStack_c0,0xffffffffffffffff,param_1,&uStack_38);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return;
}

u32 func_00310620(u32 param_1)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}
