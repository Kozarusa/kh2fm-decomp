#include "../common/types.h"
extern "C" u32 func_00276568(void);
// why: the recovered definition takes four s64 parameters, but this caller sets only a0 (lb of the menu byte); plain C name, resolved by the build_elf.py PROVIDE alias
extern "C" s64 func_002a4380(s64);
// why: no recovered declaration; one byte argument in a0, v0 tested against zero
extern "C" s32 func_002a9b88(s32);
// why: no recovered declaration; one byte argument in a0, v0 tested against zero
extern "C" s32 func_002a8870(s32);
// why: the accepted C++ declaration fails the isolated probe link (probe linker script defines only the plain symbol)
extern "C" s32 func_002b3ae8();

// Preserve original registry aliases.
s32 func_00296da8(u32 index) asm("_ZN2Tz8JmReport8GetIndexEj");

s32 func_00296da8(u32 index) {
    s32 table[12];
    s32* out;
    s32 i;

    out = table;
    for (i = 0; i < 9; i++) {
        if (i == 3 && func_002a4380(*(s8*)func_00276568()) != 0) continue;
        if (i == 4 && func_002b3ae8() == 0) continue;
        if (i == 6 && func_002a9b88(*(s8*)func_00276568()) == 0) continue;
        if (i == 7 && func_002a8870(*(s8*)func_00276568()) == 0) continue;
        *out++ = i;
    }
    return table[index];
}
