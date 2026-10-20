#include "../common/types.h"
extern "C" s32 D_003417a8;
extern "C" s32 D_00341788[];
extern "C" void func_001128d0(s32 value, s32 flag);

void func_001129d8(s32 value) {
    func_001128d0(value, 1);
    if (D_003417a8 >= 8) {
        func_001128d0(D_00341788[0], 1);
    }
    s32 index = D_003417a8;
    D_003417a8 = index + 1;
    D_00341788[index] = value;
}
