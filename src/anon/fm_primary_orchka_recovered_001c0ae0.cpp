#include "../common/types.h"
struct Entry {
    u32 id;
    u32 pad;
    u8 data[24];
};
struct Table {
    u32 pad;
    s32 count;
    Entry entries[1];
};
extern "C" Table* D_01d49360;
extern "C" u32 D_0032f254[];
extern "C" void func_001c0a80(u8* object); // why: accepted C++ definition (fm_primary_indexloop_recovered.cpp) with C linkage for the isolated probe link
extern "C" void func_001c0ab0(u8*, u8*);

void func_001c0ae0(u8* object) {
    s32 index = 0;
    func_001c0a80(object);
    Entry* entry = D_01d49360->entries;
    for (; index < D_01d49360->count; index++, entry++) {
        register u32 id asm("$13") = entry->id; // why: original holds the entry id in t5
        u32 mask = 1u << (id & 0x1f);
        asm("" : "+r"(mask)); // why: keeps the sllv mask; otherwise the test folds into srlv+andi
        if ((D_0032f254[id >> 5] & mask) != 0) {
            func_001c0ab0(object, entry->data);
        }
    }
}
