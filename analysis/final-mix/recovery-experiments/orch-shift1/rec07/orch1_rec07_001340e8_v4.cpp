#include "../common/types.h"

extern "C" s32 func_001341e8();
extern "C" s32 func_00134020();
extern "C" void func_00134030();
extern "C" u8 D_00347cb4;
extern "C" s32 D_10003010;

void func_001340e8() {
    if (func_001341e8() >= 0) {
        while (func_00134020() != 0) {
            func_00134030();
        }
    } else {
        func_00134030();
        D_00347cb4 = 0;
    }
    D_10003010 = 0;
}

