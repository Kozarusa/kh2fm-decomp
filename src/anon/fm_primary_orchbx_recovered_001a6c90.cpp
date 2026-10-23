#include "../common/types.h"
extern "C" u32 D_0032dec0[];
extern "C" void func_001d59b0();

void func_001a6c90(u32 index) {
    D_0032dec0[index >> 5] |= 1 << (index & 0x1f);
    func_001d59b0();
}
