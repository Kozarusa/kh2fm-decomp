#include "../common/types.h"
extern "C" f32 func_00166d38(u32);
extern "C" f32 func_00166d10(u32,u32);
extern "C" void func_00154cd0(f32,u32,u32);
void func_00155658(u32 object)
{
  register f32 first asm("$f0")=func_00166d38(*(u32 *)(object+0x34));
  register u32 nested asm("$15")=*(u32 *)(object+0x34);
  asm("" : "+r"(nested));
  register f32 saved asm("$f20");
  register u32 argument asm("$4");
  asm("mov.s %0,%2; lw %1,0x24(%3)" : "=f"(saved), "=r"(argument) : "f"(first), "r"(object), "r"(nested));
  register u32 second asm("$14")=*(u32 *)(nested+0x48c);
  asm("" : "+r"(second) : "r"(argument));
  f32 result=func_00166d10(argument,*(u32 *)(second+4));
  func_00154cd0(result,object,1);
  func_00154cd0(saved,object,2);
}
