#include "../common/types.h"
extern "C" bool func_001c8ab0(void);
extern "C" u32 func_00102818(...);
extern "C" s32 D_01d49968;
extern "C" u8 D_0032f055;
extern "C" s32 D_00351214;
extern "C" u8 D_001c89a8[];
extern "C" u8 D_001c8a70[];

void func_001c8948(void) {
    if (func_001c8ab0()) {
        D_01d49968 = 3;
        D_0032f055 = 0;
        u32 result = func_00102818(D_00351214, 0, 3, (s32)D_001c89a8, 0x2000);
        *(u32*)(result + 0x30) = (u32)D_001c8a70;
    }
}
