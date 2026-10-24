#include "../common/types.h"
extern "C" const void* D_0036b2d8[5];
extern "C" s64 func_001a1de0(s32);

s32 func_00155f40(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036b2d8
    static const void* targets[5] asm("fm_switch_table_00155f40") = {
        &&other, &&other, &&kind2, &&kind3, &&kind4};
    u8* owner = *(u8**)(object + 0x34);
    s32 result = 0x17;
    if (owner != 0) {
        u32 kind = *(u8*)(*(u8**)(owner + 0x48c) + 0x1af);
        if (kind >= 5) goto other;
        goto *D_0036b2d8[kind];
    kind4:
        result = 0x13;
        goto done;
    other: {
        s64 flag = func_001a1de0(*(s32*)(owner + 0x48c));
        result = 0x1a;
        if (flag == 0) {
            result = 0x17;
        }
        goto done;
    }
    kind2:
        result = 0x33;
        goto done;
    kind3:
        result = 0x8d;
    }
done:
    return result;
}
