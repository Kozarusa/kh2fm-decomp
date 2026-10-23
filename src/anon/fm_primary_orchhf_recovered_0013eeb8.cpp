#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Work {
    s32 a;
    s32 b;
    Quad* dst;
};
extern "C" u64 func_0013eb00(...);
extern "C" u32 func_001b7e68(void*, s64);
extern "C" u32 func_001b7f30(void*);
extern "C" u32 func_001b80d8(void*);

u32 func_0013eeb8(u8* object) {
    register u64 third asm("$13") = (u64)object[18] << 16; // why: original builds byte 18 in t5
    register u64 second asm("$11") = (u64)object[17] << 8; // why: original builds byte 17 in t3
    u64 middle = third | second;
    u64 value = (u64)object[16] | ((u64)1 << 32);
    value |= middle;
    register u64 fourth asm("$12") = object[19]; // why: original builds byte 19 in t4
    value |= fourth << 24;
    *(u64*)(object + 200) = value;
    object += 32;
    func_0013eb00();
    Work work;
    work.dst = 0;
    work.b = 0;
    work.a = 0;
    func_001b7e68(&work, 240);
    register volatile Work* w asm("$12") = &work; // why: original keeps the work pointer in t4 and reloads dst per iteration
    register s32 count asm("$13") = 14; // why: original keeps the loop counter in t5
    do {
        count = count - 1;
        register Quad* target asm("$15") = w->dst; // why: original loads the dst pointer into t7
        register Quad value asm("$14") = *(Quad*)object; // why: original loads the quad into t6
        *(volatile Quad*)target = value; // why: keeps store before the reload of dst
        object = object + 16;
        w->dst = w->dst + 1;
    } while (count >= 0);
    func_001b80d8(&work);
    return func_001b7f30(&work);
}
