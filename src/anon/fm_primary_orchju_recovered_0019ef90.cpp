#include "../common/types.h"
union Half {
    s16 word;
    u8 low;
};
struct Source {
    Half kind;
    Half first;
    Half second;
    Half third;
    s16 range;
    Half value;
};
struct Entry {
    u8 index;
    u8 kind;
    u8 flag;
    u8 pad;
    s16 first;
    s16 second;
    s16 third;
};
struct Target {
    s32 kind;
    Entry entry;
    s32 value;
};
extern "C" const void* D_0036d40c[7];
extern "C" void func_00199718(void* a0, u32 a1, s32 a2);

void func_0019ef90(Target* target, Source* source) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036d40c
    static const void* targets[7] asm("fm_switch_table_0019ef90") = {
        &&done, &&single, &&lookup, &&done, &&index_only, &&done, &&done};
    target->kind = source->kind.word;
    target->value = source->value.word;
    u32 index = (u16)source->kind.word;
    if (index >= 7) goto done;
    goto *D_0036d40c[index];
index_only:
    target->entry.index = source->first.low;
done:
    return;
single:
    target->entry.index = source->first.low;
    target->entry.kind = source->second.low;
    u8 flag = source->third.low;
    target->entry.third = -1;
    target->entry.flag = flag;
    target->entry.second = -1;
    target->entry.first = -1;
    return;
lookup:
    Entry found;
    func_00199718(&found, source->range, source->first.word);
    target->entry = found;
    target->entry.flag = source->third.low;
}
