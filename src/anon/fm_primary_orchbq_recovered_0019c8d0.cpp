#include "../common/types.h"
extern "C" s32* D_00350444;
extern "C" void func_00190128(s32*);
extern "C" void func_0019ca20(s32*);

void func_0019c8d0(s32* object) {
    object[0] = 0;
    func_00190128(object + 1);
    object[6] = 0;
    object[8] = 0;
    object[11] = 0;
    func_0019ca20(object);
    if (D_00350444 == 0) {
        D_00350444 = object;
    }
}
