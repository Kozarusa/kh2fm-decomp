#include "../common/types.h"
extern "C" u32 func_00139598(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0013e0f8(...);
extern "C" u32 func_0014b200(...);
extern "C" u32 func_00158050(...);

u32 func_001565c0(s32 object, u64 x, u64 y, u64 z) {
    s32 first;
    s32 second;
    s32 third;
    u32 result;
    first = object + 0x3600;
    func_0013e0f8(first, 7000, 1);
    func_00158050(object + 0x1bcc, 7000, x, y, 0x79, 100, z);
    second = object + 0x3850;
    func_0013e0f8(second, 7000, 1, z);
    func_00158050(object + 0x1d68, 7000, x, y, 0x79, 500, z);
    third = object + 0x3aa0;
    func_0013e0f8(third, 7000, 1, z);
    func_00158050(object + 0x1f04, 7000, x, y, 0x80, 1000, z);
    func_00158050(object + 0x20a0, 7000, x, y, 0x7c, 0, z);
    func_00158050(object + 0x223c, 7000, x, y, 0x7f, 0, z);
    func_00158050(object + 0x23d8, 7000, x, y, 0x81, 0, z);
    func_00158050(object + 0x2574, 7000, x, y, 0x7b, 0, z);
    func_00139d78(first);
    func_0014b200(object + 0x3620, 200);
    func_0014b200(object + 0x3740, 200);
    func_00139d78(second);
    func_0014b200(object + 0x3870, 600);
    func_0014b200(object + 0x3990, 600);
    func_00139d78(third);
    func_0014b200(object + 0x3ac0, 2000);
    result = func_0014b200(object + 0x3be0, 2000);
    if (*(s32*)(object + 0x34) != 0 &&
        (*(u32*)(*(s32*)(*(s32*)(object + 0x34) + 0x48c) + 0x250) & 2) != 0) {
        func_00139598(object + 0x33b0);
        func_00139598(first);
        func_00139598(object + 0x1bcc);
        func_00139598(second);
        func_00139598(object + 0x1d68);
        func_00139598(third);
        func_00139598(object + 0x1f04);
        func_00139598(object + 0x20a0);
        func_00139598(object + 0x223c);
        func_00139598(object + 0x23d8);
        return func_00139598(object + 0x2574);
    }
    return result;
}
