#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_00102c18(...);
extern "C" bool func_00105300(...);
extern "C" int func_00106520(...);
extern "C" u32 func_00106998(...);
extern "C" int func_00120800(...);
extern "C" u32 func_00132720(...);
extern "C" u64 func_00132c68(...);
extern "C" int func_00133848(...);
extern "C" int func_00133898(...);
extern "C" u64 func_001339d0(...);
extern "C" u32 func_001386e0(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00138c40(...);
extern "C" u32 func_00138c68(...);
extern "C" u32 func_00139570(...);
extern "C" u32 func_00139598(...);
extern "C" u32 func_001395a8(...);
extern "C" u32 func_001395e8(...);
extern "C" u32 func_001395f8(...);
extern "C" u32 func_00139610(...);
extern "C" u32 func_00139660(...);
extern "C" u32 func_00139688(...);
extern "C" u32 func_001396b0(...);
extern "C" bool func_001396c0(...);
extern "C" u32 func_001399c0(...);
extern "C" u32 func_00139c18(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0013a7e8(...);
extern "C" int func_0013d7e0(...);
extern "C" u32 func_0013dda0(...);
extern "C" u32 func_0013dfb8(...);
extern "C" u32 func_0013e0f8(...);
extern "C" u32 func_0014b200(...);
extern "C" u32 func_0014b208(...);
extern "C" u32 func_0014fc40(...);
extern "C" u32 func_00150260(...);
extern "C" u32 func_00153fa0(...);
extern "C" u32 func_001542c8(...);
extern "C" u32 func_00154b18(...);
extern "C" u32 func_00154ee8(...);
extern "C" u32 func_00155bf0(...);
extern "C" u32 func_00155cb0(...);
extern "C" u64 func_00155d80(...);
extern "C" u32 func_00155e30(...);
extern "C" u32 func_00155ee8(...);
extern "C" u32 func_00155f40(...);
extern "C" u32 func_00155fc0(...);
extern "C" bool func_00156010(...);
extern "C" bool func_00156030(...);
extern "C" bool func_00156058(...);
extern "C" bool func_00156080(...);
extern "C" u32 func_001560a8(...);
extern "C" u32 func_00156408(...);
extern "C" u32 func_00156d20(...);
extern "C" u32 func_001575c0(...);
extern "C" u32 func_00158050(...);
extern "C" u32 func_00158138(...);
extern "C" u32 func_001581f8(...);
extern "C" int func_00158290(...);
extern "C" u32 func_001582a8(...);
extern "C" int func_00197df8(...);
extern "C" u32 func_001aae28(...);
extern "C" u32 func_001b7e68(...);
extern "C" u32 func_001b7f30(...);
extern "C" u32 func_001b80d8(...);
extern "C" u32 func_0022a0f8(...);
extern "C" int func_0022b720(...);
extern "C" u32 func_0022b9e0(...);
extern "C" u32 func_002361a0(...);
extern "C" u32 func_002361d0(...);
extern "C" u32 func_00237458(...);
extern "C" u32 func_002374c8(...);
extern "C" int func_00237508(...);
extern "C" u32 func_00237540(...);
extern "C" int func_00237578(...);
extern "C" u32 func_002375b0(...);
extern "C" u32 func_00237640(...);
extern "C" u32 func_0023a9c0(...);
extern "C" u32 func_0023aa18(...);
extern "C" u32 func_0023aa38(...);
extern "C" u32 func_0023aa98(...);
extern "C" u32 func_0023f1e0(...);
extern "C" u32 func_0023f688(...);
extern "C" u32 func_0023f6c0(...);
extern "C" u32 func_0023f7d8(...);
extern "C" u64 func_0028dd90(...);
extern "C" u64 func_0028ddd8(...);
extern "C" u32 func_002ba2e8(...);
extern "C" int func_00303b70(...);
extern "C" u32 func_0031a260(...);

u32 func_00120a20(int param_1,int param_2,u32 *param_3,u32 param_4,int param_5)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u16 uVar7;
  u16 *puVar8;
  u16 *puVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  u32 *puVar15;
  u32 uStack_70;
  int iStack_6c;
  u32 *puStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  
  iVar1 = *(int *)(param_1 + 4);
  iStack_6c = param_2;
  puStack_68 = param_3;
  iStack_64 = param_5;
  iVar4 = func_00120800();
  iStack_60 = 0;
  iVar11 = *(int *)(iVar1 + 0x1c);
  uStack_70 = param_4;
  if (0 < iVar11) {
    iStack_5c = iStack_64 << 2;
    iVar14 = iVar1;
    puVar15 = puStack_68;
    do {
      iVar11 = 0;
      *puVar15 = uStack_70;
      puVar8 = (u16 *)(iVar1 + *(int *)(iVar14 + 0x30));
      piVar12 = (int *)(iVar1 + *(int *)(iVar14 + 0x34));
      func_001339d0(&uStack_70,iVar1 + *(int *)(puVar8 + 2),*puVar8,*(u32 *)(puVar8 + 4),
                   *(u32 *)(puVar8 + 6));
      if (0 < *piVar12) {
        iVar13 = iStack_5c + iStack_6c;
        piVar10 = piVar12;
        do {
          piVar10 = piVar10 + 1;
          puVar9 = puVar8 + 8;
          if (*piVar10 < 0) {
            func_00133848(&uStack_70,0,0x17000000,0);
            puVar9 = puVar8 + 0x10;
            uVar7 = *puVar9;
            uVar2 = *(u32 *)(puVar8 + 0x14);
            iVar5 = iVar1 + *(int *)(puVar8 + 0x12);
            uVar3 = *(u32 *)(puVar8 + 0x16);
          }
          else {
            uVar2 = *(u32 *)(puVar8 + 0xc);
            uVar7 = 4;
            uVar3 = *(u32 *)(puVar8 + 0xe);
            iVar5 = *(int *)(iVar13 + 0x2c) + *piVar10 * 0x40;
          }
          func_001339d0(&uStack_70,iVar5,uVar7,uVar2,uVar3);
          iVar11 = iVar11 + 1;
          puVar8 = puVar9;
        } while (iVar11 < *piVar12);
      }
      func_00133898(&uStack_70,0,0x17000000,0);
      iVar14 = iVar14 + 0x20;
      iStack_60 = iStack_60 + 1;
      iVar11 = *(int *)(iVar1 + 0x1c);
      puVar15 = puVar15 + 1;
    } while (iStack_60 < iVar11);
  }
  if ((iVar4 != 0) && (iStack_60 = 0, 0 < *(int *)(iVar4 + 0x1c))) {
    iVar13 = iStack_64 * 4;
    iVar14 = iVar4;
    while( true ) {
      iVar5 = 0;
      puStack_68[iVar11 + iStack_60] = uStack_70;
      puVar8 = (u16 *)(iVar4 + *(int *)(iVar14 + 0x30));
      piVar12 = (int *)(iVar4 + *(int *)(iVar14 + 0x34));
      func_001339d0(&uStack_70,iVar4 + *(int *)(puVar8 + 2),*puVar8,*(u32 *)(puVar8 + 4),
                   *(u32 *)(puVar8 + 6));
      if (0 < *piVar12) {
        iVar11 = iVar13 + iStack_6c;
        piVar10 = piVar12;
        do {
          piVar10 = piVar10 + 1;
          puVar9 = puVar8 + 8;
          if (*piVar10 < 0) {
            func_00133848(&uStack_70,0,0x17000000,0);
            puVar9 = puVar8 + 0x10;
            uVar7 = *puVar9;
            uVar2 = *(u32 *)(puVar8 + 0x14);
            iVar6 = iVar4 + *(int *)(puVar8 + 0x12);
            uVar3 = *(u32 *)(puVar8 + 0x16);
          }
          else {
            uVar2 = *(u32 *)(puVar8 + 0xc);
            uVar7 = 4;
            uVar3 = *(u32 *)(puVar8 + 0xe);
            iVar6 = *(int *)(iVar11 + 0x2c) + *piVar10 * 0x40;
          }
          func_001339d0(&uStack_70,iVar6,uVar7,uVar2,uVar3);
          iVar5 = iVar5 + 1;
          puVar8 = puVar9;
        } while (iVar5 < *piVar12);
      }
      func_00133898(&uStack_70,0,0x17000000,0);
      iStack_60 = iStack_60 + 1;
      iVar14 = iVar14 + 0x20;
      if (*(int *)(iVar4 + 0x1c) <= iStack_60) break;
      iVar11 = *(int *)(iVar1 + 0x1c);
    }
  }
  return uStack_70;
}

void func_00132850(float param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  u64 uVar4;
  u16 *puVar5;
  u16 uVar6;
  int iVar7;
  int iVar8;
  u32 uVar9;
  float fVar10;
  float fVar11;
  s64 lVar3;
  
  lVar3 = func_00132c68();
  iVar2 = (int)lVar3;
  if (lVar3 != 0) {
    iVar8 = (int)param_2;
    if ((*(u32 *)(iVar8 + 0x14) & 4) == 0) {
      func_00132720(param_2,*(u32 *)(iVar8 + 0x274));
    }
    else {
      *(u32 *)(iVar8 + 0x14) = *(u32 *)(iVar8 + 0x14) & 0xfffffffb;
    }
    iVar7 = *(int *)(iVar8 + 0x20);
    if (iVar7 == 0) {
      puVar5 = *(u16 **)(iVar8 + 0x27c);
      if (puVar5 != (u16 *)0x0) {
        uVar6 = *puVar5 & 0xf;
        if (uVar6 != 3) {
          if (uVar6 == 2) {
            *(u16 **)(iVar8 + 0x27c) =
                 (u16 *)
                 ((int)puVar5 + ((int)(short)*puVar5 >> 4) * ((u32)*(u16 *)(iVar2 + 4) * 2 + 8))
            ;
            uVar1 = *(u32 *)(iVar8 + 0x14);
          }
          else {
            uVar1 = *(u32 *)(iVar8 + 0x14);
          }
          if ((uVar1 & 1) == 0) {
            fVar11 = *(float *)(iVar8 + 0x280);
            fVar10 = *(float *)(iVar8 + 0x284) + param_1 * *(float *)(iVar8 + 0x18);
            *(float *)(iVar8 + 0x284) = fVar10;
            while (fVar11 <= fVar10) {
              *(float *)(iVar8 + 0x284) = fVar10 - fVar11;
              puVar5 = (u16 *)(*(int *)(iVar8 + 0x27c) + (u32)*(u16 *)(iVar2 + 4) * 2 + 8);
              *(u16 **)(iVar8 + 0x27c) = puVar5;
              uVar6 = *puVar5 & 0xf;
              if (uVar6 == 2) {
                if ((*(u32 *)(iVar8 + 0x14) & 2) != 0) {
                  *(u32 *)(iVar8 + 0x27c) = 0;
                  return;
                }
                *(u16 **)(iVar8 + 0x27c) =
                     (u16 *)
                     ((int)puVar5 +
                     ((int)(short)*puVar5 >> 4) * ((u32)*(u16 *)(iVar2 + 4) * 2 + 8));
                iVar7 = *(int *)(iVar8 + 0x27c);
              }
              else {
                if (uVar6 == 3) {
                  return;
                }
                iVar7 = *(int *)(iVar8 + 0x27c);
              }
              uVar4 = func_00106520(*(u16 *)(iVar7 + 2),*(u16 *)(iVar7 + 4) + 1);
              if ((s64)uVar4 < 0) {
                fVar11 = (float)(uVar4 & 0xffffffff);
              }
              else {
                fVar11 = (float)(int)uVar4;
              }
              fVar10 = *(float *)(iVar8 + 0x284);
              *(float *)(iVar8 + 0x280) = fVar11;
            }
          }
          else {
            *(u32 *)(iVar8 + 0x14) = uVar1 & 0xfffffffe;
          }
        }
      }
    }
    else {
      if (*(int *)(iVar7 + 0x27c) == 0) {
        *(u32 *)(iVar8 + 0x27c) = 0;
      }
      else {
        *(int *)(iVar8 + 0x27c) =
             *(int *)(iVar8 + 0x278) + (*(int *)(iVar7 + 0x27c) - *(int *)(iVar7 + 0x278));
      }
      *(u32 *)(iVar8 + 0x14) = *(u32 *)(iVar7 + 0x14);
      uVar9 = *(u32 *)(iVar7 + 0x284);
      *(u32 *)(iVar8 + 0x280) = *(u32 *)(iVar7 + 0x280);
      *(u32 *)(iVar8 + 0x284) = uVar9;
    }
  }
  return;
}

void func_0014bb30(int param_1)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  u64 *puVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uStack_50;
  u32 uStack_4c;
  u32 *puStack_48;
  u32 uStack_40;
  u32 uStack_3c;
  u32 *puStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 *puStack_28;
  
  uVar2 = (u64)*(u32 *)(param_1 + 0xc) << 0x20;
  *(u64 *)(param_1 + 0xd8) =
       (s64)(*(short *)(param_1 + 8) * 0x10 + 0x7000) |
       (s64)(*(short *)(param_1 + 10) * 0x10 + 0x7300) << 0x10 | uVar2;
  *(u64 *)(param_1 + 200) =
       (u64)*(u8 *)(param_1 + 0x10) | 0x100000000 |
       (u64)*(u8 *)(param_1 + 0x12) << 0x10 | (u64)*(u8 *)(param_1 + 0x11) << 8 |
       (u64)*(u8 *)(param_1 + 0x13) << 0x18;
  *(s64 *)(param_1 + 0x110) =
       (s64)*(short *)(param_1 + 0x140) |
       (s64)(int)((int)*(short *)(param_1 + 0x142) + (u32)*(u16 *)(param_1 + 0x146) + -1) <<
       0x30 | (s64)*(short *)(param_1 + 0x142) << 0x20 |
              (s64)(int)((int)*(short *)(param_1 + 0x140) + (u32)*(u16 *)(param_1 + 0x144) + -1
                         ) << 0x10;
  *(u64 *)(param_1 + 0xe8) =
       (s64)(int)(((int)*(short *)(param_1 + 8) + (u32)*(u16 *)(param_1 + 4)) * 0x10 + 0x7000)
       | (s64)(int)(((int)*(short *)(param_1 + 10) + (u32)*(u16 *)(param_1 + 6)) * 0x10 +
                    0x7300) << 0x10 | uVar2;
  puStack_48 = (u32 *)0x0;
  uStack_4c = 0;
  uStack_50 = 0;
  func_001b7e68(&uStack_50,0x20);
  puVar4 = (u64 *)(param_1 + 0x100);
  iVar3 = 1;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = *puVar4;
    uVar5 = *(u32 *)(puVar4 + 1);
    uVar6 = *(u32 *)((int)puVar4 + 0xc);
    *puStack_48 = (int)uVar1;
    puStack_48[1] = (int)((u64)uVar1 >> 0x20);
    puStack_48[2] = uVar5;
    puStack_48[3] = uVar6;
    puVar4 = puVar4 + 2;
    puStack_48 = puStack_48 + 4;
  } while (-1 < iVar3);
  func_001b80d8(&uStack_50);
  puStack_38 = (u32 *)0x0;
  uStack_3c = 0;
  uStack_40 = 0;
  func_001b7e68(&uStack_40,0xd0);
  puVar4 = (u64 *)(param_1 + 0x20);
  iVar3 = 0xc;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = *puVar4;
    uVar5 = *(u32 *)(puVar4 + 1);
    uVar6 = *(u32 *)((int)puVar4 + 0xc);
    *puStack_38 = (int)uVar1;
    puStack_38[1] = (int)((u64)uVar1 >> 0x20);
    puStack_38[2] = uVar5;
    puStack_38[3] = uVar6;
    puVar4 = puVar4 + 2;
    puStack_38 = puStack_38 + 4;
  } while (-1 < iVar3);
  func_001b80d8(&uStack_40);
  puStack_28 = (u32 *)0x0;
  uStack_2c = 0;
  uStack_30 = 0;
  func_001b7e68(&uStack_30,0x20);
  puVar4 = (u64 *)(param_1 + 0x120);
  iVar3 = 1;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = *puVar4;
    uVar5 = *(u32 *)(puVar4 + 1);
    uVar6 = *(u32 *)((int)puVar4 + 0xc);
    *puStack_28 = (int)uVar1;
    puStack_28[1] = (int)((u64)uVar1 >> 0x20);
    puStack_28[2] = uVar5;
    puStack_28[3] = uVar6;
    puVar4 = puVar4 + 2;
    puStack_28 = puStack_28 + 4;
  } while (-1 < iVar3);
  func_001b80d8(&uStack_30);
  func_001b7f30(&uStack_30);
  func_001b7f30(&uStack_40);
  func_001b7f30(&uStack_50);
  return;
}

