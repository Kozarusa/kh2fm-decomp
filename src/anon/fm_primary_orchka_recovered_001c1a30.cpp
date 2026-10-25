#include "../common/types.h"

struct Info {
    u32 pad0;
    s32 mode;
};

// why: union member stores may alias the cursor, so the original reloads it after every store
union Cell {
    f32 value;
    u8 bytes[4];
};

struct Source {
    f32 position[3];
    u8 pad0[8];
    u8 color[5];
    u8 pad1[3];
    Info* info;
    Cell* mark;
};

void func_001c1a30(Source* source, Cell** cursor) {
    source->mark = *cursor;
    switch (source->info->mode) {
    case 0: {
        (*cursor)[0].value = source->position[0];
        (*cursor)[1].value = source->position[1];
        (*cursor)[2].value = source->position[2];
        (*cursor)[3].bytes[0] = source->color[0];
        (*cursor)[3].bytes[1] = source->color[1];
        (*cursor)[3].bytes[2] = source->color[2];
        u8 value = source->color[3];
        register Cell* tail asm("$14") = *cursor; // why: original reloads the cursor into t6 for the shared last store
        tail[3].bytes[3] = value;
        break;
    }
    case 1: {
        (*cursor)[0].value = source->position[0];
        (*cursor)[1].value = source->position[1];
        (*cursor)[2].value = source->position[2];
        (*cursor)[3].bytes[0] = source->color[1];
        (*cursor)[3].bytes[1] = source->color[3];
        (*cursor)[3].bytes[2] = source->color[4];
        u8 value = source->color[2];
        register Cell* tail asm("$14") = *cursor; // why: original reloads the cursor into t6 for the shared last store
        tail[3].bytes[3] = value;
        break;
    }
    default:
        return;
    }
    *cursor += 4;
}
