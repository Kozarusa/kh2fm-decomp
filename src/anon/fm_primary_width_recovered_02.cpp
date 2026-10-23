#include "../common/types.h"

// Preserve original registry aliases.
void func_0023fa90(u32 param_1,u32 param_2) asm("_ZN2Tz7LayFile5allocEPKc");
void func_0028da70(u32 param_1,int param_2) asm("_ZN2Tz6Select11SetSequenceEz");

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
extern "C" u32 func_001d5868(...);
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
extern "C" u32 func_002941a8(...);
extern "C" u32 func_002941d8(...);
extern "C" u32 func_00294288(...);
extern "C" int func_00295158(...);
extern "C" int func_002953c8(...);
extern "C" u32 func_002b7078(...);
extern "C" u32 func_002b726c(...);
extern "C" u32 func_002b72e4(...);
extern "C" u32 func_002b73ac(...);
extern "C" u32 func_002b78ec(...);
extern "C" u32 func_002b7fbc(...);
extern "C" u32 func_002b83b4(...);
extern "C" u32 func_002b9b78(...);
extern "C" u32 func_002b9ed0(...);
extern "C" u32 func_002ba390(...);
extern "C" u32 func_002baa60(...);
extern "C" u32 func_002bb1c8(...);
extern "C" u32 func_002bb310(...);
extern "C" u32 func_002bc158(...);
extern "C" u32 func_002bc398(...);
extern "C" u32 func_002bc3f0(...);
extern "C" u32 func_002bce40(...);
extern "C" u32 func_002bce50(...);
extern "C" s32 func_002be908(...);
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
extern "C" s32 func_003105b0(...);
extern "C" u32 func_00313b80(...);
extern "C" u32 func_003142e0(...);
extern "C" u32 func_00321ce8(...);

void func_001d5960(u32 param_1)

{
  s32 lVar1;
  
  lVar1 = func_001d5868();
  if ((lVar1 == 0) && (lVar1 = func_001d58f0(param_1), lVar1 != 0)) {
    func_001d5800(param_1);
    return;
  }
  return;
}

void func_001e00b0(int param_1)

{
  u32 uVar1;
  s32 lVar2;
  u32 uVar3;
  
  if (*(int *)(param_1 + 0x54) < 0) {
    return;
  }
  lVar2 = func_001dc790(*(u32 *)(param_1 + 0x40));
  if (lVar2 == 0) {
    lVar2 = func_001dcc60(*(u32 *)(param_1 + 0x40));
    if (lVar2 != 0) {
      uVar3 = func_001dc5f8(*(u32 *)(param_1 + 0x40));
      func_002bc398(*(u32 *)(param_1 + 0x54),uVar3);
      return;
    }
    uVar1 = *(u32 *)(param_1 + 0x54);
  }
  else {
    uVar1 = *(u32 *)(param_1 + 0x54);
  }
  func_002bc3f0(uVar1);
  return;
}

void func_0023fa90(u32 param_1,u32 param_2)

{
  u32 uVar1;
  
  uVar1 = func_001708f8(param_2,0xffffffffffffffff);
  func_0023fa08(param_1,uVar1);
  *(u8 *)((int)param_1 + 0x18) = 1;
  return;
}

void func_00253410(u32 param_1,u32 param_2)

{
  u32 uVar1;
  int iVar2;
  
  if (((*(u8 *)((int)param_1 + 0x25) ^ 1) & 1) == 0) {
    iVar2 = func_0014aba8();
    *(u32 *)(iVar2 + 0xfc) = 0;
  }
  func_00258b00(param_1,param_2);
  uVar1 = func_002535d0(8);
  func_00242740(uVar1);
  func_00253180(8,0xffffffffffffffff);
  return;
}

void func_0028da70(u32 param_1,int param_2)

{
  s32 lVar1;
  
  lVar1 = func_00139d78();
  if ((lVar1 != 0) && (*(int *)((int)param_1 + 0x184) != param_2)) {
    func_00138c10(param_1,param_2);
    *(u32 *)((int)param_1 + 0x188) = 0xffffffff;
  }
  return;
}

void func_00299260(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48d8;
  if (lVar1 != 4) {
    uVar2 = 0x48d9;
  }
  func_00276c50(uVar2,0);
  return;
}

void func_002a03a0(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48ec;
  if (lVar1 != 0x18) {
    uVar2 = 0x48ed;
  }
  func_00276c50(uVar2,0);
  return;
}

void func_002a65a0(void)

{
  s32 lVar1;
  u32 uVar2;
  
  lVar1 = func_00287bc0();
  uVar2 = 0x48f8;
  if (lVar1 != 0x25) {
    uVar2 = 0x4b00;
  }
  func_00276c50(uVar2,0);
  return;
}

u32 func_002bc188(u32 param_1,u32 param_2)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb1c8(lVar2,param_1,param_2);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}

void func_002bf978(void)

{
  s32 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_002be908(lVar1), lVar1 != 0) {
    if ((*(u32 *)((int)lVar1 + 0x588) & 0x80000000) != 0) {
      func_002bf8f0(lVar1);
    }
  }
  return;
}

void func_002db7d0(u32 param_1)

{
  u32 uVar1;
  
  func_0016a9a0();
  uVar1 = 0xffffffffffffffff;
  if ((*(u8 *)((int)param_1 + 0x238) & 1) != 0) {
    uVar1 = 0;
  }
  func_002db610(param_1,uVar1);
  return;
}
