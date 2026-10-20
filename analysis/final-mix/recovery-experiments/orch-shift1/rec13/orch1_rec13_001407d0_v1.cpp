#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0015ce80(...);
extern "C" void func_0015ce90(...);
extern "C" void func_0015cea0(Quad*);
extern "C" void func_0015ceb8(Quad*);
extern "C" f32 func_0015ced0();
extern "C" f32 func_0015cee0();

void func_001407d0(Quad* object) {
    Quad temp;
    if (func_0015ce80(object) != 0) {
        func_0015ceb8(&temp);
        if (object != &temp) {
            *object = temp;
        }
        Quad* second = object + 1;
        func_0015cea0(&temp);
        if (second != &temp) {
            *second = temp;
        }
        ((f32*)object)[8] = func_0015ced0();
        ((f32*)object)[9] = func_0015cee0();
        func_0015ce90();
    }
}