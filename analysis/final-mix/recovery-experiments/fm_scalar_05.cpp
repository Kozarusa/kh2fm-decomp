#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00143fc8(...);
extern "C" u64 func_0014f688(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016ed50(...);
extern "C" u64 func_00176cd0(...);
extern "C" u64 func_00178280(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00190920(...);
extern "C" u64 func_00198450(...);
extern "C" u64 func_00198970(...);
extern "C" u64 func_0019aa00(...);
extern "C" u64 func_0019cc20(...);
extern "C" u64 func_001a3188(...);
extern "C" u64 func_001a3570(...);
extern "C" u64 func_001a35f8(...);
extern "C" u64 func_001a6d08(...);
extern "C" u64 func_001ada38(...);
extern "C" u64 func_001b40e0(...);
extern "C" u64 func_001b8958(...);
extern "C" u64 func_001ba158(...);
extern "C" u64 func_001bb4a0(...);
extern "C" u64 func_001bb4b0(...);
extern "C" u64 func_001bbcb0(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_001d16f8(...);
extern "C" u64 func_001d1950(...);
extern "C" u64 func_001d2110(...);
extern "C" u64 func_001d2248(...);
extern "C" u64 func_001d2710(...);
extern "C" u64 func_001d3350(...);
extern "C" u64 func_001d3388(...);
extern "C" u64 func_001d4f40(...);
extern "C" u64 func_001d5f30(...);
extern "C" u64 func_001d6cc8(...);
extern "C" u64 func_001d7b10(...);
extern "C" u64 func_001d8718(...);
extern "C" u64 func_001da3d8(...);
extern "C" u64 func_001db200(...);
extern "C" u64 func_001db250(...);
extern "C" u64 func_001db950(...);
extern "C" u64 func_001dba18(...);
extern "C" u64 func_001dc700(...);
extern "C" u64 func_001dc738(...);
extern "C" u64 func_001dc840(...);
extern "C" u64 func_001dc978(...);
extern "C" u64 func_001dc9e0(...);
extern "C" u64 func_001dca20(...);
extern "C" u64 func_001dde40(...);
extern "C" u64 func_001ddef0(...);
extern "C" u64 func_001e0058(...);
extern "C" u64 func_001e0158(...);
extern "C" u64 func_001e01b8(...);
extern "C" u64 func_001e03b0(...);
extern "C" u64 func_001e0cc8(...);
extern "C" u64 func_001e0ce8(...);
extern "C" u64 func_001e1728(...);
extern "C" u64 func_001e17b8(...);
extern "C" u64 func_001e1988(...);
extern "C" u64 func_001e2c00(...);
extern "C" u64 func_001e2c78(...);
extern "C" u64 func_001e3468(...);
extern "C" u64 func_001e3650(...);
extern "C" u64 func_001e3660(...);
extern "C" u64 func_001e38f8(...);
extern "C" u64 func_001e3a88(...);
extern "C" u64 func_001e3c98(...);
extern "C" u64 func_001e3e48(...);
extern "C" u64 func_001e4028(...);
extern "C" u64 func_001e4248(...);
extern "C" u64 func_001e4320(...);
extern "C" u64 func_001e4e18(...);
extern "C" u64 func_001e6000(...);
extern "C" u64 func_001e6c00(...);
extern "C" u64 func_001e6cd8(...);
extern "C" u64 func_001e6ce8(...);
extern "C" u64 func_001e6cf8(...);
extern "C" u64 func_001e6d08(...);
extern "C" u64 func_001e7070(...);
extern "C" u64 func_001e7088(...);
extern "C" u64 func_001fa950(...);
extern "C" u64 func_001fab48(...);
extern "C" u64 func_001facf8(...);
extern "C" u64 func_00209178(...);
extern "C" u64 func_0020e2e8(...);
extern "C" u64 func_0021fa10(...);
extern "C" u64 func_0021fbc0(...);
extern "C" u64 func_0021fe28(...);
extern "C" u64 func_00220070(...);
extern "C" u64 func_002223e0(...);
extern "C" u64 func_002bea60(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002fd348(...);
extern "C" u64 func_002fe0a0(...);
extern "C" u64 func_00321728(...);
extern "C" u64 func_00321cb0(...);
extern "C" u64 func_00321ce8(...);

void func_001d0200(u64 param_1)

{
  func_00198970();
  func_00178280(param_1);
  return;
}

void func_001d07e0(int param_1)

{
  func_001d2710(param_1 + 0xb74);
  func_0019cc20(*(u32 *)(param_1 + 0xb40));
  *(u32 *)(param_1 + 0x10c) = *(u32 *)(param_1 + 0x10c) | 0x200000;
  return;
}

void func_001d14b8(int param_1)

{
  if (*(int *)(param_1 + 0xb50) != 6) {
    func_00176cd0();
    return;
  }
  return;
}

u32 func_001d1760(int param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (0 < iVar1) {
    if (*(int *)(param_1 + 0x14) <= iVar1) {
      if (iVar1 <= param_2) {
        return 1;
      }
      return uVar2;
    }
    if (param_2 <= iVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

void func_001d18c0(u64 param_1)

{
  int iVar1;
  
  func_001d16f8();
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 4) != 0) {
    func_0014f688(*(int *)(iVar1 + 4),*(u32 *)(iVar1 + 8),*(u32 *)(iVar1 + 0x20),
                 *(u32 *)(iVar1 + 0x24),*(u32 *)(iVar1 + 0x1c));
  }
  func_001d1950(param_1,*(u32 *)(iVar1 + 0x14));
  return;
}

void func_001d2130(u32 param_1,u64 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  func_001d2110(param_2,*(int *)(iVar1 + 0x2c) + param_3);
  func_001d2248(param_2,*(u32 *)(iVar1 + 0x2c));
  *(u32 *)(iVar1 + 0x3c) = param_1;
  return;
}

u64 func_001d3390(u64 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)func_001d3350(0x1d5ba10,0);
  func_001d3388(param_1);
  *puVar1 = (int)param_1;
  return param_1;
}

int func_001d3498(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  if ((param_2 != 0) && (iVar1 = 0, param_2 != param_1 + *(int *)(param_1 + 4) * 0x60 + -0x58)) {
    iVar1 = param_2 + 0x60;
  }
  return iVar1;
}

u32 func_001d3f38(int param_1)

{
  u16 uVar1;
  
  uVar1 = *(u16 *)(param_1 + 0x28);
  if (uVar1 != 0x158) {
    if (uVar1 < 0x159) {
      if (uVar1 != 0x11a) {
        return 1;
      }
    }
    else if (uVar1 != 0x1e4) {
      return 1;
    }
  }
  return 0;
}

bool func_001d4528(int param_1)

{
  s64 lVar1;
  
  lVar1 = func_001a35f8(*(u16 *)(param_1 + 0x2a),*(u8 *)(param_1 + 1));
  return 0 < lVar1;
}

void func_001d4ef0(u64 param_1,u8 *param_2)

{
  int iVar1;
  
  iVar1 = func_00321728((int)param_1 + 0x38,1,*param_2);
  *(char *)(iVar1 + 1) = *(char *)(iVar1 + 1) + '\x01';
  func_001d4f40(param_1,*(u16 *)(param_2 + 0x42));
  return;
}

void func_001d5370(u32 *param_1,u64 param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = func_00168b38(param_2,0xffffffffffffffff);
  iVar3 = func_00168b38(param_2,0xffffffffffffffff,param_3 + 1);
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
    uVar2 = func_001b8958(param_1[1]);
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        uVar2 = func_00181500(param_1[1]);
        return uVar2;
      }
    }
    else if (uVar1 == 3) {
      uVar2 = func_001a6d08(param_1[1]);
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}

void func_001d5ec0(u16 *param_1,int param_2,int param_3,int param_4)

{
  u16 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (u16 *)(param_3 * 10 + 0x36e596 + param_4 * 2);
  if (0 < param_2) {
    do {
      if ((*param_1 & 0x7fff) == puVar1[-1]) {
        *param_1 = *param_1 & 0x8000 | *puVar1 & 0x7fff;
        return;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar2 < param_2);
  }
  return;
}

void func_001d6148(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xb50) != 3) {
    return;
  }
  if (param_2 != 700) {
    if (param_2 < 0x2bd) {
      if (param_2 != 0x2ae) {
        return;
      }
    }
    else if ((param_2 != 0x2bf) && (param_2 != 0x2c2)) {
      return;
    }
  }
  func_001d5f30(param_1,1);
  return;
}

void func_001d6da8(u16 *param_1)

{
  s64 lVar1;
  s64 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_001d6cc8(lVar2), lVar2 != 0) {
    lVar1 = func_001a3570(((u16 *)lVar2)[1]);
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
      func_0016ed50(iVar1,0xffffffffffffffff,0x1e);
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
    lVar1 = func_001a3570(*(u16 *)((int)lVar2 + 2));
    iVar3 = iVar3 + (u32)(0 < lVar1);
  }
  if (iVar3 == 6) {
    iVar3 = 7;
  }
  return iVar3;
}

void func_001d71f0(s64 param_1)

{
  if (param_1 == 0xc) {
    func_002bea60();
    return;
  }
  return;
}

void func_001d7940(void)

{
  int iVar1;
  
  iVar1 = func_001ba158();
  *(u32 *)(iVar1 + 0x18) = 0;
  *(u32 *)(iVar1 + 4) = 0;
  *(u32 *)(iVar1 + 0xc) = 0;
  *(u32 *)(iVar1 + 0x14) = 0;
  func_001ada38(0xc);
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
  func_001d7b10();
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
  func_001d7b10();
  return;
}

void func_001d7e00(u64 param_1)

{
  func_00190920((int)param_1 + 0x9f4,2,param_1);
  func_00198450(param_1);
  return;
}

void func_001d7e78(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x818);
  if (iVar1 != 0) {
    func_0019aa00(iVar1,param_1);
  }
  func_001b40e0(param_1);
  return;
}

