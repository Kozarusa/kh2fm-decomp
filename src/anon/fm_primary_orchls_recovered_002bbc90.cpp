#include "../common/types.h"

// why: layout of the sound request from the accepted definition of 002bb510,
// extended with the two halfword fields this function reads at 0x28 and 0x2c
struct SoundRequest {
    u8 header[16];
    s32 data;      // 0x10
    s32 size;      // 0x14
    s32 channel;   // 0x18
    u8 reserved[12];
    s16 left;      // 0x28
    u8 pad0[2];
    s16 right;     // 0x2c
    u8 pad1[2];
    u8 state;      // 0x30
    u8 kind;       // 0x31
};

// why: return types copied from the accepted caller 00303c48 and the accepted
// definitions of 002bb510 and 0014eda8; parameters derived from the argument
// registers set before each call (a0..a3, halfwords loaded with lh)
extern "C" u32 func_002b95e8(s32, s32, s32, s32);
extern "C" u32 func_002b9728(s32, s32, s32, s32);
extern "C" s32 func_002bb510(SoundRequest* request);
extern "C" u32 func_002bb5f8(SoundRequest*);
extern "C" s32 func_002bb8b0(SoundRequest*);
extern "C" void func_002bc358(s32, s32);

void func_002bbc90(SoundRequest* request)
{
    switch (request->state) {
    case 0:
        break;
    case 1:
        func_002bb8b0(request);
        func_002b95e8(request->channel, request->data, request->left, request->right);
        request->state = 2;
        break;
    case 2:
        if (func_002bb510(request)) {
            func_002bb5f8(request);
            func_002bb8b0(request);
            func_002b9728(request->channel, request->data, request->left, request->right);
            return;
        }
        func_002bc358(request->size, 1);
        break;
    case 3:
        func_002bc358(request->size, 1);
        break;
    }
}
