#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0017d160(Quad*, Quad*);

struct Pair {
    Quad* first;
    Quad* second;
};

f32 func_0016d920(Pair* pair) {
    Quad buffer[2];
    // why: lq/sq copy primitive (as kn::FVector::operator=, without the self test); plain quad copies fail on register order
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&buffer[0]), "r"(pair->second) : "$8", "memory");
    // why: lq/sq copy primitive, destination pointer formed before the source load as in the original
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&buffer[1]), "r"(pair->first) : "$8", "memory");
    f32 result = func_0017d160(&buffer[1], &buffer[0]);
    *(f32*)pair = result;
    return result; // R4.3: callee $f0 is still live at the epilogue
}
