#include "../common/types.h"
typedef void (*Callback)(u32);
extern "C" u8 D_0035f690[];
extern "C" s32 func_00139d78(u32); // copied from fm_primary_nearhelper_recovered.cpp

// Preserve original registry aliases.
void func_002b5a50() asm("_ZN2Tz8CmSLBase18GetCurrentListItemEv");

void func_002b5a50() {
    s32 row;
    for (row = 0; row < 3; row++) {
        u32* pointer = (u32*)(D_0035f690 + row * 16);
        s32 count = 3;
        do {
            u32 object = *pointer;
            if (object != 0) {
                if (func_00139d78(object) == 0) {
                    *pointer = 0;
                } else {
                    u32 receiver = *pointer;
                    Callback callback = *(Callback*)(*(u32*)receiver + 0x14);
                    callback(receiver);
                    *pointer = 0;
                }
            }
            count--;
            pointer++;
        } while (count >= 0);
    }
}
