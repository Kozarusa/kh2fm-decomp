#include "../common/types.h"
extern "C" u8 D_0032f054;
extern "C" u8* func_001a8b28();

u16 func_00198040(s32 mode) {
    u8* entry = func_001a8b28();
    u16 result;
    if (mode == 1) {
        switch (D_0032f054) {
        case 1:
            result = *(u16*)(entry + 40);
            break;
        default:
            result = *(u16*)(entry + 38);
            break;
        case 2:
            result = *(u16*)(entry + 42);
            break;
        case 3:
            result = *(u16*)(entry + 44);
            break;
        case 4:
            result = *(u16*)(entry + 46);
            break;
        case 5:
            result = *(u16*)(entry + 48);
            break;
        case 6:
            result = *(u16*)(entry + 50);
            break;
        }
    } else {
        result = 0;
    }
    return result;
}
