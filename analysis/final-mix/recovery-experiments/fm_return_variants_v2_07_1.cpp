#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(...);
extern "C" bool func_001a6d08(...);
extern "C" bool func_001b8958(...);
extern "C" bool func_001bb4a0(...);
extern "C" bool func_001bb4b0(...);
extern "C" bool func_001c5f38(...);
extern "C" bool func_001ca448(...);
extern "C" bool func_001db200(...);
extern "C" bool func_001dc9e0(...);
extern "C" bool func_001e6c40(...);
extern "C" bool func_001e6d08(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001a35f8(...);
extern "C" s32 func_001db888(...);
extern "C" s64 func_0017e668(...);
extern "C" s64 func_001db9a8(...);
extern "C" s64 func_001e6b90(...);
extern "C" u16 func_001a8b68(...);
extern "C" u16 func_001d01e0(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00105868(...);
extern "C" u32 func_0014c9d8(...);
extern "C" u32 func_0014c9f0(...);
extern "C" u32 func_0014f688(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c5b8(...);
extern "C" u32 func_0016c640(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_00176cd0(...);
extern "C" u32 func_001780d8(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_00190920(...);
extern "C" u32 func_00198450(...);
extern "C" u32 func_001987a8(...);
extern "C" u32 func_00198860(...);
extern "C" u32 func_0019baa8(...);
extern "C" u32 func_001a3188(...);
extern "C" u32 func_001a4ff8(...);
extern "C" u32 func_001a6c90(...);
extern "C" u32 func_001ada38(...);
extern "C" u32 func_001ba158(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001bbe38(...);
extern "C" u32 func_001bbe78(...);
extern "C" u32 func_001bdab0(...);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_001c1890(...);
extern "C" u32 func_001c6748(...);
extern "C" u32 func_001c6760(...);
extern "C" u32 func_001c8d80(...);
extern "C" u32 func_001c8d98(...);
extern "C" u32 func_001c99b0(...);
extern "C" u32 func_001c9ab8(...);
extern "C" u32 func_001ca988(...);
extern "C" u32 func_001ce3e8(...);
extern "C" u32 func_001d16f8(...);
extern "C" u32 func_001d1950(...);
extern "C" u32 func_001d2110(...);
extern "C" u32 func_001d2248(...);
extern "C" u32 func_001d3350(...);
extern "C" u32 func_001d3388(...);
extern "C" u32 func_001d4f40(...);
extern "C" u32 func_001d6cc8(...);
extern "C" u32 func_001d7b10(...);
extern "C" u32 func_001d8718(...);
extern "C" u32 func_001d87b8(...);
extern "C" u32 func_001d8c70(...);
extern "C" u32 func_001da3d8(...);
extern "C" u32 func_001db250(...);
extern "C" u32 func_001db8b8(...);
extern "C" u32 func_001dbd68(...);
extern "C" u32 func_001dc738(...);
extern "C" u32 func_001dca30(...);
extern "C" u32 func_001e2c00(...);
extern "C" u32 func_001e6c00(...);
extern "C" u32 func_001e7070(...);
extern "C" u32 func_001e7088(...);
extern "C" u32 func_00276fd0(...);
extern "C" u32 func_00321728(...);
extern "C" u64 func_001bd3e0(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_001e2c78(...);

void func_001bd4e8(u64 param_1,u32 *param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(u32 *)(*(int *)((int)param_1 + 0x9e0) + 0x588) & 0x2000000) == 0) {
    iVar2 = 0;
    func_001bdab0(); asm volatile("" ::: "memory");
    do {
      iVar1 = iVar2 + 3;
      iVar2 = iVar2 + 1;
      func_001bd3e0(param_1,iVar1,*param_2,param_3,1,100); asm volatile("" ::: "memory");
      param_2 = param_2 + 1;
    } while (iVar2 < 4);
  }
  return;
}

void func_001c16a0(u32 *param_1,u64 param_2)

{
  u32 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = param_1[0xc];
  }
  else {
    if (param_1[1] != 1) {
      return;
    }
    uVar1 = param_1[0xc];
  }
  func_001dca30(*param_1,uVar1,param_2); asm volatile("" ::: "memory");
  return;
}

void func_001c1708(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  while (iVar2 != 0) {
    bVar1 = iVar2 != 0;
    iVar2 = *(int *)(iVar2 + 0x24);
    if (bVar1) {
      func_001c1890(); asm volatile("" ::: "memory");
    }
  }
  return;
}

void func_001c1808(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(iVar1 + 0xc);
  if (param_1 == iVar3) {
    iVar3 = 0;
    *(u32 *)(iVar1 + 0xc) = *(u32 *)(param_1 + 0x24);
  }
  else {
    for (iVar2 = *(int *)(iVar3 + 0x24); iVar2 != param_1; iVar2 = *(int *)(iVar2 + 0x24)) {
      iVar3 = iVar2;
    }
    *(u32 *)(iVar3 + 0x24) = *(u32 *)(param_1 + 0x24);
  }
  if (param_1 == *(int *)(iVar1 + 0x10)) {
    *(int *)(iVar1 + 0x10) = iVar3;
  }
  *(u32 *)(param_1 + 0x24) = 0;
  func_001db8b8(*(int *)(param_1 + 0x1c) + 0x14,param_1); asm volatile("" ::: "memory");
  return;
}

void func_001c6850(u64 param_1)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_001c5f38(); asm volatile("" ::: "memory");
  if (lVar1 == 0) {
    iVar2 = (int)param_1;
    if (0.0 < *(float *)(iVar2 + 0x4c)) {
      func_001c6760(param_1); asm volatile("" ::: "memory");
      return;
    }
    *(u8 *)(iVar2 + 0x15) = 0;
    *(u32 *)(iVar2 + 4) = *(u32 *)(iVar2 + 0x34);
    if (*(char *)(iVar2 + 0x50) == '\0') {
      lVar1 = func_001dbd68(param_1); asm volatile("" ::: "memory");
      if (lVar1 != 0) {
        func_001c6748(param_1); asm volatile("" ::: "memory");
        return;
      }
    }
    else {
      *(char *)(iVar2 + 0x50) = *(char *)(iVar2 + 0x50) + -1;
    }
  }
  return;
}

u64 func_001c7950(u32 *param_1,u64 param_2)

{
  u64 uVar1;
  u32 uStack_20;
  float fStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uVar1 = 0;
  if ((param_1[10] & 1) != 0) {
    uStack_20 = *param_1;
    uStack_18 = param_1[2];
    uStack_14 = param_1[3];
    fStack_1c = (float)param_1[1] + *(float *)(param_1[0x13] + 4);
    uVar1 = func_001a4ff8(param_2,&uStack_20); asm volatile("" ::: "memory");
  }
  return uVar1;
}

void func_001c8710(void)

{
  func_001c8d80(0x351ec0,3); asm volatile("" ::: "memory");
  func_0014c9d8(0x10); asm volatile("" ::: "memory");
  func_001bbe38(1); asm volatile("" ::: "memory");
  func_0016c5b8(2,0xfffffffffff7ffdc); asm volatile("" ::: "memory");
  return;
}

void func_001c8750(void)

{
  func_001c8d98(0x351ec0,3); asm volatile("" ::: "memory");
  func_0014c9f0(0x10); asm volatile("" ::: "memory");
  func_001bbe78(1); asm volatile("" ::: "memory");
  func_0016c640(2); asm volatile("" ::: "memory");
  return;
}

void func_001c9080(u64 param_1,u64 param_2,u32 *param_3)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_3;
  uStack_1c = param_3[1];
  uStack_18 = param_3[2];
  uStack_14 = param_3[3];
  func_0017c4c8(param_2,&uStack_20); asm volatile("" ::: "memory");
  func_0016bd60(param_2,0x14); asm volatile("" ::: "memory");
  return;
}

u64 func_001c9b38(int param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  if (*(short *)(param_1 + 2) != 4) {
    uVar2 = 0;
    if (*(short *)(param_1 + 2) == 0x48) {
      lVar1 = func_001c9ab8(); asm volatile("" ::: "memory");
      uVar2 = 2;
      if (lVar1 != 0) {
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  uVar2 = func_001c99b0(*(u16 *)(param_1 + 4)); asm volatile("" ::: "memory");
  return uVar2;
}

bool func_001c9d88(void)

{
  u64 uVar1;
  s64 lVar2;
  
  uVar1 = func_001a8b68(); asm volatile("" ::: "memory");
  lVar2 = func_0017e668(uVar1); asm volatile("" ::: "memory");
  return lVar2 == 0;
}

u32 func_001c9df8(void)

{
  s64 lVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    lVar1 = func_0017df58(iVar2); asm volatile("" ::: "memory");
    iVar2 = iVar2 + 1;
    if ((lVar1 != 0) && (lVar1 = func_0019baa8(lVar1), lVar1 != 0)) break;
    if (1 < iVar2) {
      return 0;
    }
  }
  return 1;
}

u64 func_001cbc50(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  u64 uVar2;
  
  uVar2 = 0;
  iVar1 = *(int *)((int)param_1 + 0x9f4);
  if (*(int *)(iVar1 + 0x1c) != 0) {
    uVar2 = func_001db888(iVar1 + 0x14,0xc0); asm volatile("" ::: "memory");
    func_001ca988(uVar2,param_1,param_2,param_3,0x1cab08,param_4); asm volatile("" ::: "memory");
  }
  return uVar2;
}

u64 func_001ce488(u32 param_1,u64 param_2,u64 param_3)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar1 = func_001db9a8(param_2,0,1000); asm volatile("" ::: "memory");
  uVar2 = func_001050d8(0xa00); asm volatile("" ::: "memory");
  func_001ce3e8(param_1,uVar2,uVar1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar2;
}

u32 func_001cf560(int param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_001ca448(); asm volatile("" ::: "memory");
  if ((lVar2 != 0) || (uVar1 = 0, *(int *)(param_1 + 0x154) == 0x2c)) {
    uVar1 = 1;
  }
  return uVar1;
}

u32 func_001cf998(void)

{
  s64 lVar1;
  
  lVar1 = func_001bb4a0(); asm volatile("" ::: "memory");
  if ((lVar1 != 0) && (lVar1 = func_001d87b8(1), lVar1 < 1)) {
    return 0;
  }
  return 1;
}

void func_001cffe0(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 0x140;
  func_001780d8(); asm volatile("" ::: "memory");
  func_00198860(param_1,1); asm volatile("" ::: "memory");
  func_0017f488(0,0,iVar1,0xbf); asm volatile("" ::: "memory");
  func_0017f5e0(0,0,iVar1,0,0); asm volatile("" ::: "memory");
  func_001987a8(param_1,0x36e368,param_1); asm volatile("" ::: "memory");
  return;
}

void func_001d0068(void)

{
  u64 uVar1;
  
  uVar1 = func_001d01e0(); asm volatile("" ::: "memory");
  func_00170320(5000); asm volatile("" ::: "memory");
  func_0016ed50(uVar1,5000,7); asm volatile("" ::: "memory");
  return;
}

void func_001d14b8(int param_1)

{
  if (*(int *)(param_1 + 0xb50) != 6) {
    func_00176cd0(); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001d18c0(u64 param_1)

{
  int iVar1;
  
  func_001d16f8(); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 4) != 0) {
    func_0014f688(*(int *)(iVar1 + 4),*(u32 *)(iVar1 + 8),*(u32 *)(iVar1 + 0x20),
                 *(u32 *)(iVar1 + 0x24),*(u32 *)(iVar1 + 0x1c));
  }
  func_001d1950(param_1,*(u32 *)(iVar1 + 0x14)); asm volatile("" ::: "memory");
  return;
}

void func_001d2130(u32 param_1,u64 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  func_001d2110(param_2,*(int *)(iVar1 + 0x2c) + param_3); asm volatile("" ::: "memory");
  func_001d2248(param_2,*(u32 *)(iVar1 + 0x2c)); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0x3c) = param_1;
  return;
}

u64 func_001d3390(u64 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_001d3350(0x1d5ba10,0); asm volatile("" ::: "memory");
  func_001d3388(param_1); asm volatile("" ::: "memory");
  *puVar1 = (int)param_1;
  return param_1;
}

bool func_001d4528(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_001a35f8(*(u16 *)(param_1 + 0x2a),*(u8 *)(param_1 + 1)); asm volatile("" ::: "memory");
  return 0 < lVar1;
}

void func_001d4ef0(u64 param_1,u8 *param_2)

{
  int iVar1;
  
  iVar1 = func_00321728((int)param_1 + 0x38,1,*param_2); asm volatile("" ::: "memory");
  *(char *)(iVar1 + 1) = *(char *)(iVar1 + 1) + '\x01';
  func_001d4f40(param_1,*(u16 *)(param_2 + 0x42)); asm volatile("" ::: "memory");
  return;
}

void func_001d5370(u32 *param_1,u64 param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = func_00168b38(param_2,0xffffffffffffffff); asm volatile("" ::: "memory");
  iVar3 = func_00168b38(param_2,0xffffffffffffffff,param_3 + 1); asm volatile("" ::: "memory");
  uVar1 = *(u32 *)(iVar2 + 8);
  param_1[1] = *(u32 *)(iVar3 + 8);
  *param_1 = uVar1;
  return;
}

u64 func_001d5868(u16 *param_1)

{
  u16 uVar1;
  u64 uVar2;
  
  uVar1 = *param_1;
  if (uVar1 == 2) {
    uVar2 = func_001b8958(param_1[1]); asm volatile("" ::: "memory");
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        uVar2 = func_00181500(param_1[1]); asm volatile("" ::: "memory");
        return uVar2;
      }
    }
    else if (uVar1 == 3) {
      uVar2 = func_001a6d08(param_1[1]); asm volatile("" ::: "memory");
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}

void func_001d6da8(u16 *param_1)

{
  s64 lVar1;
  s64 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_001d6cc8(lVar2), lVar2 != 0) {
    lVar1 = func_001a3570(((u16 *)lVar2)[1]); asm volatile("" ::: "memory");
    if (0 < lVar1) {
      *param_1 = *(u16 *)lVar2;
      param_1 = param_1 + 1;
    }
  }
  *param_1 = 0;
  return;
}

void func_001d6e08(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 4);
  iVar3 = 1;
  iVar1 = *piVar2;
  while( true ) {
    piVar2 = piVar2 + 1;
    if (iVar1 != 0) {
      func_0016ed50(iVar1,0xffffffffffffffff,0x1e); asm volatile("" ::: "memory");
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar1 = *piVar2;
  }
  return;
}

int func_001d6ec8(void)

{
  s64 lVar1;
  s64 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 2;
  while (lVar2 = func_001d6cc8(lVar2), lVar2 != 0) {
    lVar1 = func_001a3570(*(u16 *)((int)lVar2 + 2)); asm volatile("" ::: "memory");
    iVar3 = iVar3 + (u32)(0 < lVar1);
  }
  if (iVar3 == 6) {
    iVar3 = 7;
  }
  return iVar3;
}

void func_001d77a0(void)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  
  lVar1 = func_001a6d08(0x6a); asm volatile("" ::: "memory");
  if (lVar1 == 0) {
    lVar1 = func_001a6d08(0x65); asm volatile("" ::: "memory");
    iVar3 = 1;
    if (lVar1 != 0) {
      while( true ) {
        iVar2 = func_00189200(0x32e020,iVar3); asm volatile("" ::: "memory");
        iVar3 = iVar3 + 1;
        if (*(u8 *)(iVar2 + 2) < 5) break;
        if (4 < iVar3) {
          func_001a6c90(0x6a); asm volatile("" ::: "memory");
          return;
        }
      }
    }
  }
  return;
}

void func_001d7940(void)

{
  int iVar1;
  
  iVar1 = func_001ba158(); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0x18) = 0;
  *(u32 *)(iVar1 + 4) = 0;
  *(u32 *)(iVar1 + 0xc) = 0;
  *(u32 *)(iVar1 + 0x14) = 0;
  func_001ada38(0xc); asm volatile("" ::: "memory");
  return;
}

