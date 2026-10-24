#include "../common/types.h"
struct Item;
struct ItemTable {
    u8 pad[0x20];
    void (*update)(Item*);
};
struct Item {
    ItemTable* table;
};
extern "C" bool func_001c0cd8(s32);
extern "C" void func_001c0e60(s32);
extern "C" u32 func_00177498(...);
extern "C" u64 func_001a1840(...);
extern "C" void func_00186020(u8*);

void func_00175928(u8* object) {
    if ((*(u32*)(object + 0x108) & 0x10000000) != 0) {
        return;
    }
    if (func_001c0cd8((s32)object)) {
        func_001c0e60((s32)object);
    }
    Item** cursor = (Item**)(object + 0xaf8);
    func_00177498(object);
    s32 count = 1;
    do {
        Item* item = *cursor++;
        if (item != 0) {
            item->table->update(item);
        }
    } while (--count >= 0);
    s32 target = *(s32*)(object + 0x48c);
    if (target != 0) {
        func_001a1840(target);
    }
    func_00186020(object);
}
