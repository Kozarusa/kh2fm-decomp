#include "../common/types.h"
struct EffectList {
    u32 head;
    u32 tail;
};
extern "C" EffectList D_01d9e348;
extern "C" void func_001dc010(u8*, u8*);

void func_001dddd0(u32* object, u8* data) {
    object[1] = (u32)data + 16;
    object[0] = (u32)data;
    func_001dc010((u8*)(object + 2), data + *(s32*)(data + 12));
    u32 tail = D_01d9e348.tail;
    if (tail == 0) {
        D_01d9e348.head = (u32)object;
        D_01d9e348.tail = (u32)object;
        object[5] = 0;
    } else {
        *(u32*)(tail + 0x14) = (u32)object;
        object[5] = 0;
        D_01d9e348.tail = (u32)object;
    }
}
