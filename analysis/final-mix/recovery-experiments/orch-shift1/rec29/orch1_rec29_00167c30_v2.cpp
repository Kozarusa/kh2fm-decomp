#include "../common/types.h"
extern "C" u8 D_0034d3c0[];
extern "C" u8 D_0034d6c0[];
extern "C" s32 D_004f5250;
extern "C" s32 D_0034d780;
extern "C" void func_00167f38(s32);

void func_00167c30() {
    u8* source = D_0034d3c0;
    u8** slot = (u8**)(D_0034d6c0 + 68);
    s32 count = 1;
    do {
        *slot = source;
        count = count - 1;
        // why: original loop body carries two nops; also keeps the loop rolled
        asm volatile("nop\n\tnop");
        slot = (u8**)((u8*)slot + 96);
        source = source + 384;
    } while (count >= 0);
    D_004f5250 = -1;
    D_0034d780 = 0;
    func_00167f38(0);
}
