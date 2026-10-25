#include "../common/types.h"
extern "C" bool func_00181500(s64);

s32 func_001afee8(s32 current, s32 next) {
    if (current == next) {
        return -1;
    }
    if (!func_00181500(0x184c) && !func_00181500(0x180c) && !func_00181500(0x182e)) {
        if (current == 5 || next == 5) {
            return -1;
        }
    }
    u32 index = next - 1;
    s32 result = -1;
    if (index < 15) {
        result = index;
        if (index >= 3) {
            result = 4;
            if (next != 15) {
                result = 3;
            }
        }
    }
    return result;
}
