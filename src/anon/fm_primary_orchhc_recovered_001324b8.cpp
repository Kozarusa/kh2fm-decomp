#include "../common/types.h"
extern "C" u8 D_00347c30[];
extern "C" u32 func_00108398(void*);
extern "C" void func_00132270(u32* object, u32 payload);

void func_001324b8(u32* object, u32 payload) {
    u8* cursor = (u8*)object + 48;
    s32 count = 3;
    func_00132270(object, payload);
    object[0] = (u32)D_00347c30;
    do {
        count--;
        func_00108398(cursor + 16);
        cursor += 144;
    } while (count != -1);
    object[2] = 1;
    object[157] = 0;
    object[158] = 0;
    object[159] = 0;
    object[156] = 0;
}
