#include "../common/types.h"
extern "C" u8 D_00347a90[];
extern "C" void func_00106420(u32*);
extern "C" void func_0011ee58(u32*);
extern "C" void func_0011f3b8(u32*);

void func_00123c98(u32* object) {
    u8* base = (u8*)object[1];
    object[0] = (u32)D_00347a90;
    for (s32* cursor = (s32*)(base + 0x10); *cursor != 0; cursor++) {
        func_0011f3b8((u32*)(base + *cursor));
    }
    func_0011ee58(object);
    func_00106420(object);
}
