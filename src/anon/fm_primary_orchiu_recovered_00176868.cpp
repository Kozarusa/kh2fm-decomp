#include "../common/types.h"
extern "C" void func_00176970(u8*);
extern "C" s32 func_00176fb0(...);
extern "C" u32 func_00177008(...);
extern "C" s32 func_00177860(...);
extern "C" void func_00177a28(u8*);
extern "C" u64 func_001a0920(...);

s32 func_00176868(u8* object, u8* request) {
    u32 flags = *(u32*)(*(u8**)(object + 12) + 8);
    u8* other = *(u8**)(object + 304);
    if (flags & 0x40) {
        if (flags & 0x800) {
            return 0;
        }
        if (*(f32*)(object + 0xf8) < *(f32*)(other + 0x58)) {
            return 0;
        }
        if (*(u32*)(object + 0x7f8) & 4) {
            return 0;
        }
        u32 bits = *(u32*)(request + 4);
        if (bits & 2) {
            if (*(u32*)func_00177860() & 0x100000) {
                func_00176970(object);
                return 1;
            }
            bits = *(u32*)(request + 4);
        }
        if (!(bits & 8)) {
            return 0;
        }
        func_00177a28(object);
        s32 party = func_00176fb0(object, 40);
        if (party != 0 && func_001a0920(party, object) != 0) {
            func_00177008(object, party, *(s32*)(object + 0xb40) + 4);
            return 1;
        }
    }
    return 0;
}
