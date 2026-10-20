#include "../common/types.h"
struct __attribute__((aligned(8))) Color { u32 value; };
extern "C" f32 D_0036ad4c;
extern "C" u32 func_0013b5d0(f32,u32,u32,u32,u32,u32,u32,u32,u32,Color,u32);
extern "C" void func_00139570(u32);
void func_0013c820(u32 first,u32 second)
{
  Color color={0x80e6e6e6};
  register f32 *value asm("$14")=&D_0036ad4c;
  asm volatile("" : "+r"(value));
  u32 result=func_0013b5d0(*value,first,second,2,0,0,0,0,0,color,2);
  func_00139570(result);
}
