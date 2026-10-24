#include "../common/types.h"
extern "C" u8 D_0036cd78[];
extern "C" u8 D_0036cd80[];
extern "C" u8 D_0036cd88[];
extern "C" u8 D_0036cd98[];
extern "C" s32 D_0033caf4;
extern "C" u8 D_01c61ab8[];
extern "C" s32 func_00105ee8(s32);
extern "C" u32 func_002fee78(...);

u8* func_001921d8(s32 index) {
    u8* name;
    switch (index) {
    case 100:
        name = D_0036cd80;
        break;
    case 101:
        name = D_0036cd78;
        break;
    case 102:
        name = D_0036cd98;
        break;
    default:
        name = (u8*)func_00105ee8(index);
        break;
    }
    func_002fee78(D_01c61ab8, D_0036cd88, D_0033caf4, name);
    return D_01c61ab8;
}