void func_001d86a0(u64 param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_001bb4b0();
  if ((lVar2 != 0) &&
     (iVar1 = func_001bbcb0(), (*(u32 *)(iVar1 + (int)param_2 * 0x38 + 0xf4) & 1) != 0)) {
    func_001d8718(param_1,param_2);
    return;
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

bool func_001d8898(int param_1)

{
  bool bVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0();
  bVar1 = false;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0();
    bVar1 = false;
    if ((*(u32 *)(iVar2 + param_1 * 0x38 + 0xf4) & 1) != 0) {
      iVar2 = func_001bbcb0();
      bVar1 = (*(u32 *)(iVar2 + param_1 * 0x38 + 0xf4) & 8) != 0;
    }
  }
  return bVar1;
}

bool func_001d8f38(int param_1)

{
  bool bVar1;
  int iVar2;
  s64 lVar3;
  
  lVar3 = func_001bb4a0();
  bVar1 = false;
  if (lVar3 != 0) {
    iVar2 = func_001bbcb0();
    bVar1 = false;
    if ((*(u32 *)(iVar2 + param_1 * 0x34 + 0x19c) & 1) != 0) {
      iVar2 = func_001bbcb0();
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
  
  lVar3 = func_001bb4a0();
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0();
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + param_1 * 0x40 + 0x26c) & 1) != 0) {
      iVar1 = func_001bbcb0();
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
  
  lVar3 = func_001bb4a0();
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = func_001bbcb0();
    uVar2 = 0;
    if ((*(u32 *)(iVar1 + param_1 * 0x40 + 0x26c) & 1) != 0) {
      iVar1 = func_001bbcb0();
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
        func_001a3188(*param_1,100,0);
        *param_1 = 0;
      }
      param_2 = param_2 + -1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

u8 func_001d9688(int param_1,int param_2,int param_3)

{
  u8 bVar1;
  u8 *pbVar2;
  
  pbVar2 = (u8 *)(param_2 * 3 + param_1 + param_3);
  bVar1 = *pbVar2;
  if (bVar1 < 99) {
    *pbVar2 = bVar1 + 1;
    bVar1 = bVar1 + 1;
  }
  return bVar1;
}

u32 func_001d9c68(char *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = param_1;
  do {
    iVar1 = iVar1 + 1;
    if (*pcVar2 != '\x01') {
      return 0;
    }
    pcVar2 = param_1 + iVar1;
  } while (iVar1 < 5);
  return 1;
}

void func_001da3f8(int param_1,u32 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + -4;
  *param_2 = *(u32 *)(iVar1 + -4);
  return;
}

int func_001da420(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*param_1 + 0x20);
  piVar2 = (int *)(*param_1 + 0x1c);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*piVar2 == param_2) break;
    iVar1 = piVar2[3];
    piVar2 = piVar2 + 2;
  }
  return iVar1;
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
      func_001da3d8(param_1,param_3);
      param_4 = param_4 + -1;
      param_3 = param_3 + 4;
    } while (param_4 != 0);
  }
  return;
}

