#include "../common/types.h"

struct Request {
    s32 type;
    s32 serial;
    s32 args[6];
};

extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" Request D_01dadc00[64];

// Preserve original registry aliases.
s32 func_00234298(s32 first, s32 second, s32 third, s32 fourth) asm("_Z16wtarget_00234298jjjj");

s32 func_00234298(s32 first, s32 second, s32 third, s32 fourth) {
    s32 serial = D_0035e368;
    Request* request = &D_01dadc00[D_0035e360];
    request->type = 6;
    request->serial = serial;
    request->args[0] = first;
    request->args[1] = second;
    request->args[2] = third;
    request->args[3] = fourth;
    D_0035e360 = (D_0035e360 + 1) & 63;
    D_0035e368 = serial + 1;
    return serial;
}
