#include "../common/types.h"

void func_001a2578(u8* object, s32 amount) {
    u8* child = *(u8**)(object + 0x244);
    if (child != 0) {
        u8 old = child[9];
        if ((s32)old + amount >= 101) {
            amount = 100 - old;
        }
        child[9] = old + amount;
    }
    *(u16*)(object + 0x188) = *(u16*)(object + 0x188) + amount;
    *(u16*)(object + 0x190) = *(u16*)(object + 0x190) + amount;
}
