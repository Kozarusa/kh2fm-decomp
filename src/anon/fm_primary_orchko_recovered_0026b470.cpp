#include "../common/types.h"
struct SheetData {
    u8 pad0[16];
    u8 count;
    u8 pad11[3];
    u16 slots[1];
};
extern "C" u32 D_0035f010;
extern "C" u32 func_00257070(...);
extern "C" u32 func_00281180(...);

// why: typed return: the only exit leaves func_00281180's v0 (its lw v0,20(a1)) untouched.

u32 func_0026b470(void) {
    u32 sheet = func_00281180(D_0035f010, func_00257070(1));
    SheetData* data = *(SheetData**)(sheet + 580);
    s32 count = data->count;
    for (s32 i = 0; i < count; i++) {
        for (s32 j = i + 1; j < count; j++) {
            if (data->slots[i] == 0 && data->slots[j] != 0) {
                data->slots[i] = data->slots[j];
                data->slots[j] = 0;
            }
        }
    }
    return sheet;
}
