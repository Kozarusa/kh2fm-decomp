#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00112ab8(...);
extern "C" u64 func_00114580(...);
extern "C" u64 func_001382b8(...);
extern "C" u64 func_0013ddc0(...);
extern "C" u64 func_00140db0(...);
extern "C" u64 func_00153e28(...);
extern "C" u64 func_00158920(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016a070(...);
extern "C" u64 func_0016ae58(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c028(...);
extern "C" u64 func_0016c460(...);
extern "C" u64 func_0016cc18(...);
extern "C" u64 func_0016ced0(...);
extern "C" u64 func_0016e920(...);
extern "C" u64 func_0016f7d0(...);
extern "C" u64 func_00170518(...);
extern "C" u64 func_001708f8(...);
extern "C" u64 func_001758b0(...);
extern "C" u64 func_00175af8(...);
extern "C" u64 func_001762f8(...);
extern "C" u64 func_00176a90(...);
extern "C" u64 func_00176ec8(...);
extern "C" u64 func_00177498(...);
extern "C" u64 func_001776f8(...);
extern "C" u64 func_00177860(...);
extern "C" u64 func_00177a38(...);
extern "C" u64 func_001781a8(...);
extern "C" u64 func_00179f10(...);
extern "C" u64 func_0017c430(...);
extern "C" u64 func_0017c4c8(...);
extern "C" f32 func_0017ce10(...);
extern "C" u64 func_0017dcc0(...);
extern "C" u64 func_0017df70(...);
extern "C" u64 func_0017e310(...);
extern "C" u64 func_0017ee68(...);
extern "C" u64 func_0017f268(...);
extern "C" u64 func_0017f380(...);
extern "C" u64 func_00180ce0(...);
extern "C" u64 func_00181a70(...);
extern "C" u64 func_00182f28(...);
extern "C" u64 func_00183768(...);
extern "C" u64 func_00184780(...);
extern "C" u64 func_001860b0(...);
extern "C" u64 func_00186378(...);
extern "C" u64 func_001863a8(...);
extern "C" u64 func_00186740(...);
extern "C" u64 func_00187018(...);
extern "C" u64 func_00187e20(...);
extern "C" u64 func_00187e58(...);
extern "C" u64 func_001880b0(...);
extern "C" u64 func_00188398(...);
extern "C" u64 func_001883d8(...);
extern "C" u64 func_00189068(...);
extern "C" f32 func_0018a970(...);
extern "C" u64 func_0018c480(...);
extern "C" u64 func_0018c490(...);
extern "C" u64 func_0018c8b8(...);
extern "C" u64 func_0018c960(...);
extern "C" u64 func_0018ee10(...);
extern "C" u64 func_00190128(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_001902a8(...);
extern "C" u64 func_001903d0(...);
extern "C" u64 func_00190878(...);
extern "C" u64 func_00190f80(...);
extern "C" u64 func_00191f78(...);
extern "C" u64 func_001921d8(...);
extern "C" u64 func_00192800(...);
extern "C" u64 func_00192868(...);
extern "C" u64 func_001940f0(...);
extern "C" u64 func_00194108(...);
extern "C" u64 func_00198630(...);
extern "C" u64 func_00199468(...);
extern "C" u64 func_0019c400(...);
extern "C" u64 func_0019c5d0(...);
extern "C" u64 func_0019ca90(...);
extern "C" u64 func_0019d358(...);
extern "C" u64 func_001a2438(...);
extern "C" u64 func_001a4550(...);
extern "C" u64 func_001a49a0(...);
extern "C" u64 func_001a4d40(...);
extern "C" u64 func_001a5880(...);
extern "C" u64 func_001a6a20(...);
extern "C" u64 func_001a8258(...);
extern "C" u64 func_001a8418(...);
extern "C" u64 func_001a8510(...);
extern "C" u64 func_001a8bd0(...);
extern "C" u64 func_001a90a8(...);
extern "C" u64 func_001a97b8(...);
extern "C" u64 func_001ad990(...);
extern "C" u64 func_001afee8(...);
extern "C" u64 func_001b1bb8(...);
extern "C" u64 func_001b50e0(...);
extern "C" u64 func_001b58f0(...);
extern "C" u64 func_001b6bd8(...);
extern "C" u64 func_001b7818(...);
extern "C" u64 func_001b9bc8(...);
extern "C" u64 func_001bdab0(...);
extern "C" u64 func_001c1b08(...);
extern "C" u64 func_001d14a0(...);
extern "C" u64 func_001d69d0(...);
extern "C" u64 func_001d6a80(...);
extern "C" u64 func_001d6ab0(...);
extern "C" u64 func_001d6ae0(...);
extern "C" u64 func_001d6b40(...);
extern "C" u64 func_001dc5f8(...);
extern "C" u64 func_001de168(...);
extern "C" u64 func_002cd1d8(...);
extern "C" u64 func_002cd290(...);
extern "C" u64 func_002fd248(...);

void func_00174060(int *param_1)

{
  func_00199468(param_1[1],*(u32 *)(*param_1 + 4),param_1[2],param_1[3]);
  return;
}

void func_00174168(int *param_1)

{
  func_00183768(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_001741e0(u32 *param_1)

{
  u64 uVar1;
  
  uVar1 = func_001d14a0();
  func_001b6bd8(uVar1,*param_1);
  return;
}

void func_00174290(int *param_1)

{
  u32 uVar1;
  int iVar2;
  u8 auStack_40 [32];
  
  uVar1 = *(u32 *)(param_1[2] + 4);
  func_00190128(auStack_40);
  func_00190878(auStack_40,uVar1,0);
  iVar2 = *(int *)(*param_1 + 4);
  func_001d6ab0(*(u32 *)(iVar2 + 0xb3c));
  func_0019ca90(*(u32 *)(iVar2 + 0xb40),param_1[1],auStack_40);
  return;
}

void func_00174518(int *param_1)

{
  int iVar1;
  
  iVar1 = func_00184780(*(u32 *)(param_1[1] + 0xc),param_1[2],param_1[3],
                       *(u32 *)(*param_1 + 4));
  *param_1 = iVar1;
  return;
}

void func_00174728(int *param_1)

{
  func_001ad990(param_1[1],param_1[2],param_1[3],*(int *)(*param_1 + 4) + 0x8c8);
  return;
}

void func_00174858(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001de168(*param_1,param_1[1],param_1[3],1,param_1[4],*(u32 *)(param_1[2] + 4));
  *param_1 = uVar1;
  return;
}

void func_00174af8(u32 *param_1)

{
  func_001b1bb8(param_1[4],*param_1,param_1[1],param_1[2],param_1[3],0x80);
  return;
}

void func_00174e10(int *param_1)

{
  u32 *puVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  puVar1 = (u32 *)*param_1;
  uStack_20 = *puVar1;
  uStack_1c = puVar1[1];
  uStack_18 = puVar1[2];
  uStack_14 = puVar1[3];
  func_00158920(&uStack_20);
  return;
}

void func_00175108(u32 *param_1)

{
  func_001a2438(*param_1,param_1[1],param_1[2]);
  return;
}

void func_00175328(u32 *param_1)

{
  func_001a5880(*param_1,param_1[1],param_1[2]);
  return;
}

void func_00175480(u32 *param_1)

{
  func_00153e28(param_1[1],param_1[2],*param_1);
  return;
}

void func_001754d0(u32 *param_1)

{
  u64 uVar1;
  
  uVar1 = func_001a8258(*param_1);
  func_001a8418(uVar1);
  uVar1 = func_001a8510();
  func_001382b8(uVar1);
  return;
}

u32 func_00176258(int param_1)

{
  int iVar1;
  s64 lVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_1 + 0xaf8);
  iVar4 = 0;
  iVar1 = *piVar3;
  while ((piVar3 = piVar3 + 1, iVar1 == 0 || (lVar2 = func_0019c5d0(iVar1), lVar2 != 0))) {
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return 0;
    }
    iVar1 = *piVar3;
  }
  return 1;
}

void func_00176d68(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_0016a070();
  uVar1 = func_001afee8(uVar1,param_2);
  func_00198630(param_1,uVar1,0);
  return;
}

void func_00177460(int param_1,u32 param_2)

{
  func_00177498();
  *(u32 *)(param_1 + 0xaec) = param_2;
  return;
}

void func_001775f8(u64 param_1)

{
  func_001940f0(param_1,2);
  func_001940f0(param_1,0xc);
  func_001940f0(param_1,0x16);
  return;
}

void func_00177638(u64 param_1)

{
  func_00194108(param_1,2);
  func_00194108(param_1,0xc);
  func_00194108(param_1,0x16);
  return;
}

void func_00177a78(int param_1)

{
  func_00177a38();
  if (*(u8 *)(param_1 + 0xb05) < 100) {
    *(u8 *)(param_1 + 0xb05) = *(u8 *)(param_1 + 0xb05) + 1;
  }
  return;
}

u64 func_00177ba0(u64 param_1)

{
  u8 bVar1;
  int iVar2;
  u64 uVar3;
  
  bVar1 = *(u8 *)((int)param_1 + 0xb04);
  iVar2 = func_00177860();
  if ((s64)(u64)bVar1 < (s64)*(char *)(iVar2 + 0x2c)) {
    uVar3 = (u64)*(u8 *)((int)param_1 + 0xb04);
  }
  else {
    iVar2 = func_00177860(param_1);
    uVar3 = (u64)*(char *)(iVar2 + 0x2c);
  }
  return uVar3;
}

u64 func_00177bf8(u64 param_1)

{
  u8 bVar1;
  int iVar2;
  u64 uVar3;
  
  bVar1 = *(u8 *)((int)param_1 + 0xb04);
  iVar2 = func_00177860();
  if ((s64)(u64)bVar1 < (s64)*(char *)(iVar2 + 0x2d)) {
    uVar3 = (u64)*(u8 *)((int)param_1 + 0xb04);
  }
  else {
    iVar2 = func_00177860(param_1);
    uVar3 = (u64)*(char *)(iVar2 + 0x2d);
  }
  return uVar3;
}

void func_001781e8(int param_1)

{
  func_00140db0();
  func_00182f28(0);
  func_001d69d0(*(u32 *)(param_1 + 0xb3c));
  *(u32 *)(param_1 + 0xb3c) = 0;
  return;
}

u32 func_00179b68(u64 param_1)

{
  int iVar1;
  s64 lVar2;
  
  iVar1 = func_001a6a20(0x10002,0xc);
  if ((*(int *)(iVar1 + 4) == 0) && (lVar2 = func_00176a90(param_1), lVar2 == 0)) {
    return 0;
  }
  return 1;
}

u32 func_00179c80(int param_1)

{
  u32 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0xb50) == 7) &&
     ((*(int *)(param_1 + 0x154) == 0xcb || (*(int *)(param_1 + 0x154) == 0xcc)))) {
    uVar1 = 1;
  }
  return uVar1;
}

