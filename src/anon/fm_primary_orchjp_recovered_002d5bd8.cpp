#include "../common/types.h"
extern "C" u32 func_00179b68(...);

u32 func_002d5bd8(s32 object) {
    s32 value = *(s32*)(*(s32*)(object + 12) + 4);
    u32 result;
    if ((value ^ 0x38) == 0 || (value ^ 0x37) == 0) {
        result = 1;
    } else {
        result = func_00179b68(object);
    }
    return result;
}
