#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    f32 v[4];
};
struct __attribute__((aligned(16))) Placement {
    s32 a;
    f32 b;
    s32 c;
    s32 d;
    Vector offset;
};
extern "C" u8* func_0016bc20(u8*, s32, s32);
extern "C" s32 func_0016bff0(u8*);
extern "C" s32 func_0018a550(Placement*, Placement*);
extern "C" void func_0018a818(Placement*, u8*, u8*);
extern "C" u8* func_001b9bc8(u8*);

u8* func_0018bc60(u8* object, s32 kind) {
    Placement first;
    Placement second;
    u8* entry = func_0016bc20(object, kind, -1);
    if (entry == 0) {
        return 0;
    }
    first.d = 0;
    func_0018a818(&first, object, entry);
    second.d = 0;
    u8* other = 0;
    while ((other = func_001b9bc8(other)) != 0) {
        if (func_0016bff0(other) == func_0016bff0(object)) {
            continue;
        }
        u8* found = func_0016bc20(other, kind, -1);
        if (found == 0) {
            continue;
        }
        func_0018a818(&second, other, found);
        if (func_0018a550(&first, &second) != 0) {
            return other;
        }
    }
    return 0;
}
