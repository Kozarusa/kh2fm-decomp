#include "../common/types.h"
struct Entry12 { s32 first; s32 second; s32 third; };
struct Owner {
    u8 pad[0x9b4];
    s32 entry;
    u8 pad2[0x2c];
    Entry12 list[1];
};

void func_00198aa8(Owner* object, s32 index, s32 value, s32 slot) {
    if (slot == 0) {
        slot = -1;
        s32 entry = object->entry;
        if (entry != 0) {
            slot = *(s16*)(entry + 2);
        }
    }
    s32 total = slot * 1000 + value;
    object->list[index].first = total;
}
