#include "../common/types.h"
extern "C" u8 D_0034af40[];
extern "C" u8 D_0034b0e0[];
extern "C" void func_0015d4e8();
extern "C" u32 func_00102818(...);
extern "C" u32 func_00102c80(void);
extern "C" u32 func_0013a7d0(s32);
extern "C" u32 func_0013a7e8(s32);
extern "C" u32 func_0013efe8(void);
extern "C" u32 func_002362b0(s32,s32);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(s32,s32);

u32 func_0015d540() {
    func_0013efe8();
    u32 mode = func_00102c80();
    func_00102818(*(s32*)(mode + 4), 0, 120000, (s32)func_0015d4e8, 0x1000);
    func_002362b0((s32)D_0034af40, func_0013a7d0(2));
    func_00239988(D_0034b0e0, func_0013a7e8(2), D_0034af40);
    return func_00239bf8((s32)D_0034b0e0, 1);
}
