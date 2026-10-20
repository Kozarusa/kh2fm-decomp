#include "../common/types.h"
extern "C" u8* D_00350790;
extern "C" u32 D_0034e948;
extern "C" u8* func_001c16f0(u32, u8*);
extern "C" void func_001a53d0(u8*, u32, u8*);

void func_001a5a48(void) {
    u8* cursor = 0;
    u8* entry;
    while (1) {
        entry = func_001c16f0(*(u32*)(D_00350790 + 0x9f4), cursor);
        cursor = entry;
        if (entry == 0) {
            break;
        }
        u32 flags = *(u32*)(entry + 0x28);
        if (flags & 1) {
            func_001a53d0(D_00350790, D_0034e948, entry);
        }
    }
}