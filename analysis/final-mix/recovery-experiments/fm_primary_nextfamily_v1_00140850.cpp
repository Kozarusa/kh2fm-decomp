#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.

void func_00140850(int param_1)

{
  if ((u32 *)(param_1 + 0x90) != (u32 *)(param_1 + 0x80)) {
    *(u32 *)(param_1 + 0x90) = *(u32 *)(param_1 + 0x80);
    *(u32 *)(param_1 + 0x94) = *(u32 *)(param_1 + 0x84);
    *(u32 *)(param_1 + 0x98) = *(u32 *)(param_1 + 0x88);
    *(u32 *)(param_1 + 0x9c) = *(u32 *)(param_1 + 0x8c);
  }
  if ((u32 *)(param_1 + 0x70) != (u32 *)(param_1 + 0x60)) {
    *(u32 *)(param_1 + 0x70) = *(u32 *)(param_1 + 0x60);
    *(u32 *)(param_1 + 0x74) = *(u32 *)(param_1 + 100);
    *(u32 *)(param_1 + 0x78) = *(u32 *)(param_1 + 0x68);
    *(u32 *)(param_1 + 0x7c) = *(u32 *)(param_1 + 0x6c);
  }
  if ((u32 *)(param_1 + 0xb0) != (u32 *)(param_1 + 0xa0)) {
    *(u32 *)(param_1 + 0xb0) = *(u32 *)(param_1 + 0xa0);
    *(u32 *)(param_1 + 0xb4) = *(u32 *)(param_1 + 0xa4);
    *(u32 *)(param_1 + 0xb8) = *(u32 *)(param_1 + 0xa8);
    *(u32 *)(param_1 + 0xbc) = *(u32 *)(param_1 + 0xac);
  }
  return;
}

