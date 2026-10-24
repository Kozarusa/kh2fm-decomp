#include "../common/types.h"
struct StreamState {
    u8* cursor;
    s32 pending;
    s32 remaining;
    s16 flags;
    s16 reserved;
    u8* base;
    s32 capacity;
    u8 pad[60];
    u8* context;
};
extern "C" u64 func_002ffd78(...);

u64 func_003015a8(u8* context, u8* buffer, u32 format, __builtin_va_list arguments) {
    StreamState stream;
    stream.flags = 0x208;
    stream.base = stream.cursor = buffer;
    stream.capacity = stream.remaining = 0x7fffffff;
    stream.context = context;
    u64 result = func_002ffd78(context, &stream, format, arguments);
    *stream.cursor = 0;
    return result;
}
