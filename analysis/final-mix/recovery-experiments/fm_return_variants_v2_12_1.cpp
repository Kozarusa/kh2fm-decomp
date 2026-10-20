#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00294480(...);
extern "C" s32 func_002b6708(...);
extern "C" s32 func_002b7440(...);
extern "C" s32 func_002b79cc(...);
extern "C" s32 func_002b9404(...);
extern "C" s32 func_002b986c(...);
extern "C" s32 func_002ba3e8(...);
extern "C" s32 func_002bbda0(...);
extern "C" s32 func_002bc0f0(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u16 func_002bc988(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(...);
extern "C" u32 func_002b6e24(...);
extern "C" u32 func_002baa78(...);
extern "C" u32 func_002bb100(...);
extern "C" u32 func_002bb5a8(...);
extern "C" u32 func_002bb9b8(...);
extern "C" u32 func_002bbbc8(...);
extern "C" u32 func_002bbc90(...);
extern "C" u32 func_002bc470(...);
extern "C" u32 func_002bc608(...);
extern "C" u32 func_002bc9a8(...);
extern "C" u32 func_002bce10(...);
extern "C" u32 func_002bcfe8(...);
extern "C" u32 func_002bd030(...);
extern "C" u32 func_002bd078(...);
extern "C" u32 func_002bd0b8(...);
extern "C" u32 func_002bd100(...);
extern "C" u32 func_002bd140(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00324718(...);
extern "C" u64 func_001a8190(...);
extern "C" u64 func_002b6adc(...);
extern "C" u64 func_002b6f28(...);

int func_002924d0(int param_1,s64 param_2)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = param_1 + 0x2b3c;
  if (param_2 != 0) {
    uVar2 = func_001a80c8(param_2); asm volatile("" ::: "memory");
    iVar1 = func_001a8190(uVar2); asm volatile("" ::: "memory");
  }
  if (iVar1 == 0) {
    iVar1 = param_1 + 0x2b3c;
  }
  return iVar1;
}

void func_0029df98(void)

{
  int iVar1;
  
  iVar1 = func_002766d0(); asm volatile("" ::: "memory");
  func_0028dac8(iVar1 + 0x4398,3); asm volatile("" ::: "memory");
  return;
}

void func_0029e050(void)

{
  int iVar1;
  
  iVar1 = func_002766d0(); asm volatile("" ::: "memory");
  func_0028dac8(iVar1 + 0x4860,6); asm volatile("" ::: "memory");
  return;
}

void func_0029e258(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0(); asm volatile("" ::: "memory");
  func_0028dac8(iVar1 + (param_1 + 1) * 0x198 + 0x4398,9); asm volatile("" ::: "memory");
  return;
}

void func_002ae280(int *param_1,int *param_2)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = func_00294000(5); asm volatile("" ::: "memory");
  *param_2 = *param_2 + *(int *)(iVar2 + 8);
  iVar3 = iVar2 + 0x10;
  if (0 < *(int *)(iVar2 + 8)) {
    do {
      lVar1 = func_00294480(iVar3); asm volatile("" ::: "memory");
      if (lVar1 == 0) {
        iVar4 = *(int *)(iVar2 + 8);
      }
      else {
        *param_1 = *param_1 + 1;
        iVar4 = *(int *)(iVar2 + 8);
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar5 < iVar4);
  }
  return;
}

u64
func_002b73ac(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(6,0x16,param_1,param_2,param_3,param_4,param_5); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b788c(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(7,0x19,param_1,param_2,param_3,param_4,1,1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b78ec(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x1a,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b792c(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x1b,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b797c(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x1c,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7c34(u32 param_1,u32 param_2,int param_3,u32 param_4)

{
  u64 uVar1;
  u32 uStack_14;
  
  uStack_14 = param_4;
  if (0x39ff < param_3) {
    uStack_14 = 0x40;
  }
  uVar1 = func_002b6708(5,0x1d,param_1,param_2,param_3,uStack_14); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7ca4(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x1e,param_1,param_2); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7cec(u32 param_1,u32 param_2,int param_3,u32 param_4)

{
  u64 uVar1;
  u32 uStack_14;
  
  uStack_14 = param_4;
  if (0x39ff < param_3) {
    uStack_14 = 0x40;
  }
  uVar1 = func_002b6708(5,0x1f,param_1,param_2,param_3,uStack_14); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7d5c(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(5,0x20,param_1,param_2,param_3,param_4); asm volatile("" ::: "memory");
  return uVar1;
}

u64
func_002b7db4(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5,u32 param_6)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(9,0x2b,param_1,param_2,param_3,param_4,param_5,param_6); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7e34(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2c,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7e74(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x2d,param_2,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7ebc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2e,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7efc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2f,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7f3c(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x30,param_1,param_2); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7f84(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x31); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7fbc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x32,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7ffc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x33,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b803c(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x34,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b8374(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x24,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b83b4(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x27); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b83ec(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x26,param_1,param_2); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b89e4(int param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  *(u32 *)(param_1 + 0x48024) = param_2;
  *(u32 *)(param_1 + 0x48028) = param_3;
  uVar1 = func_002b6708(4,0x1c,param_1 + 0x8000,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u32 func_002b96a4(u32 param_1,u32 param_2)

{
  int iVar1;
  u8 auStack_24 [4];
  u8 auStack_20 [4];
  u32 uStack_1c;
  
  iVar1 = func_002b9404(param_1,param_2,auStack_24,auStack_20); asm volatile("" ::: "memory");
  if (iVar1 < 0) {
    uStack_1c = 0xffffffff;
  }
  else {
    uStack_1c = func_002b6708(2,0x1a,iVar1); asm volatile("" ::: "memory");
  }
  return uStack_1c;
}

u32 func_002b97d8(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  u8 auStack_1c [4];
  u8 auStack_18 [4];
  u32 uStack_14;
  
  iVar1 = func_002b9404(param_1,param_2,auStack_1c,auStack_18); asm volatile("" ::: "memory");
  if (iVar1 < 0) {
    uStack_14 = 0xffffffff;
  }
  else {
    uStack_14 = func_002b6708(4,0x1c,iVar1,param_3,param_4); asm volatile("" ::: "memory");
  }
  return uStack_14;
}

u64 func_002b9968(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x18); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b99c8(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x29); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b9a00(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x2a); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b9a38(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x35,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b9a78(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x36,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

void func_002b9b78(void)

{
  func_002bc9a8(0x1e2a410,2,0); asm volatile("" ::: "memory");
  func_002bce10(0x1e2a410,2); asm volatile("" ::: "memory");
  func_002bc9a8(0x1e2a410,3,999); asm volatile("" ::: "memory");
  func_002bce10(0x1e2a410,3); asm volatile("" ::: "memory");
  return;
}

void func_002b9ed0(void)

{
  func_002baa78(); asm volatile("" ::: "memory");
  func_002bcfe8(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd030(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd078(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd0b8(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd100(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd140(0x1e2a410); asm volatile("" ::: "memory");
  return;
}

void func_002ba040(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  func_002bcfe8(0x1e2a410); asm volatile("" ::: "memory");
  func_002bd030(0x1e2a410); asm volatile("" ::: "memory");
  iVar1 = 0x14;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    func_002b6adc(2,iVar1); asm volatile("" ::: "memory");
    func_002b6adc(0,iVar1); asm volatile("" ::: "memory");
    iVar1 = iVar2 + 0x15;
    iVar2 = iVar3;
  } while (iVar3 < 2);
  return;
}

u64 func_002ba0b0(u64 param_1)

{
  func_002fee78(0x1e2a568,0x374f70,param_1); asm volatile("" ::: "memory");
  func_002ff3fc(0x1e2a568); asm volatile("" ::: "memory");
  return 0x1e2a568;
}

u64 func_002ba0f8(u64 param_1)

{
  func_002fee78(0x1e2a5a8,0x374f80,param_1); asm volatile("" ::: "memory");
  func_002ff3fc(0x1e2a5a8); asm volatile("" ::: "memory");
  return 0x1e2a5a8;
}

void func_002ba140(u64 param_1,u64 param_2,u64 param_3)

{
  func_002bc608(); asm volatile("" ::: "memory");
  func_002b6f28(param_1,param_2,param_3); asm volatile("" ::: "memory");
  return;
}

void func_002ba1b8(u64 param_1,u64 param_2,u64 param_3)

{
  func_002bc470(); asm volatile("" ::: "memory");
  func_002b6e24(param_1,param_2,param_3); asm volatile("" ::: "memory");
  return;
}

void func_002ba3b8(void)

{
  func_002ba3e8(); asm volatile("" ::: "memory");
  return;
}

void func_002bb3f0(u64 param_1,u32 param_2,u32 param_3,u64 param_4,
                 u16 param_5)

{
  int iVar1;
  
  func_002bb100(param_1,1,6); asm volatile("" ::: "memory");
  func_002bb5a8(param_1,param_4); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u16 *)(iVar1 + 0x2a) = param_5;
  *(u32 *)(iVar1 + 0x18) = param_2;
  *(u32 *)(iVar1 + 0x10) = param_3;
  return;
}

bool func_002bb510(u64 param_1)

{
  bool bVar1;
  s64 lVar2;
  int iVar3;
  
  func_00324718(0x1e2aa80,param_1); asm volatile("" ::: "memory");
  iVar3 = (int)param_1;
  bVar1 = true;
  if (*(char *)(iVar3 + 0x30) != '\x01') {
    if (*(char *)(iVar3 + 0x31) == '\x05') {
      lVar2 = func_002b79cc(*(u32 *)(iVar3 + 0x18),*(u32 *)(iVar3 + 0x10),0); asm volatile("" ::: "memory");
      bVar1 = lVar2 != 0;
    }
    else if (*(char *)(iVar3 + 0x31) == '\x06') {
      lVar2 = func_002b986c(*(u32 *)(iVar3 + 0x18),*(u32 *)(iVar3 + 0x10)); asm volatile("" ::: "memory");
      bVar1 = lVar2 != 0;
    }
    else {
      lVar2 = func_002b7440(*(u32 *)(iVar3 + 0x18),*(u32 *)(iVar3 + 0x10),
                           *(u32 *)(iVar3 + 0x14));
      bVar1 = lVar2 != 0;
    }
  }
  return bVar1;
}

void func_002bbd58(int param_1)

{
  if (*(char *)(param_1 + 0x31) == '\x05') {
    func_002bbbc8(); asm volatile("" ::: "memory");
    return;
  }
  if (*(char *)(param_1 + 0x31) != '\x06') {
    func_002bb9b8(); asm volatile("" ::: "memory");
    return;
  }
  func_002bbc90(); asm volatile("" ::: "memory");
  return;
}

u64 func_002bc158(s64 param_1)

{
  u64 uVar1;
  
  if ((param_1 != 0) && (-1 < param_1)) {
    uVar1 = func_002bc0f0(); asm volatile("" ::: "memory");
    return uVar1;
  }
  return 0;
}

void func_002bc398(u64 param_1,u64 param_2)

{
  s64 lVar1;
  
  lVar1 = func_002bbda0(); asm volatile("" ::: "memory");
  if (lVar1 != 0) {
    func_002bb5a8(lVar1,param_2); asm volatile("" ::: "memory");
    *(u32 *)((int)lVar1 + 0x24) = *(u32 *)((int)lVar1 + 0x24) & 0xfffffff7;
  }
  return;
}

void func_002bcbf0(u64 param_1,u64 param_2,u64 param_3,u32 *param_4,
                 u32 *param_5)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_002bc988(param_2); asm volatile("" ::: "memory");
  *param_5 = uVar1;
  iVar2 = (int)param_1;
  uVar1 = *(u32 *)(iVar2 + 0x14c);
  *param_4 = uVar1;
  func_002bc9a8(param_1,uVar1,*param_5); asm volatile("" ::: "memory");
  uVar1 = 0x15;
  if (*(int *)(iVar2 + 0x14c) != 0x14) {
    uVar1 = 0x14;
  }
  *(u32 *)(iVar2 + 0x14c) = uVar1;
  return;
}

u64 func_002bd260(u64 param_1)

{
  func_002fee78(0x1e2bba0,0x374fa8,param_1); asm volatile("" ::: "memory");
  func_002ff3fc(0x1e2bba0); asm volatile("" ::: "memory");
  return 0x1e2bba0;
}
