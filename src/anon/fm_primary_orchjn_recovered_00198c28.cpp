#include "../common/types.h"
extern "C" u8 D_01c61b48[];
extern "C" void func_00198dc0(u8*);

u8* func_00198c28(s32 key, s32 index) {
    u8* pointer = D_01c61b48;
    u8* entry = D_01c61b48;
    u8* slot = 0;
    u8* end = D_01c61b48 + 1408;
    do {
        if (*(s32*)entry == key && *(s32*)(entry + 4) == index) {
            return entry;
        }
        if (*(s32*)pointer < 0) {
            slot = pointer;
        }
        pointer += 88;
        entry += 88;
    } while ((s32)pointer < (s32)end);
    func_00198dc0(slot);
    *(s32*)slot = key;
    *(s32*)(slot + 4) = index;
    return slot;
}
