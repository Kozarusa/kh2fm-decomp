#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" u32 func_0016c028(u32);
extern "C" f32 D_0036adb8;
void func_0013f828(u32 object)
{
  register u32 saved asm("$17")=object;
  register u32 call_object asm("$4")=object;
  asm("" : "+r"(call_object));
  register u32 destination asm("$16")=saved+0x80;
  asm("" : "+r"(destination), "+r"(call_object));
  u32 source=func_0016c028(*(u32 *)(call_object+0x44));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  register f32 *constant asm("$15")=&D_0036adb8;
  asm("" : "+r"(constant));
  *(f32 *)(saved+0x84)-=*constant;
}
