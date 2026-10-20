#include "../common/types.h"
typedef void (*Callback)(u32);
extern "C" u32 D_0035f680[];
extern "C" u32 func_00139d78(...);

void func_002b5768() {
    u32* pointer = D_0035f680;
    s32 count = 3;
    do {
        u32 object = *pointer;
        if (object != 0) {
            if (func_00139d78(object) == 0) {
                *pointer = 0;
            } else {
                *(u32*)(*pointer + 0x1b4) = 0;
                register u32 callback_object asm("$4") = *pointer; // why: original virtual receiver loads directly into a0
                register u32 table asm("$14") = *(u32*)callback_object; // why: original vtable temporary lives in t6
                Callback callback = *(Callback*)(table + 0x14);
                callback(callback_object);
                *pointer = 0;
            }
        }
        count--;
        pointer++;
    } while (count >= 0);
}
