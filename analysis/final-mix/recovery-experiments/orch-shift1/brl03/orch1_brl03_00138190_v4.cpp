#include "../common/types.h"

extern "C" u8* D_00347d64;

void func_00138190(s32 first, s32 second) {
    u8* object = D_00347d64;
    u8* queue = object + 48;
    s32 head = *(s32*)queue;
    // why: original keeps the tail and the used count in t6
    register s32 used asm("$14") = *(s32*)(queue + 4);
    s32 next = head + 1;
    used = head - used;
    // why: original keeps used + 8 in t4, separate from used
    register s32 biased asm("$12") = used + 8;
    if (biased % 8 < 7) {
        *(s32*)queue = next % 8;
        u8* entry = queue + head * 1328 + 16;
        *(s32*)(entry + 1312) = first;
        *(s32*)(entry + 1316) = second;
    }
}
