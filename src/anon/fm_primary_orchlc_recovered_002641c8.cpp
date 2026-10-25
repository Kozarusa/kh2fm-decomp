#include "../common/types.h"
// why: the original re-masks the lhu count with andi 0xffff, the pattern of a u32 bitfield read
struct IdSet {
    u8 header[8];
    u32 low : 16;
    u32 total : 16;
    u8 gap[4];
    u16 entries[1];
};
// why: accepted definition fm_primary_orchjq_recovered_002642a8.cpp declares no parameter but forwards the untouched a0 to 001a80c8; this caller sets a0 with move a0,s0 from an lhu value, so the parameter is u16; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" s32 func_002642a8(u16 value);

void func_002641c8(IdSet* object, u16* list, s32 count, u16 mask) {
    s32 index = 0;
    if (count > 0) {
        do {
            s32 total = object->total;
            s32 slot = 0;
            u16 value = list[index];
            if (total != 0) {
                u16* entry = object->entries;
                do {
                    if (value == *entry) break;
                    entry++;
                    slot++;
                } while (slot < total);
            }
            if (slot >= (s32)object->total) {
                if (mask & func_002642a8(value)) {
                    u32 used = object->total;
                    object->total++;
                    object->entries[used] = value;
                }
            }
            index++;
        } while (index < count);
    }
}
