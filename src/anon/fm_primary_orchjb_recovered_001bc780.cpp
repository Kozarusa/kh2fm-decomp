#include "../common/types.h"
struct Info {
    u16 kind;
    u16 mode;
    u8 pad0[2];
    s8 slot;
    u8 single;
};
struct Override {
    u8 pad0[2];
    u16 code;
    u8 flag;
    u8 pad1[7];
    u8 data[4];
};
struct Slot {
    u8 pad0[8];
    s32 active;
    u8 pad1[104];
};
struct World {
    u8 pad0[36];
    Slot slots[21];
    u8 pad1[56];
    s32 handle;
};
struct Entry {
    u16 flags;
    u8 pad0[3];
    u8 state;
    u8 pad1[6];
};
struct Queue {
    u32 unused;
    World* world;
    s32 count;
    Entry entries[1];
    Entry* current() { return &entries[count]; }
};
extern "C" bool func_0019ba60(u64);
extern "C" u32 func_001b8e88(...);
extern "C" u8* func_001bd570(s32, s32);
extern "C" void func_001bc6a8(u8* object_in, u16* source, u32 arg2, u32 arg3, u32 flag);
extern "C" s32 func_001bc948(Slot*);

Entry* func_001bc780(Queue* queue, s32 code, u8* data, u32 flag) {
    Override* override = 0;
    s32 replaced = 0;
    Info* info = (Info*)func_001b8e88(code);
    func_0019ba60(queue->world->handle);
    if (info->single == 1) {
        override = (Override*)func_001bd570((s32)queue->world, 0);
    } else if (info->kind == 81) {
        override = (Override*)func_001bd570((s32)queue->world, 2);
    }
    if (override != 0) {
        data = override->data;
        flag = override->flag;
        replaced = 1;
        code = override->code;
        info = (Info*)func_001b8e88(code);
    }
    func_001bc6a8((u8*)queue->current(), (u16*)info, queue->world->handle, (u32)data, flag);
    if (replaced != 0) {
        queue->current()->flags |= 1;
    }
    if (info->mode == 3 && flag == 0) {
        queue->entries[queue->count].state = 6;
    }
    s32 slot = info->slot;
    if (slot >= 0 && slot != 4) {
        Slot* target = &queue->world->slots[slot];
        if (target->active == 0) {
            queue->entries[queue->count].state = 5;
        } else if (func_001bc948(target) == 0) {
            queue->entries[queue->count].state = 1;
        }
    }
    return &queue->entries[queue->count++];
}
