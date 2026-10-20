#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 D_0034e948;
extern "C" Quad D_00352a60;
extern "C" bool func_0019ba60(s32);
extern "C" Quad* func_0016c028(s32);
extern "C" void func_001dbcd0();
extern "C" void func_001c2578(s32) asm("_ZN2YS7MASSOBJ9_OVR_execEv");

void func_001dbad0(s32 object) {
    if (func_0019ba60(D_0034e948)) {
        Quad* source = func_0016c028(D_0034e948);
        if (source != &D_00352a60) {
            D_00352a60 = *source;
        }
    }
    func_001dbcd0();
    func_001c2578(object);
}