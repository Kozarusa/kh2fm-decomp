#include "../common/types.h"
extern "C" bool func_00181500(s64);
extern "C" u8 func_001a3570(...);

s32 func_00294408(u16* object) {
    s32 result = 0;
    if (*(s8*)(object + 3) != 2) {
        if (func_00181500(*object)) result = 1;
    } else {
        s32 calleeResult = (s32)func_001a3570(*object);
        result = 0 < calleeResult;
    }
    s32 flag = object[1];
    if (flag != 0) {
        if (func_00181500(flag)) result = 0;
    }
    return result;
}
