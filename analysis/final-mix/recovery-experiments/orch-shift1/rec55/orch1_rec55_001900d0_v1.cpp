#include "../common/types.h"
extern "C" s32 D_01c61750[];
extern "C" s32 D_01c61950;
extern "C" u8 D_01c60d10[];
extern "C" void func_001cd660(u8*);

void func_001900d0() {
    s32 index;
    for (index = 0; index < 128; index++) {
        D_01c61750[index] = index;
    }
    D_01c61950 = 128;
    func_001cd660(D_01c60d10);
}