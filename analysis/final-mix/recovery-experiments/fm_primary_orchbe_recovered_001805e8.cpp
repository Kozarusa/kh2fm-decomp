#include "../common/types.h"

void func_001805e8(u32* object) {
    u32 high = object[9] & 0xfffffffe;
    u32 low = object[8];
    object[10] = 0;
    low &= 0x7183;
    high &= 0xfffffffd;
    object[8] = low;
    object[9] = high;
}
