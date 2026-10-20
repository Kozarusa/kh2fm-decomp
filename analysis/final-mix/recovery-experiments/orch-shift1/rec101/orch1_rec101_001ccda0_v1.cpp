#include "../common/types.h"
extern "C" void func_001c6ee8(u8*);
extern "C" u8* func_001c16f0(u32, u8*);
extern "C" u8* func_00186078(u8*);

void func_001ccda0(u8* object) {
    u8* cursor;
    func_001c6ee8(object);
    cursor = 0;
    while ((cursor = func_001c16f0(*(u32*)(object + 0x9f4), cursor)) != 0) {
    }
    cursor = 0;
    do {
        cursor = func_00186078(cursor);
    } while (cursor != 0);
}