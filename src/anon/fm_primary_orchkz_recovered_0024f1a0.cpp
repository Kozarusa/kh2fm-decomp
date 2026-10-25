#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 func_0024f2b8(u32);
extern "C" void func_00138c10(s32, u64);
extern "C" u32 D_0035ee10;
extern "C" u32 D_0035ee2c;
struct Entry { s16 first; s16 value; s16 last; };
extern "C" Entry D_00372390[];

void func_0024f1a0() {
    if ((s32)D_0035ee2c < 0) return;
    if (D_0035ee10 == 0) return;
    if (func_00139d78(D_0035ee10) == 0) return;
    s32 index = func_0024f2b8(D_0035ee2c);
    s32 value = D_00372390[index].value;
    if (*(s32*)(D_0035ee10 + 388) != value) {
        D_0035ee2c = -1;
        func_00138c10(D_0035ee10, value);
        *(s32*)(D_0035ee10 + 392) = -1;
    }
}
