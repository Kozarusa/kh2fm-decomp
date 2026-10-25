#include "../common/types.h"

struct Request {
    s32 type;
    s32 serial;
    s32 args[6];
};

extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" Request D_01dadc00[64];

s32 func_00234188(s32 first, s32 second, s32 third, s32 fourth, s32 fifth, s32 sixth) {
    s32 serial = D_0035e368;
    Request* request = &D_01dadc00[D_0035e360];
    request->type = 3;
    request->serial = serial;
    request->args[0] = first;
    request->args[1] = second;
    request->args[2] = third;
    request->args[3] = fourth;
    request->args[4] = fifth;
    request->args[5] = sixth;
    D_0035e360 = (D_0035e360 + 1) & 63;
    D_0035e368 = serial + 1;
    return serial;
}
