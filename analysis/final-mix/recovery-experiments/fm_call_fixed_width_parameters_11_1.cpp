#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(s64);
extern "C" bool func_002944d0(void*);
extern "C" s32 func_001d56c8(...);
extern "C" s32 func_002924d0(s32,s64);
extern "C" s32 func_00295158(s32);
extern "C" s32 func_0029a5f0(...);
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002aa5b8(s8,s32);
extern "C" s32 func_002abf40(s8,s32);
extern "C" s32 func_002b6708(...);
extern "C" u32 func_00102448(s32,u32);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00102a38(s32,s32);
extern "C" u32 func_00103eb0(void);
extern "C" u32 func_001058e8(void);
extern "C" u32 func_00139d78(s32);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_002538f8(s32);
extern "C" u32 func_00253928(s32);
extern "C" u32 func_002539e8(s32,void*);
extern "C" u32 func_00276150(...);
extern "C" u32 func_00276568(void);
extern "C" u32 func_002766d0(void);
extern "C" u32 func_00276c18(void);
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_0028da70(u64,s32);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(u64);
extern "C" u32 func_0029df98(...);
extern "C" u32 func_0029e050(...);
extern "C" u32 func_0029e258(...);
extern "C" u32 func_002b3c38(...);
extern "C" u64 func_00192e50(...);
extern "C" u64 func_00242618(u64,s8);
extern "C" u64 func_002941a8(void*);
extern "C" u64 func_002941d8(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_00253918(void);
extern "C" u8 func_00292520(u64,s64,s64);

void func_002920c0(u32 param_1,int *param_2,u32 param_3,u32 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_002924d0(param_1,param_3); asm volatile("" ::: "memory");
  iVar2 = func_002924d0(param_1,param_4); asm volatile("" ::: "memory");
  *param_2 = ((u32)*(u16 *)(param_5 + 0x18e) - (u32)*(u8 *)(iVar1 + 7)) +
             (u32)*(u8 *)(iVar2 + 7);
  func_00292520(param_1,*(u8 *)(iVar1 + 7),*(u8 *)(iVar2 + 7)); asm volatile("" ::: "memory");
  return;
}

void func_00292148(u32 param_1,int *param_2,u32 param_3,u32 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_002924d0(param_1,param_3); asm volatile("" ::: "memory");
  iVar2 = func_002924d0(param_1,param_4); asm volatile("" ::: "memory");
  *param_2 = ((u32)*(u16 *)(param_5 + 0x188) - (u32)*(u8 *)(iVar1 + 4)) +
             (u32)*(u8 *)(iVar2 + 4);
  func_00292520(param_1,*(u8 *)(iVar1 + 4),*(u8 *)(iVar2 + 4)); asm volatile("" ::: "memory");
  return;
}

void func_002921d0(u32 param_1,int *param_2,u32 param_3,u32 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_002924d0(param_1,param_3); asm volatile("" ::: "memory");
  iVar2 = func_002924d0(param_1,param_4); asm volatile("" ::: "memory");
  *param_2 = ((u32)*(u16 *)(param_5 + 0x18a) - (u32)*(u8 *)(iVar1 + 5)) +
             (u32)*(u8 *)(iVar2 + 5);
  func_00292520(param_1,*(u8 *)(iVar1 + 5),*(u8 *)(iVar2 + 5)); asm volatile("" ::: "memory");
  return;
}

void func_00292258(u32 param_1,int *param_2,u32 param_3,u32 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_002924d0(param_1,param_3); asm volatile("" ::: "memory");
  iVar2 = func_002924d0(param_1,param_4); asm volatile("" ::: "memory");
  *param_2 = ((u32)*(u16 *)(param_5 + 0x18c) - (u32)*(u8 *)(iVar1 + 6)) +
             (u32)*(u8 *)(iVar2 + 6);
  func_00292520(param_1,*(u8 *)(iVar1 + 6),*(u8 *)(iVar2 + 6)); asm volatile("" ::: "memory");
  return;
}

void func_00293350(u32 param_1,u32 param_2,u32 param_3)

{
  int iVar1;
  
  iVar1 = func_00103eb0(); asm volatile("" ::: "memory");
  iVar1 = func_00102818(*(u32 *)(iVar1 + 4),0,140000,0x2933b8,0x1000); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0xc) = param_3;
  *(u32 *)(iVar1 + 4) = param_1;
  *(u32 *)(iVar1 + 8) = param_2;
  return;
}

