#include "../common/types.h"
extern "C" u32 D_0034a42c;
extern "C" s32 func_00150bc0(u32);
extern "C" s32 func_00150be0(u32);
extern "C" s32 func_00139d78(u32);
extern "C" void func_00150b68(u32);

void func_0014f5d0(s32 value) {
    if (func_00150bc0(D_0034a42c) != 0) {
        if (value == 0 || func_00150be0(D_0034a42c) == value) {
            if (func_00139d78(D_0034a42c) != 0) {
                func_00150b68(D_0034a42c);
                return;
            }
        }
    }
}
