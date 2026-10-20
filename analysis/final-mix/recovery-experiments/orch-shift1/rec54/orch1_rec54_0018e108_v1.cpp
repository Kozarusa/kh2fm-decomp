#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_0034eef0;
extern "C" Quad D_0034ef00;

void func_0018e108(Quad* source0, Quad* source1) {
    if (source0 != &D_0034eef0) {
        D_0034eef0 = *source0;
    }
    if (source1 != &D_0034ef00) {
        D_0034ef00 = *source1;
    }
}
