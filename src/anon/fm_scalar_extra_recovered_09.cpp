#include "../common/types.h"

// Preserve original registry aliases.
void func_002ed438(void) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");
void func_002f0708(int *param_1) asm("_ZN2kn15trap_empty_funcEP8BD_VALUE");
void func_002f08d8(int *param_1) asm("_ZN2kn22trap_genie_change_formEP8BD_VALUE");
void func_002f09d8(int *param_1) asm("_ZN2kn23trap_stitch_shot_effectEP8BD_VALUE");
void func_002f0a68(int *param_1) asm("_ZN2kn23trap_stitch_effect_killEP8BD_VALUE");
void func_002f0da8(int *param_1) asm("_ZN2kn31trap_friend_get_player_attackerEP8BD_VALUE");
void func_002f1130(int *param_1) asm("_ZN2kn29trap_btlobj_is_reflect_motionEP8BD_VALUE");
void func_002f1230(int *param_1) asm("_ZN2kn35trap_chickenlittle_set_shoot_targetEP8BD_VALUE");

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102080(...);
extern "C" u64 func_00102210(...);
extern "C" u64 func_001031b0(...);
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00105c30(...);
extern "C" u64 func_00106450(...);
extern "C" u64 func_0010c7b0(...);
extern "C" u64 func_0010c7e8(...);
extern "C" u64 func_0010fa28(...);
extern "C" u64 func_0010fa58(...);
extern "C" u64 func_00110500(...);
extern "C" u64 func_00110618(...);
extern "C" u64 func_00114438(...);
extern "C" u64 func_00117808(...);
extern "C" u64 func_00117aa8(...);
extern "C" u64 func_00118d10(...);
extern "C" u64 func_00119830(...);
extern "C" u64 func_00119e60(...);
extern "C" u64 func_0011a408(...);
extern "C" u64 func_0011a918(...);
extern "C" u64 func_0011a938(...);
extern "C" u64 func_0011cdf0(...);
extern "C" u64 func_00136158(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c568(...);
extern "C" u64 func_0016e920(...);
extern "C" u64 func_00176fb0(...);
extern "C" u64 func_00177008(...);
extern "C" u64 func_0017c030(...);
extern "C" u64 func_0017c430(...);
extern "C" u64 func_0017c4c8(...);
extern "C" u64 func_0017f488(...);
extern "C" u64 func_0017f5e0(...);
extern "C" u64 func_0017f5f8(...);
extern "C" u64 func_00180c88(...);
extern "C" u64 func_0018a008(...);
extern "C" u64 func_00190128(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_001906f0(...);
extern "C" u64 func_0019bc38(...);
extern "C" u64 func_001b2210(...);
extern "C" u64 func_001b8228(...);
extern "C" u64 func_001b8258(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_0023a918(...);
extern "C" u64 func_0023cc18(...);
extern "C" u64 func_002bc1e8(...);
extern "C" u64 func_002e7670(...);
extern "C" u64 func_002e76b0(...);
extern "C" u64 func_002e77a8(...);
extern "C" u64 func_002e95a0(...);
extern "C" u64 func_002e9610(...);
extern "C" u64 func_002e9cb8(...);
extern "C" u64 func_002e9d08(...);
extern "C" u64 func_002e9fe0(...);
extern "C" u64 func_002eac70(...);
extern "C" u64 func_002eaf40(...);
extern "C" u64 func_002eb990(...);
extern "C" u64 func_002ed300(...);
extern "C" u64 func_002ee730(...);
extern "C" u64 func_002ee840(...);
extern "C" u64 func_002ef618(...);
extern "C" u64 func_002ef7b8(...);
extern "C" u64 func_002efa98(...);
extern "C" u64 func_002efb08(...);
extern "C" u64 func_002f25a0(...);
extern "C" u64 func_002f3500(...);
extern "C" u64 func_002f3c28(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002f40a0(...);
extern "C" u64 func_002f4148(...);
extern "C" u64 func_002f41f0(...);
extern "C" u64 func_002ff014(...);
extern "C" u64 func_002ffbb0(...);
extern "C" u64 func_002ffd78(...);
extern "C" u64 func_003032d0(...);
extern "C" u64 func_00305110(...);
extern "C" u64 func_00305168(...);
extern "C" u64 func_00306e48(...);
extern "C" u64 func_00306e80(...);
extern "C" u64 func_003071d0(...);
extern "C" u64 func_003080d0(...);
extern "C" u64 func_00308780(...);
extern "C" u64 func_00308dc0(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_0030f468(...);
extern "C" u64 func_0030ffd8(...);
extern "C" u64 func_00310090(...);
extern "C" u64 func_00310180(...);
extern "C" u64 func_00310230(...);
extern "C" u64 func_00310330(...);
extern "C" u64 func_00316d08(...);

void func_002eaaf0(u64 param_1)

{
  func_0017c430();
  func_0016bd60(param_1,0x2c);
  return;
}

void func_002ed438(void)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar1 = func_001050d8(0xa00);
  uVar2 = func_0016e920(0x5c3);
  func_002ed300(uVar1,uVar2,0x100);
  return;
}

void func_002ef7c8(void)

{
  s64 lVar1;
  
  lVar1 = func_002ef7b8();
  if (lVar1 != 0) {
    func_001b8228();
    return;
  }
  func_001b8258();
  return;
}

void func_002efb60(u64 param_1)

{
  func_002efb08();
  func_002efa98(param_1);
  return;
}

void func_002f05d8(u64 param_1)

{
  func_0017c430();
  func_0016bd60(param_1,0x3f);
  return;
}

void func_002f0708(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00117808(uVar1,param_1[1]);
  return;
}

void func_002f08d8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00119e60(uVar1,param_1[1]);
  return;
}

void func_002f09d8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00119830(uVar1,param_1[1]);
  return;
}

void func_002f0a68(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00117aa8(uVar1,param_1[1]);
  return;
}

void func_002f0da8(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_00118d10(uVar1,param_1[1]);
  return;
}

void func_002f1130(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7b0(*(u32 *)(*param_1 + 4));
  func_00136158(uVar1,param_1[1]);
  return;
}

void func_002f1230(int *param_1)

{
  u64 uVar1;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  func_0011a918(uVar1,param_1[1]);
  return;
}

u32 func_002fd220(u64 param_1)

{
  u32 uVar1;
  
  uVar1 = func_002ffbb0(param_1,0,10);
  return uVar1;
}
