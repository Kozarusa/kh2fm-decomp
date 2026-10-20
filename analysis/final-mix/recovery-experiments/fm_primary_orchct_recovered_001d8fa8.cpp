#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

void func_001d8fa8(u8 select, s32 index) {
    if (func_001bb4a0()) {
        u8* entry = (u8*)(func_001bbcb0() + index * 0x34);
        if (*(u32*)(entry + 0x19c) & 1) {
            u8* object = entry + 400;
            // why: original holds the vtable pointer in t6 ($14)
            register void** vtable asm("$14") = *(void***)object;
            // why: original holds the method pointer in t7 ($15)
            register void (*method)(u8*) asm("$15");
            if (select != 0) {
                method = (void (*)(u8*))vtable[3];
            } else {
                method = (void (*)(u8*))vtable[4];
            }
            method(object);
        }
    }
}