void func_00179e18(u64 param_1)

{
  func_001d6a80(*(u32 *)((int)param_1 + 0xb3c));
  *(u32 *)((int)param_1 + 0xb48) = 0;
  func_00176ec8(param_1);
  return;
}

void func_00179f58(u64 param_1)

{
  func_00179f10();
  func_001781a8(param_1);
  return;
}

void func_0017a1c8(int param_1,u64 param_2)

{
  *(u32 *)(param_1 + 0x10c) = *(u32 *)(param_1 + 0x10c) & 0xfffffffd;
  func_001762f8();
  func_00112ab8(0,param_2);
  return;
}

void func_0017a230(u64 param_1)

{
  func_001bdab0(*(u32 *)((int)param_1 + 0xb44));
  func_001776f8(param_1);
  return;
}

void func_0017a418(int param_1,s64 param_2)

{
  if (param_2 == 1) {
    func_001d6ae0(*(u32 *)(param_1 + 0xb3c));
    *(u8 *)(param_1 + 0xb64) = 1;
  }
  else if (param_2 == 2) {
    func_001d6b40(*(u32 *)(param_1 + 0xb3c));
    *(u8 *)(param_1 + 0xb64) = 2;
  }
  else {
    *(char *)(param_1 + 0xb64) = (char)param_2;
  }
  return;
}

