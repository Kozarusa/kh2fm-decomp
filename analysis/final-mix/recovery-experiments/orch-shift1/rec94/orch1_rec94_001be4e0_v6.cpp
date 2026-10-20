#include "../common/types.h"

struct Entry {
    u8 bytes[0x74];
};

struct Holder {
    u8 pad0[0x24];
    Entry entries[16];
};

extern "C" void func_001bc730(Entry*, s32);
extern "C" void func_001bd5b0(u8*, s32, s32);
extern "C" void func_001bd618(u8*, s32);

void func_001be4e0(u8* object, s32 index) {
    Entry* entry = &((Holder*)object)->entries[index];
    *(s32*)(object + 0xaa4) = index;
    u8* base = **(u8***)(object + 0x8c0);
    func_001bc730(entry, *(s32*)(base + 0x6c));
    func_001bd618(object, 0);
    func_001bd5b0(object, *(s32*)(object + 0xaa4), 0);
}
