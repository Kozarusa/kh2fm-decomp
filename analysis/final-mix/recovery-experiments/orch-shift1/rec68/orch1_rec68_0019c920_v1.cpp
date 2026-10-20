#include "../common/types.h"
extern "C" s32 D_00350444;
extern "C" void func_00190128(u8*);
extern "C" void func_0019ca20(u8*);

void func_0019c920(u8* object) {
    *(s32*)object = 0;
    func_00190128(object + 4);
    *(s32*)(object + 24) = 0;
    *(s32*)(object + 32) = 0;
    *(s32*)(object + 44) = 0;
    func_0019ca20(object);
    if (D_00350444 == 0) {
        D_00350444 = (s32)object;
    }
}
