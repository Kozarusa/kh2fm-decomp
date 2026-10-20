#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_001391a8(u8*, Quad*);
extern "C" s32 func_00139d78(u8*);

void func_0013e3b0(u8* object, Quad* source) {
    Quad copy = *source;
    func_001391a8(object, &copy);
    if (func_00139d78(object + 0x1c0)) {
        copy = *source;
        func_001391a8(object + 0x1c0, &copy);
    }
}
