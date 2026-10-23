#include "../common/types.h"

extern "C" s32 func_00114620(...);
extern "C" s32 func_001145b0(s32);

void func_001136b8(s32 owner) {
    s32 table = *(s32*)(owner + 8);
    if (table == 0) {
        return;
    }
    s32 records = table + *(s32*)(table + 164);
    for (s32 index = 0; index < *(s32*)(owner + 12); index++) {
        *(s32*)(*(s32*)(owner + 16) + index * 36 + 16) = 0;
        for (s32 search = 0; search < *(s32*)(*(s32*)(owner + 8) + 160); search++) {
            if (*(s32*)(*(s32*)(owner + 16) + index * 36 + 12) == *(s32*)(records + search * 128)) {
                *(s32*)(*(s32*)(owner + 16) + index * 36 + 16) = records + search * 128;
                break;
            }
        }
        if (*(s32*)(*(s32*)(owner + 16) + index * 36 + 20) != 0) {
            *(s32*)(*(s32*)(owner + 16) + index * 36 + 24) = func_00114620(*(s32*)(*(s32*)(owner + 16) + index * 36 + 20));
        }
        s32 entry = index * 36 + *(s32*)(owner + 16);
        if (*(s32*)(entry + 24) != 0) {
            *(s32*)(entry + 28) = func_001145b0(*(s32*)(entry + 24));
        }
    }
}
