#include "../common/types.h"
extern "C" bool func_00181500(s64);
extern "C" u8 func_001a3570(...);
s32 func_00294480(u8* object) {
    s32 result = 0;
    if (*(s8*)(object + 6) != 2) {
        if (func_00181500(*(u16*)object)) result = 1;
    } else {
        result = func_001a3570(*(u16*)object) > 0;
    }
    return result;
}
