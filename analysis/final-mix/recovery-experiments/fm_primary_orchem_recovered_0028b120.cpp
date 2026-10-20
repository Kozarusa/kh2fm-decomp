#include "../common/types.h"
union Value { s16 half[2]; s32 word; };

void func_0028b120(Value* object,Value* remainder,Value* quotient,s32 value) {
    if (value < 0) value = object[0].half[0] + object[4].half[1];
    s16 count = object[6].half[0];
    remainder->word = value % count;
    quotient->word = value / object[6].half[0];
}
