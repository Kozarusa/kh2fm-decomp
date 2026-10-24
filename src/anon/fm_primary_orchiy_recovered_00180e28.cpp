#include "../common/types.h"
extern "C" u32 func_001dc9d0(u32);

void func_00180e28(u8* object) {
    u8* node = *(u8**)(object + 0x18c);
    u8* cursor = node;
    while (node != 0) {
        u8* next;
        if (cursor == 0) {
            next = *(u8**)(object + 0x18c);
        } else {
            next = *(u8**)(cursor + 0x2c);
        }
        cursor = next;
        if (func_001dc9d0((u32)node) == 0) {
            u8** list = (u8**)(object + 0x18c);
            u8* head = list[0];
            u8* prev;
            if (node == head) {
                prev = 0;
                list[0] = *(u8**)(node + 0x2c);
            } else {
                prev = head;
                u8* pointer = *(u8**)(head + 0x2c);
                while (pointer != node) {
                    u8* following = *(u8**)(pointer + 0x2c);
                    asm("" : "+r"(following)); // why: keeps the next pointer apart from prev so the loop uses three registers
                    prev = pointer;
                    pointer = following;
                }
                *(u8**)(prev + 0x2c) = *(u8**)(node + 0x2c);
            }
            if (node == list[1]) {
                list[1] = prev;
            }
            *(u8**)(node + 0x2c) = 0;
        }
        node = next;
    }
}
