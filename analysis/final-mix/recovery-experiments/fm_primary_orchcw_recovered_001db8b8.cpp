#include "../common/types.h"
struct Buf {
    u32 pad0;
    u32 pad4;
    s32 count;
    u32 base;
    u32* data;
    u32 divisor;
};

void func_001db8b8(Buf* buf, u32 value) {
    s32 index = buf->count;
    u32 quotient = (value - buf->base) / buf->divisor;
    buf->data[index] = quotient;
    buf->count = index + 1;
}
