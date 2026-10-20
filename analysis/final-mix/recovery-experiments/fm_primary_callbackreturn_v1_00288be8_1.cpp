#include "../common/types.h"
extern "C" u32 D_0035f34c;
typedef void (*code)(u32,u32,u32);
void func_00288be8(u32 param_1)
{
  register u32 object asm("$4")=D_0035f34c;
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(table), "+r"(callback));
  callback(object,param_1,(u32)__builtin_return_address(0));
  asm volatile("");
}