void func_00154558(int param_1)

{
  u64 uVar1;
  int iVar2;
  u64 uVar3;
  u64 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = param_1 + 0x30;
  iVar8 = 5;
  func_00154b18();
  func_0014fc40(param_1,0x12,0,7000,6,1);
  *(u32 *)(param_1 + 0x20) = 0;
  uVar1 = func_0013a7e8(1);
  uVar3 = func_0013d7e0();
  func_001386e0(iVar6,7000,uVar1,uVar3,0x26,6);
  func_001386e0(param_1 + 0x1c8,7000,uVar1,uVar3,0x2a,6);
  func_001386e0(param_1 + 0x360,7000,uVar1,uVar3,0x27,6);
  func_001386e0(param_1 + 0x4f8,7000,uVar1,uVar3,0x28,6);
  func_001386e0(param_1 + 0x690,7000,uVar1,uVar3,0x29,6);
  func_001386e0(param_1 + 0x828,7000,uVar1,uVar3,0x2b,6);
  iVar5 = iVar6;
  do {
    *(int *)(iVar5 + 0x18c) = iVar6;
    func_001396b0(iVar5);
    if (*(int *)(iVar5 + 0x18c) != 0) {
      *(u32 *)(iVar5 + 400) = 0;
      func_001396b0(iVar5);
      if (*(int *)(iVar5 + 400) != 0) {
        func_0031a260(iVar5,0);
      }
    }
    iVar8 = iVar8 + -1;
    iVar5 = iVar5 + 0x198;
  } while (-1 < iVar8);
  *(u32 *)(param_1 + 0x1bc) = 0;
  func_001396b0(iVar6);
  if (*(int *)(param_1 + 0x1bc) != 0) {
    *(u32 *)(param_1 + 0x1c0) = 0;
    func_001396b0(iVar6);
    if (*(int *)(param_1 + 0x1c0) != 0) {
      func_0031a260(iVar6,0);
    }
  }
  iVar8 = 0;
  iVar5 = param_1 + 0x9d8;
  iVar9 = param_1 + 0x3300;
  do {
    iVar7 = 0;
    iVar2 = param_1 + 0x9c0;
    do {
      uVar4 = 0x2d;
      if (iVar7 != 0) {
        uVar4 = 0x2c;
      }
      func_001386e0(iVar2,7000,uVar1,uVar3,uVar4,6);
      iVar7 = iVar7 + 1;
      *(int *)(iVar2 + 0x18c) = iVar6;
      func_001396b0(iVar2);
      if (*(int *)(iVar2 + 0x18c) != 0) {
        *(u32 *)(iVar2 + 400) = 0;
        func_001396b0(iVar2);
        if (*(int *)(iVar2 + 400) != 0) {
          func_0031a260(iVar2,0);
        }
      }
      func_00138c68(iVar2,iVar8,0);
      iVar2 = iVar2 + 0x198;
    } while (iVar7 < 2);
    param_1 = param_1 + 0x330;
    iVar2 = func_0023aa98(iVar5);
    iVar5 = iVar5 + 0x330;
    iVar8 = iVar8 - iVar2;
  } while (param_1 < iVar9);
  func_001399c0(6);
  return;
}

