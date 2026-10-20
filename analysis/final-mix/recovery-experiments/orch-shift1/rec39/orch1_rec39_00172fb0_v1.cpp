#include "../common/types.h"
extern "C" u32 func_00104f58(void*, u64, s64, u8, s64);

void func_00172fb0(u8* param) {
    u8 local[16];
    local[1] = *param;
    local[2] = param[4];
    *(u16*)(local + 8) = 0xffff;
    local[0] = 0xff;
    *(u16*)(local + 4) = 0xffff;
    *(u16*)(local + 6) = 0xffff;
    func_00104f58(local, *(u32*)(param + 8), 0, 0, 0);
}