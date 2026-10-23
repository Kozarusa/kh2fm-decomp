#include "../common/types.h"
extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319fb0(u32);
extern "C" s32 func_00105110(u32);
extern "C" char func_0034ee08;

s32 func_002d0028(u32 object) {
    *(u32*)object = (u32)(long)&func_0034ee08;
    func_0019f9a8((u32)(long)((u8*)object + 2568));
    func_001c0248((u32)(long)((u8*)object + 2640));
    func_00319fb0(object);
    return func_00105110(object);
}
