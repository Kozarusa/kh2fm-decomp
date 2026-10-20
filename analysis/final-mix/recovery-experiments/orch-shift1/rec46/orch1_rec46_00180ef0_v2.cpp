#include "../common/types.h"

void func_00180ef0(u8* object) {
    u8* node = 0;
    u8* next;
    while (1) {
        if (node == 0) {
            next = *(u8**)(object + 0x18c);
        } else {
            next = *(u8**)(node + 0x2c);
        }
        node = next;
        if (next != 0) {
            *(u32*)(next + 8) = *(u32*)(next + 8) | 0x2000000;
        } else {
            *(s32*)(object + 0x18c) = 0;
            *(s32*)(object + 0x190) = 0;
            return;
        }
    }
}