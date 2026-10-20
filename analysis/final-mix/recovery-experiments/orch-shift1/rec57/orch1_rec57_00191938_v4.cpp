#include "../common/types.h"
extern "C" s32 D_01c61958;
extern "C" void func_001c1130(s32);
extern "C" void func_001c11a8(s32);

void func_00191938(s32 value) {
    if (value != 0) {
        if (value >= 0) {
            if (value < 3) {
                func_001c1130(6);
            }
        }
    } else {
        func_001c11a8(6);
    }
    D_01c61958 = value;
}
