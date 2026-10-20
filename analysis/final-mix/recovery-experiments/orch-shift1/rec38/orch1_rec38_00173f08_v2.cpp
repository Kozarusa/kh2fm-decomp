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
struct Owner { s32 pad; s32 link; };
struct Holder { Owner* owner; };
extern "C" Vec4 D_01c5f480;
extern "C" Vec4* func_0016c028(s32);
extern "C" f32 func_00184a90(s32);

void func_00173f08(Holder* object) {
    Vec4* source = func_0016c028(object->owner->link);
    Vec4* pointer = &D_01c5f480;
    *pointer = *source;
    pointer->y = func_00184a90(object->owner->link);
    *(Vec4**)object = pointer;
}