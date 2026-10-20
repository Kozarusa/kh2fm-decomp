#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305e20() { s32* pointer=func_00316d08(); register s32 value asm("$3")=5; asm volatile("" : "+r"(value)); *(volatile s32*)pointer=value; return -1; }
