#include "../common/types.h"

// why: same request layout as the accepted callee 002bb510, with the two
// halfword fields this function reads at 0x28 and 0x2c (lh)
struct SoundRequest {
    u8 header[16];
    s32 data;      // 0x10
    s32 size;      // 0x14
    s32 channel;   // 0x18
    u8 reserved0[12];
    s16 volume;    // 0x28
    s16 reserved1;
    s16 pan;       // 0x2c
    s16 reserved2;
    u8 state;      // 0x30
    u8 kind;       // 0x31
};

// why: types from the accepted definitions 002b7c34 / 002b7cec / 002bb510; extern "C"
// because the probe linker script defines only the plain symbol (the C++ form failed
// to link in v1), and the full build resolves plain func_<addr> names via alias generation
extern "C" u64 func_002b7c34(u32 input0, u32 input1, u32 input2, u32 input3);
extern "C" u64 func_002b7cec(u32 input0, u32 input1, u32 input2, u32 input3);
extern "C" s32 func_002bb510(SoundRequest* request);
// why: no accepted using site; the request pointer is the only argument (a0) and the results are unused
extern "C" void func_002bb5f8(SoundRequest* request);
extern "C" void func_002bb8b0(SoundRequest* request);
// why: declaration copied from the accepted caller 0014eda8
extern "C" void func_002bc358(s32, s32);

void func_002bbbc8(SoundRequest* request)
{
    switch (request->state) {
    case 0:
        // idle: nothing to do
        break;
    case 1:
        func_002bb8b0(request);
        func_002b7c34(request->channel, request->data, request->volume, request->pan);
        request->state = 2;
        break;
    case 2:
        if (func_002bb510(request) != 0) {
            func_002bb5f8(request);
            func_002bb8b0(request);
            func_002b7cec(request->channel, request->data, request->volume, request->pan);
            return;
        }
        func_002bc358(request->size, 1);
        break;
    case 3:
        func_002bc358(request->size, 1);
        break;
    }
}
