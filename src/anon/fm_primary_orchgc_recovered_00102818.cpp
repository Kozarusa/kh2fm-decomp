#include "../common/types.h"
typedef void* (*AllocFunc)(void*, s32, void*);
struct Allocator {
    AllocFunc* table;
};
extern "C" void* func_00102788(Allocator*, s32, s32, s32);

void* func_00102818(Allocator* object, s32 first, s32 second, s32 third, s32 size) {
    u8* pointer = (u8*)object->table[0](object, size + 256, __builtin_return_address(0));
    u8* result = (u8*)func_00102788(object, first, second, third);
    *(s32*)(pointer + 252) = size;
    *(u8*)(pointer + 240) = 0;
    *(s32*)(pointer + 244) = 0;
    *(s32*)(pointer + 248) = 0;
    *(s32*)(result + 52) = (s32)pointer;
    return result;
}
