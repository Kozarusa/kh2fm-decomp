#include "../common/types.h"
struct Slot {
    s32 offset;
    u32 unused;
};
struct Header {
    u32 unused0;
    s32 count;
    u32 unused8;
    Slot slots[1];
};
struct Entry {
    u8 pad[0x80];
    u8* item;
    u8 pad2[12];
};
// why: header and entries are word fields so the count load and the header reload stay after the stores (original order)
struct Owner {
    u32 header;
    u32 entries;
    u32 unused8;
    s32 id;
};
extern "C" s32 D_01d48c90;
// why: copied from the accepted call site in fm_oct7_extended_recovered_00.cpp (the u64 form adds a widening move)
extern "C" u32 func_001050d8(...);
// why: types from the accepted definition in fm_primary_orchav_recovered_001659b8.cpp; extern "C" because that C++-linkage definition is not in the isolated probe link
extern "C" u8* func_001659b8(u32 first, u32 second);
// why: accepted definition in tiny.cpp is void with u32 parameters and reads only a0; the original call sets only a0, so only that first u32 parameter is declared; extern "C" for the isolated probe link
extern "C" void func_00165870(u32 object);

void func_001b2f38(Owner* owner, Header* header, u8 flag) {
    owner->header = (u32)header;
    s32 index = 0;
    owner->entries = func_001050d8(header->count * 144);
    Header* current = (Header*)owner->header;
    if (current->count > 0) {
        do {
            Entry* entry = (Entry*)(index * 144 + owner->entries);
            entry->item = func_001659b8((u32)current + current->slots[index].offset, D_01d48c90);
            if (flag == 0) {
                func_00165870((u32)((Entry*)(index * 144 + owner->entries))->item);
            }
            index++;
            current = (Header*)owner->header;
        } while (index < current->count);
    }
    owner->id = D_01d48c90;
    D_01d48c90++;
}
