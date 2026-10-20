#include "../common/types.h"
extern "C" u8 D_00341060[];
extern "C" u8 D_00341270[];
extern "C" u8 D_00341480[];
extern "C" void func_001342c8(u8*, s32, s32);

void func_0010ab08(s32 value) {
    u8* pointer;
    if (value == 1) {
        pointer = D_00341270;
    } else if (value < 2) {
        if (value != 0) {
            return;
        }
        pointer = D_00341060;
    } else {
        if (value != 2) {
            return;
        }
        pointer = D_00341480;
    }
    func_001342c8(pointer, 33, 0x13000000);
}
