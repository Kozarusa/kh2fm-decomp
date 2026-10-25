#include "../common/types.h"
extern "C" u8 D_00352360[];
extern "C" u8 D_00351eb8[];
extern "C" u8 D_00351ec0[];
extern "C" u8 D_0034e8b8[];
extern "C" u8 D_0034ee08[];
extern "C" u32 func_001c8d98(void*,u32);
extern "C" void func_001c9b90();
extern "C" u64 func_001d2710(...);
extern "C" void func_00319f88(u32);
extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319fb0(u32);
extern "C" s32 func_00105110(u32);

s32 func_001cff48(u32 object) {
    *(u32*)object = (u32)D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(object + 2932);
    *(u32*)object = (u32)D_0034e8b8;
    func_00319f88(object + 2824);
    *(u32*)object = (u32)D_0034ee08;
    func_0019f9a8(object + 2568);
    func_001c0248(object + 2640);
    func_00319fb0(object);
    return func_00105110(object);
}
