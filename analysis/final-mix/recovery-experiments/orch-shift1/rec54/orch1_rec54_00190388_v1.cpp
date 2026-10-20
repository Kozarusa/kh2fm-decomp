#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_001902a8(u64, u64);

struct Local {
    u8 head[12];
    s32 zero;
    Quad value;
};

Quad* func_00190388(Quad* destination, u32 source) {
    Local local;
    local.zero = 0;
    func_001902a8(source, (u32)&local);
    *destination = local.value;
    return destination;
}
