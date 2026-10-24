#include "../common/types.h"

extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_003032d0(u64,void*);

struct LocalData {
    u32 input;
    u32 value;
};

struct Packet {
    LocalData* data;
    u32 flag;
    u32 value;
};

struct Frame {
    Packet packet;
    u32 padding;
    LocalData data;
};

u32 func_00316d18(u32 input, u64 context) {
    Frame frame;
    frame.data.input = input;
    u32 result = func_002ff3fc();
    frame.packet.data = &frame.data;
    frame.packet.flag = 1;
    frame.packet.value = result;
    frame.data.value = result;
    return func_003032d0(context, &frame.packet);
}
