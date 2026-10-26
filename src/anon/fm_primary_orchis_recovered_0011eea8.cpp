#include "../common/types.h"

void func_0011eea8(u8* object, u8* value) {
    u8* pointer = *(u8**)(object + 8);
    if (pointer == value) {
        *(u8**)(object + 8) = *(u8**)(value + 4);
        return;
    }
    u8* previous = pointer;
    u8* next = *(u8**)(pointer + 4);
    while (next != 0 && next != value) {
        u8* loaded = *(u8**)(next + 4);
        previous = next;
        next = loaded;
    }
    *(u8**)(previous + 4) = *(u8**)(value + 4);
}
