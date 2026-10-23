#include "../common/types.h"
extern "C" u8 D_0034ee08[];
extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319fb0(u32);
extern "C" s32 func_00105110(u32);

s32 func_00324980(u8* object) {
    *(u8**)object = D_0034ee08;
    func_0019f9a8((u32)(object + 2568));
    func_001c0248((u32)(object + 2640));
    func_00319fb0((u32)object);
    return func_00105110((u32)object);
}
