#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001a1de0(...);
extern "C" f32 func_00166d10(...);
extern "C" s32 func_00132130(...);
extern "C" s32 func_0013d7e0(...);
extern "C" s32 func_0014e648(...);
extern "C" s32 func_0016c028(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_001320b0(...);
extern "C" u32 func_00132208(...);
extern "C" u32 func_0013a4c8(...);
extern "C" u32 func_0013a7d0(...);
extern "C" u32 func_0013a7e8(...);
extern "C" u32 func_001492c8(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_00155d58(...);
extern "C" u32 func_00155f40(...);
extern "C" u32 func_00166d38(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016b0d0(...);
extern "C" u32 func_0017df58(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_0023aa78(...);
extern "C" u32 func_00242b58(...);
extern "C" u64 func_00102788(...);
extern "C" u64 func_0014ca80(...);
extern "C" u64 func_0015c228(...);
extern "C" u64 func_00167cd0(...);
extern "C" u64 func_0016abf8(...);
extern "C" u64 func_0016d080(...);
extern "C" u64 func_00192cc0(...);
extern "C" void func_001024a8(...);
extern "C" void func_00102818(...);
extern "C" void func_00102c18(...);
extern "C" void func_0011c4b0(...);
extern "C" void func_0011c4e8(...);
extern "C" void func_00138c10(...);
extern "C" void func_00138d60(...);
extern "C" void func_001391c8(...);
extern "C" void func_0013a600(...);
extern "C" void func_0013a6d0(...);
extern "C" void func_0013a9e8(...);
extern "C" void func_0013efe8(...);
extern "C" void func_0013f030(...);
extern "C" void func_0013f608(...);
extern "C" void func_0013f888(...);
extern "C" void func_0013fca8(...);
extern "C" void func_00142940(...);
extern "C" void func_00144450(...);
extern "C" void func_00144908(...);
extern "C" void func_001493b8(...);
extern "C" void func_00149428(...);
extern "C" void func_00149448(...);
extern "C" void func_00149bd0(...);
extern "C" void func_00149de0(...);
extern "C" void func_0014a9a0(...);
extern "C" void func_0014aa80(...);
extern "C" void func_0014ae10(...);
extern "C" void func_0014b5e8(...);
extern "C" void func_0014dd60(...);
extern "C" void func_0014f148(...);
extern "C" void func_0014f1e0(...);
extern "C" void func_0014f220(...);
extern "C" void func_0014f288(...);
extern "C" void func_00150be8(...);
extern "C" void func_00151d48(...);
extern "C" void func_00153c80(...);
extern "C" void func_00154408(...);
extern "C" void func_00154cd0(...);
extern "C" void func_00156408(...);
extern "C" void func_001574a0(...);
extern "C" void func_00159ce0(...);
extern "C" void func_0015a850(...);
extern "C" void func_0015eba8(...);
extern "C" void func_0015edb8(...);
extern "C" void func_001616d8(...);
extern "C" void func_00165968(...);
extern "C" void func_00166618(...);
extern "C" void func_001666a0(...);
extern "C" void func_001666d0(...);
extern "C" void func_001666f0(...);
extern "C" void func_00167658(...);
extern "C" void func_001676b0(...);
extern "C" void func_001678f0(...);
extern "C" void func_00167e00(...);
extern "C" void func_0016cbc8(...);
extern "C" void func_0016cce8(...);
extern "C" void func_001a98e8(...);
extern "C" void func_001a9ae8(...);
extern "C" void func_001b7e68(...);
extern "C" void func_001b7f30(...);
extern "C" void func_001b80d8(...);
extern "C" void func_002362b0(...);
extern "C" void func_00239bf8(...);
extern "C" void func_002bea00(...);
extern "C" void func_002fee78(...);

u64 func_00132180(u64 param_1,s64 param_2)

{
  s64 lVar1;
  
  while ((lVar1 = func_00132208(param_1), lVar1 != 0 &&
         (lVar1 = func_001320b0(param_1), lVar1 != 0x354e4b5f))) {
    lVar1 = func_001320b0(param_1); asm volatile("" ::: "memory");
    if (lVar1 == param_2) {
      return param_1;
    }
    param_1 = func_00132130(param_1); asm volatile("" ::: "memory");
  }
  return 0;
}

void func_0013f648(u32 *param_1)

{
  u32 *puVar1;
  
  func_0013f608(); asm volatile("" ::: "memory");
  puVar1 = param_1 + 0x1c;
  if (puVar1 != param_1 + 0x18) {
    *puVar1 = param_1[0x18];
    param_1[0x1d] = param_1[0x19];
    param_1[0x1e] = param_1[0x1a];
    param_1[0x1f] = param_1[0x1b];
  }
  if (param_1 + 4 != puVar1) {
    param_1[4] = *puVar1;
    param_1[5] = param_1[0x1d];
    param_1[6] = param_1[0x1e];
    param_1[7] = param_1[0x1f];
  }
  puVar1 = param_1 + 0x24;
  if (puVar1 != param_1 + 0x20) {
    *puVar1 = param_1[0x20];
    param_1[0x25] = param_1[0x21];
    param_1[0x26] = param_1[0x22];
    param_1[0x27] = param_1[0x23];
  }
  if (param_1 != puVar1) {
    *param_1 = *puVar1;
    param_1[1] = param_1[0x25];
    param_1[2] = param_1[0x26];
    param_1[3] = param_1[0x27];
  }
  puVar1 = param_1 + 0x2c;
  if (puVar1 != param_1 + 0x28) {
    *puVar1 = param_1[0x28];
    param_1[0x2d] = param_1[0x29];
    param_1[0x2e] = param_1[0x2a];
    param_1[0x2f] = param_1[0x2b];
  }
  if (param_1 + 8 != puVar1) {
    param_1[8] = *puVar1;
    param_1[9] = param_1[0x2d];
    param_1[10] = param_1[0x2e];
    param_1[0xb] = param_1[0x2f];
  }
  return;
}

void func_00149c08(void)

{
  func_0013a600(); asm volatile("" ::: "memory");
  func_0013a4c8(); asm volatile("" ::: "memory");
  func_001493b8(0x348d68); asm volatile("" ::: "memory");
  func_00149428(0x348d68); asm volatile("" ::: "memory");
  return;
}

void func_00149c40(u64 param_1)

{
  u64 uVar1;
  
  func_00149448(0x348d68); asm volatile("" ::: "memory");
  uVar1 = func_001492c8(0x348d68); asm volatile("" ::: "memory");
  func_0015c228(uVar1); asm volatile("" ::: "memory");
  uVar1 = func_001050c8(); asm volatile("" ::: "memory");
  func_0015eba8(0x348d68,uVar1,1,param_1); asm volatile("" ::: "memory");
  return;
}

void func_00149ec0(u64 param_1)

{
  func_0015a850(); asm volatile("" ::: "memory");
  func_00153c80(); asm volatile("" ::: "memory");
  func_0014f148(); asm volatile("" ::: "memory");
  func_0014f220(); asm volatile("" ::: "memory");
  func_0014f1e0(); asm volatile("" ::: "memory");
  func_0014f288(); asm volatile("" ::: "memory");
  func_0015edb8(); asm volatile("" ::: "memory");
  func_00165968(); asm volatile("" ::: "memory");
  func_00149bd0(0x348d68); asm volatile("" ::: "memory");
  func_00149de0(param_1); asm volatile("" ::: "memory");
  return;
}

void func_0014a188(void)

{
  int iVar1;
  
  func_0013a6d0(); asm volatile("" ::: "memory");
  iVar1 = func_00102c18(0,75000,0x14a830); asm volatile("" ::: "memory");
  *(u8 *)(iVar1 + 4) = 0;
  func_0014ae10(); asm volatile("" ::: "memory");
  func_0013a9e8(1); asm volatile("" ::: "memory");
  func_002bea00(); asm volatile("" ::: "memory");
  return;
}

void func_0014aa58(int param_1,u64 param_2,u8 param_3)

{
  *(u32 *)(param_1 + 0xfc) = 3;
  *(u8 *)(param_1 + 0xf4) = param_3;
  func_0014a9a0(); asm volatile("" ::: "memory");
  return;
}

void func_0014b4b0(u64 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5)

{
  func_0014b5e8(param_1,(s64)(int)((param_2 & 0xffff) * 0x10 + 8) |
                       (s64)(int)((param_4 & 0xffff) * 0x10 + 8) << 0x10,
               (s64)(int)((param_3 & 0xffff) * 0x10 + 8) |
               (s64)(int)((param_5 & 0xffff) * 0x10 + 8) << 0x10);
  return;
}

void func_0014b9a8(u32 *param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uStack_20;
  u32 uStack_1c;
  u32 *puStack_18;
  
  puStack_18 = (u32 *)0x0;
  uStack_1c = 0;
  uStack_20 = 0;
  func_001b7e68(&uStack_20,0x20); asm volatile("" ::: "memory");
  iVar1 = 1;
  do {
    iVar1 = iVar1 + -1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *puStack_18 = *param_1;
    puStack_18[1] = uVar2;
    puStack_18[2] = uVar3;
    puStack_18[3] = uVar4;
    param_1 = param_1 + 4;
    puStack_18 = puStack_18 + 4;
  } while (-1 < iVar1);
  func_001b80d8(&uStack_20); asm volatile("" ::: "memory");
  func_001b7f30(&uStack_20); asm volatile("" ::: "memory");
  return;
}

void func_0014cc40(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 int param_5)

{
  int iVar1;
  
  iVar1 = func_001058e8(); asm volatile("" ::: "memory");
  func_0014ca80(*(u32 *)(param_5 * 4 + iVar1 + 0x244c),param_1,param_2,param_3,param_4); asm volatile("" ::: "memory");
  return;
}

void func_0014db78(u64 param_1,u16 param_2,u64 param_3,u16 param_4,
                 u16 param_5,u16 param_6,u32 param_7)

{
  func_001666d0(param_1,param_2,param_3,param_4,param_5); asm volatile("" ::: "memory");
  *(u32 *)((int)param_1 + 0x1d0) = param_7;
  *(u16 *)((int)param_1 + 0x1d4) = param_6;
  return;
}

void func_0014dbc8(int param_1)

{
  func_001666a0(); asm volatile("" ::: "memory");
  *(u8 *)(param_1 + 0x1d9) = 0;
  *(u32 *)(param_1 + 0x1d0) = 0;
  *(u16 *)(param_1 + 0x1d4) = 0;
  *(u8 *)(param_1 + 0x1d6) = 0;
  *(u8 *)(param_1 + 0x1d7) = 0;
  *(u8 *)(param_1 + 0x1d8) = 0;
  return;
}

void func_0014dc08(int param_1)

{
  func_001666a0(); asm volatile("" ::: "memory");
  *(u8 *)(param_1 + 0x1d9) = 0;
  *(u32 *)(param_1 + 0x1d0) = 0;
  *(u16 *)(param_1 + 0x1d4) = 0;
  *(u8 *)(param_1 + 0x1d6) = 0;
  *(u8 *)(param_1 + 0x1d7) = 0;
  *(u8 *)(param_1 + 0x1d8) = 0;
  return;
}

void func_0014dc48(u64 param_1,u16 param_2,u64 param_3,u16 param_4,
                 u16 param_5,u16 param_6,u32 param_7)

{
  int iVar1;
  
  func_001666f0(param_1,param_2,param_3,param_4,param_5); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x1d0) = param_7;
  *(u16 *)(iVar1 + 0x1d4) = param_6;
  *(u8 *)(iVar1 + 0x1d9) = 0;
  *(u8 *)(iVar1 + 0x1d6) = 0;
  *(u8 *)(iVar1 + 0x1d7) = 0;
  *(u8 *)(iVar1 + 0x1d8) = 0;
  return;
}

void func_0014dca8(u64 param_1,u16 param_2,u64 param_3,u16 param_4,
                 u16 param_5,u16 param_6,u32 param_7)

{
  int iVar1;
  
  func_001666f0(param_1,param_2,param_3,param_4,param_5); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x1d0) = param_7;
  *(u16 *)(iVar1 + 0x1d4) = param_6;
  *(u8 *)(iVar1 + 0x1d9) = 0;
  *(u8 *)(iVar1 + 0x1d6) = 0;
  *(u8 *)(iVar1 + 0x1d7) = 0;
  *(u8 *)(iVar1 + 0x1d8) = 0;
  return;
}

void func_0014de30(int param_1,u64 param_2,int param_3)

{
  u16 uVar1;
  int iVar2;
  
  iVar2 = (param_3 << 0x15) >> 0x10;
  func_00166618(param_2,1,iVar2,*(u16 *)(param_1 + 4),*(u16 *)(param_1 + 6) >> 1,0,0); asm volatile("" ::: "memory");
  uVar1 = *(u16 *)(param_1 + 6) >> 1;
  func_00166618((int)param_2 + 0x4e000,1,iVar2,*(u16 *)(param_1 + 4),uVar1,uVar1,1); asm volatile("" ::: "memory");
  return;
}

void func_0014e140(u8 param_1,u8 param_2,u8 param_3)

{
  u64 uVar1;
  
  uVar1 = func_0014e648(0x349f00); asm volatile("" ::: "memory");
  func_0014dd60(uVar1,param_1,param_2,param_3); asm volatile("" ::: "memory");
  return;
}

void func_001514e8(u64 param_1)

{
  func_00138c10((int)param_1 + 0x1f0,3); asm volatile("" ::: "memory");
  func_00138c10((int)param_1 + 0x388,9); asm volatile("" ::: "memory");
  func_00150be8(param_1); asm volatile("" ::: "memory");
  return;
}

void func_001520c0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(int *)(iVar1 + 0xb4c) = *(int *)(iVar1 + 0xb4c) + param_2;
  func_00138c10(iVar1 + 0x30,0x11); asm volatile("" ::: "memory");
  func_00151d48(param_1); asm volatile("" ::: "memory");
  return;
}

void func_00152508(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u32 param_5)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  
  uVar1 = func_0013a7e8(1); asm volatile("" ::: "memory");
  uVar2 = func_0013d7e0(); asm volatile("" ::: "memory");
  func_00138d60(param_1,9000,uVar1,uVar2,param_2,param_4,0xe); asm volatile("" ::: "memory");
  iVar3 = (int)param_1;
  *(u32 *)(iVar3 + 0x174) = param_5;
  *(u32 *)(iVar3 + 0x1a8) = 0xe;
  func_0023aa78(iVar3 + 0x18); asm volatile("" ::: "memory");
  return;
}

