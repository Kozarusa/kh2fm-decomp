#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001b58a8(...);
extern "C" bool func_001bb4a0(...);
extern "C" bool func_001bd590(...);
extern "C" bool func_001bd918(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001c8db8(...);
extern "C" bool func_001d1ca8(...);
extern "C" bool func_001d1f08(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001a8bd0(...);
extern "C" s32 func_001affe0(...);
extern "C" s32 func_001b8420(...);
extern "C" s32 func_001bc780(...);
extern "C" s32 func_001bd418(...);
extern "C" s32 func_001bd570(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u16 func_001a36e0(...);
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00105110(...);
extern "C" u32 func_00165768(...);
extern "C" u32 func_0016bc20(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016f7d0(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_001819c0(...);
extern "C" u32 func_001a17c8(...);
extern "C" u32 func_001a1910(...);
extern "C" u32 func_001a1a50(...);
extern "C" u32 func_001a1cc0(...);
extern "C" u32 func_001a34e0(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a8110(...);
extern "C" u32 func_001abba8(...);
extern "C" u32 func_001ac310(...);
extern "C" u32 func_001ac7c8(...);
extern "C" u32 func_001acdc0(...);
extern "C" u32 func_001ad0f8(...);
extern "C" u32 func_001afee8(...);
extern "C" u32 func_001aff90(...);
extern "C" u32 func_001b1be0(...);
extern "C" u32 func_001b6dd0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u32 func_001ba598(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001bc720(...);
extern "C" u32 func_001bc778(...);
extern "C" u32 func_001bc990(...);
extern "C" u32 func_001bd370(...);
extern "C" u32 func_001bd3a0(...);
extern "C" u32 func_001bd668(...);
extern "C" u32 func_001bdf68(...);
extern "C" u32 func_001bdff0(...);
extern "C" u32 func_001c9df8(...);
extern "C" u32 func_001d1d68(...);
extern "C" u32 func_001d20a8(...);
extern "C" u32 func_001d2180(...);
extern "C" u32 func_001d48b0(...);
extern "C" u32 func_001d4fa8(...);
extern "C" u32 func_001d5370(...);
extern "C" u32 func_001d6da8(...);
extern "C" u32 func_001db610(...);
extern "C" u32 func_001db710(...);
extern "C" u32 func_001db7d0(...);
extern "C" u32 func_001dc920(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023acd8(...);
extern "C" u32 func_0023ade0(...);
extern "C" u32 func_002534e0(...);
extern "C" u32 func_002ba2e8(...);
extern "C" u32 func_003201e8(...);
extern "C" u32 func_003204c8(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_001a8bf8(...);

u16 func_001a3958(u32 param_1)

{
  s32 lVar1;
  u16 *puVar2;
  s32 lVar3;
  
  lVar3 = 0;
  do {
    lVar3 = func_001a8110(lVar3); asm volatile("" ::: "memory");
    if (lVar3 == 0) {
      return 0;
    }
    puVar2 = (u16 *)lVar3;
  } while ((*(u8 *)(puVar2 + 1) != param_1) || (lVar1 = func_001a3570(*puVar2), lVar1 < 1)); asm volatile("" ::: "memory");
  func_001a34e0(*puVar2,1); asm volatile("" ::: "memory");
  return *puVar2;
}

void func_001abf38(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    func_0023acd8(param_1 + 1); asm volatile("" ::: "memory");
    param_1[0x53] = param_2;
    param_1[0x54] = param_3;
    func_0023ade0(param_1 + 1); asm volatile("" ::: "memory");
    return;
  }
  if ((1 < iVar1) && (iVar1 == 2)) {
    func_001abba8(param_1 + 0x57); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001ad020(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_1 + *(int *)(param_1 + 0xb68) * 0x158;
  *(int *)(param_1 + 0xb68) = *(int *)(param_1 + 0xb68) + 1;
  func_00239bf8(iVar1 + 0x608,param_4 + 10); asm volatile("" ::: "memory");
  *(int *)(iVar1 + 0x754) = param_3 + -0x7300 >> 4;
  *(int *)(iVar1 + 0x750) = param_2 + -0x7000 >> 4;
  return;
}

void func_001ad158(int param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_001050d8(0xb6c); asm volatile("" ::: "memory");
  func_001ad0f8(uVar1,param_4,0); asm volatile("" ::: "memory");
  iVar2 = (int)uVar1;
  *(int *)(param_1 + 0x4a8) = iVar2;
  *(u32 *)(iVar2 + 8) = param_3;
  *(u32 *)(iVar2 + 4) = param_2;
  return;
}

void func_001ad3e0(int param_1)

{
  func_001acdc0(); asm volatile("" ::: "memory");
  func_001ac310(param_1 + 0xb6c); asm volatile("" ::: "memory");
  return;
}

void func_001ad520(int param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  
  uVar1 = func_001050d8(0xb6c); asm volatile("" ::: "memory");
  func_001ad0f8(uVar1,param_4,0); asm volatile("" ::: "memory");
  uVar2 = func_001050d8(0x1c); asm volatile("" ::: "memory");
  func_001ac7c8(uVar2,uVar1); asm volatile("" ::: "memory");
  iVar3 = (int)uVar1;
  *(int *)(param_1 + 0x4a8) = iVar3;
  *(u32 *)(iVar3 + 8) = param_3;
  *(u32 *)(iVar3 + 4) = param_2;
  return;
}

void func_001adb80(u32 param_1,u32 param_2)

{
  func_001a1a50(param_2,0); asm volatile("" ::: "memory");
  func_001a1910(param_2,*(u32 *)((int)param_2 + 4),0); asm volatile("" ::: "memory");
  return;
}

u16 func_001ae270(int param_1)

{
  char cVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u16 uVar5;
  u16 uVar6;
  char *pcVar7;
  
  uVar6 = 0xffff;
  uVar2 = func_002ff3fc(); asm volatile("" ::: "memory");
  uVar3 = 0;
  pcVar7 = (char *)(param_1 + uVar2 + -1);
  if (uVar2 != 0) {
    cVar1 = *pcVar7;
    while( true ) {
      iVar4 = 7;
      pcVar7 = pcVar7 + -1;
      uVar6 = uVar6 ^ (short)cVar1 << 8;
      do {
        uVar5 = uVar6 & 0x8000;
        uVar6 = uVar6 << 1;
        if (uVar5 != 0) {
          uVar6 = uVar6 ^ 0x1021;
        }
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
      uVar3 = uVar3 + 1;
      if (uVar2 <= uVar3) break;
      cVar1 = *pcVar7;
    }
  }
  return ~uVar6;
}

u32 func_001afe70(u32 param_1,u32 param_2,u32 param_3,u32 *param_4)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_001aff90(); asm volatile("" ::: "memory");
  if (lVar1 != 0) {
    *param_4 = (u32)*(u8 *)((int)lVar1 + 2);
    uVar2 = func_001affe0(lVar1,param_1,param_3); asm volatile("" ::: "memory");
    return uVar2;
  }
  return 0xffffffffffffffff;
}

s32 func_001b0148(u32 param_1,u32 param_2,s32 param_3,u32 param_4)

{
  bool bVar1;
  s32 lVar2;
  
  if ((param_3 < 0) && (bVar1 = param_3 == -3, param_3 = -1, bVar1)) {
    lVar2 = func_001afee8(param_2,param_4); asm volatile("" ::: "memory");
    return lVar2;
  }
  return param_3;
}

void func_001b0448(u32 *param_1,u32 param_2)

{
  s32 lVar1;
  
  lVar1 = func_0016bc20(param_2,0xc,0xffffffffffffffff); asm volatile("" ::: "memory");
  if (lVar1 != 0) {
    *param_1 = (int)param_2;
    param_1[3] = (u32)*(u16 *)((int)lVar1 + 6);
  }
  return;
}

void func_001b1bb8(int param_1,u8 param_2,u8 param_3,u8 param_4,
                 u8 param_5)

{
  *(u8 *)(param_1 + 0x14) = param_2;
  *(u8 *)(param_1 + 0x17) = param_5;
  *(u8 *)(param_1 + 0x15) = param_3;
  *(u8 *)(param_1 + 0x16) = param_4;
  func_001b1be0(); asm volatile("" ::: "memory");
  return;
}

void func_001b2488(u32 param_1)

{
  func_00105110(*(u32 *)((int)param_1 + 0x14)); asm volatile("" ::: "memory");
  func_003201e8(0x1d48c80,param_1); asm volatile("" ::: "memory");
  return;
}

void func_001b2780(u32 param_1,u32 param_2,u32 *param_3)

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

void func_001b27f0(u32 param_1,u32 param_2,u8 param_3)

{
  int iVar1;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 auStack_20 [4];
  
  func_0017c030(&uStack_40,param_2,auStack_20,param_3); asm volatile("" ::: "memory");
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  func_001b6dd0(param_2); asm volatile("" ::: "memory");
  iVar1 = (int)param_2;
  *(u8 *)(iVar1 + 0x514) = 4;
  func_0017f488(0,0,iVar1 + 0x140,auStack_20[0]); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0x104) = 5;
  *(u32 *)(iVar1 + 0x100) = 4;
  return;
}

void func_001b3018(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(*param_1 + 4)) {
      iVar2 = 0;
      iVar1 = param_1[1];
      while( true ) {
        iVar3 = iVar3 + 1;
        iVar1 = iVar2 + iVar1;
        iVar2 = iVar2 + 0x90;
        func_00165768(*(u32 *)(iVar1 + 0x80)); asm volatile("" ::: "memory");
        if (*(int *)(*param_1 + 4) <= iVar3) break;
        iVar1 = param_1[1];
      }
    }
    func_00105110(param_1[1]); asm volatile("" ::: "memory");
    *param_1 = 0;
  }
  return;
}

void func_001b3098(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(*param_1 + 4)) {
      iVar2 = 0;
      iVar1 = param_1[1];
      while( true ) {
        iVar3 = iVar3 + 1;
        iVar1 = iVar2 + iVar1;
        iVar2 = iVar2 + 0x90;
        func_00165768(*(u32 *)(iVar1 + 0x80)); asm volatile("" ::: "memory");
        if (*(int *)(*param_1 + 4) <= iVar3) break;
        iVar1 = param_1[1];
      }
    }
    func_00105110(param_1[1]); asm volatile("" ::: "memory");
    *param_1 = 0;
  }
  return;
}

bool func_001b55e8(int *param_1)

{
  u32 uVar1;
  s32 lVar2;
  bool bVar3;
  
  if ((*(int *)(*param_1 + 0x24) != 0) &&
     (uVar1 = func_0016f7d0(*(int *)(*param_1 + 0x24),0), (uVar1 & 8) != 0)) {
    return false;
  }
  lVar2 = func_001d1ca8(param_1 + 0x1a); asm volatile("" ::: "memory");
  bVar3 = false;
  if (lVar2 == 0) {
    lVar2 = func_001d1f08(param_1 + 0x2a); asm volatile("" ::: "memory");
    bVar3 = false;
    if (lVar2 == 0) {
      lVar2 = func_001c9df8(); asm volatile("" ::: "memory");
      bVar3 = false;
      if ((lVar2 == 0) && (bVar3 = false, param_1[9] == 0)) {
        bVar3 = param_1[0xf] == 0;
      }
    }
  }
  return bVar3;
}

void func_001b5878(int param_1)

{
  if ((*(u32 *)(param_1 + 0xb4) & 4) != 0) {
    func_001d1d68(param_1 + 0xa8); asm volatile("" ::: "memory");
    return;
  }
  return;
}

u32 func_001b5c78(int param_1)

{
  u32 uVar1;
  
  uVar1 = *(u32 *)(param_1 + 0x94);
  func_001d2180(param_1 + 0x68); asm volatile("" ::: "memory");
  func_001d20a8(param_1 + 0x68); asm volatile("" ::: "memory");
  return uVar1;
}

bool func_001b6070(void)

{
  s32 lVar1;
  u32 uVar2;
  bool bVar3;
  
  lVar1 = func_001b58a8(); asm volatile("" ::: "memory");
  bVar3 = false;
  if (lVar1 == 0) {
    bVar3 = false;
    uVar2 = func_001a8bd0(0xffffffffffffffff); asm volatile("" ::: "memory");
    lVar1 = func_001a8bf8(uVar2,3); asm volatile("" ::: "memory");
    if (lVar1 != 0x12) {
      lVar1 = func_001c8db8(0x351ec0,0); asm volatile("" ::: "memory");
      bVar3 = lVar1 == 0;
    }
  }
  return bVar3;
}

void func_001b6ab8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = func_00189200(0x32e020,*(u32 *)(param_1 + 4)); asm volatile("" ::: "memory");
    func_001a1cc0(*(u32 *)(param_1 + 0x14),*(u32 *)(param_1 + 4),
                 *(u8 *)(iVar1 + 2));
    func_001a17c8(*(u32 *)(param_1 + 0x14)); asm volatile("" ::: "memory");
    *(u32 *)(param_1 + 0x14) = 0;
  }
  return;
}

bool func_001b84b8(u32 param_1,u32 param_2)

{
  bool bVar1;
  u32 uVar2;
  s32 lVar3;
  u32 *puVar4;
  
  bVar1 = false;
  puVar4 = (u32 *)param_1;
  if (puVar4[1] != 0) {
    puVar4[4] = param_2;
    if (puVar4[2] == 0) {
      uVar2 = func_001b8420(*puVar4); asm volatile("" ::: "memory");
      puVar4[2] = uVar2;
      uVar2 = puVar4[2];
    }
    else {
      uVar2 = puVar4[2];
    }
    lVar3 = func_001db610(uVar2,0x1b8520,param_1); asm volatile("" ::: "memory");
    puVar4[2] = (int)lVar3;
    bVar1 = lVar3 != 0;
  }
  return bVar1;
}

void func_001b90c8(void)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_001a36e0(); asm volatile("" ::: "memory");
  iVar2 = func_001a80c8(uVar1); asm volatile("" ::: "memory");
  func_001b8e88(*(u16 *)(iVar2 + 0x10)); asm volatile("" ::: "memory");
  return;
}

void func_001ba310(u32 param_1)

{
  func_001ba598(); asm volatile("" ::: "memory");
  func_003204c8(0x1d48de0,param_1); asm volatile("" ::: "memory");
  return;
}

u32 func_001bba30(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uVar2 = 0;
  if (*(int *)(param_1 + 0x48) != 0) {
    bVar1 = *(u8 *)(*(int *)(param_1 + 8) + 0xc);
    if (bVar1 == 0) {
      uVar2 = 0;
    }
    else {
      func_001d5370(&uStack_20,*(int *)(param_1 + 0x48),bVar1 - 1); asm volatile("" ::: "memory");
      func_002534e0(uStack_1c,uStack_20); asm volatile("" ::: "memory");
      uVar2 = 1;
    }
  }
  return uVar2;
}

u8 func_001bbcc0(void)

{
  u8 uVar1;
  int iVar2;
  s32 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar1 = 1;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar1 = *(u8 *)(*(int *)(iVar2 + 8) + 0xe);
  }
  return uVar1;
}

u32 func_001bbdb8(u32 param_1)

{
  int iVar1;
  u32 uVar2;
  s32 lVar3;
  
  lVar3 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + 0x2f0) & 4) != 0) {
      iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
      func_001d4fa8(iVar1 + 0x2e4,param_1); asm volatile("" ::: "memory");
      uVar2 = 1;
    }
  }
  return uVar2;
}