void func_00154f30(u64 param_1)

{
  u64 uVar1;
  u64 uVar2;
  u32 uVar3;
  u64 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = (int)param_1;
  iVar8 = 3;
  iVar9 = iVar10 + 0x394;
  func_00158138();
  iVar5 = iVar10 + 0xa10;
  uVar1 = func_0013a7e8(1);
  uVar2 = func_0013d7e0();
  uVar4 = func_00158290(param_1);
  iVar6 = iVar10 + 0x1100;
  *(u8 *)(iVar10 + 0x15a0) = 0;
  *(u8 *)(iVar10 + 0x15a1) = 0;
  *(u8 *)(iVar10 + 0x15a2) = 0;
  func_00158050(iVar9,7000,uVar1,uVar2,0x47,0,uVar4);
  func_0013e0f8(iVar5,7000,0,uVar4);
  iVar7 = iVar10 + 0x40;
  func_0013e0f8(iVar10 + 0xc60,7000,1,uVar4);
  func_00158050(iVar10 + 0x530,7000,uVar1,uVar2,0x40,100,uVar4);
  func_0013e0f8(iVar10 + 0xeb0,7000,1,uVar4);
  func_00158050(iVar10 + 0x6cc,7000,uVar1,uVar2,0x41,1000,uVar4);
  func_0013e0f8(iVar6,7000,0,uVar4);
  func_0013e0f8(iVar10 + 0x1350,7000,1,uVar4);
  func_00158050(iVar10 + 0x868,7000,uVar1,uVar2,0x42,10000,uVar4);
  func_001581f8(param_1);
  func_00153fa0(iVar7,7000,*(int *)(iVar10 + 0x30) + 1,*(u32 *)(iVar10 + 0x34),
               *(u32 *)(iVar10 + 0x18),uVar4);
  func_00139d78(iVar5);
  func_0014b208(iVar10 + 0xa30,0x40,0x40);
  func_00139d78(iVar6);
  func_0014b208(iVar10 + 0x1120,0x40,0x40);
  func_00139d78(iVar5);
  func_0014b200(iVar10 + 0xa30,0);
  func_0014b200(iVar10 + 0xb50,0);
  func_00139d78(iVar6);
  func_0014b200(iVar10 + 0x1120,0);
  func_0014b200(iVar10 + 0x1240,0);
  func_00139d78(iVar10 + 0xc60);
  func_0014b200(iVar10 + 0xc80,200);
  func_0014b200(iVar10 + 0xda0,200);
  func_00139d78(iVar10 + 0xeb0);
  func_0014b200(iVar10 + 0xed0,2000);
  func_0014b200(iVar10 + 0xff0,2000);
  func_00139d78(iVar10 + 0x1350);
  func_0014b200(iVar10 + 0x1370,20000);
  func_0014b200(iVar10 + 0x1490,20000);
  iVar5 = iVar9;
  do {
    *(int *)(iVar5 + 0x18c) = iVar9;
    func_001396b0(iVar5);
    if (*(int *)(iVar5 + 0x18c) != 0) {
      *(u32 *)(iVar5 + 400) = 0;
      func_001396b0(iVar5);
      if (*(int *)(iVar5 + 400) != 0) {
        func_0031a260(iVar5,0);
      }
    }
    iVar8 = iVar8 + -1;
    func_001395e8(iVar5);
    func_00139610(iVar5);
    iVar5 = iVar5 + 0x19c;
  } while (-1 < iVar8);
  iVar5 = iVar10 + 0xa10;
  iVar6 = 4;
  do {
    iVar6 = iVar6 + -1;
    func_00139d78(iVar5);
    *(int *)(iVar5 + 0x240) = iVar9;
    iVar5 = iVar5 + 0x250;
  } while (-1 < iVar6);
  *(int *)(iVar10 + 0x1cc) = iVar9;
  func_001396b0(iVar7);
  if (*(int *)(iVar10 + 0x1cc) == 0) {
    *(u32 *)(iVar10 + 0x520) = 0;
  }
  else {
    *(u32 *)(iVar10 + 0x1d0) = 0;
    func_001396b0(iVar7);
    if (*(int *)(iVar10 + 0x1d0) != 0) {
      func_0031a260(iVar7,0);
    }
    *(u32 *)(iVar10 + 0x520) = 0;
  }
  func_001396b0(iVar9);
  if (*(int *)(iVar10 + 0x520) != 0) {
    *(u32 *)(iVar10 + 0x524) = 0;
    func_001396b0(iVar9);
    if (*(int *)(iVar10 + 0x524) != 0) {
      func_0031a260(iVar9,0);
    }
  }
  uVar3 = func_00154ee8(param_1);
  *(u32 *)(iVar10 + 0x51c) = uVar3;
  iVar5 = func_0023aa98(iVar10 + 0x3ac);
  func_00138c40(iVar9,0,iVar5 * *(int *)(iVar10 + 0x30));
  func_001582a8(param_1);
  return;
}

