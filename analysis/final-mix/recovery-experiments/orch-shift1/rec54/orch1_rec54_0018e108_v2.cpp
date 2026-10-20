#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_0034eef0[];
extern "C" Quad D_0034ef00[];

void func_0018e108(Quad* source0, Quad* source1) {
    Quad* target0 = D_0034eef0;
    if (source0 != target0) {
        *target0 = *source0;
    }
    Quad* target1 = D_0034ef00;
    if (source1 != target1) {
        *target1 = *source1;
    }
}
