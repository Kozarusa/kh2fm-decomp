#include "../common/types.h"

union Data {
    u16 half[10];
    u32 word[5];
};

void func_00141988(u8* object, Data* source, Data* result) {
    result->word[0] = *(u32*)(object + 16) + (source->half[1] << 4);
    result->word[1] = *(u32*)(object + 16) + (source->half[2] << 4);
    result->word[2] = *(u32*)(object + 16) + (source->half[3] << 4);
    u32 index = source->half[4];
    if (index != 0xffff) {
        result->word[3] = *(u32*)(object + 16) + (index << 4);
        result->word[4] = 4;
        return;
    }
    result->word[4] = 3;
}
