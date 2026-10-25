#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Object;
// why: accepted C++ definition void func_0019d188(Object*) (fm_primary_orchkh_recovered_0019d188.cpp); extern "C" so the isolated probe links the plain symbol
extern "C" void func_0019d188(Object*);
// why: no accepted source calls or defines func_001bd6a8; parameter derived from a0, result unused
extern "C" void func_001bd6a8(u8*);
extern "C" void func_001d6ab0(s32);

// why: void per DEVIATIONS #36; exits are entry v0, stale-b (store-only func_001d6ab0 tail, func_001bd6a8 leftovers) or the integer vtable result

void func_001d6ba0(u8* object) {
    if (*(s32*)(object + 0xaf4) == 0) {
        return;
    }
    // why: original reads the whole flags word (lw), a plain read is narrowed to lbu
    if ((u8)(*(volatile u32*)(object + 0xaf0) & 1) != 0) {
        func_0019d188((Object*)(object + 0xac0));
    }
    func_001bd6a8(object);
    u32 count = object[0xaf8];
    if ((u8)count == 0) {
        return;
    }
    if ((u8)count < 2) {
        void*** target = *(void****)(object + 0xaf4);
        if (((Method)(*target)[16])(target) == 0) {
            return;
        }
        count = object[0xaf8];
    }
    u32 next = count - 1;
    object[0xaf8] = next;
    if ((u8)next == 0) {
        func_001d6ab0((s32)object);
    }
}
