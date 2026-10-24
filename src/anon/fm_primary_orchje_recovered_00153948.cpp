#include "../common/types.h"
struct Entry24 {
    s32 id;
    u8 pad[20];
};
struct Slot64 {
    u8 pad[0x30];
    u8 flag;
    u8 rest[15];
};
extern "C" Slot64* D_0034a790;
extern "C" s32 D_0034a77c;
extern "C" Entry24* D_0034a778;

void func_00153948(u8 id) {
    if (D_0034a790 != 0) {
        s32 count = D_0034a77c;
        s32 index;
        for (index = 0; index < count; index++) {
            if (D_0034a778[index].id == id) {
                D_0034a790[index].flag = 0;
            }
        }
    }
}
