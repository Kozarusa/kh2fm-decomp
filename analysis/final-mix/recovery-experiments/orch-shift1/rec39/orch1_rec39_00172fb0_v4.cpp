#include "../common/types.h"
extern "C" u32 func_00104f58(void*, s32, s64, u8, s64);

void func_00172fb0(u8* param) {
    u8 local[16];
    u32 mask = 0xffff;
    *(u16*)(local + 8) = mask;
    local[1] = *param;
    local[2] = param[4];
    local[0] = mask;
    *(u16*)(local + 4) = mask;
    *(u16*)(local + 6) = mask;
    func_00104f58(local, *(s32*)(param + 8), 0, 0, 0);
}