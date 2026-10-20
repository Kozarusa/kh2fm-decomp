#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305e20() { register s32* pointer asm("$2")=func_00316d08(); register s32 value asm("$3")=5; asm("sw %1,%0" : "=m"(*pointer) : "r"(value)); return -1; }
