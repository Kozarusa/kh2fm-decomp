#include "../common/types.h"
extern "C" void func_00138c10(u8*, s32);

void func_00154b98(u8* object, s32 count) {
    s32 limit = *(s32*)(object + 0x3cc4);
    if (limit < count) {
        count = limit;
    }
    *(s32*)(object + 0x3cc0) = count;
    *(s32*)(object + 0x3ccc) = count;
    *(s32*)(object + 0x3cc8) = count;
    s32 blocks = (count - 1) / 200;
    if (blocks > 0) {
        object = object + 0xb58;
        do {
            func_00138c10(object, 0x2c);
            blocks--;
            object = object + 0x330;
        } while (blocks != 0);
    }
}