void func_00293b70(void)

{
  int iVar1;
  
  iVar1 = func_00103eb0(); asm volatile("" ::: "memory");
  func_00102a38(*(u32 *)(iVar1 + 4),0x293b08); asm volatile("" ::: "memory");
  return;
}

u64 func_00294208(char param_1)

{
  int *piVar1;
  char *pcVar2;
  u64 uVar3;
  int iVar4;
  
  pcVar2 = (char *)func_00294000(0); asm volatile("" ::: "memory");
  piVar1 = (int *)(pcVar2 + 8);
  iVar4 = 0;
  if (0 < *piVar1) {
    do {
      pcVar2 = pcVar2 + 0x10;
      iVar4 = iVar4 + 1;
      if (*pcVar2 == param_1) {
        uVar3 = func_002941d8(); asm volatile("" ::: "memory");
        return uVar3;
      }
    } while (iVar4 < *piVar1);
  }
  return 0;
}

bool func_00294408(u16 *param_1)

{
  s64 lVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(char *)(param_1 + 3) == '\x02') {
    lVar1 = func_001a3570(*param_1); asm volatile("" ::: "memory");
    bVar2 = 0 < lVar1;
  }
  else {
    lVar1 = func_00181500(*param_1); asm volatile("" ::: "memory");
    if (lVar1 != 0) {
      bVar2 = true;
    }
  }
  if ((param_1[1] != 0) && (lVar1 = func_00181500(param_1[1]), lVar1 != 0)) {
    bVar2 = false;
  }
  return bVar2;
}

bool func_00294480(u16 *param_1)

{
  s64 lVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(char *)(param_1 + 3) == '\x02') {
    lVar1 = func_001a3570(*param_1); asm volatile("" ::: "memory");
    bVar2 = 0 < lVar1;
  }
  else {
    lVar1 = func_00181500(*param_1); asm volatile("" ::: "memory");
    if (lVar1 != 0) {
      bVar2 = true;
    }
  }
  return bVar2;
}

u8 func_00295228(u32 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_00294000(0); asm volatile("" ::: "memory");
  iVar2 = func_00295158(param_1); asm volatile("" ::: "memory");
  return *(u8 *)(iVar2 * 0x10 + iVar1 + 0x10);
}

int func_002953c8(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_00294000(0); asm volatile("" ::: "memory");
  iVar3 = 0;
  if (*(int *)(iVar1 + 8) < 1) {
    iVar2 = 0;
  }
  else {
    do {
      iVar2 = iVar3 * 0x10;
      iVar3 = iVar3 + 1;
      if (*(char *)(iVar2 + iVar1 + 0x10) == param_1) break;
      iVar2 = iVar3 * 0x10;
    } while (iVar3 < *(int *)(iVar1 + 8));
  }
  return iVar1 + 0x10 + iVar2;
}

void func_002956c0(u32 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_00294000(0); asm volatile("" ::: "memory");
  iVar2 = func_00295158(param_1); asm volatile("" ::: "memory");
  func_002941a8(iVar1 + 0x10 + iVar2 * 0x10); asm volatile("" ::: "memory");
  return;
}

bool func_0029a780(s32 param_1)

{
  bool bVar1;
  u8 *pbVar2;
  u64 uVar3;
  u64 uVar4;
  int iStack_30;
  int aiStack_2c [3];
  
  uVar3 = func_00287bc0(); asm volatile("" ::: "memory");
  if ((int)param_1 + 9U < 2) {
    func_00276150(uVar3); asm volatile("" ::: "memory");
    if (param_1 == -8) {
      iStack_30 = aiStack_2c[0];
    }
    pbVar2 = (u8 *)func_00276568(); asm volatile("" ::: "memory");
    if ((iStack_30 != 2) || (bVar1 = false, *pbVar2 < 0xf)) {
      bVar1 = true;
    }
  }
  else {
    uVar4 = func_0029a5f0(param_1,&iStack_30,aiStack_2c); asm volatile("" ::: "memory");
    bVar1 = uVar4 < 0xc;
  }
  return bVar1;
}

