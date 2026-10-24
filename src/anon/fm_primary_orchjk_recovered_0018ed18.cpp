#include "../common/types.h"
extern "C" s32 func_00186078(s32);
extern "C" u64 func_0019bb58(...);
extern "C" u32 func_0018d940(...);
extern "C" u32 func_0018f010(u32);
extern "C" u8* func_001b7998(s32* list, s32 key);
extern "C" u32 func_0018e298(u32* holder, u8* owner, u8* entry);

s32 func_0018ed18(s32* table) {
    s32 object = 0;
    while ((object = func_00186078(object)) != 0) {
        if (func_0019bb58(object) == 0) {
            continue;
        }
        s32 index = 0;
        if (*table <= 0) {
            continue;
        }
        u8* entry = (u8*)table;
        do {
            u32* holder = (u32*)(entry + 16);
            if (func_0018d940(*holder, object) != 0) {
                u8* node = (u8*)*holder;
                if ((*(u32*)(node + 4) & 0x40) == 0 && func_0018f010((u32)node) == 0) {
                    u8* result = func_001b7998(*(s32**)((u8*)object + 0x510), (s32)(entry + 32));
                    if (result != 0) {
                        func_0018e298(holder, (u8*)object, result);
                        break;
                    }
                }
            }
            index++;
            entry += 48;
        } while (index < *table);
    }
    return object;
}
