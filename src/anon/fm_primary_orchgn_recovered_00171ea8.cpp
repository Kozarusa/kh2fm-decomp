#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    Vec4& operator=(const Vec4& other) {
        if (&other != this) {
            register Quad value asm("$8") = *(const volatile Quad*)&other; // why: original copies through t0
            *(Quad*)this = value;
        }
        return *this;
    }
};
struct Holder {
    u32* first;
    u32* second;
    f32 scale;
};
extern "C" Vec4 D_01c5f480;
extern "C" Vec4 func_001ca148(u32 first, u32 second, f32 scale);

void func_00171ea8(Holder* holder) {
    Vec4 result = func_001ca148(holder->first[1], holder->second[1], holder->scale);
    register Vec4* destination asm("$15") = &D_01c5f480; // why: original keeps the global address in t7
    asm("" : "+r"(destination)); // why: keeps the global address in one register
    *destination = result;
    holder->first = (u32*)destination;
}
