#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001050d8(...);
extern "C" s64 func_0010cce0(...);
extern "C" u32 func_00127c70(...);
extern "C" u32 func_001325c8(...);
extern "C" u32 func_00132720(...);
extern "C" u64 func_00132c68(...);
extern "C" u32 func_00135e50(...);
extern "C" u32 func_00136020(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_0013fd10(...);
extern "C" u32 func_0013fd78(...);
extern "C" u32 func_00152508(...);
extern "C" u32 func_00152598(...);
extern "C" u32 func_00154408(...);
extern "C" u32 func_00154ee8(...);
extern "C" u32 func_001581f8(...);
extern "C" u32 func_00167e28(...);
extern "C" u32 func_00168b38(...);
extern "C" s64 func_0016b7a0(...);
extern "C" s64 func_0016b800(...);
extern "C" u32 func_0016bc20(...);
extern "C" u64 func_0016bda8(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0016cc18(...);
extern "C" u16 func_0016f610(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" bool func_0017e3b8(...);
extern "C" int func_0017ec98(...);
extern "C" s64 func_0017edf0(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_001802d8(...);
extern "C" u32 func_00180408(...);
extern "C" u32 func_00181178(...);
extern "C" bool func_00181500(...);
extern "C" u32 func_00185890(...);
extern "C" u32 func_00185da8(...);
extern "C" u32 func_00186078(...);
extern "C" bool func_00186ce8(...);
extern "C" u32 func_00188948(...);
extern "C" int func_00188fe0(...);
extern "C" u32 func_0018a818(...);
extern "C" u32 func_0018d940(...);
extern "C" u64 func_0018da18(...);
extern "C" u32 func_00190128(...);
extern "C" s64 func_00190208(...);
extern "C" s64 func_00190730(...);
extern "C" int func_00195468(...);
extern "C" u32 func_00195530(...);
extern "C" u32 func_00195558(...);
extern "C" bool func_0019ba60(...);
extern "C" u32 func_0019c090(...);
extern "C" u64 func_0019c410(...);
extern "C" u32 func_001a1a20(...);
extern "C" u16 func_001a67b0(...);
extern "C" u32 func_001ab800(...);
extern "C" u32 func_001ab810(...);
extern "C" u32 func_001abb28(...);
extern "C" u32 func_001b7df0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u16 func_001bc010(...);
extern "C" u32 func_001bc730(...);
extern "C" u32 func_001bd2d0(...);
extern "C" u32 func_001bd5b0(...);
extern "C" u32 func_001bd618(...);
extern "C" u32 func_001bdc18(...);
extern "C" u64 func_001c0320(...);
extern "C" bool func_001c0cd8(...);
extern "C" u32 func_001c16f0(...);
extern "C" u32 func_001c6ee8(...);
extern "C" u32 func_001cdbc8(...);
extern "C" u32 func_001d17b0(...);
extern "C" u32 func_001db8b8(...);
extern "C" u32 func_001dc5f0(...);
extern "C" u32 func_00239700(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_003208a8(...);

bool func_00112d28(s64 param_1)

{
  s64 lVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = false;
  if (param_1 != 0) {
    lVar1 = func_0019ba60();
    bVar2 = false;
    if (((lVar1 != 0) && (iVar3 = (int)param_1, (*(u32 *)(iVar3 + 0x588) & 0x10) != 0)) &&
       ((*(u32 *)(iVar3 + 0x7f8) & 4) == 0)) {
      bVar2 = (*(u32 *)(iVar3 + 0x108) & 0x8000) == 0;
    }
  }
  return bVar2;
}

int func_001182d0(void)

{
  s64 lVar1;
  s64 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 0;
  while (lVar2 = func_0010cce0(lVar2), lVar2 != 0) {
    lVar1 = func_0019c410(lVar2);
    if (lVar1 == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}

void func_00132e28(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_00132c68();
  iVar2 = (int)lVar3;
  if (lVar3 != 0) {
    lVar3 = func_001325c8(param_1,0xffff,param_2);
    if (-1 < lVar3) {
      iVar1 = *(int *)((int)lVar3 * 4 + iVar2 + *(int *)(iVar2 + 0x1c));
      *(u32 *)((int)param_1 + 0x14) = *(u32 *)((int)param_1 + 0x14) | 4;
      func_00132720(param_1,iVar2 + iVar1);
      return;
    }
  }
  return;
}

void func_00135dc8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x110);
  func_00135e50(uVar1);
  *(int **)((int)uVar1 + 4) = param_1;
  *param_1 = (int)uVar1;
  return;
}

void func_00136200(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = param_1;
  if (0 < iVar1) {
    do {
      if (*(int *)(iVar2 + 0x10) == param_2) {
        iVar1 = func_001dc5f0(param_2);
        if (*(int *)(iVar2 + 0x14) == iVar1) {
          *(u32 *)(iVar2 + 0x14) = 0;
          *(u32 *)(iVar2 + 0x10) = 0;
          break;
        }
        iVar1 = *(int *)(param_1 + 0xc);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (iVar3 < iVar1);
  }
  func_00136020(param_1);
  return;
}

void func_001387f8(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  func_00239988((int)param_1 + 0x18);
  func_00138c10(param_1,param_4);
  *(u32 *)((int)param_1 + 0x188) = 0xffffffff;
  return;
}

void func_0013fec0(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  
  uVar2 = func_0013fd10();
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x50) = uVar2;
  func_0013fd78(param_1);
  if ((u32 *)(iVar1 + 0x10) != (u32 *)(iVar1 + 0x60)) {
    *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar1 + 0x60);
    *(u32 *)(iVar1 + 0x14) = *(u32 *)(iVar1 + 100);
    *(u32 *)(iVar1 + 0x18) = *(u32 *)(iVar1 + 0x68);
    *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x6c);
  }
  return;
}

void func_00146d68(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  *(u32 *)(param_1 + 0x5360) = 0;
  iVar1 = *(int *)(param_1 + 0x10);
  if (0 < iVar1) {
    piVar2 = (int *)(*(int *)(param_1 + 4) + 0x2c);
    do {
      iVar3 = *piVar2;
      if (iVar3 == 0) {
        *piVar2 = 0;
      }
      else {
        do {
          if ((u32 *)(iVar3 + 0x80) == (u32 *)(iVar3 + 0x40)) {
            iVar3 = *(int *)(iVar3 + 0x110);
          }
          else {
            *(u32 *)(iVar3 + 0x80) = *(u32 *)(iVar3 + 0x40);
            *(u32 *)(iVar3 + 0x84) = *(u32 *)(iVar3 + 0x44);
            *(u32 *)(iVar3 + 0x88) = *(u32 *)(iVar3 + 0x48);
            *(u32 *)(iVar3 + 0x8c) = *(u32 *)(iVar3 + 0x4c);
            *(u32 *)(iVar3 + 0x90) = *(u32 *)(iVar3 + 0x50);
            *(u32 *)(iVar3 + 0x94) = *(u32 *)(iVar3 + 0x54);
            *(u32 *)(iVar3 + 0x98) = *(u32 *)(iVar3 + 0x58);
            *(u32 *)(iVar3 + 0x9c) = *(u32 *)(iVar3 + 0x5c);
            *(u32 *)(iVar3 + 0xa0) = *(u32 *)(iVar3 + 0x60);
            *(u32 *)(iVar3 + 0xa4) = *(u32 *)(iVar3 + 100);
            *(u32 *)(iVar3 + 0xa8) = *(u32 *)(iVar3 + 0x68);
            *(u32 *)(iVar3 + 0xac) = *(u32 *)(iVar3 + 0x6c);
            *(u32 *)(iVar3 + 0xb0) = *(u32 *)(iVar3 + 0x70);
            *(u32 *)(iVar3 + 0xb4) = *(u32 *)(iVar3 + 0x74);
            *(u32 *)(iVar3 + 0xb8) = *(u32 *)(iVar3 + 0x78);
            *(u32 *)(iVar3 + 0xbc) = *(u32 *)(iVar3 + 0x7c);
            iVar3 = *(int *)(iVar3 + 0x110);
          }
        } while (iVar3 != 0);
        *piVar2 = 0;
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + 0xc;
    } while (iVar1 != 0);
  }
  return;
}

void func_00152990(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u32 param_6,u64 param_7,u64 param_8)

{
  u64 uVar1;
  int iVar2;
  
  uVar1 = func_00152598(param_1,param_7,param_5,0x34a6b8);
  iVar2 = (int)param_1;
  *(int *)(iVar2 + 0x1c0) = (int)param_7;
  *(u32 *)(iVar2 + 0x1bc) = param_6;
  *(int *)(iVar2 + 0x1b8) = (int)param_5;
  *(int *)(iVar2 + 0x1b4) = (int)param_3;
  func_00152508(param_1,uVar1,param_3,param_4,param_8);
  return;
}

void func_00155410(int param_1)

{
  u32 uVar1;
  u64 uVar2;
  
  uVar1 = **(u32 **)(*(int *)(param_1 + 0x34) + 0x48c);
  *(u32 *)(param_1 + 0x24) = uVar1;
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar2 = func_00154ee8();
  func_00138c10(param_1 + 0x394,uVar2);
  func_00154408(param_1 + 0x40,*(u32 *)(param_1 + 0x18));
  return;
}

void func_00155528(u64 param_1)

{
  u64 uVar1;
  
  func_001581f8();
  uVar1 = func_00154ee8(param_1);
  func_00138c10((int)param_1 + 0x394,uVar1);
  return;
}

void func_00167ee0(void)

{
  func_00167e28(0x34d6c0);
  func_00167e28(0x34d720);
  return;
}

int func_0016c028(int param_1)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_001c0cd8();
  iVar2 = param_1 + 0x70;
  if (lVar1 == 0) {
    iVar2 = param_1 + 0x540;
  }
  return iVar2;
}

u64 func_0016c2b0(u64 param_1,u64 param_2)

{
  s64 lVar1;
  u32 *puVar2;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  lVar1 = func_0016bc20(param_2,0x11,0xffffffffffffffff);
  if (lVar1 == 0) {
    func_0016bda8(param_1,param_2,0);
  }
  else {
    func_0018a818(auStack_40);
    puVar2 = (u32 *)param_1;
    *puVar2 = uStack_30;
    puVar2[1] = uStack_2c;
    puVar2[2] = uStack_28;
    puVar2[3] = uStack_24;
  }
  return param_1;
}

void func_0016f6a0(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_0016f610();
  if (lVar1 != 0) {
    func_00185890(*(u16 *)(param_1 + 0x4e),lVar1);
    return;
  }
  return;
}

void func_00172bd8(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  uVar2 = func_0016b7a0(param_1[1]);
  *(u32 *)(iVar1 + 4) = uVar2;
  return;
}

void func_00172c08(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  uVar2 = func_0016b800(param_1[1]);
  *(u32 *)(iVar1 + 4) = uVar2;
  return;
}

void func_0017c0a0(u64 param_1,u64 param_2,u8 param_3)

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
  
  func_0017c030(&uStack_40,param_2,auStack_20,param_3);
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  func_0017c4c8(param_2);
  iVar1 = (int)param_2;
  func_0017f488(0,0,iVar1 + 0x140,auStack_20[0]);
  *(u32 *)(iVar1 + 0x104) = 5;
  *(u32 *)(iVar1 + 0x100) = 4;
  return;
}

void func_0017ee68(int param_1)

{
  u32 uVar1;
  u64 uVar2;
  
  uVar1 = *(u32 *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
  return;
}

u32 func_0017f4e0(u64 param_1)

{
  int iVar1;
  u64 uVar2;
  s64 lVar3;
  
  uVar2 = func_0017ec98();
  lVar3 = func_0017edf0(param_1,uVar2);
  if ((lVar3 != 0) &&
     (iVar1 = func_00168b38(lVar3,9,0), *(int *)((int)param_1 + 0xc) != *(int *)(iVar1 + 8))) {
    return 1;
  }
  return 0;
}

bool func_001805a8(u64 param_1)

{
  u64 uVar1;
  s64 lVar2;
  
  uVar1 = func_0017ec98();
  uVar1 = func_0017edf0(param_1,uVar1);
  lVar2 = func_00180408(param_1,uVar1);
  return lVar2 != 0;
}

void func_00180c88(u32 param_1,int param_2,u64 param_3)

{
  if (*(int *)(param_2 + 0x100) == 0) {
    func_0017f488(param_1,0);
    return;
  }
  func_001802d8(*(u32 *)(param_2 + 0xfc),*(int *)(param_2 + 0x100),
               *(u32 *)(param_2 + 0xf0),*(u32 *)(param_2 + 8),param_3,0);
  return;
}

u32 func_00181570(u64 param_1,u64 param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_00181500();
  if ((lVar2 == 0) && (lVar2 = func_00181500(param_2), lVar2 != 0)) {
    func_00181178(param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

u32 func_001819c0(void)

{
  s64 lVar1;
  
  lVar1 = func_00181500(0x817);
  if (((lVar1 != 0) && (lVar1 = func_00181500(0x142b), lVar1 == 0)) &&
     (lVar1 = func_00181500(0x2001), lVar1 == 0)) {
    return 0;
  }
  return 1;
}

u32 func_00181a18(void)

{
  s64 lVar1;
  
  lVar1 = func_00181500(0x817);
  if (((lVar1 != 0) && (lVar1 = func_00181500(0x142b), lVar1 == 0)) &&
     (lVar1 = func_00181500(0x2018), lVar1 == 0)) {
    return 0;
  }
  return 1;
}

void func_00185e20(u64 param_1)

{
  s64 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_00185da8(lVar1), lVar1 != 0) {
    func_0016c568(0,lVar1,param_1);
  }
  return;
}

void func_00185e78(u64 param_1)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_00185da8(lVar2), lVar2 != 0) {
    iVar1 = *(int *)((int)lVar2 + 0x828);
    if (iVar1 != 0) {
      func_001b7df0(iVar1,param_1);
    }
  }
  return;
}

u32 func_00188398(int param_1,s64 param_2)

{
  u32 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0x88) + 4) + 0x484) != 0) && (param_2 != 0)) {
    func_0016cc18();
    uVar1 = 1;
  }
  return uVar1;
}

