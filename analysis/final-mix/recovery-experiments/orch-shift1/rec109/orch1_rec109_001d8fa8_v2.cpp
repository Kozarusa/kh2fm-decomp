#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

void func_001d8fa8(u8 select, s32 index) {
    if (func_001bb4a0()) {
        u8* entry = (u8*)(func_001bbcb0() + index * 0x34);
        if (*(u32*)(entry + 0x19c) & 1) {
            void** vtable = *(void***)(entry + 400);
            void (*method)(u8*);
            if (select != 0) {
                method = (void (*)(u8*))vtable[3];
            } else {
                method = (void (*)(u8*))vtable[4];
            }
            method(entry + 400);
        }
    }
}
