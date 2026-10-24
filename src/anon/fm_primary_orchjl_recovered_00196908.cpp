#include "../common/types.h"
extern "C" u32 D_00350338[];
extern "C" u32 func_0016d080(u32, u32);
extern "C" void func_0016cce8(u32, u32, void*, u32, u32);
extern "C" void func_0016cbc8(u32, u32, u32, u32);
extern "C" u32 func_0016cb88(u32, u32);

s32 func_00196908(u32 process) {
    s32 index;
    for (index = 0; index < 8; index++) {
        if (D_00350338[index * 2 + 1] == 0) {
            break;
        }
    }
    u32* slot = &D_00350338[index * 2];
    u32 handle = func_0016d080(process, 0);
    slot[1] = handle;
    func_0016cce8(handle, 2, 0, 0, 0);
    func_0016cbc8(handle, 3, 0, 0);
    *(u32*)(handle + 0x24) = func_0016cb88(handle, 4);
    slot[0] = 0;
    return index;
}
