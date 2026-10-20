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

void func_002ba220(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6)

{
  func_002b7078();
  func_002b7010(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

void func_002ba5d0(u64 param_1,u64 param_2)

{
  func_002baf48(10,1,param_1,param_2,0,0);
  return;
}

void func_002ba948(void)

{
  func_002b70b8(0,0x3000,0xf0);
  func_002b70b8(1,0x3000,0xf0);
  return;
}

void func_002bb070(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  func_002baf48(param_1,3,param_2,param_3,param_4,param_5);
  return;
}

void func_002bc358(u64 param_1,u64 param_2)

{
  s64 lVar1;
  
  lVar1 = func_002bbda0();
  if (lVar1 != 0) {
    func_002bbf68(lVar1,param_2);
    return;
  }
  return;
}

void func_002bd188(u64 param_1,u64 param_2)

{
  func_002b6adc(2);
  func_002b6adc(0,param_2);
  func_002b6ab8();
  return;
}

void func_002bfd48(u32 *param_1,u64 param_2)

{
  s64 lVar1;
  
  func_002be340(param_2);
  while (lVar1 = func_002be4a0(), lVar1 != 0) {
    func_00102448(*param_1,0);
  }
  return;
}

void func_002c0700(void)

{
  u64 uVar1;
  
  uVar1 = func_002c6218();
  func_002c6280(uVar1,1);
  return;
}

void func_002c1c50(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002c1b48();
  uVar1 = func_001c2b58(uVar1);
  func_002c1b60(param_1,uVar1);
  return;
}

void func_002c5460(u64 param_1)

{
  func_00104f58(param_1,1,0,0,0);
  return;
}

void func_002cb160(void)

{
  u64 uVar1;
  
  uVar1 = func_002c6218();
  func_002c6280(uVar1,2);
  return;
}

void func_002d1270(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x150);
  func_002d1550(uVar1,param_1,param_2);
  return;
}

void func_002dc278(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x80a0);
  func_002dc4e0(uVar1,param_1,param_2);
  return;
}

void func_002e0bb0(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0xf0);
  func_002e0d28(uVar1,param_1);
  return;
}

void func_002e1f40(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x140);
  func_002e20d8(uVar1,param_1);
  return;
}
