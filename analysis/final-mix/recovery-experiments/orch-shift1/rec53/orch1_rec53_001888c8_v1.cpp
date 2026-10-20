#include "../common/types.h"
extern "C" u32 func_00114580(void*);

void func_001888c8(s32 object) {
    s32 count;
    u16* pointer;

    *(u8*)(object + 9) = 0;
    *(u8*)(object + 7) = 100;
    *(u8*)(object + 0x11) = 1;
    pointer = (u16*)(object + 0x54);
    *(u8*)(object + 4) = 100;
    count = 0x4f;
    *(u8*)(object + 5) = 100;
    *(u8*)(object + 6) = 100;
    *(u8*)(object + 10) = 0;
    *(u8*)(object + 0xb) = 0;
    *(u8*)(object + 0xc) = 0;
    *(u8*)(object + 0xd) = 0;
    *(u8*)(object + 0xe) = 0;
    *(u8*)(object + 0xf) = 1;
    *(u8*)(object + 0x10) = 1;
    *(u8*)(object + 0x12) = 0;
    do {
        *pointer = 0;
        count = count + -1;
        pointer = pointer + 1;
    } while (count != -1);
    func_00114580((void*)(object + 0xf4));
}