void func_00152688(int param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u64 uVar1;
  u8 auStack_a0 [16];
  u8 auStack_90 [96];
  
  uVar1 = func_00192cc0(auStack_a0,0x36b248,*(u32 *)(param_1 + 0x1bc)); asm volatile("" ::: "memory");
  func_001a98e8(auStack_90,1,uVar1,*(u32 *)(param_1 + 0x1a8),0); asm volatile("" ::: "memory");
  func_001a9ae8(auStack_90,param_2,param_3,param_4); asm volatile("" ::: "memory");
  return;
}

void func_00152b50(int param_1)

{
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x20) = *(u32 *)(param_1 + 0x20) | 1;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x25ac) = 0;
  *(u32 *)(param_1 + 0x25b0) = 0;
  *(u32 *)(param_1 + 0x25b4) = 0;
  *(u32 *)(param_1 + 0x25b8) = 0;
  *(u32 *)(param_1 + 0x25b4) = *(u32 *)(param_1 + 0x25b4) | 1;
  *(u32 *)(param_1 + 0x25bc) = 0;
  *(u32 *)(param_1 + 0x2f20) = 0;
  *(u32 *)(param_1 + 0x2f24) = 0;
  *(u32 *)(param_1 + 0x2f28) = 0;
  *(u32 *)(param_1 + 0x2f2c) = 0;
  *(u32 *)(param_1 + 0x2f28) = *(u32 *)(param_1 + 0x2f28) | 1;
  *(u32 *)(param_1 + 0x2f30) = 0;
  func_001391c8(param_1,9000,0); asm volatile("" ::: "memory");
  return;
}

