#include "../common/types.h"
extern "C" void func_00224828();
extern "C" void func_0022afe8(s32);
extern "C" f32 D_00371110;
void func_0022afa0(s32 value) {
    func_00224828();
    f32* pointer = &D_00371110;
    asm("" : "+r"(pointer)); // why: retains original separate global address materialization
    func_0022afe8((s32)((f32)value * *pointer));
}
