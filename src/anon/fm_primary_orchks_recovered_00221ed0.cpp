#include "../common/types.h"
// why: no recovered source calls or defines this callee; parameters come from a0 (object) and a1 (masked u16 flag) set before each jal, and void because its original instructions write neither v0 nor $f0
extern "C" void func_00220088(u8* entry, u32 flags);

void func_00221ed0(u8* object) {
    u8* entry = object + 64;
    s32 count = *(u16*)(object + 60);
    u16 flags = *(u16*)(object + 62) & 0x20;
    s32 i;
    for (i = count; i > 0; i--) {
        func_00220088(entry, flags);
        entry += 48;
    }
    s32 second = *(u16*)(object + 56);
    entry = object + *(u16*)(object + 52) * 48 + 64;
    for (i = second; i > 0; i--) {
        func_00220088(entry, flags);
        entry += 48;
    }
    if (*(u8***)(object + 12) != 0) {
        u8* head = *(u8**)(object + 8);
        if (head != 0) {
            *(u8***)(head + 12) = *(u8***)(object + 12);
        }
        **(u8***)(object + 12) = head;
    }
}