void func_00155658(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  iVar1 = (int)param_1;
  uVar2 = func_00166d38(*(u32 *)(iVar1 + 0x34)); asm volatile("" ::: "memory");
  uVar3 = func_00166d10(*(u32 *)(iVar1 + 0x24),
                       *(u32 *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x48c) + 4));
  func_00154cd0(uVar3,param_1,1); asm volatile("" ::: "memory");
  func_00154cd0(uVar2,param_1,2); asm volatile("" ::: "memory");
  return;
}

void func_00157068(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_00155f40(); asm volatile("" ::: "memory");
  func_00138c10((int)param_1 + 0x2d80,uVar1); asm volatile("" ::: "memory");
  func_00156408(param_1); asm volatile("" ::: "memory");
  return;
}

void func_00157160(u64 param_1)

{
  s64 lVar1;
  
  lVar1 = func_0017df58(0); asm volatile("" ::: "memory");
  if ((lVar1 != 0) && ((*(u32 *)((int)lVar1 + 0x588) & 0x400000) != 0)) {
    func_001574a0(*(u32 *)((int)param_1 + 4)); asm volatile("" ::: "memory");
    func_001024a8(param_1); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_001576e8(u64 param_1)

{
  u64 uVar1;
  int iVar2;
  
  uVar1 = func_00155d58(param_1,0); asm volatile("" ::: "memory");
  iVar2 = (int)param_1;
  func_00138c10(iVar2 + 0x1a30,uVar1); asm volatile("" ::: "memory");
  uVar1 = func_00155d58(param_1,1); asm volatile("" ::: "memory");
  func_00138c10(iVar2 + 0x1bcc,uVar1); asm volatile("" ::: "memory");
  uVar1 = func_00155d58(param_1,2); asm volatile("" ::: "memory");
  func_00138c10(iVar2 + 0x20a0,uVar1); asm volatile("" ::: "memory");
  func_00154408(iVar2 + 0x40,*(u32 *)(iVar2 + 0x18)); asm volatile("" ::: "memory");
  return;
}

void func_00157990(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = **(int **)(*(int *)(param_1 + 0x34) + 0x48c);
  if (iVar1 != iVar2) {
    if (iVar1 < iVar2) {
      *(int *)(param_1 + 0x24) = iVar2;
    }
    else {
      *(int *)(param_1 + 0x24) = iVar1;
    }
    *(int *)(param_1 + 0x28) = iVar2;
    func_00138c10(param_1 + 0x1d68,0x7e); asm volatile("" ::: "memory");
    func_00138c10(param_1 + 0x223c,0x7f); asm volatile("" ::: "memory");
    return;
  }
  return;
}

void func_00157aa0(int param_1)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_001a1de0(*(u32 *)(*(int *)(param_1 + 0x34) + 0x48c)); asm volatile("" ::: "memory");
  uVar2 = 0x75;
  if (lVar1 != 0) {
    uVar2 = 0x6f;
  }
  func_00138c10(param_1 + 10000,uVar2); asm volatile("" ::: "memory");
  return;
}

bool func_001585a0(u64 *param_1)

{
  bool bVar1;
  s64 lVar2;
  
  bVar1 = (*param_1 & 0x100000000) != 0;
  lVar2 = func_00242b58(); asm volatile("" ::: "memory");
  if (lVar2 == 0) {
    bVar1 = !bVar1;
  }
  return bVar1;
}

void func_0015a528(u64 param_1)

{
  int iVar1;
  u32 *puVar2;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  iVar1 = (int)param_1;
  puVar2 = (u32 *)(iVar1 + 0x80);
  uStack_40 = *puVar2;
  uStack_3c = *(u32 *)(iVar1 + 0x84);
  uStack_38 = *(u32 *)(iVar1 + 0x88);
  uStack_34 = *(u32 *)(iVar1 + 0x8c);
  func_00159ce0(param_1,&uStack_30); asm volatile("" ::: "memory");
  func_0013f888(param_1,&uStack_30,0); asm volatile("" ::: "memory");
  if (puVar2 != &uStack_30) {
    *puVar2 = uStack_30;
    *(u32 *)(iVar1 + 0x84) = uStack_2c;
    *(u32 *)(iVar1 + 0x88) = uStack_28;
    *(u32 *)(iVar1 + 0x8c) = uStack_24;
  }
  func_0013fca8(param_1); asm volatile("" ::: "memory");
  if (puVar2 != &uStack_40) {
    *puVar2 = uStack_40;
    *(u32 *)(iVar1 + 0x84) = uStack_3c;
    *(u32 *)(iVar1 + 0x88) = uStack_38;
    *(u32 *)(iVar1 + 0x8c) = uStack_34;
  }
  return;
}

void func_0015aa98(u32 param_1,u64 param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  
  func_001391c8(param_2,11000,0); asm volatile("" ::: "memory");
  iVar1 = (int)param_2;
  *(u32 *)(iVar1 + 0x20) = param_4;
  *(u32 *)(iVar1 + 0x18) = param_3;
  *(u32 *)(iVar1 + 0x1c) = param_1;
  return;
}

int func_0015b4f8(int param_1,u64 param_2,u32 *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char acStack_30 [16];
  
  func_002fee78(acStack_30,0x36b3c0,param_2); asm volatile("" ::: "memory");
  iVar1 = 0;
  iVar2 = 0;
  do {
    pcVar3 = acStack_30 + iVar2;
    iVar2 = iVar2 + 1;
    if (*pcVar3 == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    *param_3 = *(u32 *)((*pcVar3 + -0x30) * 4 + param_1);
    param_3 = param_3 + 1;
  } while (iVar2 < 0x10);
  return iVar1;
}

void func_0015d540(void)

{
  u64 uVar1;
  int iVar2;
  
  func_0013efe8(); asm volatile("" ::: "memory");
  iVar2 = func_00102c80(); asm volatile("" ::: "memory");
  func_00102818(*(u32 *)(iVar2 + 4),0,120000,0x15d4e8,0x1000); asm volatile("" ::: "memory");
  uVar1 = func_0013a7d0(2); asm volatile("" ::: "memory");
  func_002362b0(0x34af40,uVar1); asm volatile("" ::: "memory");
  uVar1 = func_0013a7e8(2); asm volatile("" ::: "memory");
  func_00239988(0x34b0e0,uVar1,0x34af40); asm volatile("" ::: "memory");
  func_00239bf8(0x34b0e0,1); asm volatile("" ::: "memory");
  return;
}

void func_0015d690(void)

{
  u64 uVar1;
  int iVar2;
  
  func_0013f030(); asm volatile("" ::: "memory");
  iVar2 = func_00102c80(); asm volatile("" ::: "memory");
  func_00102788(*(u32 *)(iVar2 + 4),1,120000,0x15d5d0); asm volatile("" ::: "memory");
  uVar1 = func_0014aba8(); asm volatile("" ::: "memory");
  func_0014aa80(uVar1,1,0); asm volatile("" ::: "memory");
  uVar1 = func_0013a7d0(2); asm volatile("" ::: "memory");
  func_002362b0(0x34af40,uVar1); asm volatile("" ::: "memory");
  uVar1 = func_0013a7e8(2); asm volatile("" ::: "memory");
  func_00239988(0x34b0e0,uVar1,0x34af40); asm volatile("" ::: "memory");
  func_00239bf8(0x34b0e0,0); asm volatile("" ::: "memory");
  return;
}

void func_001608c0(int param_1)

{
  int iVar1;
  s64 lVar2;
  float fVar3;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  func_00144908(param_1 + 0x290,&uStack_20); asm volatile("" ::: "memory");
  if ((u32 *)(param_1 + 0x280) != &uStack_20) {
    *(u32 *)(param_1 + 0x280) = uStack_20;
    *(u32 *)(param_1 + 0x284) = uStack_1c;
    *(u32 *)(param_1 + 0x288) = uStack_18;
    *(u32 *)(param_1 + 0x28c) = uStack_14;
  }
  lVar2 = func_0016b0d0(); asm volatile("" ::: "memory");
  if (lVar2 != 0) {
    iVar1 = func_0016c028(lVar2); asm volatile("" ::: "memory");
    fVar3 = *(float *)(iVar1 + 4);
    if ((*(float *)(param_1 + 0x294) <= fVar3) && (fVar3 <= *(float *)(param_1 + 0x2a0))) {
      *(float *)(param_1 + 0x284) = fVar3;
    }
  }
  return;
}

void func_001614e8(u64 param_1,u32 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x44) = param_2;
  *(u32 *)(iVar1 + 0x40) = 0;
  *(u32 *)(iVar1 + 0x48) = 0;
  *(u32 *)(iVar1 + 0x4c) = 0;
  *(u32 *)(iVar1 + 0x50) = 0;
  func_00144450(iVar1 + 0x54); asm volatile("" ::: "memory");
  func_001616d8(param_1); asm volatile("" ::: "memory");
  return;
}

u32 func_00161548(int param_1,s64 param_2)

{
  u32 uVar1;
  s64 lVar2;
  
  uVar1 = 0;
  if (-1 < param_2) {
    if (*(int *)(param_1 + 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      lVar2 = func_00168b38(*(int *)(param_1 + 0x40),9,param_2); asm volatile("" ::: "memory");
      uVar1 = 0;
      if (lVar2 != 0) {
        uVar1 = *(u32 *)((int)lVar2 + 8);
      }
    }
  }
  return uVar1;
}

void func_00161598(int param_1)

{
  if (*(int *)(param_1 + 0x48) != 0) {
    func_0011c4e8(*(u32 *)(param_1 + 0x4c)); asm volatile("" ::: "memory");
    return;
  }
  func_0011c4b0(*(u32 *)(*(int *)(param_1 + 0x44) + 0x1c0),*(int *)(param_1 + 0x44) + 0x200,0)
  ;
  return;
}

void func_00165830(int param_1,u32 *param_2)

{
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_50 = *param_2;
  uStack_4c = param_2[1];
  uStack_48 = param_2[2];
  uStack_44 = param_2[3];
  uStack_40 = param_2[4];
  uStack_3c = param_2[5];
  uStack_38 = param_2[6];
  uStack_34 = param_2[7];
  uStack_30 = param_2[8];
  uStack_2c = param_2[9];
  uStack_28 = param_2[10];
  uStack_24 = param_2[0xb];
  uStack_20 = param_2[0xc];
  uStack_1c = param_2[0xd];
  uStack_18 = param_2[0xe];
  uStack_14 = param_2[0xf];
  func_00142940(*(u32 *)(param_1 + 4),&uStack_50); asm volatile("" ::: "memory");
  return;
}

void func_00166808(u64 param_1,u8 param_2,u16 param_3,u64 param_4,
                 u16 param_5,u16 param_6,u16 param_7,u16 param_8)

{
  int iVar1;
  
  func_001666f0(param_1,param_3,param_4,param_5,param_6); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u8 *)(iVar1 + 0xe) = param_2;
  *(u16 *)(iVar1 + 10) = param_7;
  *(u16 *)(iVar1 + 0xc) = param_8;
  return;
}

void func_00166880(u64 param_1,u8 param_2,u16 param_3,u64 param_4,
                 u16 param_5,u16 param_6,u16 param_7,u16 param_8)

{
  int iVar1;
  
  func_001666f0(param_1,param_3,param_4,param_5,param_6); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u8 *)(iVar1 + 0xe) = param_2;
  *(u16 *)(iVar1 + 10) = param_7;
  *(u16 *)(iVar1 + 0xc) = param_8;
  return;
}

