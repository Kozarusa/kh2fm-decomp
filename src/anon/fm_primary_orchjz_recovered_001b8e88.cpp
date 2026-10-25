#include "../common/types.h"
extern "C" u8* D_01d48d98;
extern "C" u8 D_00320458[];
extern "C" u8* func_002fd248(u32, u8*, u32, u32, u8*);
extern "C" u16 func_001a67b0(s32);

// Preserve original registry aliases.
u8* func_001b8e88(u32 value) asm("_Z16u_call4_001b8e88jjjj");

u8* func_001b8e88(u32 value) {
    u8* entry = func_002fd248(value, D_01d48d98 + 8, *(u32*)(D_01d48d98 + 4), 48, D_00320458);
    if (*(u16*)(entry + 2) == 2 && *(u16*)entry != 2) {
        u8* table = D_01d48d98;
        entry = func_002fd248(func_001a67b0(*(s16*)(entry + 4)), table + 8, *(u32*)(table + 4), 48, D_00320458);
    }
    return entry;
}
