#include "../common/types.h"
struct Counter {
    s32 id;
    s32 value;
};
extern "C" u8 D_0032e020[];
// why: accepted C++ definition (fm_primary_twoword_recovered_001bbb28.cpp) fails the isolated probe link; same types, C linkage
extern "C" bool func_001bbb28(void);
extern "C" s32 func_00189200(s32,s32);
// why: no accepted source calls or defines func_001d5c10; a0/a1 from registers, result used as the next counter pointer
extern "C" Counter* func_001d5c10(s32, Counter*);
// why: no accepted source calls or defines func_001d5d80; a0/a1 from registers, result unused
extern "C" void func_001d5d80(u8*, s32);
// why: accepted C++ definition (fm_scalar_recovered_04.cpp) fails the isolated probe link; same types, C linkage
extern "C" void func_001b7468(u64);

// why: void per DEVIATIONS #36; the tail into accepted-void func_001b7468 is stale-b, the other exits are direct results of the final callee

void func_001d5f30(u8* object, s32 amount) {
    if (func_001bbb28()) {
        return;
    }
    s32 key = *(s32*)(object + 0xb50);
    s32 advanced = 0;
    Counter* counter = (Counter*)func_00189200((s32)D_0032e020, key);
    counter->value += amount;
    while (1) {
        Counter* next = func_001d5c10(key, counter);
        if (next == 0) {
            counter->value = 0;
            break;
        }
        if (counter->value < next->value) {
            break;
        }
        advanced = 1;
        func_001d5d80(object, key);
        counter->value -= next->value;
    }
    if (advanced) {
        func_001b7468((s32)object);
    }
}
