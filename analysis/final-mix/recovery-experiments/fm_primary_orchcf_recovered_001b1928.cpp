#include "../common/types.h"
struct Light { s32 pad0; Light* next; u8 pad[32]; };
struct LightPool { Light items[16]; s32 freeIndex[16]; s32 freeCount; };
struct LightList { Light* head; Light* tail; };
extern "C" LightPool D_01d44108;
extern "C" LightList D_01d44100;
extern "C" void func_001b1a30(Light*, s32);

Light* func_001b1928(s32 arg) {
    D_01d44108.freeCount--;
    Light* light = &D_01d44108.items[D_01d44108.freeIndex[D_01d44108.freeCount]];
    func_001b1a30(light, arg);
    if (D_01d44100.tail == 0) {
        D_01d44100.tail = light;
        D_01d44100.head = light;
    } else {
        D_01d44100.tail->next = light;
        D_01d44100.tail = light;
    }
    light->next = 0;
    return light;
}
