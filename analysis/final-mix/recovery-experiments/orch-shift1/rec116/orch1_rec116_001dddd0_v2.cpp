#include "../common/types.h"
struct EffectList {
    u32 head;
    u32 tail;
};
extern "C" EffectList D_01d9e348;
extern "C" void func_001dc010(u8*, u8*);

void func_001dddd0(u32* object, u8* data) {
    u8* base = data;
    object[1] = (u32)data + 16;
    asm("" : "+r"(base));  // why: original keeps a copy of data in t7 (move t7,a1) for the later sum and the store of object[0]
    u32* self = object;
    self[0] = (u32)base;
    func_001dc010((u8*)(self + 2), (u8*)(*(s32*)(data + 12) + (u32)base));
    u32 tail = D_01d9e348.tail;
    if (tail == 0) {
        D_01d9e348.head = (u32)self;
        D_01d9e348.tail = (u32)self;
        self[5] = 0;
    } else {
        *(u32*)(tail + 0x14) = (u32)self;
        self[5] = 0;
        D_01d9e348.tail = (u32)self;
    }
}
