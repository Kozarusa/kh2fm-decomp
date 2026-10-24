#include "../common/types.h"
struct List {
    u8* head;
    u8* tail;
};
extern "C" u8 D_0034ef18[];
extern "C" List D_01c60cd8;
extern "C" void func_0018e040(u8*);
extern "C" void func_001c0058(u32);
extern "C" s32 func_001c0248(u8*);

s32 func_0018d420(u8* object) {
    *(u8**)object = D_0034ef18;
    u8* first = *(u8**)(object + 0x8);
    if (first != 0) {
        *(s32*)(first + 0x488) -= 1;
    }
    u8* second = *(u8**)(object + 0x10);
    if (second != 0) {
        *(s32*)(second + 0x488) -= 1;
    }
    u8* previous;
    if (object == D_01c60cd8.head) {
        D_01c60cd8.head = *(u8**)(object + 0xc0);
        previous = 0;
    } else {
        previous = D_01c60cd8.head;
        u8* node = *(u8**)(previous + 0xc0);
        if (node != object) {
            u8* next;
            do {
                next = *(u8**)(node + 0xc0);
                previous = node;
                node = next;
            } while (next != object);
        }
        *(u8**)(previous + 0xc0) = *(u8**)(object + 0xc0);
    }
    if (object == D_01c60cd8.tail) {
        D_01c60cd8.tail = previous;
    }
    *(u8**)(object + 0xc0) = 0;
    if ((*(u32*)(object + 0x4) & 0x400) == 0) {
        func_0018e040(object);
        func_001c0058(*(u32*)(object + 0x1c));
    }
    s32 result = func_001c0248(object + 0x30);
    asm volatile("" ::: "memory"); // why: original calls with jal and returns on its own, no tail call
    return result;
}
