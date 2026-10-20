#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" bool func_001c0cd8(s32);
extern "C" void func_001c0e60(s32);

void func_001c1060() {
    s32 object = 0;
    while ((object = func_001b9bc8(object)) != 0) {
        if (func_001c0cd8(object)) {
            func_001c0e60(object);
        }
    }
}
