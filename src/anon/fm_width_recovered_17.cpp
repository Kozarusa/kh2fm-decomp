#include "../common/types.h"

// Preserve original registry aliases.
void func_002ee778(u32 param_1) asm("_ZN4menu4Mode5startEv");
void func_002f0c58(int *param_1) asm("_ZN2kn42trap_peterpan_receive_notify_player_targetEP8BD_VALUE");
void func_002f0e60(int *param_1) asm("_ZN2kn28trap_friend_get_action_paramEP8BD_VALUE");

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0030edb0(...);
extern "C" bool func_0030ee00(...);
extern "C" s32 func_00102210(...);
extern "C" s32 func_0010fa28(...);
extern "C" s32 func_0010fa58(...);
extern "C" s32 func_003071d0(...);
extern "C" s32 func_00308dc0(...);
extern "C" s32 func_0030a8f8(...);
extern "C" s32 func_0030ab88(...);
extern "C" s32 func_00305168(...);
extern "C" u32 func_00102080(...);
extern "C" u32 func_001031b0(...);
extern "C" u32 func_00105c30(...);
extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00110500(...);
extern "C" u32 func_00110618(...);
extern "C" u32 func_00114438(...);
extern "C" u32 func_0011a408(...);
extern "C" u32 func_0011a938(...);
extern "C" u32 func_0011cdf0(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c430(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_0017f5f8(...);
extern "C" u32 func_00180c88(...);
extern "C" u32 func_0018a008(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_0019bc38(...);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_0023a918(...);
extern "C" u32 func_0023cc18(...);
extern "C" u32 func_002bc1e8(...);
extern "C" u32 func_002e95a0(...);
extern "C" u32 func_002e9610(...);
extern "C" u32 func_002eaf40(...);
extern "C" u32 func_002ee730(...);
extern "C" u32 func_002ee840(...);
extern "C" u32 func_002ef618(...);
extern "C" u32 func_002f25a0(...);
extern "C" u32 func_002f3c28(...);
extern "C" u32 func_002f3f88(...);
extern "C" u32 func_002f40a0(...);
extern "C" u32 func_002f4148(...);
extern "C" u32 func_002f41f0(...);
extern "C" u32 func_002fd220(...);
extern "C" u32 func_002feac0(...);
extern "C" u32 func_003032d0(...);
extern "C" u32 func_00305110(...);
extern "C" u32 func_00306e80(...);
extern "C" u32 func_003080d0(...);
extern "C" u32 func_0030af40(...);
extern "C" u32 func_0030f468(...);
extern "C" u32 func_0030ffd8(...);
extern "C" u32 func_00316d08(...);

void func_002eb4b0(u32 param_1)

{
  func_0017c430();
  *(u32 *)((int)param_1 + 0x100) = 0x100;
  *(u32 *)((int)param_1 + 0x104) = 0x101;
  func_0016bd60(param_1,0x31);
  return;
}

void func_002ed508(u32 param_1,int param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  int iVar1;
  
  func_001c1748(param_1,*(u32 *)(param_2 + 0x9f4),param_4,param_5);
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x50) = param_3;
  func_00190128(iVar1 + 100);
  *(u32 *)(iVar1 + 0x78) = 0;
  return;
}

void func_002ed558(u32 param_1,int param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  int iVar1;
  
  func_001c1748(param_1,*(u32 *)(param_2 + 0x9f4),param_4,param_5);
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x50) = param_3;
  func_00190128(iVar1 + 100);
  *(u32 *)(iVar1 + 0x78) = 0;
  return;
}

void func_002ee778(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_00102210();
  *(u32 *)((int)param_1 + 0x2c) = uVar1;
  func_00102080(param_1);
  iVar2 = func_002ee840();
  uVar1 = func_001031b0();
  *(u32 *)(iVar2 + 4) = uVar1;
  return;
}

void func_002f0c58(int *param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  iVar2 = func_0011a408(uVar1);
  *param_1 = iVar2;
  return;
}

void func_002f0e60(int *param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_0010c7e8(*(u32 *)(*param_1 + 4));
  iVar2 = func_00114438(uVar1,param_1[1]);
  *param_1 = iVar2;
  return;
}
