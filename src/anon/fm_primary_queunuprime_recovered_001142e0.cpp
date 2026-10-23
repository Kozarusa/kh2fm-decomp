#include "../common/types.h"
struct BufferContext {u32 words[2];f32*buffer;};

f32 func_001142e0(BufferContext*object,s32 index,u8 first,u8 second) { if(first) {if(second)return object->buffer[index*2+8];return object->buffer[index*2+16];} return object->buffer[index*2+0];}
