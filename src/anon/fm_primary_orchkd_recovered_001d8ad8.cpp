#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u8* func_001bbcb0(void);

typedef s32 (*Handler)(u8*);

s32 func_001d8ad8(s32 index, u8 enable) {
    u8* entry = func_001bbcb0() + index * 0x38;
    s32 result = func_001bb4a0();
    u8* object = entry + 0xe8;
    if (result != 0) {
        u32 bits = *(u32*)(entry + 0xf4);
        if ((u8)(bits & 1) != 0) {
            register Handler handler asm("$15"); // why: original holds the virtual handler in t7 for the shared jalr; unbound it lands in v0
            if (enable != 0) {
                if ((bits & 8) != 0) {
                    return result;
                }
                handler = (*(Handler**)object)[3];
            } else {
                if ((bits & 8) == 0) {
                    return result;
                }
                handler = (*(Handler**)object)[4];
            }
            result = handler(object);
        }
    }
    return result;
}
