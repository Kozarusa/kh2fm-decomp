#include "../common/types.h"
extern "C" void func_00139948(s32 key);
extern "C" s32 func_00154910(u8* object);
extern "C" s32 func_00154930(u8* object);
extern "C" u32 func_00139598(...);
extern "C" void func_001544b0(u8* object);
extern "C" void func_001547e0(u8* object, s32 value, s32 slot);
extern "C" u32 func_001548a8(u8* object, s32 count);

u32 func_00154950(u8* object) {
    func_00139948(6);
    s32 total = *(s32*)(object + 15556);
    s32 page = (total - 1) / 200;
    *(s32*)(object + 15568) = page;
    *(s32*)(object + 15572) = total - page * 200;
    s32 first = func_00154910(object);
    *(s32*)(object + 15580) = *(s32*)(object + 15552) - first * 200;
    s32 second = func_00154930(object);
    *(s32*)(object + 15576) = *(s32*)(object + 15560) - second * 200;
    if (*(s32*)(object + 15580) > *(s32*)(object + 15572)) {
        *(s32*)(object + 15572) = 200;
    }
    if (*(s32*)(object + 15568) != first) {
        *(s32*)(object + 15572) = 200;
    }
    if (second != first) {
        *(s32*)(object + 15576) = 200;
    }
    object[15585] = 0;
    if (first == *(s32*)(object + 15568) && first != 0) {
        object[15585] = 1;
    }
    if (object[15585] == 0) {
        func_00139598(object + 456);
    }
    func_001544b0(object);
    func_001547e0(object, *(s32*)(object + 15572), 2);
    func_001547e0(object, *(s32*)(object + 15576), 4);
    func_001547e0(object, *(s32*)(object + 15580), 5);
    return func_001548a8(object, second);
}