void func_00156130(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u64 uVar1;
  u64 uVar2;
  s64 lVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar8 = (int)param_1;
  iVar9 = iVar8 + 0x2f1c;
  iVar10 = 2;
  iVar11 = iVar8 + 0x394;
  uVar1 = func_00155ee8();
  iVar12 = iVar8 + 0x30b8;
  iVar5 = iVar8 + 0x2d80;
  iVar6 = iVar8 + 0x3260;
  func_00158050(iVar5,7000,param_2,param_3,uVar1,0,param_4);
  func_0013dfb8(iVar6,7000,param_4);
  uVar1 = func_00155fc0(param_1);
  func_00158050(iVar9,7000,param_2,param_3,uVar1,5000,param_4);
  uVar1 = func_00155e30(param_1);
  func_00158050(iVar12,7000,param_2,param_3,uVar1,0,param_4);
  func_001386e0(iVar11,0x1b62,param_2,param_3,0x14,param_4);
  func_00139d78(iVar6);
  func_0014b200(iVar8 + 0x3280,6000);
  iVar7 = iVar5;
  do {
    *(int *)(iVar7 + 0x18c) = iVar8 + 0x1a30;
    func_001396b0(iVar7);
    if (*(int *)(iVar7 + 0x18c) != 0) {
      *(u32 *)(iVar7 + 400) = 0;
      func_001396b0(iVar7);
      if (*(int *)(iVar7 + 400) != 0) {
        func_0031a260(iVar7,0);
      }
    }
    iVar10 = iVar10 + -1;
    func_001395e8(iVar7);
    func_00139610(iVar7);
    iVar7 = iVar7 + 0x19c;
  } while (-1 < iVar10);
  *(int *)(iVar8 + 0x30a8) = iVar5;
  func_001396b0(iVar9);
  if (*(int *)(iVar8 + 0x30a8) != 0) {
    *(u32 *)(iVar8 + 0x30ac) = 0;
    func_001396b0(iVar9);
    if (*(int *)(iVar8 + 0x30ac) != 0) {
      func_0031a260(iVar9,0);
    }
  }
  *(int *)(iVar8 + 0x3244) = iVar5;
  func_001396b0(iVar12);
  if (*(int *)(iVar8 + 0x3244) != 0) {
    *(u32 *)(iVar8 + 0x3248) = 0;
    func_001396b0(iVar12);
    if (*(int *)(iVar8 + 0x3248) != 0) {
      func_0031a260(iVar12,0);
    }
  }
  func_00139d78(iVar6);
  *(int *)(iVar8 + 0x33a0) = iVar5;
  *(int *)(iVar8 + 0x520) = iVar5;
  func_001396b0(iVar11);
  if (*(int *)(iVar8 + 0x520) != 0) {
    *(u32 *)(iVar8 + 0x524) = 0;
    func_001396b0(iVar11);
    if (*(int *)(iVar8 + 0x524) != 0) {
      func_0031a260(iVar11,0);
    }
  }
  func_00139598(iVar11);
  uVar1 = func_0023aa18(iVar8 + 0x2d98);
  uVar2 = func_0023aa38(iVar8 + 0x2d98);
  func_00138c68(iVar12,uVar1,uVar2);
  uVar4 = func_00155f40(param_1);
  *(u32 *)(iVar8 + 0x2f08) = uVar4;
  lVar3 = func_00156030(param_1);
  if (lVar3 != 0) {
    func_00138c10(iVar5,0x12);
    uVar4 = func_00155f40(param_1);
    *(u32 *)(iVar8 + 0x2f08) = uVar4;
  }
  func_00156408(param_1);
  return;
}