void func_001668f8(int param_1)

{
  func_001666a0(); asm volatile("" ::: "memory");
  *(u16 *)(param_1 + 10) = 0;
  *(u8 *)(param_1 + 0xe) = 1;
  *(u16 *)(param_1 + 0xc) = 0;
  return;
}

void func_00166930(int param_1)

{
  func_001666a0(); asm volatile("" ::: "memory");
  *(u16 *)(param_1 + 10) = 0;
  *(u8 *)(param_1 + 0xe) = 1;
  *(u16 *)(param_1 + 0xc) = 0;
  return;
}

void func_00166968(u64 param_1,u8 param_2,u16 param_3,u64 param_4,
                 u16 param_5,u16 param_6,u16 param_7,u16 param_8)

{
  int iVar1;
  
  func_001666d0(param_1,param_3,param_4,param_5,param_6); asm volatile("" ::: "memory");
  iVar1 = (int)param_1;
  *(u16 *)(iVar1 + 0xc) = param_8;
  *(u8 *)(iVar1 + 0xe) = param_2;
  *(u16 *)(iVar1 + 10) = param_7;
  return;
}

void func_00167b60(void)

{
  func_001678f0(0x34d3c0); asm volatile("" ::: "memory");
  func_001678f0(0x34d540); asm volatile("" ::: "memory");
  return;
}

