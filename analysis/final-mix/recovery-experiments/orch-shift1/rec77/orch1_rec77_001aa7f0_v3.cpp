#include "../common/types.h"

struct Sub {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct Obj {
    u32 f0;
    u32 f1;
    u32 pad0[3];
    u32 f5;
    u32 pad1[2];
    u32 q[6];
    u32 e;
    u32 f;
    Sub sub;
};

extern "C" u32 func_00192f78(u32*);
extern "C" u32 func_001ab750(u32, Sub*);

void func_001aa7f0(Obj* object, u32 value) {
    object->f0 = value;
    object->f5 = 0x60000000;
    object->f1 = 0;
    func_00192f78(object->q);
    object->e = 0;
    object->f = 0;
    Sub* inner = &object->sub;
    inner->a = 0;
    inner->c = 0;
    inner->b = 0;
    object->sub.d = 0;
    // why: volatile read keeps the reload of f0 after the final store`r`n    func_001ab750(*(volatile u32*)&object->f0, inner);
}
