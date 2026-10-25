#include "../common/types.h"

struct SoundRequest {
    u8 header[16];
    s32 data;      // 0x10
    s32 size;      // 0x14
    s32 channel;   // 0x18
    u8 reserved[20];
    u8 state;      // 0x30
    u8 kind;       // 0x31
};

// why: the request list head whose address is passed as the first argument
extern "C" u8 D_01e2aa80[];
// why: declarations copied from the packet-listed caller 002ba140
extern "C" s32 func_002b7440(s32,s32,s32);
extern "C" s32 func_002b79cc(s32,s32,s32);
extern "C" s32 func_002b986c(u32,u32);
extern "C" u32 func_00324718(void*,s32);

s32 func_002bb510(SoundRequest* request)
{
    func_00324718(D_01e2aa80, (s32)request);
    if (request->state == 1) {
        return 1;
    }
    switch (request->kind) {
    case 5:
        return func_002b79cc(request->channel, request->data, 0) != 0;
    case 6:
        return func_002b986c(request->channel, request->data) != 0;
    default:
        return func_002b7440(request->channel, request->data, request->size) != 0;
    }
}
