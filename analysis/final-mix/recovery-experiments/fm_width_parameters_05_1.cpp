#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001917c0(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_0019c898(...);
extern "C" bool func_0019d4a8(...);
extern "C" bool func_001a2478(...);
extern "C" bool func_001a9758(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001d35e0(...);
extern "C" bool func_00239d10(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_0019f7d0(...);
extern "C" u16 func_0016a070(...);
extern "C" u16 func_0016bff0(...);
extern "C" u16 func_001a3958(...);
extern "C" u16 func_001a67b0(...);
extern "C" u32 func_00102c18(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00138190(...);
extern "C" u32 func_0013dad0(...);
extern "C" u32 func_00154b40(...);
extern "C" u32 func_0015a638(...);
extern "C" u32 func_0016a0a0(...);
extern "C" u32 func_0016cbc8(...);
extern "C" u32 func_00170e58(...);
extern "C" u32 func_00177998(...);
extern "C" u32 func_00181858(...);
extern "C" u32 func_00185118(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_001902a8(...);
extern "C" u32 func_00190878(...);
extern "C" u32 func_00192f78(...);
extern "C" u32 func_001956d0(...);
extern "C" u32 func_00195700(...);
extern "C" u32 func_0019c6f0(...);
extern "C" u32 func_0019cbe8(...);
extern "C" u32 func_0019d228(...);
extern "C" u32 func_0019d480(...);
extern "C" u32 func_0019da68(...);
extern "C" u32 func_0019e848(...);
extern "C" u32 func_0019ec88(...);
extern "C" u32 func_0019ed48(...);
extern "C" u32 func_001a0e78(...);
extern "C" u32 func_001a1db8(...);
extern "C" u32 func_001a4df0(...);
extern "C" u32 func_001a7a48(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a84b0(...);
extern "C" u32 func_001a9218(...);
extern "C" u32 func_001a9350(...);
extern "C" u32 func_001ab260(...);
extern "C" u32 func_001abb78(...);
extern "C" u32 func_001abbf0(...);
extern "C" u32 func_001ac728(...);
extern "C" u32 func_001acdc0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u32 func_001bc688(...);
extern "C" u32 func_001c0150(...);
extern "C" u32 func_001c70e8(...);
extern "C" u32 func_001c8ab0(...);
extern "C" u32 func_001c9db0(...);
extern "C" u32 func_001d22a8(...);
extern "C" u32 func_001d45a0(...);
extern "C" u32 func_001d5af8(...);
extern "C" u32 func_001d96c0(...);
extern "C" u32 func_001db5a8(...);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023acd8(...);
extern "C" u32 func_0023ade0(...);
extern "C" u32 func_002ba2e8(...);
extern "C" u32 func_002c0688(...);
extern "C" u64 func_00143928(...);
extern "C" u64 func_0016e920(...);
extern "C" u64 func_001a0ee0(...);
extern "C" u64 func_001a7da8(...);
extern "C" u64 func_001ab750(...);
extern "C" u8 func_001a8bf8(...);

u32 func_0019bb98(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  float fVar3;
  
  fVar3 = (float)func_0016a0a0(); asm volatile("" ::: "memory");
  if ((((fVar3 != 0.0) && (iVar2 = (int)param_1, (*(u32 *)(iVar2 + 0x108) & 4) == 0)) &&
      ((*(u32 *)(iVar2 + 0x160) & 0x2000000) == 0)) &&
     (((lVar1 = func_001c0cd8(param_1), lVar1 == 0 &&
       ((*(u32 *)(*(int *)(iVar2 + 0xc) + 8) & 4) == 0)) &&
      (lVar1 = func_0019c6f0(param_1), lVar1 == 0)))) {
    return 0;
  }
  return 1;
}

u32 func_0019bf50(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u64 uVar4;
  
  func_00185118(); asm volatile("" ::: "memory");
  if ((u32 *)(param_1 + 0x590) != (u32 *)(param_1 + 0x540)) {
    *(u32 *)(param_1 + 0x590) = *(u32 *)(param_1 + 0x540);
    *(u32 *)(param_1 + 0x594) = *(u32 *)(param_1 + 0x544);
    *(u32 *)(param_1 + 0x598) = *(u32 *)(param_1 + 0x548);
    *(u32 *)(param_1 + 0x59c) = *(u32 *)(param_1 + 0x54c);
  }
  if ((u32 *)(param_1 + 0x5a0) == param_2) {
    uVar4 = *(u64 *)(param_1 + 0x600);
  }
  else {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(u32 *)(param_1 + 0x5a0) = *param_2;
    *(u32 *)(param_1 + 0x5a4) = uVar1;
    *(u32 *)(param_1 + 0x5a8) = uVar2;
    *(u32 *)(param_1 + 0x5ac) = uVar3;
    uVar4 = *(u64 *)(param_1 + 0x600);
  }
  *(u64 *)(param_1 + 0x600) = uVar4 & 0xfffffffffffffffe;
  func_00143928(); asm volatile("" ::: "memory");
  return *(u32 *)(param_1 + 0x604) & 1;
}

u32 func_0019c4f8(int param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  if (((((*(u32 *)(param_1 + 0x7f8) & 4) != 0) || ((*(u32 *)(param_1 + 0x7f8) & 0x400) == 0)) ||
      ((*(u32 *)(param_1 + 0x108) & 0x40) != 0)) ||
     ((((*(u32 *)(param_1 + 0x160) & 0x8000000) != 0 || (lVar2 = func_0019c6f0(), lVar2 != 0)) ||
      (uVar1 = 0, (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x2000) != 0)))) {
    uVar1 = 1;
  }
  return uVar1;
}

bool func_0019c590(int param_1)

{
  bool bVar1;
  s64 lVar2;
  
  bVar1 = false;
  if (((*(u32 *)(param_1 + 0x588) & 4) == 0) && ((*(u32 *)(param_1 + 0x588) & 0x40) == 0)) {
    lVar2 = func_001c8ab0(); asm volatile("" ::: "memory");
    bVar1 = lVar2 == 1;
  }
  return bVar1;
}

void func_0019c8a8(void)

{
  u64 uVar1;
  
  uVar1 = func_0016a070(); asm volatile("" ::: "memory");
  func_0019c898(uVar1); asm volatile("" ::: "memory");
  return;
}

void func_0019ca28(int param_1,u32 *param_2)

{
  u8 auStack_30 [12];
  int iStack_24;
  
  iStack_24 = 0;
  *(u32 *)(param_1 + 4) = *param_2;
  *(u32 *)(param_1 + 8) = param_2[1];
  *(u32 *)(param_1 + 0xc) = param_2[2];
  *(u32 *)(param_1 + 0x10) = param_2[3];
  *(u32 *)(param_1 + 0x14) = param_2[4];
  func_001902a8(param_1 + 4,auStack_30); asm volatile("" ::: "memory");
  *(u32 *)(param_1 + 0x24) = (u32)*(u8 *)(iStack_24 + 1);
  return;
}

void func_0019cb48(int param_1)

{
  int iVar1;
  s64 lVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 *puVar5;
  
  func_0019cbe8(); asm volatile("" ::: "memory");
  if ((((*(int *)(*(int *)(param_1 + 0x28) + 0x48c) != 0) &&
       (puVar3 = (u32 *)func_00177860(*(int *)(param_1 + 0x28)), (*puVar3 & 0x80000) != 0)) &&
      (lVar2 = func_0019ba60(*(u32 *)(param_1 + 4)), lVar2 != 0)) &&
     (((*(u32 *)(*(int *)(param_1 + 4) + 0x108) & 0x4000) == 0 &&
      (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x48c), iVar1 != 0)))) {
    puVar5 = (u32 *)(*(int *)(param_1 + 0x24) * 0xc + iVar1);
    uVar4 = func_00154b40(*puVar5,puVar5[1]); asm volatile("" ::: "memory");
    *(u32 *)(param_1 + 0x20) = uVar4;
  }
  return;
}

void func_0019cc20(u32 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  if (*piVar1 != 0) {
    func_0019d228(); asm volatile("" ::: "memory");
    func_0019cbe8(param_1); asm volatile("" ::: "memory");
    if (*piVar1 == 2) {
      func_0019d480(param_1); asm volatile("" ::: "memory");
    }
    *piVar1 = 0;
    func_00190128(piVar1 + 1); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_0019d438(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_0019d4a8(); asm volatile("" ::: "memory");
  if (lVar1 != 0) {
    func_002c0688(*(u32 *)(param_1 + 0x28)); asm volatile("" ::: "memory");
    return;
  }
  func_0015a638(param_1 + 4,param_1 + 4); asm volatile("" ::: "memory");
  return;
}

bool func_0019d748(int param_1)

{
  bool bVar1;
  s64 lVar2;
  
  lVar2 = func_00181858(); asm volatile("" ::: "memory");
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = (*(u32 *)(param_1 + 0x20) & 1) != 0;
  }
  return bVar1;
}

void func_0019da20(u32 *param_1,u32 param_2)

{
  *param_1 = param_2;
  *(u16 *)(param_1 + 1) = 0;
  func_001bc688(param_1 + 1); asm volatile("" ::: "memory");
  func_00190128(param_1 + 4); asm volatile("" ::: "memory");
  param_1[0x14] = 0;
  param_1[9] = 0xffffffff;
  param_1[0xf] = 0;
  return;
}

u64 func_0019e5f8(u32 *param_1,s32 param_2)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  s64 lVar4;
  u64 uVar5;
  
  iVar1 = *(int *)(*(int *)*param_1 + 0x9e0);
  uVar5 = 0;
  if (param_2 != 0) {
    uVar3 = func_001b8e88(param_2); asm volatile("" ::: "memory");
    lVar4 = func_001917c0(); asm volatile("" ::: "memory");
    iVar2 = *(int *)((int)uVar3 + 0xc);
    if ((((lVar4 == 0) || (uVar5 = 0, (iVar2 >> 4 & 1U) != 0)) &&
        (uVar5 = uVar3, (iVar2 >> 6 & 1U) != 0)) &&
       ((uVar5 = 0, (*(u32 *)(iVar1 + 0x160) & 0x200000) != 0 &&
        (*(u32 *)(iVar1 + 0x50c) == (u32)*(u16 *)((int)uVar3 + 0x22))))) {
      uVar5 = uVar3;
    }
  }
  return uVar5;
}

u64 func_0019e6e8(u32 param_1,u32 param_2)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  
  iVar1 = *(int *)((int)param_2 + 0x48c);
  if ((iVar1 == 0) || (lVar2 = func_001a2478(iVar1), lVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0019e848(param_1,param_2,0x36d3f0,5); asm volatile("" ::: "memory");
  }
  return uVar3;
}

bool func_0019ead0(u32 param_1,u32 param_2)

{
  s64 lVar1;
  u8 auStack_40 [32];
  
  lVar1 = func_001d45a0(param_2,*(u16 *)(*(int *)param_1 + 0x26)); asm volatile("" ::: "memory");
  if (lVar1 != 0) {
    func_00190128(auStack_40); asm volatile("" ::: "memory");
    func_00190878(auStack_40,param_2,0); asm volatile("" ::: "memory");
    func_0019da68(param_1,lVar1,auStack_40,0,0); asm volatile("" ::: "memory");
  }
  return lVar1 != 0;
}

void func_0019ec20(void)

{
  func_0019ec88(0x350448); asm volatile("" ::: "memory");
  func_0019ed48(0x350448); asm volatile("" ::: "memory");
  func_00102c18(1,42000,0x19ec68); asm volatile("" ::: "memory");
  return;
}

int func_0019f8c0(void)

{
  u16 uVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_0019f7d0(); asm volatile("" ::: "memory");
  if (lVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = *(u16 *)((int)lVar3 + 2);
    iVar2 = (int)lVar3 + (u32)uVar1;
    if (uVar1 == 0) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

void func_0019f8f8(u32 *param_1,u32 param_2)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = 0;
  func_001c0150(param_1 + 0x12); asm volatile("" ::: "memory");
  param_1 = param_1 + 3;
  iVar1 = 7;
  do {
    *param_1 = 0;
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 2;
  } while (-1 < iVar1);
  return;
}

void func_0019f950(u32 *param_1,u32 param_2)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = 0;
  func_001c0150(param_1 + 0x12); asm volatile("" ::: "memory");
  param_1 = param_1 + 3;
  iVar1 = 7;
  do {
    *param_1 = 0;
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 2;
  } while (-1 < iVar1);
  return;
}

void func_001a0678(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001d5af8(*param_1,param_1[1],param_1[2]); asm volatile("" ::: "memory");
  *param_1 = uVar1;
  return;
}

void func_001a06e0(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001d96c0(*param_1,param_1[1]); asm volatile("" ::: "memory");
  *param_1 = uVar1;
  return;
}

u64 func_001a1018(u32 param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar1 = func_001a0e78(); asm volatile("" ::: "memory");
  uVar2 = func_001db5a8(param_1); asm volatile("" ::: "memory");
  func_001a0ee0(uVar1,uVar2); asm volatile("" ::: "memory");
  return uVar1;
}

void func_001a1d50(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_2 + 0x1c0);
  fVar2 = 0.0;
  if (0.0 < fVar1) {
    param_1 = *(float *)(param_2 + 0x1bc) + param_1;
    if ((0.0 <= param_1) && (fVar2 = param_1, fVar1 < param_1)) {
      fVar2 = fVar1;
    }
    *(float *)(param_2 + 0x1bc) = fVar2;
    if (fVar2 == 0.0) {
      func_001a1db8(); asm volatile("" ::: "memory");
      return;
    }
  }
  return;
}

void func_001a2710(int param_1)

{
  if ((*(u32 *)(param_1 + 0x250) & 1) != 0) {
    func_0013dad0(); asm volatile("" ::: "memory");
    *(u32 *)(param_1 + 0x250) = *(u32 *)(param_1 + 0x250) & 0xfffffffe;
  }
  return;
}

u64 func_001a3820(void)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = func_001a80c8(); asm volatile("" ::: "memory");
  if (*(char *)(iVar1 + 2) == '\0') {
    uVar2 = (u64)*(u16 *)(iVar1 + 0x10);
  }
  else {
    if (*(char *)(iVar1 + 2) == '\x12') {
      uVar2 = func_001a67b0(*(u16 *)(iVar1 + 4)); asm volatile("" ::: "memory");
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}

void func_001a38b8(int param_1)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  
  iVar1 = func_00189200(0x32e020,6); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 4) = 0;
  iVar1 = func_001b8e88(*(u16 *)(param_1 + 0x10)); asm volatile("" ::: "memory");
  sVar2 = *(short *)(iVar1 + 4);
  if (((sVar2 == 1) || ((0 < sVar2 && ((int)sVar2 - 4U < 2)))) &&
     (psVar3 = (short *)func_00189200(0x32e020,sVar2), *psVar3 == 0)) {
    sVar2 = func_001a3958(2); asm volatile("" ::: "memory");
    *psVar3 = sVar2;
  }
  return;
}

void func_001a5928(void)

{
  u64 uVar1;
  u64 uVar2;
  
  func_001c70e8(); asm volatile("" ::: "memory");
  uVar1 = func_001050d8(0xa00); asm volatile("" ::: "memory");
  uVar2 = func_0016e920(0x5c3); asm volatile("" ::: "memory");
  func_001a4df0(uVar1,uVar2,0x100,0x60); asm volatile("" ::: "memory");
  return;
}

void func_001a6440(u32 *param_1)

{
  u32 uVar1;
  
  if ((*(u32 *)(param_1[1] + 0x588) & 4) == 0) {
    uVar1 = *param_1;
  }
  else {
    func_00177998(); asm volatile("" ::: "memory");
    uVar1 = *param_1;
  }
  func_0016cbc8(uVar1,0x15,0,0); asm volatile("" ::: "memory");
  return;
}

void func_001a6c38(void)

{
  u64 uVar1;
  
  uVar1 = func_0016bff0(); asm volatile("" ::: "memory");
  func_001956d0(0x34fa78,uVar1); asm volatile("" ::: "memory");
  return;
}

void func_001a6c60(void)

{
  u64 uVar1;
  
  uVar1 = func_0016bff0(); asm volatile("" ::: "memory");
  func_00195700(0x34fa78,uVar1); asm volatile("" ::: "memory");
  return;
}

u32 func_001a7588(u32 param_1,u32 param_2,u32 *param_3)

{
  s64 lVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_1c;
  
  lVar1 = func_001d35e0(&uStack_30,param_1,param_2); asm volatile("" ::: "memory");
  if ((lVar1 != 0) && (param_3 != &uStack_30)) {
    *param_3 = uStack_30;
    param_3[1] = uStack_2c;
    param_3[2] = uStack_28;
    param_3[3] = uStack_24;
  }
  return uStack_1c;
}

u64
func_001a78c0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u8 auStack_50 [48];
  
  func_001a7a48(auStack_50); asm volatile("" ::: "memory");
  func_001a7da8(param_3,param_4,param_5,auStack_50); asm volatile("" ::: "memory");
  return param_5;
}

u64 func_001a8190(int param_1)

{
  u8 bVar1;
  u16 uVar2;
  u64 uVar3;
  
  bVar1 = *(u8 *)(param_1 + 2);
  if (bVar1 < 2) {
    return 0;
  }
  if (bVar1 < 0xe) {
    uVar2 = *(u16 *)(param_1 + 6);
  }
  else {
    if (0xf < bVar1) {
      return 0;
    }
    uVar2 = *(u16 *)(param_1 + 4);
  }
  uVar3 = func_001d22a8(uVar2); asm volatile("" ::: "memory");
  return uVar3;
}

void func_001a8548(void)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_001a84b0(); asm volatile("" ::: "memory");
  func_00138190(*puVar1,puVar1[2]); asm volatile("" ::: "memory");
  return;
}