void func_00167d68(u64 param_1)

{
  u64 uVar1;
  u64 *puVar2;
  u32 uVar3;
  
  puVar2 = (u64 *)param_1;
  if ((*(u32 *)(puVar2 + 9) & 1) == 0) {
    uVar1 = func_00167cd0(); asm volatile("" ::: "memory");
    if ((*(u32 *)(puVar2 + 9) & 2) != 0) {
      *puVar2 = uVar1;
    }
    func_001676b0(param_1,uVar1); asm volatile("" ::: "memory");
    if (*(int *)(*(int *)((int)puVar2 + 0x44) + 0x48) == 1) {
      *(u32 *)(puVar2 + 9) = *(u32 *)(puVar2 + 9) & 0xfffffffd;
      return;
    }
    uVar3 = *(u32 *)(puVar2 + 9);
  }
  else {
    func_00167658(param_1,0); asm volatile("" ::: "memory");
    uVar3 = *(u32 *)(puVar2 + 9);
  }
  *(u32 *)(puVar2 + 9) = uVar3 | 2;
  return;
}

void func_00167e28(u64 param_1)

{
  u64 uVar1;
  u64 *puVar2;
  
  puVar2 = (u64 *)param_1;
  *(u32 *)(puVar2 + 9) = *(u32 *)(puVar2 + 9) & 0xfffffffe;
  func_00167658(param_1,0); asm volatile("" ::: "memory");
  uVar1 = func_00167cd0(param_1); asm volatile("" ::: "memory");
  *puVar2 = uVar1;
  return;
}

