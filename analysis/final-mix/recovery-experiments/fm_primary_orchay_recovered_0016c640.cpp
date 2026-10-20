#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" void func_0016c5a0(s32, s32);

void func_0016c640(s32 value) {
    s32 current = 0;
    while ((current = func_001b9bc8(current)) != 0) {
        func_0016c5a0(current, value);
    }
}
