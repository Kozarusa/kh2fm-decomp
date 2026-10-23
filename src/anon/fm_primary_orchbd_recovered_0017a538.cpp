#include "../common/types.h"
extern "C" s64 func_0016a070();

s32 func_0017a538(u8* object) {
    s32 result = 0;
    if (func_0016a070() == 1) {
        s32 value = *(s32*)(object + 0xb50);
        s32 flag = value != 0 && value < 7;
        result = flag;
    }
    return result;
}