void func_001d79b8(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)0x0;
  iVar3 = 0;
  piVar4 = (int *)(param_2 + 4);
  do {
    piVar2 = piVar4;
    if (*piVar4 == param_3) break;
    iVar3 = iVar3 + 1;
    if (*piVar4 == 0) {
      piVar1 = piVar4;
    }
    piVar4 = piVar4 + 2;
    piVar2 = piVar1;
  } while (iVar3 < 4);
  piVar2[1] = param_1;
  *piVar2 = param_3;
  func_001d7b10(); asm volatile("" ::: "memory");
  return;
}

void func_001d7a50(int param_1)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = 3;
  puVar2 = (u32 *)(param_1 + 4);
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 2;
  } while (-1 < iVar1);
  func_001d7b10(); asm volatile("" ::: "memory");
  return;
}

void func_001d7e00(u64 param_1)

{
  func_00190920((int)param_1 + 0x9f4,2,param_1); asm volatile("" ::: "memory");
  func_00198450(param_1); asm volatile("" ::: "memory");
  return;
}

void func_001d86a0(u64 param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_001bb4b0(); asm volatile("" ::: "memory");
  if ((lVar2 != 0) &&
     (iVar1 = func_001bbcb0(), (*(u32 *)(iVar1 + (int)param_2 * 0x38 + 0xf4) & 1) != 0)) {
    func_001d8718(param_1,param_2); asm volatile("" ::: "memory");
    return;
  }
  return;
}