void func_0029e2f8(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0(); asm volatile("" ::: "memory");
  func_00139d78(iVar1 + (param_1 + 1) * 0x198 + 0x4398); asm volatile("" ::: "memory");
  return;
}

void func_0029e3a0(int param_1)

{
  int iVar1;
  
  iVar1 = func_002766d0(); asm volatile("" ::: "memory");
  func_0028da70(iVar1 + (param_1 + 1) * 0x198 + 0x4398,8); asm volatile("" ::: "memory");
  return;
}

int func_002a01c8(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(4); asm volatile("" ::: "memory");
  return iVar1 + 0x10 + param_1 * 8;
}

int func_002a6368(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(6); asm volatile("" ::: "memory");
  return iVar1 + 0x10 + param_1 * 8;
}

u32 func_002a6500(void)

{
  int iVar1;
  s64 lVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  
  iVar4 = 0;
  uVar5 = 0;
  iVar1 = func_00294000(6); asm volatile("" ::: "memory");
  iVar3 = iVar1 + 0x10;
  if (0 < *(int *)(iVar1 + 8)) {
    do {
      lVar2 = func_002944d0(iVar3); asm volatile("" ::: "memory");
      if (lVar2 != 0) {
        uVar5 = 1;
        break;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 8;
    } while (iVar4 < *(int *)(iVar1 + 8));
  }
  lVar2 = func_00276c18(); asm volatile("" ::: "memory");
  if (lVar2 != 0) {
    uVar5 = 1;
  }
  return uVar5;
}

u32 func_002a74c0(void)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar1 = func_001058e8(); asm volatile("" ::: "memory");
  uVar2 = 0;
  uVar4 = 0;
  while( true ) {
    uVar3 = uVar2 & 0x1f;
    uVar2 = uVar2 + 1;
    if ((*(u32 *)(uVar4 * 4 + iVar1 + 0x49f4) & 1 << uVar3) != 0) {
      return 1;
    }
    if (0x3f < (int)uVar2) break;
    uVar4 = uVar2 >> 5;
  }
  return 0;
}

int func_002a7f20(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(7); asm volatile("" ::: "memory");
  return iVar1 + 0x10 + param_1 * 8;
}

int func_002a92a0(int param_1)

{
  int iVar1;
  
  iVar1 = func_00294000(8); asm volatile("" ::: "memory");
  return iVar1 + 0x10 + param_1 * 0x10;
}

void func_002aa450(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x13c);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002aa8e0(u32 param_1,u32 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  uVar3 = func_002aa5b8(param_1,param_2); asm volatile("" ::: "memory");
  puVar4 = (u32 *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0x44);
  uVar1 = *puVar4;
  uVar3 = 1 << (uVar3 & 0x1f);
  if ((uVar1 & uVar3) == 0) {
    *puVar4 = uVar1 | uVar3;
  }
  return;
}

void func_002aab90(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x84);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002aae30(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x94);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002ab258(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  puVar3 = (u32 *)((param_1 >> 5) * 4 + iVar2 + 0x88);
  uVar1 = *puVar3;
  uVar4 = 1 << (param_1 & 0x1f);
  if ((uVar1 & uVar4) == 0) {
    *puVar3 = uVar1 | uVar4;
  }
  return;
}

void func_002abdc8(void)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  
  iVar1 = func_002a9d68(); asm volatile("" ::: "memory");
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar4 = 1 << (uVar3 & 0x1f);
    puVar2 = (u32 *)(uVar5 * 4 + iVar1 + 0x140);
    uVar3 = uVar3 + 1;
    uVar5 = *puVar2;
    if ((uVar5 & uVar4) == 0) {
      *puVar2 = uVar5 | uVar4;
    }
    uVar5 = uVar3 >> 5;
  } while ((int)uVar3 < 4);
  return;
}

