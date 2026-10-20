#include "../common/types.h"

extern "C" s32 func_001341e8();
extern "C" s32 func_00134020();
extern "C" void func_00134030();
extern "C" volatile u8 D_00347cb4;

void func_001340e8() {
    if (func_001341e8() >= 0) {
        while (func_00134020() != 0) {
            func_00134030();
        }
    } else {
        func_00134030();
        D_00347cb4 = 0;
    }
    *(volatile s32*)0x10003010 = 0;
}
