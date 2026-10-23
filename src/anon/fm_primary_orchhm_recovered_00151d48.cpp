#include "../common/types.h"
struct Entry {
    u8 data[344];
};
struct Object {
    u8 pad0[456];
    Entry entries[7];
    u8 pad1[2864 - 456 - 344 * 7];
    s32 totals[7];
    s32 key;
    s32 count;
};
extern "C" u8 D_0034a5e8[];
extern "C" int func_0015b4f8(...);
extern "C" u64 func_00239c38(...);
extern "C" u32 func_0023aa98(...);

s32 func_00151d48(Object* object) {
    s32 values[8];
    s32 index = 0;
    s32 total = 0;
    s32 result = func_0015b4f8(D_0034a5e8, object->key, values);
    object->count = result;
    if (result > 0) {
        Entry* entry = object->entries;
        do {
            s32 current = index;
            index++;
            func_00239c38(entry, values[current]);
            result = func_0023aa98(entry);
            entry++;
            total += result;
            object->totals[current] = total;
        } while (index < object->count);
    }
    return result;
}