void func_001565c0(int param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 0x3600;
  iVar2 = param_1 + 0x3850;
  iVar1 = param_1 + 0x3aa0;
  func_0013e0f8(iVar3,7000,1);
  func_00158050(param_1 + 0x1bcc,7000,param_2,param_3,0x79,100,param_4);
  func_0013e0f8(iVar2,7000,1,param_4);
  func_00158050(param_1 + 0x1d68,7000,param_2,param_3,0x79,500,param_4);
  func_0013e0f8(iVar1,7000,1,param_4);
  func_00158050(param_1 + 0x1f04,7000,param_2,param_3,0x80,1000,param_4);
  func_00158050(param_1 + 0x20a0,7000,param_2,param_3,0x7c,0,param_4);
  func_00158050(param_1 + 0x223c,7000,param_2,param_3,0x7f,0,param_4);
  func_00158050(param_1 + 0x23d8,7000,param_2,param_3,0x81,0,param_4);
  func_00158050(param_1 + 0x2574,7000,param_2,param_3,0x7b,0,param_4);
  func_00139d78(iVar3);
  func_0014b200(param_1 + 0x3620,200);
  func_0014b200(param_1 + 0x3740,200);
  func_00139d78(iVar2);
  func_0014b200(param_1 + 0x3870,600);
  func_0014b200(param_1 + 0x3990,600);
  func_00139d78(iVar1);
  func_0014b200(param_1 + 0x3ac0,2000);
  func_0014b200(param_1 + 0x3be0,2000);
  if ((*(int *)(param_1 + 0x34) != 0) &&
     ((*(u32 *)(*(int *)(*(int *)(param_1 + 0x34) + 0x48c) + 0x250) & 2) != 0)) {
    func_00139598(param_1 + 0x33b0);
    func_00139598(iVar3);
    func_00139598(param_1 + 0x1bcc);
    func_00139598(iVar2);
    func_00139598(param_1 + 0x1d68);
    func_00139598(iVar1);
    func_00139598(param_1 + 0x1f04);
    func_00139598(param_1 + 0x20a0);
    func_00139598(param_1 + 0x223c);
    func_00139598(param_1 + 0x23d8);
    func_00139598(param_1 + 0x2574);
    return;
  }
  return;
}

void func_00156e48(u64 param_1)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  s64 lVar4;
  int iVar5;
  u64 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar6 = func_0013dda0(0);
  uVar1 = func_00158290(param_1);
  uVar2 = func_0013a7e8(1);
  uVar3 = func_0013d7e0();
  lVar4 = func_00156030(param_1);
  iVar9 = (int)param_1;
  if (((lVar4 == 0) &&
      (iVar5 = *(int *)(iVar9 + 0x2f04), iVar7 = func_00155f40(param_1), iVar5 != iVar7)) &&
     (iVar5 = *(int *)(iVar9 + 0x2f04), iVar7 = func_00155ee8(param_1), iVar5 != iVar7)) {
    if (*(char *)(iVar9 + 0x3cfb) == '\x01') {
      iVar5 = func_00139c18(iVar9 + 0xd24);
      iVar7 = iVar9 + iVar5 * 0x198;
      iVar8 = iVar7 + 0xd24;
      func_001386e0(iVar8,7000,uVar2,uVar3,0x82,uVar1);
      *(int *)(iVar7 + 0xeb0) = iVar9 + 0x1a30;
      func_001396b0(iVar8);
      if (*(int *)(iVar7 + 0xeb0) != 0) {
        *(u32 *)(iVar7 + 0xeb4) = 0;
        func_001396b0(iVar8);
        if (*(int *)(iVar7 + 0xeb4) != 0) {
          func_0031a260(iVar8,0);
        }
      }
      lVar4 = func_001396c0(iVar9 + 0x1a30);
      if (lVar4 != 0) {
        func_00139570(iVar9 + iVar5 * 0x198 + 0xd24);
      }
    }
    lVar4 = func_00156058(param_1);
    if ((lVar4 == 0) && (lVar4 = func_00156080(param_1), lVar4 == 0)) {
      func_00156d20(param_1);
    }
    else {
      uVar1 = func_00155f40(param_1);
      func_00138c10(iVar9 + 0x2d80,uVar1);
      uVar1 = func_00155fc0(param_1);
      func_00138c10(iVar9 + 0x2f1c,uVar1);
      *(u8 *)(iVar9 + 0x3cf7) = 1;
    }
  }
  func_00156408(param_1);
  *(int *)(iVar9 + 0x34) = (int)uVar6;
  func_001581f8(param_1);
  func_001542c8(iVar9 + 0x40,uVar6,*(u32 *)(iVar9 + 0x18));
  if (*(int *)(iVar9 + 0x34) != 0) {
    func_001575c0(param_1);
    return;
  }
  return;
}

void func_00157c88(u64 param_1)

