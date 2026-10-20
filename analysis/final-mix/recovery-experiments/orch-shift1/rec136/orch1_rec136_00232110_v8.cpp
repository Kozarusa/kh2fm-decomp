#include "../common/types.h"
extern "C" u8 D_0035de14;
extern "C" u8 D_0035de15;
void func_00232110(u8* object) {
    register u8 one asm("$15") = 1; // why: original initial flag value uses t7
    D_0035de14 = one;
    asm volatile("" ::: "memory"); // why: keeps initial store before object load
    s32 value = *(s16*)(object + 6);
    switch(value) {
    case 0: D_0035de15 = 0; return;
    case 1: D_0035de15 = value; return;
    default: return;
    }
}
