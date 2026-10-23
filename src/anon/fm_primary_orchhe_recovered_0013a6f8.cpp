#include "../common/types.h"
extern "C" s32 D_00347fb0[];
extern "C" u8 D_003b8bc0[];
extern "C" u8 D_00347fd8[];
extern "C" u8 D_004193c0[];
extern "C" s32 func_00168aa0(void*,u64);
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" s32 func_0031ae58(u8*, u8*);

s32 func_0013a6f8() {
    s32 index = 0;
    s32* base = D_00347fb0;
    D_00347fb0[0] = (s32)D_003b8bc0;
    base[1] = func_00168aa0(D_003b8bc0, 25);
    if (base[1] > 0) {
        s32* header = base;
        s32* cursor = base;
        do {
            cursor[3] = *(s32*)(func_00168b38((void*)D_00347fb0[0], 25, index) + 8);
            if (func_00168b38((void*)D_00347fb0[0], 24, 0) != 0) {
                cursor[2] = *(s32*)(func_00168b38((void*)D_00347fb0[0], 24, index) + 8);
            } else {
                cursor[2] = 0;
            }
            index++;
            cursor += 2;
        } while (index < header[1]);
    }
    return func_0031ae58(D_00347fd8, D_004193c0);
}
