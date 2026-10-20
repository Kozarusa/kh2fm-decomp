#include "../common/types.h"
extern "C" s64 func_001adf00();
extern "C" void func_003058a0(s32);

s64 func_001682b8() {
    s64 result = func_001adf00();
    func_003058a0(0);
    return result;
}
