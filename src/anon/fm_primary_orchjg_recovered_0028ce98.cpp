#include "../common/types.h"
extern "C" s32 D_0035f3fc;
extern "C" s16* D_0035f400;
extern "C" s32* D_0035f408;
extern "C" void func_00138c10(s32, s32);

void func_0028ce98(s32 index, s32 value) {
    if (D_0035f408[index] == value) {
        return;
    }
    D_0035f408[index] = value;
    s16 number;
    if (value == 0) {
        number = D_0035f400[index * 2];
    } else {
        number = D_0035f400[index * 2 + 1];
    }
    func_00138c10(D_0035f3fc + index * 408, number);
}
