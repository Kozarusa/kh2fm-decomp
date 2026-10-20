#include "../common/types.h"
extern "C" u32 D_01d5bb00;
typedef void (*code)(u32,u32,u32);
void func_001dc488(u32 param_1)
{
  register u32 high asm("$15");
  asm volatile("lui %0,%1" : "=r"(high) : "i"(470));
  register u32 object asm("$4");
  asm volatile("lw %0,%1(%2)" : "=r"(object) : "i"(-17664), "r"(high) : "memory");
  register u32 table asm("$15")=*(u32 *)object;
  register code callback asm("$2")=*(code *)table;
  asm volatile("" : "+r"(callback));
  callback(object,param_1,0);
  asm volatile("");
}
