#include "../common/types.h"
extern "C" s32 D_0035f270;
extern "C" s32 D_0035f274;
extern "C" s32 D_0035f278;
extern "C" s32 D_0035f27c;
extern "C" s32 D_0035f284;
extern "C" s32 D_0035f288;
extern "C" s32 D_0035f28c;
extern "C" u8 D_0035f299;
extern "C" u16 D_0035f2a0[];
extern "C" u16 D_0035f2a8[];
extern "C" u16 D_003741a8[];

void func_002817d8(s32 first, s32 second, s32 third, s32 fourth, s32 fifth, u16* ids, u16* pair) {
    s32 index;
    D_0035f270 = first;
    D_0035f278 = second;
    D_0035f27c = third;
    D_0035f284 = fourth;
    D_0035f274 = fifth;
    if (ids != 0) {
        D_0035f28c = D_0035f288;
        D_0035f299 = 1;
    } else {
        D_0035f28c = 0;
        D_0035f299 = 0;
    }
    for (index = 0; index < 3; index++) {
        D_0035f2a0[index] = (ids != 0) ? ids[index] : -1;
    }
    if (pair == 0) {
        pair = D_003741a8;
    }
    for (index = 0; index < 2; index++) {
        D_0035f2a8[index] = pair[index];
    }
}
