#include "../common/types.h"
extern "C" u32 D_0034dc98;
typedef void (*code)(u32,u32,u32);
void func_0016fac8(u32 param_1)
{
  register u32 high asm("$15");
  asm volatile("lui %0,%1" : "=r"(high) : "i"(53));
  register u32 caller asm("$6")=(u32)__builtin_return_address(0);
  asm volatile("" : "+r"(caller) : "r"(high));
  register u32 object asm("$4");
  asm volatile("lw %0,%1(%2)" : "=r"(object) : "i"(-9064), "r"(high), "r"(caller) : "memory");
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(table), "+r"(callback));
  callback(object,param_1,caller);
  asm volatile("");
}