int func_001da4d8(int *param_1,u32 param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar2 = (param_2 & 0xffff) >> 6;
  uVar3 = (u32)*(u16 *)(param_1[1] * 2 + *param_1 + 0x10);
  param_1[1] = param_1[1] + 1;
  if (uVar2 == 1) {
    iVar1 = param_1[4];
  }
  else if (uVar2 < 2) {
    if (uVar2 == 0) {
      iVar1 = param_1[2];
    }
    else {
      iVar1 = 0;
    }
  }
  else if (uVar2 == 2) {
    iVar1 = *(int *)param_1[2];
  }
  else if (uVar2 == 3) {
    iVar1 = *param_1 + 0x10;
    uVar3 = uVar3 << 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1 + uVar3;
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
        lVar2 = func_001db200();
        if (lVar2 != 0) {
          lVar2 = func_001db250(param_1);
          bVar1 = lVar2 != 0;
        }
      }
    }
  }
  return bVar1;
}

void func_001db850(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar1 = 0;
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x10);
    while( true ) {
      *(int *)(iVar1 * 4 + iVar2) = iVar1;
      iVar2 = *(int *)(param_1 + 0x18);
      iVar1 = iVar1 + 1;
      if (iVar2 <= iVar1) break;
      iVar2 = *(int *)(param_1 + 0x10);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  return;
}

