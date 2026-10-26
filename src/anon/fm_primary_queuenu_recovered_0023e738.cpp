#include "../common/types.h"
struct Entry { s16 first; s16 pad[3]; s16 second; };
void func_0023e738(u32 object, u32 index, s16 firstWord, s16 secondWord) {
    Entry* entry = (Entry*)(index * 2 + object + 0xb70);
    entry->first = firstWord;
    entry->second = secondWord;
}
