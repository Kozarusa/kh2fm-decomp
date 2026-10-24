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
    s32 context;
};
extern "C" s32 D_00365c48;
extern "C" u32 func_002ffd00(...);

// Preserve original registry aliases.
u32 func_002fee78(u8* buffer, u32 format, ...) asm("_Z16wtarget_002fee78jjjj");

u32 func_002fee78(u8* buffer, u32 format, ...) {
    StreamState stream;
    __builtin_va_list arguments;
    stream.flags = 0x208;
    stream.base = stream.cursor = buffer;
    stream.capacity = stream.remaining = 0x7fffffff;
    stream.context = D_00365c48;
    __builtin_stdarg_start(arguments, format);
    u32 result = func_002ffd00(&stream, format, arguments);
    *stream.cursor = 0;
    return result;
}
