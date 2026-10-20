#include "../common/types.h"
extern "C" u32 func_00152508(u64,u64,u32,u64,u32);

void func_00152ab8(u64 object, u64 unused, u32 value, u64 arg, u32 first, u32 second, u32 third, u32 last) {
    *(u32*)((s32)object + 0x1b8) = first;
    *(u32*)((s32)object + 0x1c0) = third;
    *(u32*)((s32)object + 0x1bc) = second;
    *(u32*)((s32)object + 0x1b4) = value;
    func_00152508(object, 0x6c, value, arg, last);
}
