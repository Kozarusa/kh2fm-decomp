#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Work {
    s32 a;
    s32 b;
    Quad* dst;
};
extern "C" u32 func_001b7e68(void*, s64);
extern "C" u32 func_001b7f30(void*);
extern "C" u32 func_001b80d8(void*);

void func_0014b9a8(Quad* src) {
    Work work;
    work.dst = 0;
    work.b = 0;
    work.a = 0;
    func_001b7e68(&work, 32);
    register volatile Work* w asm("$12") = &work; // why: original keeps the work pointer in t4 and reloads dst per iteration
    register s32 count asm("$13") = 1; // why: original keeps the loop counter in t5
    do {
        count = count - 1;
        *(volatile Quad*)w->dst = *src; // why: keeps store before the reload of dst
        src = src + 1;
        w->dst = w->dst + 1;
    } while (count >= 0);
    func_001b80d8(&work);
    func_001b7f30(&work);
}