{
  char cVar1;
  int iVar2;
  s64 lVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  int iVar7;
  int iVar8;
  u32 uStack_40;
  u32 auStack_3c [3];
  
  func_00156408();
  lVar3 = func_00156010(param_1);
  if (lVar3 == 0) {
    lVar3 = func_00156030(param_1);
    iVar7 = (int)param_1;
    if (lVar3 == 0) {
      lVar3 = func_00156058(param_1);
      if ((lVar3 == 0) && (lVar3 = func_00156080(param_1), lVar3 == 0)) {
        func_00155bf0(param_1,*(u8 *)(*(int *)(*(int *)(iVar7 + 0x34) + 0x48c) + 0x1b0));
        func_00155d80(param_1);
        iVar2 = *(int *)(*(int *)(iVar7 + 0x34) + 0x48c);
        if (*(u8 *)(iVar2 + 0x1b1) < *(u8 *)(iVar2 + 0x1b2)) {
          *(u8 *)(iVar7 + 0x3cf9) = 0;
          func_00139598(iVar7 + 0x394);
          cVar1 = *(char *)(iVar7 + 0x3cf6);
        }
        else {
          if (*(char *)(iVar7 + 0x3cf9) == '\0') {
            if ((*(char *)(iVar7 + 0x3cf8) == '\x01') && (lVar3 = func_00105300(), lVar3 == 0)) {
              func_002ba2e8(0x21,0);
            }
            func_00138c10(iVar7 + 0x394,0x14);
            *(u8 *)(iVar7 + 0x3cf9) = 1;
          }
          func_001395a8(iVar7 + 0x394);
          cVar1 = *(char *)(iVar7 + 0x3cf6);
        }
        if (cVar1 != '\x01') {
          return;
        }
        *(u8 *)(iVar7 + 0x3cf6) = 0;
        uVar4 = func_00155e30(param_1);
        func_00138c10(iVar7 + 0x30b8,uVar4);
        if (*(char *)(iVar7 + 0x3cf8) != '\x01') {
          return;
        }
        if (*(char *)(iVar7 + 0x3cf9) == '\0') {
          func_002ba2e8(0x20,0);
        }
        uVar4 = func_00158290(param_1);
        uVar5 = func_0013a7e8(1);
        uVar6 = func_0013d7e0();
        iVar2 = func_00139c18(iVar7 + 0x9f4);
        iVar2 = iVar7 + iVar2 * 0x198;
        iVar8 = iVar2 + 0x9f4;
        lVar3 = func_00139d78(iVar8);
        if (lVar3 != 0) {
          *(u8 *)(iVar7 + 0x3cf8) = 0;
          return;
        }
        func_001386e0(iVar8,7000,uVar5,uVar6,0x16,uVar4);
        *(int *)(iVar2 + 0xb80) = iVar7 + 0x2d80;
        func_001396b0(iVar8);
        if (*(int *)(iVar2 + 0xb80) == 0) {
          *(u8 *)(iVar7 + 0x3cf8) = 0;
          return;
        }
        *(u32 *)(iVar2 + 0xb84) = 0;
        func_001396b0(iVar8);
        if (*(int *)(iVar2 + 0xb84) == 0) {
          *(u8 *)(iVar7 + 0x3cf8) = 0;
          return;
        }
        func_0031a260(iVar8,0);
        *(u8 *)(iVar7 + 0x3cf8) = 0;
        return;
      }
      uStack_40 = 0;
      auStack_3c[0] = 0;
      func_00155d80(param_1);
      func_001560a8(param_1,&uStack_40,auStack_3c);
      func_00155cb0(param_1,uStack_40,auStack_3c[0]);
      if (*(char *)(iVar7 + 0x3cf7) == '\x01') {
        *(u8 *)(iVar7 + 0x3cf7) = 0;
        uVar4 = func_00155e30(param_1);
        func_00138c10(iVar7 + 0x30b8,uVar4);
      }
    }
    func_00139598(iVar7 + 0x394);
  }
  return;
}

void func_001620a8(void)

{
  int iVar1;
  
  func_00106998(1);
  func_00102c18(5,6000,0x161868);
  func_00102c18(5,0x1771,0x1433e8);
  func_00102c18(5,0x1772,0x161a10);
  func_00102c18(5,29999,0x161a28);
  func_00102c18(5,30000,0x107888);
  func_00102c18(5,40999,0x161a10);
  func_00102c18(5,41000,0x1dd2b8);
  func_00102c18(5,42999,0x161a28);
  func_00102c18(5,43000,0x144250);
  func_00102c18(5,49999,0x161880);
  func_00102c18(5,50000,0x1618a0);
  func_00102c18(5,60000,0x161a10);
  func_00102c18(5,0xea61,0x1dd920);
  iVar1 = func_00102c18(5,71000,0x167228);
  *(u8 *)(iVar1 + 4) = 0;
  func_00102c18(5,65000,0x15de18);
  func_00102c18(5,90000,0x161a40);
  func_00102c18(5,0x15f95,0x14df48);
  func_00102c18(5,0x15f9a,0x161868);
  func_00102c18(5,0x15fa4,0x161a10);
  func_00102c18(5,0x15fae,0x107888);
  func_00102c18(5,0x15fb7,0x161a28);
  func_00102c18(5,0x15fb8,0x1dd2b8);
  func_00102c18(5,0x15fc1,0x161a10);
  func_00102c18(5,0x15fc2,0x144250);
  func_00102c18(5,0x15fcc,0x161880);
  func_00102c18(5,0x15fd6,0x1618a0);
  func_00102c18(5,0x15fdf,0x161a28);
  func_00102c18(5,0x15fe0,0x1dd920);
  iVar1 = func_00102c18(5,0x15ff4,0x167228);
  *(u8 *)(iVar1 + 4) = 0;
  func_00102c18(5,0x15ffe,0x15de18);
  func_00102c18(5,0x16012,0x161c70);
  return;
}

void func_001ab890(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_001aae28(0x1c6cc60,0,0,9,8,0x12,0x12,0x12);
    func_001aae28(0x1c6cc80,1,0,9,8,0x12,0x12,0x12);
    func_001aae28(0x1c6cca0,2,0,9,8,0x12,0x12,0x12);
    func_001aae28(0x1c6ccc0,3,0x800,9,9,0x18,0x18,0x18);
    func_001aae28(0x1c6cce0,4,0x800,9,9,0x18,0x18,0x18);
    func_001aae28(0x1c6cd00,5,0,9,8,0x12,0x12,0x12);
  }
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_002361a0(0x1c6cd20);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    func_002361d0(0x1c6cd20);
    return;
  }
  return;
}

void func_002298a8(u64 param_1,s64 param_2)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uStack_60;
  
  iVar5 = (int)param_1;
  *(int *)(iVar5 + 0xba0) = (int)param_2;
  uStack_60 = 0x6f;
  uVar7 = 0x60;
  uVar8 = 0x89;
  uVar1 = func_0022b720();
  uVar2 = func_0022b9e0();
  if (param_2 == 1) {
    uVar7 = 0x5f;
    uStack_60 = 0x6e;
    uVar8 = 0x87;
  }
  func_0022a0f8(iVar5 + 0x360,0x9c4,0,0xb);
  iVar3 = iVar5 + 0x1b8;
  func_0022a0f8(iVar5 + 0x6b0,0x9c4,1,0xb);
  iVar6 = iVar5 + 0xa00;
  func_00158050(iVar3,0x9c4,uVar2,uVar1,uVar7,100,0xb);
  func_001386e0(iVar6,0x9c4,uVar2,uVar1,uVar8,0xb);
  func_001386e0(param_1,0x9c3,uVar2,uVar1,uStack_60,0xb);
  func_00139570(iVar6);
  func_00139d78(iVar5 + 0x360);
  func_0014b200(iVar5 + 0x380,0);
  func_0014b200(iVar5 + 0x4a0,0);
  func_0014b200(iVar5 + 0x5a0,0);
  func_00139d78(iVar5 + 0x6b0);
  func_0014b200(iVar5 + 0x6d0,200);
  func_0014b200(iVar5 + 0x7f0,200);
  func_0014b200(iVar5 + 0x8f0,200);
  *(int *)(iVar5 + 0x344) = iVar5;
  func_001396b0(iVar3);
  if (*(int *)(iVar5 + 0x344) != 0) {
    *(u32 *)(iVar5 + 0x348) = 0;
    func_001396b0(iVar3);
    if (*(int *)(iVar5 + 0x348) != 0) {
      func_0031a260(iVar3,0);
    }
  }
  iVar3 = iVar5 + 0x360;
  iVar4 = 1;
  do {
    iVar4 = iVar4 + -1;
    func_00139d78(iVar3);
    *(int *)(iVar3 + 0x340) = iVar5;
    iVar3 = iVar3 + 0x350;
  } while (-1 < iVar4);
  *(int *)(iVar5 + 0xb8c) = iVar5;
  func_001396b0(iVar6);
  if (*(int *)(iVar5 + 0xb8c) == 0) {
    *(u32 *)(iVar5 + 0x18c) = 0;
  }
  else {
    *(u32 *)(iVar5 + 0xb90) = 0;
    func_001396b0(iVar6);
    if (*(int *)(iVar5 + 0xb90) != 0) {
      func_0031a260(iVar6,0);
    }
    *(u32 *)(iVar5 + 0x18c) = 0;
  }
  func_001396b0(param_1);
  if (*(int *)(iVar5 + 0x18c) != 0) {
    *(u32 *)(iVar5 + 400) = 0;
    func_001396b0(param_1);
    if (*(int *)(iVar5 + 400) != 0) {
      func_0031a260(param_1,0);
      return;
    }
  }
  return;
}

