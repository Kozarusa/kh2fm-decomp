#include "../common/types.h"
struct Out {
    s32 a;
    s32 b;
    s32 c;
    u8* pointer;
    s32 pad[4];
};
extern "C" void func_001902a8(s32*, Out*);

void func_0019ca28(s32* object, s32* source) {
    Out out;
    // why: C10a local first so the zero store follows the load
    s32 first = source[0];
    // why: C10d barrier keeps the zero store after the first lw
    asm volatile("" ::: "memory");
    out.pointer = 0;
    object[1] = first;
    object[2] = source[1];
    object[3] = source[2];
    object[4] = source[3];
    object[5] = source[4];
    func_001902a8(object + 1, &out);
    object[9] = out.pointer[1];
}