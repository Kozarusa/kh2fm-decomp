#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0017d160(Quad*, Quad*);

struct Pair {
    Quad* first;
    Quad* second;
};

void func_0016d920(Pair* pair) {
    Quad second = *pair->second;
    Quad first = *pair->first;
    *(f32*)pair = func_0017d160(&first, &second);
}