void func_0022c1f8(int param_1,u64 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  u32 *puVar7;
  int iVar8;
  u32 auStack_70 [2];
  int aiStack_68 [6];
  
  puVar7 = auStack_70;
  iVar3 = param_3 + 0x18;
  iVar6 = 2;
  *(int *)(param_1 + 0x18) = param_3;
  iVar8 = 0;
  iVar1 = func_00197df8();
  func_00150260(0x35e2f0,param_2,3,auStack_70);
  iVar4 = param_1 + 0x1c;
  func_0023a9c0(iVar3,aiStack_68 + 2,aiStack_68 + 3);
  iVar2 = func_0023aa18(iVar3);
  aiStack_68[2] = aiStack_68[2] + iVar2;
  iVar2 = func_0023aa38(iVar3);
  aiStack_68[3] = aiStack_68[3] + iVar2;
  do {
    func_001386e0(iVar4,26000,*(u32 *)(iVar1 + 4),param_3 + 0x1c0,*puVar7,0x10);
    puVar7 = puVar7 + 1;
    *(int *)(iVar4 + 0x18c) = param_3;
    func_001396b0(iVar4);
    if (*(int *)(iVar4 + 0x18c) != 0) {
      *(u32 *)(iVar4 + 400) = 0;
      func_001396b0(iVar4);
      if (*(int *)(iVar4 + 400) != 0) {
        func_0031a260(iVar4,0);
      }
    }
    iVar6 = iVar6 + -1;
    func_00139660(iVar4);
    func_00139688(iVar4);
    iVar4 = iVar4 + 0x198;
  } while (-1 < iVar6);
  iVar2 = 2;
  iVar1 = param_1 + 0x34c;
  piVar5 = aiStack_68;
  do {
    iVar3 = *piVar5;
    piVar5 = piVar5 + -1;
    if (iVar3 != 7) break;
    func_00138c10(iVar1,0x11);
    iVar2 = iVar2 + -1;
    func_00139598(iVar1);
    iVar1 = iVar1 + -0x198;
  } while (0 < iVar2);
  iVar2 = 2;
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x1a0) != 0x11) {
      iVar3 = func_0023aa98(iVar1 + 0x34);
      iVar8 = iVar8 + iVar3;
    }
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + 0x198;
  } while (-1 < iVar2);
  aiStack_68[2] = aiStack_68[2] + iVar8 / 2;
  iVar1 = 2;
  do {
    if (*(int *)(param_1 + 0x1a0) != 0x11) {
      iVar2 = func_0023aa98(param_1 + 0x34);
      aiStack_68[2] = aiStack_68[2] - iVar2;
      func_00138c68(param_1 + 0x1c,aiStack_68[2],aiStack_68[3]);
    }
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 0x198;
  } while (-1 < iVar1);
  return;
}

void func_0023bc58(u64 param_1,int param_2,int param_3)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  u16 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar4 = (int)param_1;
  puVar10 = (u16 *)(*(int *)(iVar4 + 0xb4) + *(int *)(iVar4 + 0x114) * 0x24);
  uVar2 = param_3 + *(int *)(puVar10 + 10) & 0xfffffffe;
  uVar3 = param_2 + *(int *)(puVar10 + 8) & 0xfffffffe;
  iVar11 = param_3 + *(int *)(puVar10 + 10) >> 1;
  iVar12 = param_2 + *(int *)(puVar10 + 8) >> 1;
  uVar1 = *(u32 *)(*(int *)(iVar4 + 0xb0) + (u32)*puVar10 * 0x90 + 4);
  iVar4 = func_00237508(param_1,uVar1,0);
  iVar5 = func_00237578(param_1,uVar1,0);
  iVar6 = func_00237578(param_1,uVar1,1);
  iVar7 = func_00237578(param_1,uVar1,2);
  iVar8 = func_00237508(param_1,uVar1,3);
  iVar9 = func_00237508(param_1,uVar1,6);
  iVar13 = (int)-uVar2 / 2;
  iVar14 = (int)-uVar3 / 2;
  func_00237458(param_1,uVar1,0,iVar14 - iVar4);
  func_002374c8(param_1,uVar1,0,iVar13 - iVar5);
  func_00237458(param_1,uVar1,1,iVar14);
  func_002374c8(param_1,uVar1,1,iVar13 - iVar6);
  func_00237540(param_1,uVar1,1,uVar3);
  func_00237458(param_1,uVar1,2,iVar12);
  func_002374c8(param_1,uVar1,2,iVar13 - iVar7);
  func_00237458(param_1,uVar1,3,iVar14 - iVar8);
  func_002374c8(param_1,uVar1,3,iVar13);
  func_002375b0(param_1,uVar1,3,uVar2);
  func_00237458(param_1,uVar1,4,iVar14);
  func_002374c8(param_1,uVar1,4,iVar13);
  func_00237640(param_1,uVar1,4,uVar3,uVar2);
  func_00237458(param_1,uVar1,5,iVar12);
  func_002374c8(param_1,uVar1,5,iVar13);
  func_002375b0(param_1,uVar1,5,uVar2);
  func_00237458(param_1,uVar1,6,iVar14 - iVar9);
  func_002374c8(param_1,uVar1,6,iVar11);
  func_00237458(param_1,uVar1,7,iVar14);
  func_002374c8(param_1,uVar1,7,iVar11);
  func_00237540(param_1,uVar1,7,uVar3);
  func_00237458(param_1,uVar1,8,iVar12);
  func_002374c8(param_1,uVar1,8,iVar11);
  return;
}

