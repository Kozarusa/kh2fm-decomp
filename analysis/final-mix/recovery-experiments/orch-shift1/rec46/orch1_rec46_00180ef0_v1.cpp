#include "../common/types.h"

void func_00180ef0(u8* object) {
    u8* node = 0;
    while (1) {
        if (node == 0) {
            node = *(u8**)(object + 0x18c);
        } else {
            node = *(u8**)(node + 0x2c);
        }
        if (node == 0) {
            break;
        }
        *(u32*)(node + 8) = *(u32*)(node + 8) | 0x2000000;
    }
    *(s32*)(object + 0x18c) = 0;
    *(s32*)(object + 0x190) = 0;
}