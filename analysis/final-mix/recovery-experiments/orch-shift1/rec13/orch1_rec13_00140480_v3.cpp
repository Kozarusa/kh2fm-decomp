#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_00143d10(Quad*, Quad*, u8*, s32*);

void func_00140480(Quad* target) {
    Quad first;
    Quad second;
    Quad result;
    u8 flag[4];
    s32 count;
    if (&first != target) {
        first = target[0];
    }
    if (&second != target + 1) {
        second = target[1];
    }
    count = 0;
    if (func_00143d10(&first, &result, flag, &count) != 0 && target != &result) {
        target[0] = result;
    }
}