#include "../common/types.h"
extern "C" u8* D_01d48cb0;
extern "C" s32 func_001b5cb8(u8*);

u8* func_001b5a10() {
    u8* result = 0;
    if (D_01d48cb0 != 0) {
        if (func_001b5cb8(D_01d48cb0) != 0) {
            result = *(u8**)(D_01d48cb0 + 12) + 128;
        } else {
            result = D_01d48cb0 + 24;
        }
    }
    return result;
}