int func_001db888(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8) + -1;
  *(int *)(param_1 + 8) = iVar1;
  return *(int *)(param_1 + 0xc) +
         *(int *)(param_1 + 0x14) * *(int *)(iVar1 * 4 + *(int *)(param_1 + 0x10));
}

s64 func_001db9a8(u64 param_1,u64 param_2,u64 param_3)

{
  s64 lVar1;
  
  lVar1 = func_001dba18();
  if (lVar1 == 0) {
    lVar1 = func_001050d8(0xa00);
    func_001db950(lVar1,param_1,param_2,param_3);
  }
  return lVar1;
}

void func_001dbc58(int param_1,u64 param_2,u32 *param_3,u8 *param_4)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  func_001c1748();
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

u8 func_001dc018(int *param_1,int param_2,u32 *param_3,u32 *param_4)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  
  iVar2 = 0;
  iVar1 = *(int *)(*param_1 + 0xc);
  puVar3 = (u32 *)(*param_1 + 0x10);
  if (0 < iVar1) {
    do {
      if (puVar3[2] == param_2) {
        *param_3 = *puVar3;
        *param_4 = puVar3[1];
        return 1;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 8;
    } while (iVar2 < iVar1);
  }
  return 0;
}

void func_001dc620(int param_1)

{
  func_001dc9e0();
  func_001e6cd8(*(u32 *)(param_1 + 0x1c));
  return;
}

void func_001dc648(int param_1)

{
  func_001dc9e0();
  func_001e6ce8(*(u32 *)(param_1 + 0x1c));
  return;
}

void func_001dc670(int param_1)

{
  func_001dc9e0();
  func_001e6cf8(*(u32 *)(param_1 + 0x1c));
  return;
}

