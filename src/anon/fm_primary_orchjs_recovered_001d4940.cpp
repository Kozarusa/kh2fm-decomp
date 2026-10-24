#include "../common/types.h"
extern "C" u8 D_0036e490[];
extern "C" u8 D_01d5ba58[];
extern "C" u8 D_0036e4e0[];
extern "C" u8 D_0036e4e8[];
extern "C" u8 D_0036e4f8[];
extern "C" u8 D_0036e500[];
extern "C" u8 D_0036e508[];
extern "C" u8 D_0036e510[];
extern "C" u8 D_0036e520[];
extern "C" const void* D_0036e458[13];
extern "C" bool func_0019ba60(s32);
extern "C" u32 func_001bc778(s32);
extern "C" u32 func_001bce90(...);
extern "C" u32 func_00190878(void*,u32,u32);
extern "C" s32 func_001d4ae0(s32*, s32, s32);
extern "C" s32 func_001d4bd8(s32*, s32, s32);

s32 func_001d4940(s32* object, s32 player, s32 menu) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036e458, pattern of accepted func_001815d0
    static const void* targets[13] asm("fm_switch_table_001d4940") = {
        &&done, &&single, &&first, &&second, &&third, &&fourth, &&fifth, &&sixth,
        &&seventh, &&eighth, &&done, &&sidecar, &&target};
    u32 index;
    s32 result;
    if (object[1] != 0 && !func_0019ba60(object[1])) {
        return 0;
    }
    if (object[0] == 10) {
        return 1;
    }
    func_001bc778(menu);
    index = object[0];
    if (index >= 13) goto done;
    goto *D_0036e458[index];
single:
    func_001bce90(menu, D_0036e490, 3, 0);
    goto done;
first:
    result = func_001d4ae0(object, player, menu);
    goto finish;
second:
    func_001bce90(menu, D_01d5ba58, 3, 0);
    goto done;
third:
    func_001bce90(menu, D_0036e4e0, 2, 0);
    goto done;
fourth:
    func_001bce90(menu, D_0036e4e8, 3, 0);
    goto done;
fifth:
    func_001bce90(menu, D_0036e4f8, 1, 0);
    goto done;
sixth:
    func_001bce90(menu, D_0036e500, 1, 0);
    goto done;
seventh:
    func_001bce90(menu, D_0036e508, 1, 0);
    goto done;
eighth:
    func_001bce90(menu, D_0036e510, 3, 0);
    goto done;
sidecar:
    result = func_001d4bd8(object, player, menu);
    goto finish;
target:
    func_00190878(object + 3, object[1], 0);
    func_001bce90(menu, D_0036e520, 3, object + 3);
done:
    return 1;
finish:
    return result;
}
