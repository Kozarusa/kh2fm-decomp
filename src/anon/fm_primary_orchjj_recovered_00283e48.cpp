#include "../common/types.h"
struct Entry {
    u8 pad[6];
    u8 value;
    u8 pad7;
};
struct State {
    u8 pad[4];
    s8 list[9];
    s8 count;
    s8 index;
};
extern "C" u32 func_002835a8();
extern "C" u32 func_00283900(s32);
extern "C" State* D_0035f2b4;
extern "C" Entry D_003742c8[];

u32 func_00283e48() {
    State* state = D_0035f2b4;
    if (state->index + 1 >= state->count) {
        return func_002835a8();
    }
    return func_00283900(D_003742c8[state->list[state->index]].value != D_003742c8[state->list[state->index + 1]].value);
}
