#include "../common/types.h"
union Field {
    u8 byte;
    u16 half;
    s16 signedHalf;
    s32 word;
    f32 real;
};

f32 func_00232ea0(u8* object, u8* data, s32* source, s32 value) {
    ((Field*)(object + 0))->word = ((Field*)source)[0].word;
    ((Field*)(object + 4))->word = ((Field*)source)[1].word;
    ((Field*)(object + 8))->word = ((Field*)source)[2].word;
    f32 size = (f32)((Field*)(data + 8))->half;
    ((Field*)(object + 20))->real = size + size;
    ((Field*)(object + 24))->half = ((Field*)(data + 10))->half;
    ((Field*)(object + 26))->half = ((Field*)(data + 12))->half;
    s32 count = ((Field*)(data + 8))->half;
    s32 offset = ((Field*)(data + 16))->signedHalf;
    ((Field*)(object + 48))->byte = 1;
    ((Field*)(object + 12))->word = value;
    f32 result = (f32)(count - offset);
    result = result + result;
    ((Field*)(object + 16))->real = result;
    return result;
}
