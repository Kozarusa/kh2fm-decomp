#include "../common/types.h"
struct EffectList {
    u32 head;
    u32 tail;
};
extern "C" EffectList D_01d9e348;
extern "C" void func_001dc010(u8*, u8*);

void func_001dddd0(u32* object, u8* data) {
    // why: original keeps a1+16 in t6 ($14), which the compiler otherwise puts in t7
    register u32 end asm("$14") = (u32)data + 16;
    object[1] = end;
    register u8* base asm("$15") = data; // why: original retains data copy in t7 after computing a1+16
    asm("" : "+r"(base));  // why: original keeps a copy of data in t7 (move t7,a1) for the later sum and the store of object[0]
    u32* self = object;
    asm("" : "+r"(self)); // why: keep original object copy before object[0] store
    self[0] = (u32)base;
    func_001dc010((u8*)(self + 2), (u8*)(*(s32*)(data + 12) + (u32)base));
    u32 tail = D_01d9e348.tail;
    if (tail == 0) {
        D_01d9e348.tail = (u32)self;
        D_01d9e348.head = (u32)self;
        self[5] = 0;
    } else {
        *(u32*)(tail + 0x14) = (u32)self;
        self[5] = 0;
        D_01d9e348.tail = (u32)self;
    }
}
