#include "../common/types.h"
struct Child {
    void** vtable;
};

void func_001d7f80(u8* object) {
    s32 count = *(s32*)(object + 0x2c8);
    s32 index = 0;
    if (count > 0) {
        Child** cursor = (Child**)(object + 0x2a4);
        do {
            Child* child = *cursor;
            cursor++;
            if ((*(u32*)((u8*)child + 12) & 0x10) == 0) {
                ((void (*)(Child*))child->vtable[1])(child);
                count = *(s32*)(object + 0x2c8);
            }
            index++;
        } while (index < count);
    }
    *(u32*)(object + 4) |= 1;
}
