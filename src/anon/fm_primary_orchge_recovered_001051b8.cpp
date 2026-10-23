#include "../common/types.h"
extern "C" u8 D_003a7b20[];
extern "C" u8 D_00369e58[];
extern "C" u8 D_00369e60[];
extern "C" u8 D_00369e70[];
extern "C" u32 func_00105140(u8*, u8*);
extern "C" u32 func_002fee78(...);
extern "C" s32 func_002ff3fc(...);

u8* func_001051b8(u8* object) {
    u32 name = func_00105140(object, 0);
    func_002fee78(D_003a7b20, D_00369e58, name, object[2]);
    if (*(u16*)(object + 4) < 25 && *(u16*)(object + 6) < 25 && *(u16*)(object + 8) < 25) {
        s32 length = func_002ff3fc(D_003a7b20);
        func_002fee78(D_003a7b20 + length, D_00369e60, *(u16*)(object + 4) + 97,
                      *(u16*)(object + 6) + 97, *(u16*)(object + 8) + 97);
    } else {
        s32 length = func_002ff3fc(D_003a7b20);
        func_002fee78(D_003a7b20 + length, D_00369e70, (u32)*(u16*)(object + 4),
                      (u32)*(u16*)(object + 6), (u32)*(u16*)(object + 8));
    }
    return D_003a7b20;
}
