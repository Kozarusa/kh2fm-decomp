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

u64 func_00177ba0(u8* param_1)

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

u64 func_00177bf8(u8* param_1)

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

void func_00179e18(u8* param_1)

{
  func_001d6a80(*(u32 *)((int)param_1 + 0xb3c));
  *(u32 *)((int)param_1 + 0xb48) = 0;
  func_00176ec8(param_1);
  return;
}

void func_0017a230(u8* param_1)

{
  func_001bdab0(*(u32 *)((int)param_1 + 0xb44));
  func_001776f8(param_1);
  return;
}

void func_0017dbb8(u8* param_1)

{
  int iVar1;
  
  if (((*(u32 *)((int)param_1 + 0x588) & 0x400000) == 0) &&
     (iVar1 = *(int *)((int)param_1 + 0xb48), iVar1 < 2)) {
    func_0013ddc0(iVar1 + 1,param_1);
  }
  func_001758b0(param_1);
  return;
}

void func_00185050(u8* param_1,u64 param_2)

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

void func_00185da8(u8* param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 0x10) == 0);
  return;
}

void func_00186078(u8* param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 2) == 0);
  return;
}