bool func_001d8898(int param_1)

{
  bool bVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  bVar1 = false;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
    bVar1 = false;
    if ((*(u32 *)(iVar2 + param_1 * 0x38 + 0xf4) & 1) != 0) {
      iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
      bVar1 = (*(u32 *)(iVar2 + param_1 * 0x38 + 0xf4) & 8) != 0;
    }
  }
  return bVar1;
}

void func_001d8d08(float param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4b0(); asm volatile("" ::: "memory");
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
    iVar1 = (int)param_2 * 0x34;
    if ((*(u32 *)(iVar2 + iVar1 + 0x19c) & 1) != 0) {
      iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
      func_001d8c70(*(float *)(iVar2 + iVar1 + 0x1bc) + param_1,param_2); asm volatile("" ::: "memory");
      return;
    }
  }
  return;
}

bool func_001d8f38(int param_1)

{
  bool bVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  bVar1 = false;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
    bVar1 = false;
    if ((*(u32 *)(iVar2 + param_1 * 0x34 + 0x19c) & 1) != 0) {
      iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
      bVar1 = (*(u32 *)(iVar2 + param_1 * 0x34 + 0x19c) & 8) != 0;
    }
  }
  return bVar1;
}

u32 func_001d9148(int param_1)

{
  int iVar1;
  u32 uVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + param_1 * 0x40 + 0x26c) & 1) != 0) {
      iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
      uVar2 = *(u32 *)(iVar1 + param_1 * 0x40 + 0x298);
    }
  }
  return uVar2;
}

