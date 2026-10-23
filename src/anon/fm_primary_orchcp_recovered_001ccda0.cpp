#include "../common/types.h"
extern "C" void func_001c6ee8(u8*);
extern "C" u8* func_001c16f0(u32, u8*);
extern "C" s32 func_00186078(s32);

void func_001ccda0(u8* object) {
    u8* cursor;
    s32 next;
    func_001c6ee8(object);
    cursor = 0;
    while ((cursor = func_001c16f0(*(u32*)(object + 0x9f4), cursor)) != 0) {
    }
    next = 0;
    do {
        next = func_00186078(next);
    } while (next != 0);
}
