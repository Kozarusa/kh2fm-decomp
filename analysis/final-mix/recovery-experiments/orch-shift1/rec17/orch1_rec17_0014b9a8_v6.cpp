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
    volatile Work* w = &work; // why: keeps destination reload per iteration
    s32 count = 1;
    do {
        count = count - 1;
        *(volatile Quad*)w->dst = *src; // why: keeps store before the reload of dst
        src = src + 1;
        w->dst = w->dst + 1;
    } while (count >= 0);
    func_001b80d8(&work);
    func_001b7f30(&work);
}