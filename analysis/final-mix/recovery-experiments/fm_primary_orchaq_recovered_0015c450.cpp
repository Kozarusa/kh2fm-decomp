#include "../common/types.h"
extern "C" u64 D_0034af30;
extern "C" s32 D_0034af28;
extern "C" void func_00160e50(u32, s64);
extern "C" void func_0015c2a0(s32, u64);

void func_0015c450(u32 index) {
    if ((u8)((D_0034af30 >> index) & 1)) {
        func_00160e50(index, 1);
        return;
    }
    func_0015c2a0(D_0034af28, (u64)1 << index);
}
