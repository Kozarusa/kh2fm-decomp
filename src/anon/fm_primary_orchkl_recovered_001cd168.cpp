#include "../common/types.h"
// why: 16-byte alignment makes the block move copy 64 bytes per loop iteration as the original does (v1 with 8-byte alignment copied 32)
struct __attribute__((aligned(16))) Block { u64 words[0x10fc0 / 8]; };
struct Header { u16 halves[5]; };
struct Table { u32 words[2088 / 4]; };
struct State {
    Header header;
    Table first;
    Table second;
};
extern "C" Block D_0032bb30;
extern "C" Block D_01d499b0;
extern "C" Header D_0032bae0;
extern "C" Table D_0034f250;
extern "C" Table D_0034fa78;
extern "C" State D_01d5a970;
// why: no accepted declaration; the callee returns a 0/1 flag in v0 (read from its packet)
extern "C" s32 func_001cd4c0();

s32 func_001cd168() {
    // why: both exits leave the func_001cd4c0 flag in v0, so the flag is returned
    s32 result = func_001cd4c0();
    if (result != 0) {
        D_01d499b0 = D_0032bb30;
        D_01d5a970.header = D_0032bae0;
        D_01d5a970.first = D_0034f250;
        D_01d5a970.second = D_0034fa78;
    }
    return result;
}