u16 func_001bbec0(void)

{
  int iVar1;
  s32 lVar2;
  u16 uVar3;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar3 = *(u16 *)(*(int *)(iVar1 + 8) + 4) >> 0xb & 1;
  }
  return uVar3;
}

u16 func_001bbf00(void)

{
  int iVar1;
  s32 lVar2;
  u16 uVar3;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar3 = *(u16 *)(*(int *)(iVar1 + 8) + 4) >> 0xc & 1;
  }
  return uVar3;
}

u16 func_001bbf40(void)

{
  int iVar1;
  s32 lVar2;
  u16 uVar3;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar3 = *(u16 *)(*(int *)(iVar1 + 8) + 4) >> 1 & 1;
  }
  return uVar3;
}

u16 func_001bc010(void)

{
  int iVar1;
  s32 lVar2;
  u16 uVar3;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar3 = *(u16 *)(*(int *)(iVar1 + 8) + 4) >> 0xd & 1;
  }
  return uVar3;
}

u16 func_001bc050(void)

{
  int iVar1;
  s32 lVar2;
  u16 uVar3;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = func_001bbcb0(); asm volatile("" ::: "memory");
    uVar3 = *(u16 *)(*(int *)(iVar1 + 8) + 4) >> 0xe & 1;
  }
  return uVar3;
}

