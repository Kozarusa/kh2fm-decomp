#include "../common/types.h"
struct Child {
    void** vtable;
};

void func_001d8070(u8* object) {
    s32 index = 0;
    if (*(s32*)(object + 0x2c8) > 0) {
        Child** cursor = (Child**)(object + 0x2a4);
        do {
            Child* child = *cursor;
            index++;
            ((void (*)(Child*))child->vtable[2])(child);
            cursor++;
        } while (index < *(s32*)(object + 0x2c8));
    }
    *(u32*)(object + 4) &= ~1u;
}
