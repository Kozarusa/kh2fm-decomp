#include "../common/types.h"
extern "C" u32 D_0032fb68[];
extern "C" void func_001b8838(s32);
extern "C" void func_001b8da0();

void func_001b87b0() {
    s32 index = 7;
    u32* pointer = D_0032fb68;
    do {
        *pointer = 0;
        index--;
        pointer++;
    } while (index >= 0);
    ((u8*)D_0032fb68)[287] = 0;
    func_001b8838(0);
    func_001b8da0();
}
