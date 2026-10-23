#include "../common/types.h"
extern "C" u64 D_0034c710;
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" void func_00143060();
extern "C" void func_001538d8(u8);
extern "C" void func_0015c4a0(u32);
extern "C" void func_001de3d8(u8*, u32);

// Preserve original registry aliases.
void func_0015ee10(u32 index) asm("_ZN2dk3Map12setHideGroupEj");

void func_0015ee10(u32 index) {
    D_0034c710 = ~((u64)1 << index) & D_0034c710;
    func_00143060();
    func_001538d8(index & 0xff);
    func_0015c4a0(index);
    if (D_0034c70c == 1) {
        func_001de3d8(D_0034c6f0, index);
    }
}
