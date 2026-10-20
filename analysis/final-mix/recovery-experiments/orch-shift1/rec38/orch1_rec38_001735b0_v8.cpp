#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Vec4 {
    f32 x; f32 y; f32 z; f32 w;
    Vec4& operator=(const Vec4& other) {
        if (this != &other) {
            *(Quad*)this = *(const Quad*)&other;
        }
        return *this;
    }
};
struct Holder { Vec4* target; f32 x; f32 y; f32 z; f32 w; };
extern "C" Vec4 D_01c5f480;
extern "C" Vec4 func_001a78c0(Vec4*, f32, f32, f32, f32, s32);

void func_001735b0(Holder* object) {
    Vec4 temp = func_001a78c0(object->target, object->x, object->y, object->z, object->w, 2);
    Vec4* pointer = &D_01c5f480;
    // why: keeps the address in one register so the copy uses a zero offset
    asm("" : "+r"(pointer));
    *pointer = temp;
    object->target = pointer;
}