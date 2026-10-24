#include "../common/types.h"
struct Slot4 {
    u8 b[4];
};
extern "C" Slot4* D_01c6cc0c;
extern "C" void func_001a8bb8(u8* object);
extern "C" u32 func_001a8bf8(u8* object, s32 index);
extern "C" u32 func_001a8c60(u8* object, s32 index, u32 value);
extern "C" s32 func_001a8cd0(u8* object, u32 id);

u32 func_001a8d40(Slot4* result, s32 index) {
    Slot4 source;
    Slot4 target;
    s32 count;
    s32 i;
    s32 found;
    u32 value;

    count = 1;
    func_001a8bb8(source.b);
    func_001a8bb8(target.b);
    source = D_01c6cc0c[index];
    func_001a8c60(target.b, 0, func_001a8bf8(source.b, 0));
    for (i = 1; i < 4; i++) {
        if (source.b[i] & 0xc0) {
            func_001a8c60(target.b, count, source.b[i]);
            count++;
            source.b[i] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        found = func_001a8cd0(source.b, func_001a8bf8(result->b, i));
        if (found >= 0) {
            func_001a8c60(target.b, count, func_001a8bf8(result->b, i));
            count++;
            source.b[found] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        value = func_001a8bf8(source.b, i);
        if (value != 18) {
            value = func_001a8c60(target.b, count, source.b[i]);
            count++;
        }
    }
    for (; count < 4; count++) {
        value = func_001a8c60(target.b, count, 18);
    }
    *result = target;
    return value;
}
