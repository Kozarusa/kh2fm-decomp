#include "../common/types.h"
struct Slot {
    u32 state;
    u32 sector;
    u32 stream;
    u32 position;
};
struct Stream {
    u32 slot;
    u32 address;
    u32 size;
    u32 sector;
    u8 rest[28];
};
struct Record {
    u32 word0;
    u32 flags;
    u32 sector;
    u32 address;
};
extern "C" Slot D_0034d800[];
extern "C" Stream D_01c6cf00[];
extern "C" u32 func_001ae460(...);

// name: a0 is never written before the jal, so the caller's a0 reaches func_001ae460 (its accepted callers pass the name there)

Slot* func_001ae6a8(u32 name) {
    s32 index;
    s32 stream_index;
    for (index = 0; index < 4; index++) {
        if (D_0034d800[index].stream == 0) {
            break;
        }
    }
    for (stream_index = 0; stream_index < 4; stream_index++) {
        if (D_01c6cf00[stream_index].slot == 0) {
            break;
        }
    }
    Record* record = (Record*)func_001ae460(name);
    Slot* slot = &D_0034d800[index];
    Stream* stream = &D_01c6cf00[stream_index];
    // why: word views keep the field stores in the original order (struct member stores were rescheduled)
    u32* slot_words = (u32*)slot;
    u32* stream_words = (u32*)stream;
    slot_words[0] = 0;
    u32 sector = record->address;
    // why: source order of each same-value store pair is reversed relative to the emitted order
    stream_words[3] = sector;
    slot_words[1] = sector;
    slot_words[2] = (u32)stream;
    slot_words[3] = 0;
    stream_words[0] = (u32)slot;
    u32 address = record->sector;
    stream_words[2] = address;
    stream_words[1] = address;
    return slot;
}
