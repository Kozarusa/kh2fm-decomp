#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec4 {
    Quad q;
    Vec4& operator=(const Vec4& other) {
        if (this != &other) {
            q = other.q;
        }
        return *this;
    }
};
extern "C" Vec4 D_004f37b0;
extern "C" Vec4 D_004f37a0;
extern "C" Vec4 D_004f3790;
extern "C" Vec4 D_004f3780;
extern "C" Vec4 D_004f37e0;
extern "C" Vec4 D_004f37d0;

void func_0015cff0() {
    D_004f37b0 = D_004f37a0;
    D_004f3790 = D_004f3780;
    D_004f37e0 = D_004f37d0;
}