u32 func_001dc790(int param_1)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_001dc738();
  if ((lVar2 != 0) || (uVar1 = 0, (*(u32 *)(param_1 + 8) & 0x200000) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

bool func_001dc7e8(int param_1)

{
  s64 lVar1;
  
  func_001dc9e0();
  lVar1 = func_001e2c78(*(u32 *)(param_1 + 0x1c));
  return lVar1 != 0;
}

void func_001dc878(int param_1)

{
  *(u32 *)(param_1 + 8) = *(u32 *)(param_1 + 8) | 0x10000;
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_001e2c00(*(int *)(param_1 + 0x1c));
    func_001e6c00(*(u32 *)(param_1 + 0x1c));
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  return;
}

void func_001dc920(int param_1)

{
  *(u32 *)(param_1 + 8) = *(u32 *)(param_1 + 8) | 0x10001;
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_001e2c00(*(int *)(param_1 + 0x1c));
    func_001e6c00(*(u32 *)(param_1 + 0x1c));
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  return;
}

bool func_001dc9f0(int param_1)

{
  s64 lVar1;
  
  func_001dc9e0();
  lVar1 = func_001e6d08(*(u32 *)(param_1 + 0x1c));
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
  func_001e7070(uVar1,uVar2);
  uVar1 = 0;
  if ((*(u32 *)(param_1 + 8) & 0x80000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(u32 *)(param_1 + 0x34);
    uVar1 = *(u32 *)(param_1 + 0x30);
  }
  func_001e7088(uVar1,uVar2);
  return;
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

void func_001ddd88(u64 param_1)

{
  s64 lVar1;
  
  lVar1 = func_00321cb0(0x1d9e348,param_1);
  if (lVar1 != 0) {
    func_001dde40(param_1);
    return;
  }
  return;
}

u64 func_001de168(int *param_1,u64 param_2)

{
  u64 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(*param_1 + 8)) {
    iVar2 = param_1[1];
    do {
      iVar3 = iVar3 + 1;
      if (*(u16 *)(iVar2 + 2) == param_2) {
        uVar1 = func_001ddef0();
        return uVar1;
      }
      iVar2 = iVar2 + 0x50;
    } while (iVar3 < *(int *)(*param_1 + 8));
  }
  return 0;
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

void func_001e01e8(int param_1,int param_2,u32 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar1 != 0) {
    if (((*(u32 *)(*(int *)(iVar1 + 0x44) + 0x10) & 0x200) == 0) &&
       (*(int *)(iVar1 + 0x48) == param_2)) {
      *(u32 *)(iVar1 + 0x48) = param_3;
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x60);
    }
  }
  return;
}

void func_001e0750(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_001e03b0(0x352b60);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    return;
  }
  return;
}

void func_001e0958(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      *(char *)(param_1 + 0x18) = (char)iVar1;
      *(char *)(param_1 + 0x19) = (char)iVar2;
      param_1 = param_1 + 0x40;
    } while (iVar2 < 3);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}

void func_001e0de8(s64 param_1)

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

void func_001e2238(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xdcc)) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      func_001e1728(*(int *)(param_1 + 0xdc8) + iVar1);
      iVar1 = iVar1 + 0x30;
    } while (iVar2 < *(int *)(param_1 + 0xdcc));
  }
  return;
}

void func_001e2660(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar4 = iVar4 + 1;
    if (*(char *)(param_1 + 0xac) == '\0') {
      if ((u32 *)(param_1 + 0xa0) != param_2) {
        uVar1 = param_2[1];
        uVar2 = param_2[2];
        uVar3 = param_2[3];
        *(u32 *)(param_1 + 0xa0) = *param_2;
        *(u32 *)(param_1 + 0xa4) = uVar1;
        *(u32 *)(param_1 + 0xa8) = uVar2;
        *(u32 *)(param_1 + 0xac) = uVar3;
      }
      *(u8 *)(param_1 + 0xad) = 0;
      *(u8 *)(param_1 + 0xaf) = 0x1e;
      *(u8 *)(param_1 + 0xac) = 0x80;
      *(u8 *)(param_1 + 0xae) = 0;
      return;
    }
    param_1 = param_1 + 0x10;
  } while (iVar4 < 10);
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

void func_001e3898(u64 param_1,int param_2)

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

void func_001e4f00(void)

{
  u64 uVar1;
  
  uVar1 = func_001e3650();
  uVar1 = func_001e3660(uVar1,1);
  uVar1 = func_001e4248(uVar1);
  uVar1 = func_001e4e18(uVar1);
  func_001e4320(uVar1);
  return;
}

void func_001e6038(int param_1)

{
  func_001e6000(param_1 + 0xb0);
  func_001e6000(param_1 + 0xc0);
  func_001e6000(param_1 + 0xd0);
  func_001e6000(param_1 + 0xe0);
  func_001e6000(param_1 + 0xf0);
  func_001e6000(param_1 + 0x100);
  func_001e6000(param_1 + 0x110);
  func_001e6000(param_1 + 0x120);
  func_001e6000(param_1 + 0x130);
  func_001e6000(param_1 + 0x140);
  return;
}