u32 func_001a8c78(int param_1,s32 param_2)

{
  u8 bVar1;
  s64 lVar2;
  
  if (((param_2 != 0) && (bVar1 = *(u8 *)(param_1 + (int)param_2), (bVar1 & 0x80) == 0)) &&
     (lVar2 = func_001c9db0(bVar1 & 0x1f), lVar2 == 0)) {
    return 0;
  }
  return 1;
}

int func_001a8cd0(u32 param_1,u32 param_2)

{
  u64 uVar1;
  int iVar2;
  
  if ((param_2 & 0x1f) != 0x12) {
    iVar2 = 0;
    do {
      uVar1 = func_001a8bf8(param_1,iVar2); asm volatile("" ::: "memory");
      if (uVar1 == (param_2 & 0x1f)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  return -1;
}

void func_001a92d8(u32 param_1,u32 param_2,s32 param_3)

{
  s64 lVar1;
  int iVar2;
  
  func_001a9350(); asm volatile("" ::: "memory");
  if (param_3 == 0) {
    param_3 = func_0016e920(param_2); asm volatile("" ::: "memory");
  }
  lVar1 = func_001a9758(param_2,param_3); asm volatile("" ::: "memory");
  iVar2 = (int)param_1;
  if (lVar1 == 0) {
    func_00170e58(); asm volatile("" ::: "memory");
    *(int *)(iVar2 + 4) = (int)param_2;
  }
  else {
    *(int *)(iVar2 + 4) = (int)param_2;
  }
  *(int *)(iVar2 + 8) = (int)param_3;
  func_001a9218(param_1); asm volatile("" ::: "memory");
  return;
}

void func_001a93b0(u32 param_1,u32 param_2)

{
  func_001a9350(); asm volatile("" ::: "memory");
  *(u32 *)param_1 = param_2;
  func_001a9218(param_1); asm volatile("" ::: "memory");
  return;
}

void func_001aa790(u32 *param_1,u32 param_2)

{
  *param_1 = param_2;
  param_1[5] = 0x60000000;
  param_1[1] = 0;
  func_00192f78(param_1 + 8); asm volatile("" ::: "memory");
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  func_001ab750(*param_1,param_1 + 0x10); asm volatile("" ::: "memory");
  return;
}

void func_001aa7f0(u32 *param_1,u32 param_2)

{
  *param_1 = param_2;
  param_1[5] = 0x60000000;
  param_1[1] = 0;
  func_00192f78(param_1 + 8); asm volatile("" ::: "memory");
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  func_001ab750(*param_1,param_1 + 0x10); asm volatile("" ::: "memory");
  return;
}

void func_001aa8f0(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  func_001ab260(param_1[9],param_1[10],*param_1,param_1 + 0x10,param_2,param_3,param_4,param_5,
               param_1[0xe]);
  return;
}

void func_001aadb0(u32 param_1)

{
  func_002362b0(0x1c6cd20,param_1); asm volatile("" ::: "memory");
  func_002367c8(0x1c6cd20); asm volatile("" ::: "memory");
  return;
}

void func_001abba8(int param_1)

{
  func_0023acd8(param_1 + 0x14); asm volatile("" ::: "memory");
  *(u32 *)(param_1 + 0x160) = *(u32 *)(param_1 + 0x10);
  *(u32 *)(param_1 + 0x15c) = *(u32 *)(param_1 + 0xc);
  func_0023ade0(param_1 + 0x14); asm volatile("" ::: "memory");
  return;
}

void func_001abdf0(int *param_1,int param_2)

{
  *param_1 = param_2;
  if (param_2 == 1) {
    func_00239bf8(param_1 + 1,0x41); asm volatile("" ::: "memory");
    return;
  }
  if ((1 < param_2) && (param_2 == 2)) {
    func_001abb78(param_1 + 0x57); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001abe80(int *param_1,u32 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    if ((*(u64 *)(param_3 + 8) & 0x40c) != 0) {
      func_002ba2e8(0x18,0); asm volatile("" ::: "memory");
      func_001ac728(param_2); asm volatile("" ::: "memory");
      return;
    }
  }
  else if ((1 < iVar1) && (iVar1 == 2)) {
    func_001abbf0(param_1 + 0x57); asm volatile("" ::: "memory");
    return;
  }
  return;
}

u64 func_001abf00(int *param_1)

{
  u64 uVar1;
  
  uVar1 = 0;
  if (*param_1 == 1) {
    uVar1 = func_00239d10(param_1 + 1); asm volatile("" ::: "memory");
  }
  return uVar1;
}

void func_001ac078(u8 *param_1,s32 param_2,int param_3,s32 param_4)

{
  int iVar1;
  int iVar2;
  
  *param_1 = (char)param_2;
  param_1[1] = (char)param_3;
  iVar2 = ((int)param_2 * 4 + param_3) * 2;
  param_1[2] = (char)param_4;
  iVar1 = iVar2 + 0x21;
  if (param_4 < 4) {
    iVar1 = iVar2 + 0x25;
  }
  if (param_2 != 0) {
    func_00239bf8(param_1 + 4,iVar1); asm volatile("" ::: "memory");
    return;
  }
  return;
}

bool func_001ac1d0(char *param_1)

{
  bool bVar1;
  s64 lVar2;
  
  bVar1 = false;
  if (*param_1 != '\0') {
    lVar2 = func_00239d10(param_1 + 4); asm volatile("" ::: "memory");
    bVar1 = lVar2 != 0;
  }
  return bVar1;
}

void func_001ac2a8(int *param_1,s32 param_2,int param_3,int param_4)

{
  if (param_2 != 0) {
    func_00239bf8(param_1 + 3,(int)param_2 + 1); asm volatile("" ::: "memory");
  }
  param_1[2] = param_4;
  *param_1 = (int)param_2;
  param_1[1] = param_3;
  return;
}

void func_001ac310(int *param_1)

{
  if (*param_1 != 0) {
    func_0023acd8(param_1 + 3); asm volatile("" ::: "memory");
    param_1[0x55] = param_1[1];
    param_1[0x56] = param_1[2];
    func_0023ade0(param_1 + 3); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001acf38(int param_1)

{
  if (*(int *)(param_1 + 100) == 2) {
    func_001acdc0(param_1,*(int *)(param_1 + 4),
                 *(int *)(param_1 + 8) + (*(u32 *)(param_1 + 0x60) >> 1),
                 *(int *)(param_1 + 4) + (*(u32 *)(param_1 + 0x5c) >> 1),
                 *(int *)(param_1 + 8) + *(u32 *)(param_1 + 0x60),0);
    return;
  }
  func_001acdc0(); asm volatile("" ::: "memory");
  return;
}
