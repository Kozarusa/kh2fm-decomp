#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_00143d10(...);

void func_00140480(Quad* target) {
    Quad first;
    Quad second;
    Quad result;
    s32 outs[4];
    if (&first != target) {
        first = target[0];
    }
    if (&second != target + 1) {
        second = target[1];
    }
    outs[1] = 0;
    if (func_00143d10(&first, &result, &outs[0], &outs[1]) != 0 && target != &result) {
        target[0] = result;
    }
}