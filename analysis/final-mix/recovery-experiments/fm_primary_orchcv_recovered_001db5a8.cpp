#include "../common/types.h"
extern "C" u8 D_00321b28[];
extern "C" u8* D_01d5baac;
extern "C" s64 func_002fd248(s64, u8*, s32, s32, u8*);

void func_001db5a8(s64 code) {
    if (func_002fd248(code, D_01d5baac + 8, *(s32*)(D_01d5baac + 4), 0x5c, D_00321b28) == 0) {
        func_002fd248(0x45, D_01d5baac + 8, *(s32*)(D_01d5baac + 4), 0x5c, D_00321b28);
        asm volatile("" ::: "memory"); // why: original does not tail-call the second callback
    }
}
