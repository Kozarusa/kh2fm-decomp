#include "../common/types.h"

struct Info {
    u8 pad[14];
    u8 kind;
};

struct Target {
    u8 pad0[8];
    Info* info;
};

struct Source {
    u8 pad0[4];
    s32 value;
};

struct Offset {
    u8 pad0[12];
    s32* offset;
};

typedef void (*Handler)(void*, s32);

extern "C" Handler* volatile D_01d9eaa0;

void func_001e9078(u8* object, Source* source, Offset* offset) {
    *(s32*)(object + *offset->offset + 160) = source->value;
    Handler* table = D_01d9eaa0;
    if (table != 0) {
        Handler handler = table[((Target*)object)->info->kind];
        if (handler != 0) {
            handler(object, source->value);
        }
    }
}