u32 func_001d9228(int param_1)

{
  int iVar1;
  u32 uVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + param_1 * 0x40 + 0x26c) & 1) != 0) {
      iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
      uVar2 = *(u32 *)(iVar1 + param_1 * 0x40 + 0x28c);
    }
  }
  return uVar2;
}

void func_001d9630(short *param_1,int param_2)

{
  if (0 < param_2) {
    do {
      if (*param_1 != 0) {
        func_001a3188(*param_1,100,0); asm volatile("" ::: "memory");
        *param_1 = 0;
      }
      param_2 = param_2 + -1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

u64 func_001d9980(void)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_00105868(0x32bb30); asm volatile("" ::: "memory");
  uVar2 = 1;
  if (lVar1 != 1) {
    if (lVar1 < 2) {
      uVar2 = 0;
      if (lVar1 != 0) {
        uVar2 = 0;
      }
    }
    else if (lVar1 == 2) {
      lVar1 = func_00276fd0(); asm volatile("" ::: "memory");
      uVar2 = 3;
      if (lVar1 != 100) {
        uVar2 = 2;
      }
    }
    else if (lVar1 == 3) {
      lVar1 = func_00276fd0(); asm volatile("" ::: "memory");
      uVar2 = 5;
      if (lVar1 != 100) {
        uVar2 = 4;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

void func_001da458(u64 param_1,u32 param_2,int param_3,int param_4)

{
  u32 *puVar1;
  int iVar2;
  u32 uVar3;
  
  iVar2 = (int)param_1;
  *(u32 *)(iVar2 + 4) = param_2;
  uVar3 = 0;
  do {
    puVar1 = *(u32 **)(iVar2 + 8);
    uVar3 = uVar3 + 1;
    *puVar1 = 0;
    *(u32 **)(iVar2 + 8) = puVar1 + 1;
  } while (uVar3 < 4);
  if (0 < param_4) {
    do {
      func_001da3d8(param_1,param_3); asm volatile("" ::: "memory");
      param_4 = param_4 + -1;
      param_3 = param_3 + 4;
    } while (param_4 != 0);
  }
  return;
}

bool func_001db198(u64 param_1,s64 param_2)

{
  bool bVar1;
  s64 lVar2;
  
  bVar1 = true;
  if (param_2 != 0) {
    if (param_2 < 0) {
      bVar1 = false;
    }
    else {
      bVar1 = false;
      if (param_2 < 3) {
        bVar1 = false;
        lVar2 = func_001db200(); asm volatile("" ::: "memory");
        if (lVar2 != 0) {
          lVar2 = func_001db250(param_1); asm volatile("" ::: "memory");
          bVar1 = lVar2 != 0;
        }
      }
    }
  }
  return bVar1;
}

void func_001dbc58(int param_1,u64 param_2,u32 *param_3,u8 *param_4)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  func_001c1748(); asm volatile("" ::: "memory");
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *(u32 *)(param_1 + 0x30) = *param_3;
  *(u32 *)(param_1 + 0x34) = uVar1;
  *(u32 *)(param_1 + 0x38) = uVar2;
  *(u32 *)(param_1 + 0x3c) = uVar3;
  *(u8 **)(param_1 + 0x5c) = param_4;
  *(u8 *)(param_1 + 0x50) = 0;
  *(u8 *)(param_1 + 0x16) = 0xff;
  *(u8 *)(param_1 + 0x51) = 0;
  *(u32 *)(param_1 + 0x54) = 0;
  *(u32 *)(param_1 + 0x58) = 0;
  *(u8 *)(param_1 + 0x14) = *param_4;
  return;
}

bool func_001dc558(u32 param_1,int param_2)

{
  u64 uVar1;
  s64 lVar2;
  bool bVar3;
  
  bVar3 = true;
  if (*(int *)(param_2 + 4) != 4) {
    uVar1 = func_001e6b90(); asm volatile("" ::: "memory");
    *(int *)(param_2 + 0x1c) = (int)uVar1;
    lVar2 = func_001e6c40(param_1,uVar1,*(u32 *)(param_2 + 0x14),
                         *(u32 *)(param_2 + 0x18),*(u32 *)(param_2 + 0x10));
    bVar3 = lVar2 != 0;
  }
  if ((bVar3 == false) && (*(int *)(param_2 + 0x1c) != 0)) {
    func_001e2c00(*(int *)(param_2 + 0x1c)); asm volatile("" ::: "memory");
    func_001e6c00(*(u32 *)(param_2 + 0x1c)); asm volatile("" ::: "memory");
    *(u32 *)(param_2 + 0x1c) = 0;
  }
  return bVar3;
}

u32 func_001dc790(int param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_001dc738(); asm volatile("" ::: "memory");
  if ((lVar2 != 0) || (uVar1 = 0, (*(u32 *)(param_1 + 8) & 0x200000) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

bool func_001dc7e8(int param_1)

{
  s64 lVar1;
  
  func_001dc9e0(); asm volatile("" ::: "memory");
  lVar1 = func_001e2c78(*(u32 *)(param_1 + 0x1c)); asm volatile("" ::: "memory");
  return lVar1 != 0;
}

bool func_001dc9f0(int param_1)

{
  s64 lVar1;
  
  func_001dc9e0(); asm volatile("" ::: "memory");
  lVar1 = func_001e6d08(*(u32 *)(param_1 + 0x1c)); asm volatile("" ::: "memory");
  return lVar1 != 0;
}

void func_001dca70(int param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = 0;
  if ((*(u32 *)(param_1 + 8) & 0x40000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(u32 *)(param_1 + 0x30);
    uVar2 = *(u32 *)(param_1 + 0x34);
  }
  func_001e7070(uVar1,uVar2); asm volatile("" ::: "memory");
  uVar1 = 0;
  if ((*(u32 *)(param_1 + 8) & 0x80000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(u32 *)(param_1 + 0x34);
    uVar1 = *(u32 *)(param_1 + 0x30);
  }
  func_001e7088(uVar1,uVar2); asm volatile("" ::: "memory");
  return;
}
