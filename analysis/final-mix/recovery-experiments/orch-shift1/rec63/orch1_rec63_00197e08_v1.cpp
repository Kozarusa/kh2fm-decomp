#include "../common/types.h"

extern "C" u8* D_0035037c;
extern "C" void func_001d32e8(u8*, s32, s32);

void func_00197e08(s32 first, s32 second) {
    u8* object = D_0035037c;
    if (object != 0) {
        func_001d32e8(object + 0x40, first, second);
    }
}
