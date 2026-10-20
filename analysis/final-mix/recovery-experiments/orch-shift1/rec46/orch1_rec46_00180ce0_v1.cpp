#include "../common/types.h"
extern "C" void func_00180c38(u8*);
extern "C" void func_00180ef0(u8*);

void func_00180ce0(u8* object) {
    s32* counter = *(s32**)(object + 0x148);
    if (counter != 0) {
        *counter = *counter - 1;
        *(s32*)(object + 0x148) = 0;
    }
    func_00180c38(object);
    func_00180ef0(object);
    void (*callback)(s32) = *(void (**)(s32))(object + 0x194);
    if (callback != 0) {
        callback(*(s32*)(object + 8));
        *(s32*)(object + 0x194) = 0;
    }
}