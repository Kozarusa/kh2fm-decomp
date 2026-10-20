#include "../common/types.h"
extern "C" void func_00138c10(u8*, s32);

void func_00154b98(u8* object, s32 count) {
    if (*(s32*)(object + 0x3cc4) < count) {
        count = *(s32*)(object + 0x3cc4);
    }
    *(s32*)(object + 0x3cc0) = count;
    s32 blocks = (count - 1) / 200;
    *(s32*)(object + 0x3ccc) = count;
    *(s32*)(object + 0x3cc8) = count;
    object = object + 0xb58;
    if (blocks > 0) {
        do {
            func_00138c10(object, 0x2c);
            blocks--;
            object = object + 0x330;
        } while (blocks != 0);
    }
}