bool func_0017a538(int param_1)

{
  s64 lVar1;
  bool bVar2;
  
  lVar1 = func_0016a070();
  bVar2 = false;
  if (lVar1 == 1) {
    bVar2 = *(int *)(param_1 + 0xb50) != 0 && *(int *)(param_1 + 0xb50) < 7;
  }
  return bVar2;
}

void func_0017a600(u64 param_1)

{
  s64 lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  iVar3 = iVar2 + 0x9f4;
  lVar1 = func_00190140(iVar3);
  if (lVar1 == 0) {
    func_00190f80(0,iVar3,param_1);
    lVar1 = func_00190140(iVar3);
    if (lVar1 != 0) {
      func_0019ca90(*(u32 *)(iVar2 + 0xb40),1,iVar3);
      func_0019d358(*(u32 *)(iVar2 + 0xb40));
      return;
    }
  }
  return;
}

void func_0017a8f8(u64 param_1,u64 param_2,u32 *param_3)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_3;
  uStack_1c = param_3[1];
  uStack_18 = param_3[2];
  uStack_14 = param_3[3];
  func_0017c4c8(param_2,&uStack_20);
  func_0016bd60(param_2,1);
  return;
}

void func_0017a938(u64 param_1,u64 param_2)

{
  func_0017c430(param_2);
  func_0016bd60(param_2,1);
  return;
}

