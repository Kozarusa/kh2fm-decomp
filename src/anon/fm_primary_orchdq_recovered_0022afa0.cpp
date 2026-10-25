#include "../common/types.h"
extern "C" void func_00224828();
extern "C" void func_0022afe8(s32);

void func_0022afa0(s32 value) {
    func_00224828();
    register f32 converted asm("$f0") = (f32)value;
         func_0022afe8((s32)(converted * 1.5f));
}
