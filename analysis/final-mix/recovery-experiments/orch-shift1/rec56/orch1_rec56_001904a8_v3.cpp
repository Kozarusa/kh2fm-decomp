#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec { Quad q; };
struct Temp {
    u8 head[12];
    u32 zero;
    Vec value;
};
extern "C" u32 func_001903d0(u64, Temp*);

Vec func_001904a8(u64 source) {
    Temp local;
    local.zero = 0;
    func_001903d0(source, &local);
    return local.value;
}