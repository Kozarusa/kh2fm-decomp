#include "../common/types.h"
struct Allocator;
struct AllocatorTable {
    s32 (*allocate)(Allocator*, s32, void*);
};
struct Allocator {
    AllocatorTable* table;
};
struct Definition {
    s32 pad0[4];
    s32 count;
    s32 size1;
    s32 size2;
};
struct Object {
    s32 definition;
    s32 field4;
    s32 buffer1;
    s32 buffer2;
    s32 handle;
    s32 cursor1;
    s32 cursor2;
    s32 field28;
    s32 field32;
    s32 field36;
    s32 field40;
    s32 field44;
    s32 field48;
    s32 source;
    s32 owner;
};
extern "C" s32 D_004f6288;
extern "C" s32 func_0016d1a0(s32);
extern "C" s32 func_0016d1d8(s32);

s32 func_0016c8f8(Object* object, Definition* definition, s32 source, u8* owner) {
    s32 result;
    s32 value;
    s32 size;
    Allocator* allocator;
    object->source = source;
    object->owner = (s32)owner;
    object->definition = (s32)definition;
    object->field28 = 0;
    object->field32 = 0;
    object->field36 = 0;
    object->field48 = 0;
    object->field44 = 0;
    result = ((Allocator*)D_004f6288)->table->allocate((Allocator*)D_004f6288, definition->size1 + 256, __builtin_return_address(0));
    *(volatile s32*)&object->buffer1 = result;
    *(volatile s32*)&object->cursor1 = result;
    size = ((Definition*)*(volatile s32*)&object->definition)->size2 + 256;
    allocator = (Allocator*)*(volatile s32*)&D_004f6288;
    result = allocator->table->allocate(allocator, size, __builtin_return_address(0));
    object->cursor2 = result;
    object->buffer2 = result;
    value = object->source;
    if (value == 0) {
        s32 count = ((Definition*)object->definition)->count;
        if (count > 0) {
            value = func_0016d1a0(count);
            object->source = value;
        }
    }
    result = value ? func_0016d1d8(value) : 0;
    object->handle = result;
    object->field4 = 0;
    if (object->owner != 0) {
        *(s32*)((u8*)object->owner + 1160) += 1;
    }
    return result;
}
