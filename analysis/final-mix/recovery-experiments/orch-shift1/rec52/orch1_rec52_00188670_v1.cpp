#include "../common/types.h"
extern "C" u32 func_00102788(u64,u64,u64,u64);
extern "C" u32 D_01c608c0[];
extern "C" s32 D_01c60bc0;
extern "C" s32 D_00351214;

u32 func_00188670() {
    u32* pointer = D_01c608c0;
    *pointer = 0;
    while (pointer += 3, (s32)pointer < 0x1c60bc0) {
        *pointer = 0;
    }
    D_01c60bc0 = 0;
    return func_00102788(D_00351214, 0, 0, 0x188550);
}