#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036c574;
extern "C" u32 func_0011b6a8(void*);
extern "C" void func_0011b7b0(void*, void*);

u8* func_0017d8c0(u8* object, void* vector, Quad* source) {
    func_0011b6a8(object);
    func_0011b7b0(object, vector);
    // why: original keeps the destination pointer in s0 (reuses the vector register)
    register Quad* destination asm("$16") = (Quad*)(object + 0x30);
    if (destination != source) {
        *destination = *source;
    }
    asm volatile("" ::: "memory"); // why: keeps the constant load after the copy join
    ((f32*)destination)[3] = D_0036c574;
    return object;
}
