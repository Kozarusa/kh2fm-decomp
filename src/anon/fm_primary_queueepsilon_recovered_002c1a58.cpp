#include "../common/types.h"
extern "C" void func_002be770(void);
extern "C" char func_00361b20;
void func_002c1a58(u32* param_1) {
    func_002be770();
    u32 bits = param_1[0x163];
    param_1[0x2b9] = 0;
    *(u32*)param_1 = (u32)(long)&func_00361b20;
    *(u8*)((u8*)param_1 + 2792) = 0;
    param_1[0x163] = bits | 1;
}

