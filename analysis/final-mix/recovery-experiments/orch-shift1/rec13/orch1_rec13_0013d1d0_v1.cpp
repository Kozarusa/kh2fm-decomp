#include "../common/types.h"
extern "C" u32 func_00139598(...);

void func_0013d1d0(u8* object) {
    u8* child = *(u8**)(object + 0x29c);
    if (child == 0) {
        return;
    }
    if ((*(u32*)(child + 0x20) & 8) == 0) {
        return;
    }
    func_00139598(object + 0x104);
}