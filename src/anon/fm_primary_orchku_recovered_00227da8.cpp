#include "../common/types.h"
struct Entry {
    s32 words[10];
};
extern "C" Entry* D_0035dcfc;

void func_00227da8(Entry* source) {
    s32 index;
    for (index = 0; index < 96; index++) {
        Entry* entry = (Entry*)(index * sizeof(Entry) + (u32)D_0035dcfc);
        if (entry->words[0] == -1) {
            *entry = *source;
            return;
        }
    }
}