u32 * func_0017c030(u32 *param_1,u64 param_2,u64 param_3,char param_4)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  
  iVar4 = (int)param_2;
  if (param_1 != (u32 *)(iVar4 + 0x10)) {
    uVar1 = *(u32 *)(iVar4 + 0x14);
    uVar2 = *(u32 *)(iVar4 + 0x18);
    uVar3 = *(u32 *)(iVar4 + 0x1c);
    *param_1 = *(u32 *)(iVar4 + 0x10);
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
  }
  uVar1 = func_0016c460(param_2,param_3);
  param_1[1] = uVar1;
  if (param_4 != '\0') {
    *(u32 *)(iVar4 + 0x108) = *(u32 *)(iVar4 + 0x108) | 0x10000;
  }
  return param_1;
}

void func_0017ce80(float param_1,float param_2,float param_3)

{
  float fVar1;
  
  param_2 = param_2 - param_1;
  fVar1 = (float)func_0017ce10(param_2);
  if (fVar1 < -param_3) {
    param_1 = param_1 - param_3;
  }
  else {
    fVar1 = (float)func_0017ce10(param_2);
    if (param_3 < fVar1) {
      param_1 = param_1 + param_3;
    }
    else {
      fVar1 = (float)func_0017ce10(param_2);
      param_1 = param_1 + fVar1;
    }
  }
  func_0017ce10(param_1);
  return;
}

int func_0017d930(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 1;
  if (0 < param_1) {
    do {
      iVar2 = iVar2 * 10;
      iVar1 = iVar1 + 1;
    } while (iVar2 <= param_1);
  }
  return iVar1;
}

void func_0017dbb8(u64 param_1)

{
  int iVar1;
  
  if (((*(u32 *)((int)param_1 + 0x588) & 0x400000) == 0) &&
     (iVar1 = *(int *)((int)param_1 + 0xb48), iVar1 < 2)) {
    func_0013ddc0(iVar1 + 1,param_1);
  }
  func_001758b0(param_1);
  return;
}

void func_0017dc98(u64 param_1)

{
  func_0017dcc0();
  func_00175af8(param_1);
  return;
}

s64 func_0017dfc8(void)

{
  s64 lVar1;
  u64 uVar2;
  u64 uVar3;
  
  lVar1 = func_0017df70();
  if (((lVar1 != 0) && (uVar2 = func_0016e920(lVar1), *(short *)((int)uVar2 + 0x4c) == 8)) &&
     (uVar3 = func_0016f7d0(lVar1,uVar2), uVar3 < 2)) {
    lVar1 = 0x81d;
  }
  return lVar1;
}

bool func_0017e358(u64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  u64 uVar3;
  bool bVar4;
  
  bVar4 = false;
  lVar1 = func_0017e310();
  if (lVar1 != 0) {
    uVar2 = func_001a8bd0(0xffffffffffffffff);
    uVar3 = func_0016a070(param_1);
    lVar1 = func_001a90a8(uVar2,uVar3);
    bVar4 = lVar1 == 0;
  }
  return bVar4;
}

void func_0017eb68(u64 param_1)

{
  func_00180ce0();
  func_0017ee68(param_1);
  return;
}

void func_0017eb98(u64 param_1)

{
  func_00180ce0();
  func_0017ee68(param_1);
  return;
}

s64 func_0017edf0(int *param_1,s64 param_2)

{
  s64 lVar1;
  
  if ((param_2 < 0) || (*param_1 == 0)) {
    lVar1 = 0;
  }
  else if ((param_1[1] == 0) || (lVar1 = func_001a97b8(param_1[1]), lVar1 == 0)) {
    lVar1 = func_001a97b8(*param_1,param_2);
    return lVar1;
  }
  return lVar1;
}

