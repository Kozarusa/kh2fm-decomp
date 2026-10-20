#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

extern "C" u32 func_00198660(...);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001d5770(void*, void*);
extern "C" u32 func_0016a9b8(u64);

void func_00198690(s32 object) {
    Quad value;
    s32 cursor;
    s32 count;
    func_00198660();
    value = *(Quad*)func_0016c028(object);
    cursor = object + 0x9dc;
    count = 1;
    do {
        void* pointer = &value;
        asm("" : "+r"(pointer)); // why: keeps the stack address computed inside the loop, not hoisted
        func_001d5770((void*)cursor, pointer);
        count = count - 1;
        cursor = cursor + 12;
    } while (count >= 0);
    func_0016a9b8(object);
}
