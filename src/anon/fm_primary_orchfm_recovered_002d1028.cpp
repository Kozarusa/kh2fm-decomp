#include "../common/types.h"
extern "C" u64 func_00182f28(...);
extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319f88(u32);
extern "C" void func_00319fb0(u32);
extern "C" s32 func_00105110(u32);
extern "C" u8 D_00362060[];
extern "C" u32 D_00362050;
extern "C" u8 D_0034e8b8[];
extern "C" char D_0034ee08;

s32 func_002d1028(u32 object) {
    *(u32*)object = (u32)(long)D_00362060;
    func_00182f28(0);
    D_00362050 = 0;
    *(u32*)object = (u32)(long)D_0034e8b8;
    func_00319f88(object + 2824);
    *(u32*)object = (u32)(long)&D_0034ee08;
    func_0019f9a8(object + 2568);
    func_001c0248(object + 2640);
    func_00319fb0(object);
    return func_00105110(object);
}
