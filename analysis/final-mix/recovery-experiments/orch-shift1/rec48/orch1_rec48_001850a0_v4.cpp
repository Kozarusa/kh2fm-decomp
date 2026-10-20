#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0016c028(u8*);
extern "C" void func_002cbca0(u8*, s32, u32, u8*);

u8* func_001850a0(u8* out, u8* object) {
    if (*(s32*)(object + 1288) == 0) {
        // why: VU zero-vector store has no C++ equivalent
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(out) : "memory");
        return out;
    }
    Quad temp;
    u32 value = func_0016c028(object);
    func_002cbca0((u8*)&temp, *(s32*)(object + 1288), value, object + 1360);
    if (out != (u8*)&temp) {
        // why: original copies the quad through t0
        register Quad copy asm("$8") = temp;
        *(Quad*)out = copy;
        return out;
    }
    return out;
}