void func_001e7230(u32 *param_1,u32 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2 >> 2;
  while (iVar1 = iVar1 + -1, iVar1 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  param_2 = param_2 & 3;
  while (param_2 = param_2 - 1, param_2 != 0xffffffff) {
    *(u8 *)param_1 = 0;
    param_1 = (u32 *)((int)param_1 + 1);
  }
  return;
}

void func_001e7798(u32 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)(param_2 + -0x10);
  *(u32 *)(param_2 + -8) = 0;
  *param_1 = piVar2;
  param_1[3] = param_1[3] - (*(int *)(param_2 + -0x10) - (int)piVar2);
  piVar3 = *(int **)(param_2 + -0xc);
  if (piVar3 == (int *)0x0) {
    piVar1 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  else if (piVar3[2] == 0) {
    *piVar3 = *(int *)(param_2 + -0x10);
    *(int **)(*(int *)(param_2 + -0x10) + 4) = piVar3;
    piVar1 = (int *)*piVar3;
  }
  else {
    piVar1 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  if (piVar1[2] == 0) {
    *piVar3 = *piVar1;
    *(int **)(*piVar1 + 4) = piVar3;
  }
  return;
}

void func_001efb18(int param_1,int param_2)

{
  param_1 = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  *(u32 *)(param_1 + 0xa0) = 0;
  *(u32 *)(param_1 + 0xa4) = 0;
  *(u32 *)(param_1 + 0xa8) = 0;
  return;
}

void func_001efd38(int param_1,int param_2)

{
  param_1 = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  *(u32 *)(param_1 + 0xa0) = 0;
  *(u32 *)(param_1 + 0xa4) = 0;
  *(u32 *)(param_1 + 0xa8) = 0;
  return;
}

void func_001f0430(int param_1,int *param_2)

{
  int iVar1;
  
  param_2[1] = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x14);
  *param_2 = param_1;
  param_2[4] = iVar1;
  param_2[2] = 0;
  param_2[6] = 0;
  param_2[5] = 0;
  param_2[3] = 0;
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

void func_001fa928(int param_1,int param_2)

{
  func_0021fbc0(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
  return;
}

void func_001fab08(int param_1,int param_2)

{
  param_1 = param_1 + **(int **)(param_2 + 0xc);
  func_0021fa10(param_1 + 0xa0);
  *(u8 *)(param_1 + 0xa8) = 4;
  return;
}

void func_001facd0(int param_1,int param_2)

{
  func_0021fe28(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
  return;
}

void func_001fae80(int param_1,int param_2)

{
  func_00220070(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
  return;
}

void func_001fb698(int param_1,int param_2)

{
  func_0021fbc0(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
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

void func_001fba88(int param_1,int param_2)

{
  func_0021fe28(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
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

void func_001fbc78(int param_1,int param_2)

{
  func_00220070(param_1 + **(int **)(param_2 + 0xc) + 0xa0);
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

u32 func_00203ae8(int param_1,int param_2)

{
  char cVar1;
  u32 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    cVar1 = *(char *)(param_2 + 0xcc);
    if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\x02')) {
      if (*(int *)(param_1 + 0x54) == 0) {
        return 0;
      }
      cVar1 = *(char *)(param_2 + 0xc9);
    }
    else {
      cVar1 = *(char *)(param_2 + 0xc9);
    }
    uVar2 = 1;
    if ((cVar1 != '\0') && (uVar2 = 0, *(int *)(param_1 + 0x58) != 0)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

u32 func_00207308(int param_1,int param_2)

{
  char cVar1;
  u32 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(char *)(param_2 + 0x106) == '\0') {
      cVar1 = *(char *)(param_2 + 0x101);
    }
    else {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 0;
      }
      cVar1 = *(char *)(param_2 + 0x101);
    }
    uVar2 = 1;
    if ((cVar1 != '\0') && (uVar2 = 0, *(int *)(param_1 + 0x18) != 0)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

void func_002092e0(int param_1,u64 param_2,int param_3)

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

void func_0020e548(int param_1,u64 param_2,u64 param_3)

{
  if (*(int *)(param_1 + 4) == 0) {
    func_002fe0a0(0x370748,param_2,param_3,param_2);
    func_002fd348(1);
  }
  func_0020e2e8();
  return;
}
