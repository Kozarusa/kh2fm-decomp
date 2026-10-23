#include "../common/types.h"

// Preserve original registry aliases.
void func_002ba2e8(u64 param_1,u64 param_2) asm("_ZN5SOUND12systemSePlayEii");

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_001058e8(...);
extern "C" u32 func_001064a8(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_001390f0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_0016a9a0(...);
extern "C" u32 func_001708f8(...);
extern "C" u32 func_00170950(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0018a958(...);
extern "C" u32 func_00192048(...);
extern "C" int func_001b9bc8(...);
extern "C" u32 func_001d5800(...);
extern "C" u64 func_001d5868(...);
extern "C" bool func_001d58f0(...);
extern "C" u32 func_001d7980(...);
extern "C" u8 func_001dc018(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_001dc790(...);
extern "C" u32 func_001dc920(...);
extern "C" bool func_001dc9e0(...);
extern "C" bool func_001dcc60(...);
extern "C" u32 func_001e0058(...);
extern "C" u32 func_00229d40(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_002368e8(...);
extern "C" u32 func_0023fa08(...);
extern "C" u32 func_00242740(...);
extern "C" u32 func_00242b58(...);
extern "C" u32 func_00242b88(...);
extern "C" u32 func_00242bd0(...);
extern "C" u32 func_00253180(...);
extern "C" u32 func_002535d0(...);
extern "C" u32 func_002537c8(...);
extern "C" u32 func_00258b00(...);
extern "C" u32 func_002637e8(...);
extern "C" u32 func_00276568(...);
extern "C" u32 func_002766d0(...);
extern "C" u32 func_00276c50(...);
extern "C" u32 func_00280ef8(...);
extern "C" u32 func_00281008(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00288ce0(...);
extern "C" int func_0028c198(...);
extern "C" u32 func_0028e438(...);
extern "C" u32 func_00294000(...);
extern "C" u64 func_002941a8(...);
extern "C" u64 func_002941d8(...);
extern "C" u32 func_00294288(...);
extern "C" int func_00295158(...);
extern "C" int func_002953c8(...);
extern "C" u64 func_002b7078(...);
extern "C" u64 func_002b726c(...);
extern "C" u64 func_002b72e4(...);
extern "C" u64 func_002b73ac(...);
extern "C" u64 func_002b78ec(...);
extern "C" u64 func_002b7fbc(...);
extern "C" u64 func_002b83b4(...);
extern "C" u32 func_002b9b78(...);
extern "C" u32 func_002b9ed0(...);
extern "C" u32 func_002ba390(...);
extern "C" u32 func_002baa60(...);
extern "C" u32 func_002bb1c8(...);
extern "C" u32 func_002bb310(...);
extern "C" u64 func_002bc158(...);
extern "C" u32 func_002bc398(...);
extern "C" u32 func_002bc3f0(...);
extern "C" u32 func_002bce40(...);
extern "C" u32 func_002bce50(...);
extern "C" s64 func_002be908(...);
extern "C" u32 func_002bf8f0(...);
extern "C" u32 func_002c1cb0(...);
extern "C" u32 func_002d0bd8(...);
extern "C" u32 func_002db610(...);
extern "C" u32 func_002eb6f8(...);
extern "C" u32 func_002f3490(...);
extern "C" u32 func_002f3588(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00306f30(...);
extern "C" int func_003071d0(...);
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s64 func_003105b0(...);
extern "C" u32 func_00313b80(...);
extern "C" u32 func_003142e0(...);
extern "C" u32 func_00321ce8(...);

void func_001de450(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x60);
    func_00321ce8(param_1 + 0xc,iVar2);
    func_001dc920(*(u32 *)(iVar2 + 0x40));
    func_001e0058(iVar2);
    iVar2 = iVar1;
  }
  return;
}

void func_00229d68(u64 param_1)

{
  func_00229d40();
  func_001390f0(param_1);
  return;
}

void func_00242088(int param_1)

{
  u32 uVar1;
  u32 *puVar2;
  int iVar3;
  
  iVar3 = 0xff;
  puVar2 = *(u32 **)(param_1 + 4);
  do {
    iVar3 = iVar3 + -1;
    uVar1 = func_001064a8(0xffffffffffffffff);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar3);
  return;
}

void func_002810c8(u64 param_1,u64 param_2)

{
  func_00281008();
  func_00280ef8(param_1,param_2);
  return;
}

void func_002ba2e8(u64 param_1,u64 param_2)

{
  func_002b726c(2,param_1,param_2,0x3fff,0x40);
  return;
}

void func_002ba330(u64 param_1,u64 param_2,u64 param_3)

{
  func_002b73ac(2,param_1,param_3,0xffffffffffffffff,param_2);
  return;
}

void func_002ba8a8(void)

{
  func_002b7078(0);
  func_002b7078(1);
  func_002b72e4(0xffffffffffffff9c,0xffffffffffffffff,0);
  func_002baa60();
  func_002b83b4();
  return;
}
