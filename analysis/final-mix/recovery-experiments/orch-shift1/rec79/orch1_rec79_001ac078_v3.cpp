#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);

void func_001ac078(u8* object, s32 first, s32 second, s32 third) {
    s32 base;
    s32 value;
    // why: pin copies to the original t4/t6 registers
    register s32 saved asm("$12") = first;
    register u8* cursor asm("$14") = object;
    cursor[0] = (u8)saved;
    cursor[1] = (u8)second;
    base = (saved * 4 + second) * 2;
    cursor[2] = (u8)third;
    value = base + 0x21;
    if (third < 4) {
        value = base + 0x25;
    }
    if (saved != 0) {
        func_00239bf8((s32)(object + 4), value);
        return;
    }
}
