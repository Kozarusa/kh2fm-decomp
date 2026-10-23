#include "../common/types.h"

typedef void (*code)(u32);
extern "C" u32 *func_00180698();

void func_00180770(void)
{
  u32 *puVar1;
  puVar1 = func_00180698();
  (*(code *)(*(u32 *)puVar1 + 0x1c))(puVar1);
}
