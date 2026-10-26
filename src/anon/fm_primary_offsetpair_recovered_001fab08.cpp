#include "../common/types.h"
extern "C" void func_0021fa10(u32);

void func_001fab08(u32 first, u32* second) {
    u32 indirect = second[3];
    u32 offset = *(u32*)indirect;
    u32 object = first + offset + 160;
    func_0021fa10(object);
    *(u8*)(object + 8) = 4;
}
