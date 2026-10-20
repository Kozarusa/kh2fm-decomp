#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0017d160(Quad*, Quad*);

struct Pair {
    Quad* first;
    Quad* second;
};

void func_0016d920(Pair* pair) {
    Quad buffer[2];
    // why: original used t0 ($8) for the quad copy temporary
    register Quad second asm("$8") = *pair->second;
    buffer[0] = second;
    Quad* destination = &buffer[1];
    asm volatile("" ::: "memory"); // why: keeps the second load after the first quad store
    register Quad first asm("$8") = *pair->first;
    *destination = first;
    *(f32*)pair = func_0017d160(destination, &buffer[0]);
}