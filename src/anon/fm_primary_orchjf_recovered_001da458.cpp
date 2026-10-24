#include "../common/types.h"
extern "C" u32 func_001da3d8(s32,void*);

struct Holder {
    u32 pad0;
    u32 value;
    u32 cursor;
};

void func_001da458(Holder* object, u32 value, s32* items, s32 count) {
    object->value = value;
    s32 index = 0;
    do {
        u32 cursor = object->cursor;
        index = index + 1;
        *(u32*)cursor = 0;
        object->cursor = cursor + 4;
    } while ((u32)index < 4);
    if (count > 0) {
        s32* entry = items;
        index = count;
        do {
            func_001da3d8((s32)object, entry);
            index = index - 1;
            entry = entry + 1;
        } while (index != 0);
    }
}
