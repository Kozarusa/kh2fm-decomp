#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Temp {
    u8 head[12];
    u32 zero;
    u8 pad[16];
    Quad value;
};
extern "C" void func_001902a8(u64, Temp*);
extern "C" void func_0018a970(Temp*);

void func_001906f0(u64 source, Quad* input) {
    Temp local;
    local.zero = 0;
    func_001902a8(source, &local);
    local.value = *input;
    func_0018a970(&local);
}