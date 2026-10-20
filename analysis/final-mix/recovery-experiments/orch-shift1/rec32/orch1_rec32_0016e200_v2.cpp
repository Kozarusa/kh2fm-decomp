#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad* func_001dc648(s32);

struct Holder {
    s32 key;
    Quad* source;
};

Quad* func_0016e200(Holder* holder) {
    Quad* result = func_001dc648(holder->key);
    Quad* source = holder->source;
    if (result != source) {
        // why: original used t0 ($8) for the quad copy temporary
        register Quad tmp asm("$8") = *source;
        *result = tmp;
    }
    return result;
}