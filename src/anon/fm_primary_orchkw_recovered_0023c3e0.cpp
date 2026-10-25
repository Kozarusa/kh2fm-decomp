#include "../common/types.h"
struct Key0023c3e0 {
    u16 first;
    u8 pad[18];
};
struct Slot0023c3e0 {
    s32 unused;
    s32 group;
    s32 index;
    u8 pad[12];
};
struct Object0023c3e0 {
    u8 pad0[0x10];
    Slot0023c3e0* slots;
    Key0023c3e0* keys;
    u8 pad18[0xc];
    s32 groupCount;
    u8 pad28[4];
    u8* groups;
    u8* entries;
    s32 slotCount;
    u8 pad38[0x14];
    s32 keyIndex;
};

u8* func_0023c3e0(Object0023c3e0* object, s32 position, s32 skip) {
    s32 base = 0;
    s32 group = 0;
    s32 groupCount = object->groupCount;
    if (groupCount > 0) {
        s32* size = (s32*)(object->groups + 0xf8);
        do {
            register s32 start asm("$12") = base; // why: original keeps the group start in t4
            base += *size;
            if (position < base) {
                register s32 keyIndex asm("$13") = object->keyIndex; // why: original loads the key index into t5
                s32 local = position - start;
                register Key0023c3e0* key asm("$14") = object->keys + keyIndex; // why: original forms the key address in t6
                s32 slotCount = object->slotCount;
                Slot0023c3e0* slot = &object->slots[key->first];
                s32 i = 0;
                if (slotCount > 0) {
                    s32 offset = 0;
                    do {
                        if (slot->group == group && slot->index == local) {
                            if (skip == 0) {
                                return object->entries + offset;
                            }
                            skip--;
                        }
                        i++;
                        offset += 0x158;
                        slot++;
                    } while (i < slotCount);
                }
            }
            group++;
            size += 0x56;
        } while (group < groupCount);
    }
    return 0;
}
