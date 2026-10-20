#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 func_0024f2b8(u32);
extern "C" u32 D_0035ee10;
extern "C" u32 D_0035ee2c;
struct Entry { s16 first; s16 value; s16 last; };
extern "C" Entry D_00372390[];
bool func_0024f240() {
    if (D_0035ee10 == 0 || func_00139d78(D_0035ee10) == 0) return true;
    s32 index = func_0024f2b8(D_0035ee2c);
    return *(s32*)(D_0035ee10 + 388) == D_00372390[index].value;
}

