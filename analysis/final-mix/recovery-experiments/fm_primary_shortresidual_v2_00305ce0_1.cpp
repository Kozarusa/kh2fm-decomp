#include "../common/types.h"
// Complete-range register/address correction proposal.
extern "C" s32* func_00316d08(void);
s32 func_00305ce0(void) { s32* result=func_00316d08(); register s32 value asm("$3")=5; asm("addiu %0,$0,5" : "=r"(value)); *result=value; return -1; }
