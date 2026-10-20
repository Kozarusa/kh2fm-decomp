#include "../common/types.h"
extern "C" u8 D_0034d3c0[];
extern "C" u8 D_0034d6c0[];
extern "C" s32 D_004f5250;
extern "C" s32 D_0034d780;
extern "C" void func_00167f38(s32);

void func_00167c30() {
    u8* base = D_0034d6c0;
    // why: keeps the symbol address and the +68 field offset as two separate adds
    asm("" : "+r"(base));
    u8** slot = (u8**)(base + 68);
    u8* source = D_0034d3c0;
    s32 index = 1;
    do {
        *slot = source;
        index = index - 1;
        slot = (u8**)((u8*)slot + 96);
        // why: original loop body carries two nops; also keeps the loop rolled
        asm volatile("nop\n\tnop");
        source = source + 384;
    } while (index >= 0);
    D_004f5250 = -1;
    D_0034d780 = 0;
    func_00167f38(0);
}
