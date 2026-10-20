#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern s32 D_0034f240;
extern s32 D_00352ae0;
extern s32 D_00352bd0;
extern f32 D_00359110;
extern f32 D_00359114;
extern f32 D_00359118;
extern f32 D_0035911c;
extern f32 D_00359120;
extern f32 D_00359124;
extern f32 D_00359128;
extern f32 D_0035912c;
extern f32 D_00359130;
extern f32 D_00359134;
extern f32 D_00359138;
extern f32 D_0035913c;
extern f32 D_00359140;
extern f32 D_00359144;
extern f32 D_00359148;
extern f32 D_0035914c;
extern u8 D_00359150;
extern u8 D_00359151;
extern u8 D_00359152;
extern s32 D_00359780;
extern s32 D_00359788;
extern s32 D_00359808;
extern s32 D_00359810;
extern s32 D_0035dad4;
extern s32 D_0035dad8;
extern s32 D_0035db00;
extern s32 D_0035db04;
extern s32 D_0035db08;
extern s32 D_0035db10;
extern f32 D_0035db20;
extern f32 D_0035db24;
extern f32 D_0035db28;
extern f32 D_0035db30;
extern f32 D_0035db34;
extern f32 D_0035db38;
extern s32 D_0035dce4;
extern s32 D_0035dce8;
extern s32 D_0035dcf0;
extern s32 D_0035dcf4;
extern s32 D_0035dcf8;
extern s32 D_0035dcfc;
extern u8 D_0035de14;
extern u8 D_0035de15;
extern s32 D_0035de20;
extern u8 D_0035de27;
extern s32 D_0035de30;
extern s32 D_0035de34;
extern s32 D_0035de38;
extern s32 D_0035de3c;
extern u8 D_0035de54;
extern s32 D_0035de5c;
extern u8 D_0035e440;
extern s32 D_0035ea40;
extern s32 D_0035eb48;
extern s32 D_0035eb4c;
extern u8 D_0035eb84;
extern s32 D_0035eb88;
extern s32 D_0035eb8c;
extern s32 D_0035ec94;
extern f32 D_0036e928;
extern f32 D_0036e92c;
extern f32 D_003707b0;
extern f32 D_003707b4;
extern f32 D_003707b8;
extern f32 D_003707bc;
extern f32 D_003714bc;
extern f32 D_003714c0;
extern f32 D_003714c4;
extern f32 D_003714c8;
extern s32 D_01d49350;
extern u32* D_01d49354;
extern s32 D_01d9e348;
extern s32 D_01d9e34c;
extern s32 D_01dad910;
extern s32 D_01dad914;
extern s32 D_01dad9c0;

void func_00226a78(void)

{
  D_0035db10 = 0;
  D_0035de27 = 0;
  D_0035de30 = 0;
  D_0035de34 = 0;
  D_0035de38 = 0;
  D_0035de3c = 0;
  return;
}

void func_00230838(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = iVar1 * 8;
    iVar1 = iVar1 + 1;
    piVar2 = (int *)(iVar3 + D_0035dce8);
    if (*piVar2 == 0) {
      *piVar2 = param_1;
      return;
    }
  } while (iVar1 < 0x40);
  return;
}

void func_00236d10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u8 *puVar4;
  
  iVar1 = 0x3500;
  puVar4 = &D_0035e440;
  iVar2 = 0x3600;
  iVar3 = 0x3f;
  do {
    *(int *)(puVar4 + 0x10) = iVar2;
    iVar3 = iVar3 + -1;
    *(int *)(puVar4 + 0x14) = iVar1;
    *puVar4 = 0;
    iVar2 = iVar2 + 0x20;
    *(u32 *)(puVar4 + 4) = 0;
    iVar1 = iVar1 + 4;
    *(u32 *)(puVar4 + 8) = 0;
    puVar4 = puVar4 + 0x18;
  } while (-1 < iVar3);
  D_0035ea40 = 1;
  return;
}

bool func_0023d2e0(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = D_0035eb48 == -1;
  iVar2 = D_0035eb48;
  if (bVar1) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  return !bVar1;
}

bool func_0023d300(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = D_0035eb4c == -1;
  iVar2 = D_0035eb4c;
  if (bVar1) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  return !bVar1;
}
