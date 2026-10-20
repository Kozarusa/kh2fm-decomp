#include "../common/types.h"
struct Entry {
    u8 pad[68];
    u8* data;
    u8 rest[24];
};
extern "C" u8 D_0034d3c0[];
extern "C" Entry D_0034d6c0[];
extern "C" s32 D_004f5250;
extern "C" s32 D_0034d780;
extern "C" void func_00167f38(s32);

void func_00167c30() {
    s32 index = 1;
    u8* source = D_0034d3c0;
    Entry* entry = D_0034d6c0;
    do {
        entry->data = source;
        index = index - 1;
        entry = entry + 1;
        // why: original loop body carries two nops; also keeps the loop rolled
        asm volatile("nop\n\tnop");
        source = source + 384;
    } while (index >= 0);
    D_004f5250 = -1;
    D_0034d780 = 0;
    func_00167f38(0);
}
