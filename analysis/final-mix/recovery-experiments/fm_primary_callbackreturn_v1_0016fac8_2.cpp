#include "../common/types.h"
extern "C" u32 D_0034dc98;
typedef void (*code)(u32,u32,u32);
void func_0016fac8(u32 param_1)
{
  register u32 object asm("$4")=D_0034dc98;
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(callback));
  callback(object,param_1,(u32)__builtin_return_address(0));
  asm volatile("");
}
