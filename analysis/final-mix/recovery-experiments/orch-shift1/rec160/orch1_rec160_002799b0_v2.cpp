#include "../common/types.h"
extern "C" u8* volatile D_0035f230;
void func_002799b0() {
    *(u16*)(D_0035f230 + 4) = 0;
    s32 index = 0;
    if (*(s8*)(D_0035f230 + 7) > 0) {
        do {
            u8* object = D_0035f230;
            u8* row = index*8 + object;
            index++;
            if (*(s8*)(row + 14)) {
                *(u16*)(object + 4) = *(u16*)(object + 4) + *(s8*)(row + 17);
            }
        } while (index < *(s8*)(D_0035f230 + 7));
    }
}

