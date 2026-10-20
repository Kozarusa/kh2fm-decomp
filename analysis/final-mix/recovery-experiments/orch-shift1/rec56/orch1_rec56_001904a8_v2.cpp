#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_001903d0(u64, void*);

Quad* func_001904a8(Quad* result, u64 source) {
    u8 head[12];
    u32 zero;
    Quad value;
    Quad* pointer = &value;
    zero = 0;
    func_001903d0(source, head);
    *result = *pointer;
    return result;
}