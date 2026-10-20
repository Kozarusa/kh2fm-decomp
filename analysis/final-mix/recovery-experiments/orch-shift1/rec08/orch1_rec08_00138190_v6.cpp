#include "../common/types.h"

extern "C" u8* D_00347d64;

void func_00138190(s32 first, s32 second) {
    u8* object = D_00347d64;
    u8* queue = object + 48;
    s32 head = *(s32*)queue;
    s32 next = head + 1;
    s32 used = head - *(s32*)(queue + 4);
    if ((used + 8) % 8 < 7) {
        *(s32*)queue = next % 8;
        u8* entry = queue + head * 1328 + 16;
        *(s32*)(entry + 1312) = first;
        *(s32*)(entry + 1316) = second;
    }
}