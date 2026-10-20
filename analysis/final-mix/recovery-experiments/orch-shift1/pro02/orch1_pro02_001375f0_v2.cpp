#include "../common/types.h"
extern "C" f32 D_0036ac9c;
extern "C" void func_001374c8(f32, u32*, s32, u64, u32);
void func_001375f0(u32* object, u64 second, u32 third)
{
  f32* scale = &D_0036ac9c;
  f32 value = *scale;
  // why: second use of the full address keeps the low half out of the load offset
  asm("" : "+f"(value) : "r"(scale));
  func_001374c8(value, object, 79, second, third);
  object[0x146] = 0;
}
