#include "../common/types.h"
typedef void (*Method)(u8*);
// why: held as a word so the u32 field store may alias it and the original reload after that store follows
extern "C" u32 D_0035f034;
extern "C" u32 D_0035ef68;
extern "C" u32 D_0035ef64;
extern "C" u32 D_0035f03c;
extern "C" s16 D_00372a00[];
extern "C" s16 D_00372a08[];
extern "C" u32 func_00139d78(...);
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
extern "C" u64 func_00139620(...);

void func_00257388(s32 value, s32 select) {
    if (func_00139d78(D_0035f034)) {
        u8* object = (u8*)D_0035f034;
        (*(Method*)(*(u8**)object + 0x14))(object);
    }
    s16* table;
    if (select == 0) {
        table = D_00372a00;
    } else {
        table = D_00372a08;
    }
    func_0028d980((u8*)D_0035f034, 0x7546, D_0035ef68, D_0035ef64, D_0035f03c, table[0], table[2], value, 0);
    func_00139620(D_0035f034);
    *(u32*)(D_0035f034 + 432) = 2;
    u8* part = (u8*)D_0035f034 + 24;
    *(u32*)(part + 184) |= 8;
}
