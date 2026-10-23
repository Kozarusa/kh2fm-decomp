#include "../common/types.h"

// Preserve original registry aliases.
void func_00181a90(void) asm("_ZN2YS13TEST_PROGRESS8set_flagEi");
// Complete-range scheduling/address proposal.
extern "C" void func_00181178(u32); extern "C" u8 D_0032bb30[];

void func_00181a90(void) { func_00181178(18504); func_00181178(18505); register u8* object asm("$14")=D_0032bb30; register u32 first asm("$15"),second asm("$13"); asm("addiu %0,$0,18; addiu %1,$0,99" : "=r"(first),"=r"(second) : "r"(object)); *(volatile u8*)(object+13)=first; *(volatile u8*)(object+14)=second; *(volatile u8*)(object+12)=first; }
