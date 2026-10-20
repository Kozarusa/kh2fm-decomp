#include "../common/types.h"

void func_0017f380(u8* object) {
    u8* child;
    u8* next;
    *(s32*)(object + 60) = 0;
    child = 0;
    *(s32*)(object + 64) = 0;
    do {
        if (child == 0) {
            next = *(u8**)(object + 148);
        } else {
            next = *(u8**)(child + 156);
        }
        child = next;
        if (next != 0) {
            func_0017f380(next);
        }
    } while (next != 0);
}