void func_00189028(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u64 uVar1;
  
  uVar1 = func_00188fe0();
  func_00188948(uVar1,param_3,param_4);
  return;
}

u64 func_0018db38(u64 param_1,u64 param_2,u8 param_3,u64 param_4)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  char acStack_40 [16];
  
  lVar2 = func_0018d940();
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar3 = func_001c0320((int)param_2 + 0xa50,param_1,acStack_40);
    uVar3 = func_0018da18(param_1,param_2,uVar3,param_4);
    iVar1 = (int)uVar3;
    *(u8 *)(iVar1 + 0x24) = param_3;
    if (acStack_40[0] == '\0') {
      *(u32 *)(iVar1 + 0x18) = *(u32 *)(iVar1 + 0x18) | 3;
    }
  }
  return uVar3;
}

void func_0018f3a8(int *param_1)

{
  s64 lVar1;
  s64 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 0;
  while (lVar2 = func_00185da8(lVar2), lVar2 != 0) {
    lVar1 = func_00186ce8(lVar2);
    if (lVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  *param_1 = iVar3;
  return;
}

u32 func_00190140(int param_1)

{
  s64 lVar1;
  
  if ((*(int *)(param_1 + 8) == 0) && (lVar1 = func_00190208(param_1,0), lVar1 == 0)) {
    return 0;
  }
  return 1;
}

void func_001954a0(u64 param_1,u16 param_2)

{
  s64 lVar1;
  
  lVar1 = func_00195530();
  if (lVar1 == 0) {
    lVar1 = func_00195468(param_1,0);
    if (-1 < lVar1) {
      *(u16 *)((int)lVar1 * 2 + (int)param_1 + 8) = param_2;
    }
  }
  return;
}

void func_00195750(void)

{
  func_00195558(0x34f250);
  func_00195558(0x34fa78);
  return;
}

u32 func_0019ad00(int param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  if (*(short *)(iVar1 + 4) != 0) {
    iVar3 = 0;
    do {
      iVar2 = iVar2 + 1;
      if ((*(char *)(iVar3 + iVar1 + 0x48) == '\x02') &&
         (*(u8 *)(iVar3 + iVar1 + 0x5c) == param_2)) {
        return 1;
      }
      iVar3 = iVar2 * 0x40;
    } while (iVar2 < (int)(u32)*(u16 *)(iVar1 + 4));
  }
  return 0;
}

bool func_0019c0f8(int param_1)

{
  bool bVar1;
  s64 lVar2;
  
  lVar2 = func_0019c090();
  bVar1 = false;
  if ((lVar2 != 0) && ((*(u32 *)(param_1 + 0x160) & 0x20) == 0)) {
    bVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return bVar1;
}

void func_001a1db8(int param_1)

{
  *(u32 *)(param_1 + 0x1bc) = 0;
  *(u32 *)(param_1 + 0x1c0) = 0;
  func_001a1a20(param_1,*(u32 *)(param_1 + 0x184),0);
  return;
}

void func_001abd30(u32 *param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  *param_1 = 0;
  func_00239700(param_1 + 1);
  func_001abb28(param_1 + 0x57);
  uVar1 = func_001ab810();
  uVar2 = func_001ab800();
  func_00239988(param_1 + 1,uVar1,uVar2);
  return;
}

void func_001abd90(u32 *param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  *param_1 = 0;
  func_00239700(param_1 + 1);
  func_001abb28(param_1 + 0x57);
  uVar1 = func_001ab810();
  uVar2 = func_001ab800();
  func_00239988(param_1 + 1,uVar1,uVar2);
  return;
}

void func_001b6dd0(u64 param_1,u32 *param_2)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0017c4c8(param_1,&uStack_20);
  *(u8 *)((int)param_1 + 0x514) = 3;
  return;
}

void func_001bd668(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x8c0);
  while (iVar1 != 0) {
    func_001bd618(param_1,0);
    iVar1 = *(int *)((int)param_1 + 0x8c0);
  }
  return;
}

void func_001bdf38(u64 param_1)

{
  func_001bd2d0();
  func_001bd5b0(param_1,*(u32 *)((int)param_1 + 0xaa4),0);
  return;
}

void func_001bdff0(void)

{
  u16 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0x32f220;
  iVar4 = 3;
  do {
    iVar2 = func_001b8e88(*(u16 *)(iVar3 + 8));
    if (*(short *)(iVar2 + 2) == 2) {
      uVar1 = func_001a67b0(*(u16 *)(iVar2 + 4));
      *(u16 *)(iVar3 + 8) = uVar1;
    }
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + 2;
  } while (-1 < iVar4);
  return;
}

void func_001be4e0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(int *)(iVar1 + 0xaa4) = param_2;
  func_001bc730(iVar1 + param_2 * 0x74 + 0x24,*(u32 *)(**(int **)(iVar1 + 0x8c0) + 0x6c));
  func_001bd618(param_1,0);
  func_001bd5b0(param_1,*(u32 *)(iVar1 + 0xaa4),0);
  return;
}

