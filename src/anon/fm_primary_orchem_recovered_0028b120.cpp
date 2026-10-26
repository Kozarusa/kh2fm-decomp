#include "../common/types.h"
// why: remainder/quotient alias the s16 fields; with plain s32* the second divisor load is merged away (measured, 6 words off)
union Cell { s16 half[2]; s32 word; };
struct Divider { s16 base; u8 pad0[16]; s16 offset; u8 pad1[4]; s16 count; };

void func_0028b120(Divider* object,Cell* remainder,Cell* quotient,s32 value) {
    if (value < 0) value = object->base + object->offset;
    s16 count = object->count;
    remainder->word = value % count;
    quotient->word = value / object->count;
}
