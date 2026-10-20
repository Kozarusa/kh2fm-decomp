#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305ce0(void) { s32* p=func_00316d08(); register s32 value asm("$3")=5; asm volatile("" : "+r"(value) :: "memory"); *(volatile s32*)p=value; return -1; }
