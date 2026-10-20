#include "../common/types.h"
struct BufferContext {u32 words[2];f32*buffer;};
f32 func_00114328(BufferContext*object,s32 index,u8 first,u8 second) { if (!first) return object->buffer[index*2+1]; if (second) return object->buffer[index*2+9]; return object->buffer[index*2+17]; }
