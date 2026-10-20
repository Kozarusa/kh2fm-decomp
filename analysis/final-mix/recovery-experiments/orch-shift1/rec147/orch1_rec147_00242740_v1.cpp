#include "../common/types.h"
extern "C" bool func_00197920(...);
extern "C" u32 func_002ba978(...);
extern "C" u32 func_002bd680(...);
extern "C" u8 func_002ef7b8(...);
void func_00242740(s32 value) {
    if (value < 0) {
        bool flag = func_00197920();
        value = 1;
        if (!flag) value = 2;
    }
    func_002ba978(value);
    if (func_002ef7b8()) func_002bd680();
}
