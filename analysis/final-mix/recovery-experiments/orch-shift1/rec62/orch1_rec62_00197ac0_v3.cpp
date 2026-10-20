#include "../common/types.h"
extern "C" s32 D_0035037c;
extern "C" void func_001024a8();
extern "C" void func_001d3148(s64);

void func_00197ac0() {
    s32 pointer = D_0035037c;
    if (pointer != 0) {
        func_001d3148(pointer + 0x40);
        return;
    }
    func_001024a8();
}