#include "../common/types.h"
extern "C" u32 func_001da3d8(s32,void*);

struct Holder {
    u32 pad0;
    u32 value;
    u32* cursor;
};

void func_001da458(Holder* object, u32 value, s32* items, s32 count) {
    object->value = value;
    u32 index = 0;
    do {
        u32* cursor = object->cursor;
        index = index + 1;
        *cursor = 0;
        object->cursor = cursor + 1;
    } while (index < 4);
    if (count > 0) {
        index = count;
        do {
            func_001da3d8((s32)object, items);
            index = index - 1;
            items = items + 1;
        } while (index != 0);
    }
}
