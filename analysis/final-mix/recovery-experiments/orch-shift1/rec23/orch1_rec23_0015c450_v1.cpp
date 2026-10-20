#include "../common/types.h"
extern "C" u64 D_0034af30;
extern "C" s32 D_0034af28;
extern "C" void func_00160e50(s64, s64);
extern "C" void func_0015c2a0(s32, s64);

void func_0015c450(s64 index) {
    if ((u8)((D_0034af30 >> index) & 1)) {
        func_00160e50(index, 1);
        return;
    }
    func_0015c2a0(D_0034af28, (s64)1 << index);
}
