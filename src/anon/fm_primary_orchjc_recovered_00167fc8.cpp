#include "../common/types.h"
extern "C" s32 D_004f5250;
extern "C" volatile s32 D_0034d780;
extern "C" volatile s32 D_004f5258[];
extern "C" void func_00167f38(s32);

void func_00167fc8(s32 index) {
    s32 value = D_004f5250;
    s32 slot = D_0034d780;
    D_004f5258[slot] = value;
    D_0034d780 = slot + 1;
    func_00167f38(index);
}