u32 func_001bc0e0(void)

{
  int iVar1;
  s32 lVar2;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  if ((lVar2 != 0) && (iVar1 = func_001bbcb0(), (*(u32 *)(iVar1 + 4) & 0x10) != 0)) {
    return 0;
  }
  return 1;
}

u32 func_001bc130(void)

{
  int iVar1;
  s32 lVar2;
  
  lVar2 = func_001bb4a0(); asm volatile("" ::: "memory");
  if ((lVar2 != 0) && (iVar1 = func_001bbcb0(), (*(u16 *)(*(int *)(iVar1 + 8) + 4) >> 2 & 1) == 0)
     ) {
    return 0;
  }
  return 1;
}

void func_001bce90(u32 param_1,u16 *param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  u32 uVar2;
  
  uVar2 = 0;
  func_001bc778(); asm volatile("" ::: "memory");
  if (param_3 != 0) {
    do {
      iVar1 = func_001bc780(param_1,*param_2,param_4,1); asm volatile("" ::: "memory");
      uVar2 = uVar2 + 1;
      *(u8 *)(iVar1 + 6) = *(u8 *)(param_2 + 1);
      param_2 = param_2 + 2;
    } while (uVar2 < param_3);
  }
  return;
}

u32 func_001bd3e0(int param_1)