int func_0017f3d8(u32 param_1,u32 param_2,int param_3,u32 param_4,
                u32 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_3 + 0x3c);
  iVar2 = iVar1 + 1;
  iVar3 = iVar1 + 4;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  iVar1 = param_3 + 0x3c + iVar1 * 0x14;
  *(int *)(param_3 + 0x3c) = iVar2 + (iVar3 >> 2) * -4;
  *(u32 *)(iVar1 + 0xc) = param_1;
  *(u32 *)(iVar1 + 0x10) = param_2;
  *(u32 *)(iVar1 + 0x14) = param_5;
  *(u32 *)(iVar1 + 8) = param_4;
  *(u32 *)(iVar1 + 0x18) = 0;
  return iVar1 + 8;
}

void func_0017f488(u32 param_1,u32 param_2,u64 param_3,u64 param_4)

{
  func_0017f380();
  func_0017f268(param_1,param_2,param_3,param_4);
  return;
}

u32 func_00180408(u64 param_1,s64 param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = func_00168b38(param_2,9,0);
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(u32 *)((int)lVar2 + 8);
    }
  }
  return uVar1;
}

void func_001805e8(int param_1)

{
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x20) = *(u32 *)(param_1 + 0x20) & 0x7183;
  *(u32 *)(param_1 + 0x24) = *(u32 *)(param_1 + 0x24) & 0xfffffffc;
  return;
}

void func_00180d40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = -1;
  iVar3 = 0;
  piVar4 = (int *)(param_1 + 0x14c);
  iVar1 = *piVar4;
  while( true ) {
    piVar4 = piVar4 + 1;
    if (iVar1 < 0) {
      iVar2 = iVar3;
    }
    if (iVar1 == param_2) break;
    iVar3 = iVar3 + 1;
    if (0xf < iVar3) {
      *(int *)(iVar2 * 4 + param_1 + 0x14c) = param_2;
      return;
    }
    iVar1 = *piVar4;
  }
  return;
}

u32 func_00180dc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x14c);
  iVar2 = 0;
  iVar3 = *piVar1;
  while( true ) {
    piVar1 = piVar1 + 1;
    if (iVar3 == param_2) {
      return 1;
    }
    iVar2 = iVar2 + 1;
    if (0xf < iVar2) break;
    iVar3 = *piVar1;
  }
  return 0;
}

void func_00180ef0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x18c);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x2c);
    }
    if (iVar1 == 0) break;
    *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 0x2000000;
  }
  *(u32 *)(param_1 + 0x18c) = 0;
  *(u32 *)(param_1 + 400) = 0;
  return;
}

void func_001814b8(u32 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)(((int)param_1 >> 10) * 0x20 + 0x32d7c0 + ((param_1 & 0x3ff) >> 5) * 4);
  *puVar1 = *puVar1 & ~(1 << (param_1 & 0x1f));
  return;
}

bool func_00181500(s64 param_1)

{
  bool bVar1;
  u32 uVar2;
  
  uVar2 = (u32)param_1;
  bVar1 = false;
  if (param_1 != 0xffff) {
    bVar1 = (*(u32 *)(((uVar2 & 0x3ff) >> 5) * 4 + ((int)uVar2 >> 10) * 0x20 + 0x32d7c0) &
            1 << (uVar2 & 0x1f)) != 0;
  }
  return bVar1;
}

void func_00182838(u32 *param_1,u32 param_2,u32 param_3,char param_4)

{
  *param_1 = param_2;
  param_1[1] = 1;
  param_1[2] = param_3;
  if (param_4 != '\0') {
    param_1[1] = 3;
  }
  return;
}

void func_001835a0(float param_1,u64 param_2)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  
  lVar1 = func_0019c400();
  if (lVar1 == 0) {
    iVar2 = (int)param_2;
    func_0016ae58(*(float *)(iVar2 + 0x55c) + param_1,param_2);
    uVar3 = func_0017ce10(*(float *)(iVar2 + 0x66c) + param_1);
    *(u32 *)(iVar2 + 0x66c) = uVar3;
  }
  return;
}

void func_00185050(u64 param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)((int)param_1 + 0x508);
  if (iVar1 == 0) {
    uVar2 = func_002cd1d8();
    *(u32 *)((int)param_1 + 0x508) = uVar2;
    return;
  }
  func_002cd290(iVar1,param_1,param_2);
  return;
}

void func_00185da8(s64 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 0x10) == 0);
  return;
}

