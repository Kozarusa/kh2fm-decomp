#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad* func_001dc670(s32);

struct Holder {
    s32 key;
    Quad* source;
};

Quad* func_0016e500(Holder* holder) {
    Quad* result = func_001dc670(holder->key);
    // why: original held the source pointer in t7 ($15) and the quad temporary in t0 ($8)
    register Quad* source asm("$15") = holder->source;
    if (result != source) {
        register Quad tmp asm("$8") = *source;
        *result = tmp;
        asm volatile("" ::: "memory"); // why: keeps the epilogue restore after the quad store
    }
    return result;
}
