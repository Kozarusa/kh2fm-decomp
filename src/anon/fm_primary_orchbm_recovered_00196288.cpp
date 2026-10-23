#include "../common/types.h"
extern "C" s32 D_01c61b00;
extern "C" u32 func_0016d080(s32, u32);
extern "C" void func_0016cbc8(u32, u32, void*, u32);
extern "C" void func_0016cd48(u32, u32);
extern "C" void func_0016cab8(u32);
extern "C" void func_0016c7d8(u32);

void func_00196288(u32 value) {
    s32 array[4];
    u32 handle = func_0016d080(D_01c61b00, 0);
    array[0] = value;
    func_0016cbc8(handle, 12, array, 1);
    func_0016cd48(handle, 0);
    if (handle != 0) {
        func_0016cab8(handle);
        func_0016c7d8(handle);
    }
}
