#include "../common/types.h"
extern "C" u8* D_01d48cb0;

u16 func_001b5af0() {
    u8* object = D_01d48cb0;
    u16 result = 0;
    if (object != 0) {
        if ((*(s32*)(object + 0x40) & 4) == 0) {
            result = *(u16*)(*(u8**)object + 0x28);
        }
    }
    return result;
}
