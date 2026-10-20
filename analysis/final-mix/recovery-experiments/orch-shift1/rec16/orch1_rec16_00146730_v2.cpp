#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_00144b38(u32, u8*);
extern "C" void func_001466b0(u32, u8*);

void func_00146730(u32 object, u32 other) {
    Quad buffer[8];
    func_00144b38(other, (u8*)buffer);
    func_001466b0(object, (u8*)buffer);
    for (s32 i = 7; i >= 0; i--) {
        buffer[i] = 0;
    }
}
