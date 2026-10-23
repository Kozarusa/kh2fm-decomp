#include "../common/types.h"
typedef u32 (*Method)(u8*);
struct Object {
    Method* table;
};
extern "C" void func_0014fcd8(u8* object);
extern "C" u32 func_00139538(u8* object);
extern "C" u32 func_00138c40(...);
extern "C" u32 func_0023acd8(u8* entry);

u32 func_00151f40(u8* object) {
    func_0014fcd8(object);
    u8* sprite = object + 48;
    if (func_00139538(sprite) != 0) {
        Method* table = ((Object*)object)->table;
        register Method method asm("$15") = table[5]; // why: original calls through t7
        return method(object);
    }
    u32 result = func_00138c40(sprite, 0, *(s32*)(object + 36));
    s32 index = 0;
    if (*(s32*)(object + 2896) > 0) {
        u8* entry = object + 456;
        do {
            result = func_0023acd8(entry);
            index++;
            entry += 344;
        } while (index < *(s32*)(object + 2896));
    }
    return result;
}
