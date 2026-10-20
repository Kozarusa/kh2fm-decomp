#include "../common/types.h"
extern "C" s32 D_00351214;
extern "C" u8* D_00351180;
extern "C" u8 D_00351ec0[];
extern "C" u8 D_001b5f68[];
extern "C" u8 D_001b5fe0[];
extern "C" u32 func_00102818(...);
extern "C" u32 func_001c8d80(void*, u32);

void func_001b5ef0(u8* object) {
    u8* node = (u8*)func_00102818(D_00351214, 0, 2, D_001b5f68, 0x2000);
    *(u8**)(node + 4) = object;
    *(u8**)(node + 48) = D_001b5fe0;
    D_00351180 = node;
    func_001c8d80(D_00351ec0, 2);
    *(u32*)(object + 264) |= 0x100;
}
