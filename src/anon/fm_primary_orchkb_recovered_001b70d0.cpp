#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u8 D_0032bae0;
extern "C" u8 D_0032e020[];
extern "C" u16 func_001a8b68(...);
extern "C" s32 func_00188fe0(...);
extern "C" s32 func_00176b58(...);
extern "C" void func_001b71e8(s32, s32, s32);
extern "C" s32 func_00188bb0(u8*, u32);

s32 func_001b70d0(s32 amount) {
    u8* base = D_0032bb30;
    s32 total = *(s32*)(base + 14048) + amount;
    *(s32*)(base + 14048) = (total < 10000000) ? total : 9999999;
    for (s32 index = 1; index < 14; index++) {
        s32 kind = index;
        switch (index) {
        case 1:
            kind = func_001a8b68(0);
            break;
        case 6:
            if (D_0032bae0 == 8) {
                kind = func_001a8b68(3);
            }
            break;
        }
        func_001b71e8(kind, func_00188fe0(D_0032e020, kind), func_00176b58(kind));
    }
    return func_00188bb0((u8*)func_00188fe0(D_0032e020, 1), 1);
}
