#include "../common/types.h"
struct Object {
    u8 pad[64];
    u32 flags;
};
extern "C" Object* D_01d48cb0;
extern "C" void func_001b4f40(Object*);
extern "C" void func_001b5460(Object*);
extern "C" u32 func_00105110(u64);

void func_001b5400() {
    if (D_01d48cb0 != 0) {
        D_01d48cb0->flags = D_01d48cb0->flags | 0x10;
        func_001b5460(D_01d48cb0);
        Object* object = D_01d48cb0;
        if (object != 0) {
            func_001b4f40(object);
            func_00105110((u64)(s32)object);
        }
    }
}