void func_002b4070(u32 *param_1,u64 param_2,u64 param_3,u64 param_4,
                 s64 param_5,s64 param_6,int param_7,int param_8,int param_9,u64 param_10,
                 int param_11,u32 param_12,u32 param_13)

{
  u64 uVar1;
  u64 uVar2;
  
  if (param_5 != 0) {
    func_0023f1e0(*param_1);
    uVar1 = func_0023f7d8(*param_1);
    uVar1 = func_0023aa98(uVar1);
    uVar2 = func_0028dd90(uVar1);
    func_0023f6c0(*param_1,uVar2);
    uVar1 = func_0028ddd8(uVar1);
    func_0023f688(*param_1,uVar1);
    func_001395f8(*param_1);
  }
  if (param_6 != 0) {
    func_0023f1e0(param_1[1],param_2,param_3,param_4,param_6,*(u16 *)(param_11 + 0x14),
                 param_12,param_13);
    uVar1 = func_0023f7d8(param_1[1]);
    uVar1 = func_0023aa98(uVar1);
    uVar2 = func_0028dd90(uVar1);
    func_0023f6c0(param_1[1],uVar2);
    uVar1 = func_0028ddd8(uVar1);
    func_0023f688(param_1[1],uVar1);
    func_001395f8(param_1[1]);
  }
  if (param_7 != 0) {
    func_0023f1e0(param_1[1] + 0x4c,param_2,param_3,param_4,param_7,*(u16 *)(param_11 + 0x16),
                 param_12,param_13);
    uVar1 = func_0023f7d8(param_1[1] + 0x4c);
    uVar1 = func_0023aa98(uVar1);
    uVar2 = func_0028dd90(uVar1);
    func_0023f6c0(param_1[1] + 0x4c,uVar2);
    uVar1 = func_0028ddd8(uVar1);
    func_0023f688(param_1[1] + 0x4c,uVar1);
    func_001395f8(param_1[1] + 0x4c);
  }
  if (param_8 != 0) {
    func_0023f1e0(param_1[1] + 0x98,param_2,param_3,param_4,param_8,*(u16 *)(param_11 + 0x18),
                 param_12,param_13);
    uVar1 = func_0023f7d8(param_1[1] + 0x98);
    uVar1 = func_0023aa98(uVar1);
    uVar2 = func_0028dd90(uVar1);
    func_0023f6c0(param_1[1] + 0x98,uVar2);
    uVar1 = func_0028ddd8(uVar1);
    func_0023f688(param_1[1] + 0x98,uVar1);
    func_001395f8(param_1[1] + 0x98);
  }
  if (param_9 != 0) {
    func_0023f1e0(param_1[2],param_2,param_3,param_4,param_9,*(u16 *)(param_11 + 0x1a),
                 param_12,param_13);
    uVar1 = func_0023f7d8(param_1[2]);
    uVar1 = func_0023aa98(uVar1);
    uVar2 = func_0028dd90(uVar1);
    func_0023f6c0(param_1[2],uVar2);
    uVar1 = func_0028ddd8(uVar1);
    func_0023f688(param_1[2],uVar1);
    func_001395f8(param_1[2]);
    return;
  }
  return;
}

void func_00303ff8(u64 param_1,int param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  int iVar12;
  u32 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  u32 *puVar17;
  
  iVar16 = *(int *)(param_2 + 0x10);
  iVar15 = *(int *)(param_3 + 0x10);
  iVar12 = param_2;
  if (iVar16 < iVar15) {
    iVar16 = *(int *)(param_3 + 0x10);
    iVar15 = *(int *)(param_2 + 0x10);
    iVar12 = param_3;
    param_3 = param_2;
  }
  iVar14 = iVar16 + iVar15;
  iVar2 = func_00303b70(param_1,*(int *)(iVar12 + 4) + (u32)(*(int *)(iVar12 + 8) < iVar14));
  puVar17 = (u32 *)(iVar2 + 0x14);
  if (puVar17 < puVar17 + iVar14) {
    *puVar17 = 0;
    puVar5 = puVar17;
    while (puVar5 = puVar5 + 1, puVar5 < puVar17 + iVar14) {
      *puVar5 = 0;
    }
  }
  puVar4 = (u32 *)(param_3 + 0x14);
  puVar3 = (u32 *)(iVar12 + 0x14);
  puVar13 = puVar4 + iVar15;
  puVar5 = puVar17;
  for (; puVar4 < puVar13; puVar4 = puVar4 + 1) {
    uVar9 = *puVar4;
    uVar11 = uVar9 & 0xffff;
    if (uVar11 != 0) {
      uVar9 = 0;
      puVar7 = puVar5;
      puVar6 = puVar3;
      do {
        uVar8 = *puVar6;
        uVar10 = *puVar7;
        puVar6 = puVar6 + 1;
        uVar9 = (uVar8 & 0xffff) * uVar11 + (uVar10 & 0xffff) + uVar9;
        *(short *)puVar7 = (short)uVar9;
        uVar9 = (uVar8 >> 0x10) * uVar11 + (uVar10 >> 0x10) + (uVar9 >> 0x10);
        *(short *)((int)puVar7 + 2) = (short)uVar9;
        uVar9 = uVar9 >> 0x10;
        puVar7 = puVar7 + 1;
      } while (puVar6 < puVar3 + iVar16);
      *puVar7 = uVar9;
      uVar9 = *puVar4;
    }
    uVar9 = uVar9 >> 0x10;
    if (uVar9 != 0) {
      uVar11 = *puVar5;
      uVar10 = 0;
      puVar7 = puVar5;
      puVar6 = puVar3;
      uVar8 = uVar11;
      do {
        uVar1 = *puVar6;
        *(short *)puVar7 = (short)uVar11;
        puVar6 = puVar6 + 1;
        uVar10 = (uVar1 & 0xffff) * uVar9 + (uVar8 >> 0x10) + uVar10;
        *(short *)((int)puVar7 + 2) = (short)uVar10;
        puVar7 = puVar7 + 1;
        uVar8 = *puVar7;
        uVar11 = (uVar1 >> 0x10) * uVar9 + (uVar8 & 0xffff) + (uVar10 >> 0x10);
        uVar10 = uVar11 >> 0x10;
      } while (puVar6 < puVar3 + iVar16);
      *puVar7 = uVar11;
    }
    puVar5 = puVar5 + 1;
  }
  if (0 < iVar14) {
    puVar17 = puVar17 + iVar14 + -1;
    if (*puVar17 != 0) {
      *(int *)(iVar2 + 0x10) = iVar14;
      return;
    }
    do {
      iVar14 = iVar14 + -1;
      if (iVar14 < 1) {
        *(int *)(iVar2 + 0x10) = iVar14;
        return;
      }
      puVar17 = puVar17 + -1;
    } while (*puVar17 == 0);
  }
  *(int *)(iVar2 + 0x10) = iVar14;
  return;
}