void func_00186078(s64 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 2) == 0);
  return;
}

void func_00186948(u64 param_1,int param_2)

{
  u64 uVar1;
  
  uVar1 = func_001860b0();
  func_001c1b08(param_1,*(u32 *)(param_2 + 0x1c),uVar1);
  return;
}

bool func_00186ce8(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(int *)(param_1 + 0x140) != 0) && (9 < *(int *)(param_1 + 0x154))) {
    bVar1 = *(int *)(param_1 + 0x154) < 0x28;
  }
  return bVar1;
}

bool func_00186d18(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(int *)(param_1 + 0x140) != 0) && (0x8b < *(int *)(param_1 + 0x154))) {
    bVar1 = *(int *)(param_1 + 0x154) < 0x97;
  }
  return bVar1;
}

void func_00187b90(u64 param_1)

{
  int iVar1;
  u32 auStack_20 [4];
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x94) != 0) {
    auStack_20[0] = *(u32 *)(iVar1 + 0x88);
    func_00188398(param_1,*(u16 *)(*(int *)(iVar1 + 0x90) + 10),auStack_20,1);
    func_0016ced0(*(u32 *)(iVar1 + 0x94));
    *(u32 *)(iVar1 + 0x90) = 0;
    *(u32 *)(iVar1 + 0x94) = 0;
  }
  return;
}

u64 func_00188340(int param_1,int param_2,u32 *param_3,u64 param_4)

{
  u64 uVar1;
  u32 auStack_20 [4];
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x90) != 0) && ((*(u32 *)(param_1 + 0x9c) & 4) == 0)) {
    if (param_3 == (u32 *)0x0) {
      auStack_20[0] = *(u32 *)(param_1 + 0x88);
      param_4 = 1;
      param_3 = auStack_20;
    }
    uVar1 = func_00188398(param_1,*(u16 *)(param_2 * 2 + *(int *)(param_1 + 0x90) + 10),
                         param_3,param_4);
  }
  return uVar1;
}

