#include "../common/types.h"
extern "C" u8 D_00347a90[];
extern "C" void func_0011ee58(u32*);
extern "C" void func_0011f3b8(u32*);

void func_00123ba8(u32* object) {
    u8* base = (u8*)object[1];
    object[0] = (u32)D_00347a90;
    s32* cursor = (s32*)(base + 0x10);
    s32 offset = *cursor;
    if (offset != 0) {
        do {
            s32 delta = offset;
            cursor++;
            func_0011f3b8((u32*)(base + delta));
            offset = *cursor;
        } while (offset != 0);
    }
    func_0011ee58(object);
    asm volatile("" ::: "memory"); // why: original does not tail-call the base destructor
}