#include "../common/types.h"
extern "C" u8* D_01d48cb0;

u16 func_001b5af0() {
    u8* object = D_01d48cb0;
    if (object == 0 || (*(s32*)(object + 0x40) & 4) != 0) {
        return 0;
    }
    return *(u16*)(*(u8**)object + 0x28);
}