u32 func_00188758(u64 param_1)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  
  iVar2 = (int)param_1;
  uVar3 = 0;
  if ((*(int *)(iVar2 + 0x8c) != 0) && (uVar3 = 0, (*(u32 *)(iVar2 + 0x9c) & 1) == 0)) {
    lVar1 = func_00187e20();
    uVar3 = 0;
    if (lVar1 == 0) {
      if (*(int *)(iVar2 + 0x98) < 300) {
        lVar1 = func_00187e58(param_1);
        uVar3 = 0;
        if (lVar1 == 0) {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

void func_001888c8(int param_1)

{
  int iVar1;
  u16 *puVar2;
  
  *(u8 *)(param_1 + 9) = 0;
  *(u8 *)(param_1 + 7) = 100;
  *(u8 *)(param_1 + 0x11) = 1;
  puVar2 = (u16 *)(param_1 + 0x54);
  *(u8 *)(param_1 + 4) = 100;
  iVar1 = 0x4f;
  *(u8 *)(param_1 + 5) = 100;
  *(u8 *)(param_1 + 6) = 100;
  *(u8 *)(param_1 + 10) = 0;
  *(u8 *)(param_1 + 0xb) = 0;
  *(u8 *)(param_1 + 0xc) = 0;
  *(u8 *)(param_1 + 0xd) = 0;
  *(u8 *)(param_1 + 0xe) = 0;
  *(u8 *)(param_1 + 0xf) = 1;
  *(u8 *)(param_1 + 0x10) = 1;
  *(u8 *)(param_1 + 0x12) = 0;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  func_00114580(param_1 + 0xf4);
  return;
}

void func_00188b68(int param_1,u16 param_2,char param_3)

{
  int iVar1;
  
  param_1 = param_1 + 0x50;
  iVar1 = 0;
  do {
    if ((*(u16 *)(param_1 + 4) & 0x7fff) == 0) {
      *(u16 *)(param_1 + 4) = param_2 & 0x7fff | (u16)(param_3 != '\0') << 0xf;
      return;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 2;
  } while (iVar1 < 0x50);
  return;
}

int func_00188fe0(int param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_001b7818(param_2);
  if (lVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + (int)lVar2 * 0x114 + -0x114;
  }
  return iVar1;
}

void func_001890a8(u64 param_1,u64 param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  lVar2 = func_00181a70();
  if (lVar2 != 0) {
    lVar2 = func_00189068(param_1,param_2);
    if ((lVar2 != 0) && (uVar1 = *(u32 *)lVar2, uVar1 < 9999)) {
      *(u32 *)lVar2 = uVar1 + 1;
    }
  }
  return;
}

void func_001891b8(int param_1,u16 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((*(u16 *)(param_1 + 8) & 0x7fff) == 0) {
      *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) & 0x8000 | param_2 & 0x7fff | 0x8000;
      return;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 2;
  } while (iVar1 < 0x18);
  return;
}

void func_00189228(int param_1,int param_2)

{
  u16 uVar1;
  
  param_1 = param_2 * 2 + param_1;
  uVar1 = *(u16 *)(param_1 + 0x1458);
  if (uVar1 < 999) {
    *(u16 *)(param_1 + 0x1458) = uVar1 + 1;
  }
  return;
}

void func_0018b200(int param_1)

{
  s64 lVar1;
  
  if ((*(char *)(*(int *)(param_1 + 8) + 4) == '\x0f') &&
     (lVar1 = func_001883d8(param_1 + 0x300,0x36cbb0), lVar1 != 0)) {
    func_001880b0(param_1 + 0x300,0x36cbb0);
    return;
  }
  return;
}

s64 func_0018bbf8(int param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = 0;
  if (*(char *)(param_1 + 0xa70) == '\0') {
    uVar2 = func_0016c028();
    lVar1 = func_0018c490(param_1 + 0xa40,uVar2);
    if (lVar1 != 0) {
      func_0018c480(param_1 + 0xa40,1);
    }
  }
  return lVar1;
}

u64 func_0018c8f0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u64 uVar1;
  
  uVar1 = func_0018c8b8();
  func_0018c960(uVar1,param_1,param_2,param_3,param_4);
  return uVar1;
}

u64 func_0018d808(u64 param_1,int param_2)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 *puVar5;
  
  puVar1 = (u32 *)func_0016c028(*(u32 *)(param_2 + 8));
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  puVar5 = (u32 *)param_1;
  *puVar5 = *puVar1;
  puVar5[1] = uVar2;
  puVar5[2] = uVar3;
  puVar5[3] = uVar4;
  return param_1;
}

u32 func_0018dbd8(int param_1)

{
  u32 uVar1;
  bool bVar2;
  
  uVar1 = *(u32 *)(param_1 + 4);
  if ((uVar1 & 2) == 0) {
    if (((uVar1 & 8) != 0) || (bVar2 = false, (uVar1 & 0x10) != 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      return 1;
    }
    if ((uVar1 & 0x200) == 0) {
      return 0;
    }
  }
  return 1;
}

void func_0018e0d8(int param_1,u32 param_2)

{
  if (param_2 == 3) {
    param_2 = 4;
  }
  *(char *)(param_1 + 0x2c) = (char)param_2;
  *(u8 *)(param_1 + 0x2d) = ~((u8)(1 << (param_2 & 0x1f)) | 1);
  return;
}

void func_0018ef68(u32 *param_1,u64 param_2,u64 param_3)

{
  func_0016cc18(*param_1,param_1[1],param_2,param_3,0);
  return;
}

void func_0018ef98(int param_1,u32 param_2)

{
  s64 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_0018ee10(lVar1), lVar1 != 0) {
    if (*(int *)((int)lVar1 + 0xc) == param_1) {
      *(u32 *)((int)lVar1 + 0xc) = param_2;
    }
  }
  return;
}

void func_0018f248(int *param_1)

{
  func_00186740(param_1[4],param_1[5],*(u32 *)(*param_1 + 4),param_1[1],param_1[2],param_1[3])
  ;
  return;
}

void func_0018f2a8(int *param_1)

{
  func_001863a8(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_0018f2d0(int *param_1)

{
  func_00186378(param_1[2],*(u32 *)(*param_1 + 4),param_1[1]);
  return;
}

void func_0018f858(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001a4550(*param_1,param_1[1]);
  *param_1 = uVar1;
  return;
}

void func_0018f9b8(u32 *param_1)

{
  func_001a4d40(param_1[3],param_1[4],*param_1,param_1[1],param_1[2]);
  return;
}

void func_0018fb70(u32 *param_1)

{
  func_001a49a0(*param_1,param_1[1],param_1[2]);
  return;
}

void func_0018fd10(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001a6a20(*param_1,param_1[1]);
  *param_1 = uVar1;
  return;
}

void func_0018fd40(u32 *param_1)

{
  func_00187018(param_1[4],*param_1,param_1[1],param_1[2],param_1[3]);
  return;
}

void func_0018fde0(u32 *param_1)

{
  func_001b50e0(param_1[2],*param_1,param_1[1],param_1[3] != 0);
  return;
}

void func_0018fe48(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001b58f0(*param_1,param_1[1],param_1[2],0);
  *param_1 = uVar1;
  return;
}

void func_0018fe80(u32 *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  s64 lVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  lVar3 = func_001b58f0(*param_1,param_1[1],param_1[3],0);
  if (lVar3 != 0) {
    puVar2 = (u32 *)func_001dc5f8(lVar3);
    puVar1 = (u32 *)param_1[2];
    if (puVar2 == puVar1) {
      *param_1 = (int)lVar3;
      return;
    }
    uVar4 = puVar1[1];
    uVar5 = puVar1[2];
    uVar6 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar4;
    puVar2[2] = uVar5;
    puVar2[3] = uVar6;
  }
  *param_1 = (int)lVar3;
  return;
}

void func_0018fee8(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = func_001b58f0(*param_1,param_1[1],param_1[3],*(u32 *)(param_1[2] + 4));
  *param_1 = uVar1;
  return;
}

u64 func_00190388(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  func_001902a8(param_2,auStack_40);
  puVar1 = (u32 *)param_1;
  *puVar1 = uStack_30;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1[3] = uStack_24;
  return param_1;
}

u64 func_001904a8(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_34 = 0;
  func_001903d0(param_2,auStack_40);
  puVar1 = (u32 *)param_1;
  *puVar1 = uStack_30;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1[3] = uStack_24;
  return param_1;
}

void func_001906f0(u64 param_1,u32 *param_2)

{
  u8 auStack_40 [12];
  u32 uStack_34;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_34 = 0;
  func_001902a8(param_1,auStack_40);
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0018a970(auStack_40);
  return;
}

int func_00191f20(int param_1,u64 param_2)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_002fd248(param_2 & 0xffffffffffff7fff,param_1 + 8,*(u32 *)(param_1 + 4),8,
                       0x31eec8);
  iVar2 = 0;
  if (lVar1 != 0) {
    iVar2 = param_1 + *(int *)((int)lVar1 + 4);
  }
  return iVar2;
}

void func_00192260(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001921d8();
  func_00170518(uVar1,param_2,0);
  return;
}

void func_00192290(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001921d8();
  uVar1 = func_001708f8(uVar1,0xffffffffffffffff);
  func_00191f78(param_2,uVar1);
  return;
}

int func_00192450(int param_1,int param_2)

{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  
  bVar1 = *(u8 *)(param_1 + param_2);
  uVar3 = bVar1 - 0x19;
  iVar2 = bVar1 - 0x20;
  if (bVar1 < 0x20) {
    if ((uVar3 & 0xff) < 7) {
      return uVar3 * 0x100 + (u32)*(u8 *)(param_2 + param_1 + 1) + 0xe0;
    }
    iVar2 = -1;
  }
  return iVar2;
}

void func_00192818(u64 param_1,u64 param_2,u32 *param_3)

{
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_1c = param_3[5];
  uStack_2c = param_3[1];
  uStack_28 = param_3[2];
  uStack_24 = param_3[3];
  uStack_20 = param_3[4];
  uStack_30 = *param_3;
  func_00192800(param_1,param_2,&uStack_30);
  return;
}

void func_00192940(u64 param_1,u64 param_2,u32 *param_3)

{
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_1c = param_3[5];
  uStack_2c = param_3[1];
  uStack_28 = param_3[2];
  uStack_24 = param_3[3];
  uStack_20 = param_3[4];
  uStack_30 = *param_3;
  func_00192868(param_1,param_2,&uStack_30);
  return;
}

void func_001940b8(u32 param_1,u32 param_2,int param_3,u8 param_4,
                 u8 param_5,u8 param_6)

{
  *(u8 *)(param_3 + 0x680) = param_4;
  *(u8 *)(param_3 + 0x681) = param_5;
  *(u8 *)(param_3 + 0x682) = param_6;
  func_001ad990(*(u32 *)(param_3 + 0x8c0),param_1,param_2,param_3 + 0x8c0);
  return;
}
