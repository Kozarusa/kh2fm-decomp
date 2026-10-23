#include "../common/types.h"
extern "C" void func_0021fa10(u32);

void func_001fab08(u32 first,u32* second) { u32 indirect=second[3]; register u32 offset asm("$14")=*(u32*)indirect; asm("" : : "r"(offset)); u32 object=first+offset+160; func_0021fa10(object); *(volatile u8*)(object+8)=4; }
