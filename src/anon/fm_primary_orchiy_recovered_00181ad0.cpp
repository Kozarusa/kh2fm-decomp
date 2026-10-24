#include "../common/types.h"
struct Area { u16 value[5]; };
extern "C" Area D_01c60530;
extern "C" s32 D_0034ecf4;
extern "C" u8 D_0036c7b8[];
extern "C" s32 func_001051a0(Area*, Area*);
extern "C" u32 func_00105140(u8*, u8*);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_001688c8(...);
extern "C" u32 func_00170b30(...);
extern "C" u32 func_00170c00(...);
extern "C" s32 func_001684c0(u8*, u8*, s32, s32);

s32 func_00181ad0(Area* area) {
    s32 result = func_001051a0(&D_01c60530, area);
    if (result == 0) {
        if (D_0034ecf4 != 0) {
            func_00170c00(D_0034ecf4);
        }
        u8 path[48];
        u32 name = func_00105140((u8*)area, 0);
        func_002fee78(path, D_0036c7b8, name);
        u32 size = func_001688c8(path);
        D_0034ecf4 = func_00170b30((size + 0x7ff) & ~0x7ff);
        result = func_001684c0(path, (u8*)D_0034ecf4, 0, 0);
        D_01c60530 = *area;
    }
    return result;
}
