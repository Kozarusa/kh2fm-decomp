#include "../common/types.h"
extern "C" bool func_00112720(...);

s32 func_0010fea0(u8* object) {
    if (func_00112720(object) != 0) return 0;
    s32 value = *(s32*)(object + 0xc54);
    s32* pointer = (s32*)(object + 0xc58);
    s32 count = 1;
    do {
        if (value != *pointer++) return 0;
        ++count;
    } while (count < 3);
    return value;
}
