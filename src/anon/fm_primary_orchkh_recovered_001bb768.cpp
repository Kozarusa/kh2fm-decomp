#include "../common/types.h"
extern "C" u32 D_01d49320;
extern "C" u32 func_001bbe18(...);
extern "C" u32 func_001d5518(...);
extern "C" u32 func_001bb890(...);
// why: accepted C++-linkage definition fails the isolated probe link (v1); same types with C linkage
extern "C" s32 func_001bb7f8(void);
// why: accepted C++-linkage definition fails the isolated probe link (v1); same types with C linkage
extern "C" void func_001bbc30();
extern "C" u32 func_001bc0d0(...);

// Preserve original registry aliases.
void func_001bb768(void) asm("_ZN2YS7MISSION6FailedEv");

void func_001bb768(void) {
    func_001bbe18(*(s32*)(*(u32*)(D_01d49320 + 8) + 0x18));
    *(u32*)(D_01d49320 + 0xb4) = 2;
    func_001d5518(D_01d49320 + 0xa0, D_01d49320 + 0xc, 0);
    func_001bb890();
    if (func_001bb7f8() != 0) {
        *(u32*)(D_01d49320 + 0x2dc) = 8;
        *(u32*)(D_01d49320 + 0x2e0) = (u32)-1;
        func_001bc0d0(D_01d49320);
        return;
    }
    func_001bbc30();
}
