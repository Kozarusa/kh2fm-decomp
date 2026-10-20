#include "../common/types.h"
extern "C" u8* D_00350790;
extern "C" u32 D_0034e948;
extern "C" u8* func_001c16f0(u32, u8*);
extern "C" void func_001a53d0(u8*, u32, u8*);

void func_001a5a48(void) {
    u8* entry = 0;
    while (1) {
        entry = func_001c16f0(*(u32*)(D_00350790 + 0x9f4), entry);
        if (entry == 0) {
            break;
        }
        if ((*(u32*)(entry + 0x28) & 1) != 0) {
            func_001a53d0(D_00350790, D_0034e948, entry);
        }
    }
}