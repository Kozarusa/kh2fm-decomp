#include "../common/types.h"
extern "C" u32 func_001dca30(s32, u32, u32);

u32 func_001c16a0(s32* object, u32 value) {
    s32 kind = object[1];
    u32 field;
    if (kind == 0) {
        field = object[12];
    } else {
        if (kind != 1) {
            return 0;
        }
        field = object[12];
    }
    return func_001dca30(object[0], field, value);
}
