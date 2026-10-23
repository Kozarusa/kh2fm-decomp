#include "../common/types.h"
typedef void (*Callback)(void*);
struct Object { Callback* table; };
extern "C" Object* D_01dad9c0[];

void func_0022d820() {
    Object** pointer = D_01dad9c0;
    s32 count = 31;
    do {
        Object* object = *pointer;
        if (object != 0) {
            object->table[8](object);
            *pointer = 0;
        }
        --count;
        pointer += 2;
    } while (count >= 0);
}
