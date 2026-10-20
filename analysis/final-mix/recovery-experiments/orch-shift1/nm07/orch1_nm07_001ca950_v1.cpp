#include "../common/types.h"

extern "C" void func_001c6fa8(u32, u32);

void func_001ca950(u32 object, u32 value, u32 unused_a2, u32 unused_a3, u32 unused_t0, u32 field)
{
  func_001c6fa8(object, value);
  *(u32 *)(object + 0x54) = field;
  *(u32 *)(object + 0x58) = 0;
}