void func_002ac268(u32 param_1,u32 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  iVar2 = func_002a9d68(); asm volatile("" ::: "memory");
  uVar3 = func_002abf40(param_1,param_2); asm volatile("" ::: "memory");
  puVar4 = (u32 *)((uVar3 >> 5) * 4 + iVar2 + (int)param_1 * 4 + 0xac);
  uVar1 = *puVar4;
  uVar3 = 1 << (uVar3 & 0x1f);
  if ((uVar1 & uVar3) == 0) {
    *puVar4 = uVar1 | uVar3;
  }
  return;
}

u64 func_002b0de0(u32 param_1)

{
  s64 lVar1;
  u64 uVar2;
  s64 lVar3;
  
  lVar3 = 1;
  if (((((param_1 & 0xc00f0) == 0) && (lVar3 = 3, (param_1 & 8) == 0)) &&
      (lVar3 = 2, (param_1 & 4) == 0)) &&
     ((lVar3 = 5, (param_1 & 0x100) == 0 && (lVar3 = 2, (param_1 & 0x32000) == 0)))) {
    lVar3 = 0;
  }
  lVar1 = func_002b3c38(); asm volatile("" ::: "memory");
  if (lVar1 == 0) {
    lVar3 = 4;
  }
  uVar2 = 0;
  if (lVar3 != 0) {
    uVar2 = func_00242618(lVar3,1); asm volatile("" ::: "memory");
  }
  return uVar2;
}

u32 func_002b6298(u32 param_1)

{
  s64 lVar1;
  
  lVar1 = func_002538f8(1); asm volatile("" ::: "memory");
  if (lVar1 == 0) {
    lVar1 = func_00253928(1); asm volatile("" ::: "memory");
    if (lVar1 == 0) {
      while ((lVar1 = func_00253918(), lVar1 != 0 || (lVar1 = func_002539e8(1,0), lVar1 != 0))) {
        func_00102448(param_1,0); asm volatile("" ::: "memory");
      }
    }
    while (lVar1 = func_002538f8(1), lVar1 == 0) {
      func_00102448(param_1,0); asm volatile("" ::: "memory");
    }
  }
  return 1;
}

void func_002b6338(u32 param_1,u32 param_2,u32 param_3,s32 param_4)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar2 = 0xb7d4;
  if (param_4 != 0) {
    uVar2 = 0xb7d5;
  }
  uVar1 = func_00192048(param_3); asm volatile("" ::: "memory");
  uVar2 = func_00192048(uVar2); asm volatile("" ::: "memory");
  func_00192e50(uVar1,param_1,param_2,uVar2); asm volatile("" ::: "memory");
  return;
}

u64 func_002b6adc(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,6,param_2,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64
func_002b6b24(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(6,7,param_1,param_2,param_3,param_4,param_5); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b6b84(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,8,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b6bc4(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,9,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b6c04(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,10,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b6f28(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0xe,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u64
func_002b7010(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5,u32 param_6)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(7,0xf,param_1,param_2,param_3,param_4,param_5,param_6); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7078(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x10,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b70b8(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x11,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b7108(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x12,param_1); asm volatile("" ::: "memory");
  return uVar1;
}

u64
func_002b726c(u32 param_1,u32 param_2,u32 param_3,int param_4,u32 param_5
            )

{
  u64 uVar1;
  u32 uStack_20;
  
  uStack_20 = param_5;
  if (0x39ff < param_4) {
    uStack_20 = 0x40;
  }
  uVar1 = func_002b6708(6,0x13,param_1,param_2,param_3,param_4,uStack_20); asm volatile("" ::: "memory");
  return uVar1;
}

u64 func_002b72e4(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x14,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return uVar1;
}

u64
func_002b7334(u32 param_1,u32 param_2,u32 param_3,int param_4,u32 param_5
            )

{
  u64 uVar1;
  u32 uStack_20;
  
  uStack_20 = param_5;
  if (0x39ff < param_4) {
    uStack_20 = 0x40;
  }
  uVar1 = func_002b6708(6,0x15,param_1,param_2,param_3,param_4,uStack_20); asm volatile("" ::: "memory");
  return uVar1;
}
