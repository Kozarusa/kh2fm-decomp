#include "../common/types.h"
extern "C" u32 func_001a80c8(...);
s32 func_002642a8() {
    s32 result = 0;
    switch (*(u8*)(func_001a80c8() + 2)) {
    case 0: case 1: return 8;
    case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: return 1;
    case 14: return 2;
    case 15: return 4;
    case 16: return 16;
    }
    return result;
}

