#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Local {
    u8 head[12];
    s32 zero;
    Quad value;
};

extern "C" u32 func_001902a8(Local*, Local*);

Quad* func_00190388(Quad* destination, Local* source) {
    Local local;
    Quad* result = &local.value;
    local.zero = 0;
    func_001902a8(source, &local);
    *destination = *result;
    return destination;
}
