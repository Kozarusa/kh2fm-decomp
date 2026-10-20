#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0017d160(Quad*, Quad*);

struct Pair {
    Quad* first;
    Quad* second;
};

void func_0016d920(volatile Pair* pair) {
    Quad buffer[2];
    Quad* destination;
    buffer[0] = *pair->second;
    destination = &buffer[1];
    *destination = *pair->first; // why: keeps load order
    *(volatile f32*)pair = func_0017d160(destination, &buffer[0]);
}