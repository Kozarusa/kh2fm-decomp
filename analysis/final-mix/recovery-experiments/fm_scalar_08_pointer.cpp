#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102448(...);
extern "C" u64 func_00104f58(...);
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00105110(...);
extern "C" u64 func_00106a18(...);
extern "C" u64 func_00106a60(...);
extern "C" u64 func_00106f30(...);
extern "C" u64 func_00107368(...);
extern "C" u64 func_00107478(...);
extern "C" u64 func_00108398(...);
extern "C" u64 func_00138c10(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016ac38(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c028(...);
extern "C" u64 func_001780d8(...);
extern "C" u64 func_00178888(...);
extern "C" u64 func_00179b68(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00184540(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_00198450(...);
extern "C" u64 func_001b6d70(...);
extern "C" u64 func_001b9bc8(...);
extern "C" u64 func_001bc778(...);
extern "C" u64 func_001bc780(...);
extern "C" u64 func_001c2b58(...);
extern "C" u64 func_001c3748(...);
extern "C" u64 func_001c3888(...);
extern "C" u64 func_001dc818(...);
extern "C" u64 func_002b6708(...);
extern "C" u64 func_002b6ab8(...);
extern "C" u64 func_002b6adc(...);
extern "C" u64 func_002b6e24(...);
extern "C" u64 func_002b6f28(...);
extern "C" u64 func_002b7010(...);
extern "C" u64 func_002b7078(...);
extern "C" u64 func_002b70b8(...);
extern "C" u64 func_002ba3e8(...);
extern "C" u64 func_002baa08(...);
extern "C" u64 func_002baa60(...);
extern "C" u64 func_002baa78(...);
extern "C" u64 func_002baf48(...);
extern "C" u64 func_002bb100(...);
extern "C" u64 func_002bb5a8(...);
extern "C" u64 func_002bb9b8(...);
extern "C" u64 func_002bbbc8(...);
extern "C" u64 func_002bbc90(...);
extern "C" u64 func_002bbda0(...);
extern "C" u64 func_002bbf68(...);
extern "C" u64 func_002bc0f0(...);
extern "C" u64 func_002bc188(...);
extern "C" u64 func_002bc470(...);
extern "C" u64 func_002bc608(...);
extern "C" u64 func_002bc988(...);
extern "C" u64 func_002bc9a8(...);
extern "C" u64 func_002bce10(...);
extern "C" u64 func_002bcfe8(...);
extern "C" u64 func_002bd030(...);
extern "C" u64 func_002bd078(...);
extern "C" u64 func_002bd0b8(...);
extern "C" u64 func_002bd100(...);
extern "C" u64 func_002bd140(...);
extern "C" u64 func_002be340(...);
extern "C" u64 func_002be4a0(...);
extern "C" u64 func_002bf650(...);
extern "C" u64 func_002c04c8(...);
extern "C" u64 func_002c1b48(...);
extern "C" u64 func_002c1b60(...);
extern "C" u64 func_002c6218(...);
extern "C" u64 func_002c6280(...);
extern "C" u64 func_002c6490(...);
extern "C" u64 func_002c6c60(...);
extern "C" u64 func_002c7060(...);
extern "C" u64 func_002cb890(...);
extern "C" u64 func_002cc620(...);
extern "C" u64 func_002cd428(...);
extern "C" u64 func_002cd878(...);
extern "C" u64 func_002cf2d0(...);
extern "C" u64 func_002d10a0(...);
extern "C" u64 func_002d1550(...);
extern "C" u64 func_002d24e8(...);
extern "C" u64 func_002dc4e0(...);
extern "C" u64 func_002dc7c8(...);
extern "C" u64 func_002e0d28(...);
extern "C" u64 func_002e20d8(...);
extern "C" u64 func_002e34d8(...);
extern "C" u64 func_002fee78(...);
extern "C" u64 func_002ff3fc(...);
extern "C" u64 func_00325320(...);

s64 func_002be908(u8* param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return 0;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 0x40000000) == 0);
  return param_1;
}

u64 func_002bec38(u64 param_1,u64 param_2,u8* param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_3 + 300);
  func_00184540(*(u32 *)(iVar1 + 0x28),*(u32 *)(iVar1 + 0x2c),param_1,param_3);
  return param_1;
}

void func_002bf5a0(u8* param_1)

{
  int iVar1;
  
  iVar1 = func_001b6d70(*(u8 *)(*(int *)((int)param_1 + 0xaf8) + 4));
  if (((*(u8 *)((int)param_1 + 0xae7) & 1) == 0) && ((*(u8 *)(iVar1 + 3) & 1) != 0)) {
    func_0016ac38(param_1,0,1,0,0);
    return;
  }
  return;
}

void func_002bf618(u8* param_1)

{
  u64 uVar1;
  
  uVar1 = func_001b6d70(*(u8 *)(*(int *)((int)param_1 + 0xaf8) + 4));
  func_002bf650(param_1,uVar1);
  return;
}

void func_002c1860(u64 param_1,u8* param_2)

{
  func_002c7060((int)param_2 + 0xb70);
  if (0.0 < *(float *)((int)param_2 + 0xbc4)) {
    return;
  }
  func_0016bd60(param_2,0x2f);
  return;
}

void func_002c1ae8(u8* param_1)

{
  u64 uVar1;
  int iVar2;
  
  iVar2 = func_002c1b48();
  *(int *)((int)param_1 + 0xae4) = iVar2 * 3 + 0x375515;
  uVar1 = func_002c1b48(param_1);
  uVar1 = func_001c2b58(uVar1);
  func_002c1b60(param_1,uVar1);
  func_00198450(param_1);
  return;
}

void func_002c58c8(u8* param_1)

{
  func_001780d8();
  func_0016bd60(param_1,0x2f);
  func_002c6c60(param_1,*(u32 *)((int)param_1 + 0xb38));
  return;
}

void func_002c5900(u8* param_1)

{
  s64 lVar1;
  u32 uVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)param_1 + 0xb44) + 0x4ac;
  func_001bc778(iVar3);
  lVar1 = func_00190140(*(int *)((int)param_1 + 0xb40) + 4);
  uVar2 = 0x246;
  if (lVar1 == 0) {
    uVar2 = 0x247;
  }
  iVar3 = func_001bc780(iVar3,uVar2,0,1);
  *(u8 *)(iVar3 + 6) = 4;
  func_00178888(param_1);
  return;
}

void func_002cb708(u8* param_1)

{
  func_00105110(*(u32 *)((int)param_1 + 0x80));
  func_00325320(0x1e2be18,param_1);
  return;
}
