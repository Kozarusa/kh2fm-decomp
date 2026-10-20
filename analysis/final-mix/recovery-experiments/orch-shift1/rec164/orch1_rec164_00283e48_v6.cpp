#include "../common/types.h"
extern "C" u32 func_002835a8();
extern "C" u32 func_00283900(s32);
extern "C" u8* D_0035f2b4;
extern "C" u8 D_003742c8[];
u32 func_00283e48() {
    u8* object = D_0035f2b4;
    s32 index = *(s8*)(object + 14);
    s32 count = *(s8*)(object + 13);
    u8* row = object + index;
    asm("" : "+r"(row)); // why: original forms row before increment and comparison
    if (index + 1 >= count) return func_002835a8();
    s32 next = *(s8*)(row + 5);
    asm("" : "+r"(next)); // why: retains next-index load before current-index load
    s32 current = *(s8*)(row + 4);
    u8 nextValue = D_003742c8[next*8 + 6];
    return func_00283900(D_003742c8[current*8 + 6] != nextValue);
}



