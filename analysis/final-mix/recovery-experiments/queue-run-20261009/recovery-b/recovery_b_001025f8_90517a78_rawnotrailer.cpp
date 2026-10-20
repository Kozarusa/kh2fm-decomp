#include "../common/types.h"
extern "C" void func_001022e8(u64);
void func_001025f8(int param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  if (param_2 == *(int *)(param_1 + 0x110)) {
    if (param_2 == 0) {
      uVar2 = *(u32 *)(param_1 + 8);
    }
    else {
      uVar2 = *(u32 *)(param_2 + 0x38);
    }
    *(u32 *)(param_1 + 0x110) = uVar2;
    iVar1 = *(int *)(param_2 + 0x3c);
  }
  else {
    iVar1 = *(int *)(param_2 + 0x3c);
  }
  if (iVar1 == 0) {
    *(u32 *)(param_1 + 8) = *(u32 *)(param_2 + 0x38);
  }
  else {
    *(u32 *)(iVar1 + 0x38) = *(u32 *)(param_2 + 0x38);
  }
  if (*(int *)(param_2 + 0x38) == 0) {
    *(u32 *)(param_1 + 0xc) = *(u32 *)(param_2 + 0x3c);
  }
  else {
    *(u32 *)(*(int *)(param_2 + 0x38) + 0x3c) = *(u32 *)(param_2 + 0x3c);
  }
  *(u32 *)(param_2 + 0x3c) = 0;
  *(u32 *)(param_2 + 0x38) = 0;
  func_001022e8(param_2);
  return;
}
