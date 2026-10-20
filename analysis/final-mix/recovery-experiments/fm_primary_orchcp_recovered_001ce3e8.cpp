#include "../common/types.h"
extern "C" u8 D_00352140[];
extern "C" u8 D_01d5b9e0[];
extern "C" void func_001980d0(u8*, u32, u32);
extern "C" void func_001dba88(u32);

void func_001ce3e8(u8* object, u32 handle, u32 arg) {
    func_001980d0(object, arg, 4);
    *(u32*)(object + 0x9f4) = handle;
    *(u8**)object = D_00352140;
    func_001dba88(handle);
    *(u32*)(object + 0x588) |= 0x800000;
    *(u8**)(object + 0x9f8) = D_01d5b9e0;
}
