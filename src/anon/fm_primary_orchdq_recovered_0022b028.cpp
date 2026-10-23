#include "../common/types.h"
extern "C" u32 func_002247e8(void);
extern "C" u32 func_002248f8(s32);
extern "C" u32 func_002249b8(void);

s32 func_0022b028(s32 value) {
    func_002247e8();
    if (func_002249b8() == 3) {
        value = -value;
        func_002248f8(value);
    } else {
        if (func_002249b8() == 5) {
            value = -value;
            if (value > 0) func_002248f8(value);
        } else value = 0;
    }
    return value;
}
