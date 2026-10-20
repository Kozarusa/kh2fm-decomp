#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec4 {
    Quad value;
    Vec4& operator=(const Vec4& other) {
        if (this != &other) {
            value = other.value;
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
    D_01c5f480 = func_001ca148(holder->first[1], holder->second[1], holder->scale);
    holder->first = (u32*)&D_01c5f480;
}