#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Work {
    s32 a;
    s32 b;
    Quad* dst;
};
extern "C" u32 func_001b7e68(void*, s64);
extern "C" u32 func_001b7f30(void*);
extern "C" u32 func_001b80d8(u64);

static inline void put(Work* w, Quad* s) {
    *w->dst = *s;
    w->dst = w->dst + 1;
}

void func_0014b9a8(Quad* src) {
    Work work;
    work.dst = 0;
    work.b = 0;
    work.a = 0;
    func_001b7e68(&work, 32);
    s32 count = 1;
    do {
        count = count - 1;
        put(&work, src);
        src = src + 1;
    } while (count >= 0);
    func_001b80d8((u64)(u32)&work);
    func_001b7f30(&work);
}