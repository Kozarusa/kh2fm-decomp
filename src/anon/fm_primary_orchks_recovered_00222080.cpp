#include "../common/types.h"
struct FmVector;
struct __attribute__((aligned(16))) FmVector { u32 x,y,z,w; };
// why: types copied from the accepted definition in fm_fallback_vector.cpp (void, VU copy only); extern "C" because the C++ declaration failed the isolated link in v1 (the probe linker script defines only the plain symbol)
extern "C" void func_002226b8(FmVector* target,const FmVector* source);
struct SpawnEntry {
    u8* node;
    u8 kind;
};
// why: no recovered call site or definition; signature derived from its instructions (reads a0, returns a pointer in v0, no float register use)
extern "C" u8* func_00221f98(u8* source);
// why: no recovered call site or definition; one pointer argument in a0, its result is never read here
extern "C" void func_00221e28(SpawnEntry* entry);

void func_00222080(u8* list, u8* source, FmVector* first, FmVector* second) {
    u8* node = func_00221f98(source);
    if (node != 0) {
        SpawnEntry entry;
        entry.node = node;
        entry.kind = source[1];
        u32 flags = 0x100;
        func_00221e28(&entry);
        *(u32*)(node + 0x5c) = 0;
        *(u32*)(node + 0x30) = 0;
        u8 bits = list[4];
        if (bits & 0x4) flags = 0x180;
        if (bits & 0x10) flags |= 0x200;
        if (bits & 0x8) flags |= 0x400;
        if (bits & 0x20) flags |= 0x1000;
        *(u16*)(node + 0x3e) |= flags;
        func_002226b8((FmVector*)(node + 0x40), first);
        func_002226b8((FmVector*)(node + 0x60), second);
        u8* head = *(u8**)list;
        if (head != 0) {
            *(u8**)(head + 4) = node;
        }
        *(u8**)node = head;
        *(u8**)(node + 4) = list;
        *(u8**)list = node;
    }
}