void func_001befa8(u64 param_1)

{
  func_001bdc18();
  func_001bd5b0(param_1,*(u32 *)((int)param_1 + 0xaa4),0);
  return;
}

void func_001c1890(u64 param_1)

{
  func_003208a8(*(int *)((int)param_1 + 0x1c) + 0xc,param_1);
  func_001db8b8(*(int *)((int)param_1 + 0x1c) + 0x14,param_1);
  return;
}

u32 func_001c9ab8(void)

{
  s64 lVar1;
  u64 uVar2;
  int iVar3;
  
  lVar1 = func_001bc010();
  if (lVar1 == 0) {
    iVar3 = 0;
    do {
      uVar2 = func_0017df58(iVar3);
      iVar3 = iVar3 + 1;
      lVar1 = func_0019ba60(uVar2);
      if (lVar1 == 0) {
        return 0;
      }
      lVar1 = func_0017e3b8(uVar2);
      if (lVar1 == 0) {
        return 0;
      }
    } while (iVar3 < 2);
  }
  return 1;
}

void func_001ccda0(int param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  func_001c6ee8();
  lVar2 = 0;
  uVar1 = *(u32 *)(param_1 + 0x9f4);
  while (lVar2 = func_001c16f0(uVar1,lVar2), lVar2 != 0) {
    uVar1 = *(u32 *)(param_1 + 0x9f4);
  }
  lVar2 = 0;
  do {
    lVar2 = func_00186078(lVar2);
  } while (lVar2 != 0);
  return;
}

void func_001cddb8(u64 param_1)

{
  s64 lVar1;
  int aiStack_70 [8];
  u8 auStack_50 [12];
  u32 uStack_44;
  
  func_00190128(aiStack_70);
  uStack_44 = 0;
  lVar1 = 0;
  while (lVar1 = func_00190730(aiStack_70,lVar1), lVar1 != 0) {
    if ((*(u32 *)(aiStack_70[0] + 0x588) & 0x20000) != 0) {
      func_0018a818(auStack_50,aiStack_70[0],lVar1);
      func_001cdbc8(param_1,auStack_50,2);
    }
  }
  return;
}

void func_001d2248(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x38) < param_2) {
    *(int *)(param_1 + 0x38) = param_2;
    func_001d17b0();
    if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x38))) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x38);
    }
  }
  return;
}
