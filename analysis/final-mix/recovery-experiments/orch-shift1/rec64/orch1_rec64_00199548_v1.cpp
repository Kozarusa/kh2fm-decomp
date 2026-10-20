#include "../common/types.h"
extern "C" s32 D_01c62128[];
extern "C" s32 D_01c62138;
extern "C" s32 D_01c62140;
extern "C" s32 D_01c62144;
extern "C" void func_00199280(void*);
extern "C" s32 func_00102c18(s32, s32, void (*)(void*));

s32 func_00199548() {
    s32 index = 0;
    s32* pointer = D_01c62128;
    do {
        *pointer = index;
        index++;
        pointer++;
    } while (index < 4);
    D_01c62138 = 4;
    D_01c62140 = 0;
    D_01c62144 = 0;
    return func_00102c18(1, 14500, func_00199280);
}