void func_00167ea8(void)

{
  func_00167e00(0x34d6c0); asm volatile("" ::: "memory");
  func_00167e00(0x34d720); asm volatile("" ::: "memory");
  return;
}

void func_0016a158(u64 param_1,u64 param_2)

{
  u64 uVar1;
  int iVar2;
  int aiStack_20 [4];
  
  uVar1 = func_0016d080(param_2,param_1); asm volatile("" ::: "memory");
  iVar2 = (int)param_1;
  *(int *)(iVar2 + 0x484) = (int)uVar1;
  aiStack_20[0] = iVar2;
  func_0016cce8(uVar1,0,aiStack_20,1,0); asm volatile("" ::: "memory");
  func_0016cbc8(*(u32 *)(iVar2 + 0x484),1,0,0); asm volatile("" ::: "memory");
  return;
}

s64 func_0016ac80(u64 param_1,u64 param_2,s64 param_3,u64 param_4,
                 u64 param_5)

{
  u32 *puVar1;
  s64 lVar2;
  s64 lVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 *puVar7;
  
  lVar2 = func_0016abf8(param_1,param_2,param_4,param_5); asm volatile("" ::: "memory");
  if ((lVar2 != 0) && (lVar3 = func_001dc5f8(lVar2), lVar3 != param_3)) {
    puVar7 = (u32 *)param_3;
    uVar4 = puVar7[1];
    uVar5 = puVar7[2];
    uVar6 = puVar7[3];
    puVar1 = (u32 *)lVar3;
    *puVar1 = *puVar7;
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
    puVar1[3] = uVar6;
  }
  return lVar2;
}
