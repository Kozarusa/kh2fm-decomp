#include "../common/types.h"
extern "C" u32 func_001c0890(...);
extern "C" u32 func_001d83c0(...);
extern "C" u32 func_001d4fd0(...);
extern "C" u32 func_001d4ff0(...);
extern "C" u32 func_001bbe18(...);
extern "C" u32 func_001bb890(...);
extern "C" bool func_00198d00(s32, s32);
extern "C" u32 func_001d5518(...);
// why: void, as in the recovered definition (store-only body, writes no v0); only the first argument is used
extern "C" void func_001bc0d0(u8*);
// why: void, as in the recovered definition void func_001bb630(u32, u32)
extern "C" void func_001bb630(u32, u32);

// why: void under DEVIATIONS #36 (E1 direct func_001d5518, E2 stale after store-only func_001bc0d0, E3 tail into void func_001bb630); the only real caller, func_001bb6d0, ignores the result

// Preserve original registry aliases.
void func_001bb4f0(u32 object, u32 kind, u32 value) asm("_Z16wtarget_001bb4f0jjjj");

void func_001bb4f0(u32 object, u32 kind, u32 value) {
    u8* base = (u8*)object;
    u8 level = *(u8*)(*(u32*)(base + 8) + 13);
    if (level != 0) {
        func_001c0890(level);
    }
    u8* score = base + 0x2e4;
    if (*(u32*)(base + 0x2f0) & 4) {
        if ((s32)func_001d83c0(0) > 0) {
            func_001d4fd0(score);
        }
        func_001d4ff0(score);
    }
    u8* entry = base + 0x68;
    func_001bbe18(*(u32*)(*(u32*)(base + 8) + 0x14));
    func_001bb890();
    if (*(u32*)(entry + 4) != 0) {
        bool found = func_00198d00(kind, -1);
        if (kind == 16 || kind == 156 ||
            (found && (*(u16*)(*(u32*)(base + 8) + 4) & 0x40) == 0)) {
            func_001d5518(entry, base + 0xc, 0);
            *(u32*)(base + 0x2d8) = 2;
        } else {
            func_001d5518(entry, base + 0xc, found);
            func_001bc0d0(base);
        }
        *(u32*)(base + 0x2dc) = kind;
        *(u32*)(base + 0x2e0) = value;
        return;
    }
    func_001bb630(kind, value);
}
