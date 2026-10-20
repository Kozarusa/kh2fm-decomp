#include "../common/types.h"
extern "C" u32 func_001fa950(...);

struct Message {
    s32 id;
    s32 pad4;
    s32 pad8;
    f32 value;
    s32 pad10;
    u16 count;
};

struct Entry {
    u8 pad[0x40];
    f32 count;
    f32 value;
};

void func_001fb720(u8* object, Message* message, u8* other) {
    Entry* entry = (Entry*)(object + **(s32**)(other + 12) + 0xa0);
    func_001fa950();
    if (message->id == *(s32*)(object + 12)) {
        entry->value = message->value;
        entry->count = (f32)message->count;
    }
}