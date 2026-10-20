#include "../common/types.h"
extern "C" u8 D_0035de14;
extern "C" u8 D_0035de15;
void func_00232110(u8* object) {
register u8* base asm("$14") = (u8*)0x00360000; // why: original first store uses high address in t6
    asm("" : "+r"(base)); // why: materializes address before initial immediate
    base[-8684] = 1;
    asm volatile("" ::: "memory"); // why: keeps initial store before object load
    s32 value = *(s16*)(object + 6);
    switch(value) {
    case 0: D_0035de15 = 0; return;
    case 1: D_0035de15 = value; return;
    default: return;
    }
}
