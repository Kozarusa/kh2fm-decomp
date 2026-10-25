#include "../common/types.h"
extern "C" u32 func_001a80c8(...);
s32 func_002642a8() {
    u8 value = *(u8*)(func_001a80c8() + 2);
    s32 result = 0;
    switch (value) {
    case 0: case 1: result = 8; break;
    case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: result = 1; break;
    case 14: result = 2; break;
    case 15: result = 4; break;
    case 16: result = 16; break;
    }
    return result;
}