{
  u32 uVar1;
  
  if ((*(u32 *)(*(int *)(param_1 + 0x9e0) + 0x588) & 0x2000000) == 0) {
    uVar1 = func_001bd418(); asm volatile("" ::: "memory");
    return uVar1;
  }
  return 0;
}

void func_001bd5b0(int param_1,int param_2,char param_3)

{
  if (*(int *)(param_1 + 0x8c0) == 0) {
    *(int *)(param_1 + 0x8c0) = param_1 + 0x9e8;
  }
  else {
    *(int *)(param_1 + 0x8c0) = *(int *)(param_1 + 0x8c0) + 4;
  }
  **(int **)(param_1 + 0x8c0) = param_1 + param_2 * 0x74 + 0x24;
  if (param_3 != '\0') {
    func_002ba2e8(3,0); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001bd618(int param_1,char param_2)

{
  **(u32 **)(param_1 + 0x8c0) = 0;
  if (*(int *)(param_1 + 0x8c0) == param_1 + 0x9e8) {
    *(u32 *)(param_1 + 0x8c0) = 0;
  }
  else {
    *(int *)(param_1 + 0x8c0) = *(int *)(param_1 + 0x8c0) + -4;
  }
  if (param_2 != '\0') {
    func_002ba2e8(4,0); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001bd8c8(u32 param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = **(int **)((int)param_1 + 0x8c0);
  uVar2 = func_001b8e88(*(u16 *)(iVar1 + *(int *)(iVar1 + 0x6c) * 0xc + 0xe)); asm volatile("" ::: "memory");
  func_001bd918(param_1,uVar2,0); asm volatile("" ::: "memory");
  return;
}

void func_001bdc18(u32 param_1)

{
  func_001d48b0((int)param_1 + 0x9c0); asm volatile("" ::: "memory");
  func_001bd668(param_1); asm volatile("" ::: "memory");
  return;
}

u32 func_001bdcd0(u32 param_1)

{
  s32 lVar1;
  
  lVar1 = func_001819c0(); asm volatile("" ::: "memory");
  if ((lVar1 != 0) && (lVar1 = func_001bd590(param_1), lVar1 == 0)) {
    return 0;
  }
  return 1;
}

void func_001bded8(u32 param_1)

{
  int iVar1;
  
  func_001bd370(); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  func_001bc720(iVar1 + 0x24); asm volatile("" ::: "memory");
  func_001bc720(iVar1 + 0x2dc); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0x9e0) = 0;
  func_001bd3a0(param_1); asm volatile("" ::: "memory");
  func_001bdf68(param_1); asm volatile("" ::: "memory");
  func_001bdff0(); asm volatile("" ::: "memory");
  func_001d6da8(iVar1 + 0xa52); asm volatile("" ::: "memory");
  *(u32 *)(iVar1 + 0xab0) = 0;
  *(u32 *)(iVar1 + 0xaa8) = 0;
  return;
}

void func_001be890(u32 param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  func_001bc778(param_2); asm volatile("" ::: "memory");
  iVar1 = 3;
  iVar2 = 0;
  do {
    iVar1 = func_001bd570(param_1,iVar1); asm volatile("" ::: "memory");
    iVar3 = iVar2 + 1;
    func_001bc780(param_2,*(u16 *)(iVar1 + 2),iVar1 + 0xc,*(u8 *)(iVar1 + 4)); asm volatile("" ::: "memory");
    iVar1 = iVar2 + 4;
    iVar2 = iVar3;
  } while (iVar3 < 4);
  return;
}

void func_001bf0c8(int param_1)

{
  func_001bc778(param_1 + 0x594); asm volatile("" ::: "memory");
  func_001bc990(param_1 + 0x594,0x351248); asm volatile("" ::: "memory");
  return;
}

bool func_001c0ce8(int param_1)

{
  bool bVar1;
  s32 lVar2;
  
  lVar2 = func_001c0cd8(); asm volatile("" ::: "memory");
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = (*(u32 *)(*(int *)(param_1 + 0x570) + 0x588) & 0x80) != 0;
  }
  return bVar1;
}

void func_001c1268(u32 *param_1,u32 param_2,s32 param_3,u32 param_4,
                 u32 param_5)

{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = param_2;
  param_1[2] = 0x10;
  param_1[1] = (int)param_3;
  param_1[4] = 0;
  param_1[3] = 0;
  uVar1 = func_001050c8(); asm volatile("" ::: "memory");
  func_001db710(param_1 + 5,uVar1,param_4,param_5); asm volatile("" ::: "memory");
  param_1[0xd] = 0;
  if ((param_3 == 0) || (param_3 == 1)) {
    uVar2 = func_001050d8((int)param_5 << 4); asm volatile("" ::: "memory");
    param_1[0xc] = uVar2;
  }
  return;
}

void func_001c1308(u32 *param_1,u32 param_2,s32 param_3,u32 param_4,
                 u32 param_5)

{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = param_2;
  param_1[2] = 0x10;
  param_1[1] = (int)param_3;
  param_1[4] = 0;
  param_1[3] = 0;
  uVar1 = func_001050c8(); asm volatile("" ::: "memory");
  func_001db710(param_1 + 5,uVar1,param_4,param_5); asm volatile("" ::: "memory");
  param_1[0xd] = 0;
  if ((param_3 == 0) || (param_3 == 1)) {
    uVar2 = func_001050d8((int)param_5 << 4); asm volatile("" ::: "memory");
    param_1[0xc] = uVar2;
  }
  return;
}

void func_001c13a8(u32 *param_1)

{
  func_001dc920(*param_1); asm volatile("" ::: "memory");
  func_00105110(param_1[0xc]); asm volatile("" ::: "memory");
  func_001db7d0(param_1 + 5); asm volatile("" ::: "memory");
  return;
}

void func_001c13e8(u32 *param_1)

{
  func_001dc920(*param_1); asm volatile("" ::: "memory");
  func_00105110(param_1[0xc]); asm volatile("" ::: "memory");
  func_001db7d0(param_1 + 5); asm volatile("" ::: "memory");
  return;
}
