#include "../common/types.h"
struct Slot {
    u32 flags;
    u32 id;
    u32 sub;
};
extern "C" Slot D_01c94090[];
extern "C" u8* D_0033caf4;
extern "C" u8 D_0036d938[];
extern "C" u8 D_0036d940[];
extern "C" u8 D_0032bae0;
extern "C" u32 D_00350e00[];
extern "C" u8 D_001afdd0[];
extern "C" u8* D_00350df8;
extern "C" u8* func_0016e920(u32);
extern "C" u32* func_001947c0(u64, u64);
extern "C" u32 func_00105c30(void);
extern "C" s32 func_00105ee8(s32);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00168388(...);
extern "C" u32 func_00102448(...);

void func_001afc00(u32 chara, u32 owner) {
    u32 buffer[12];
    u8* data;
    u32 id;
    u32 sub;
    s32 index;
    s32 match;
    u8* name;

    if (chara == 0) {
        return;
    }
    data = func_0016e920(chara);
    if (data == 0) {
        return;
    }
    id = *(u16*)(data + 76);
    if (id - 1 >= 15) {
        return;
    }
    sub = *(u16*)((u8*)func_001947c0(-1, -1) + 48);
    for (index = 0; index < 3; index++) {
        match = 0;
        if (D_01c94090[index].id == id) {
            match = D_01c94090[index].sub == sub;
        }
        if (match & 0xff) {
            D_01c94090[index].flags |= 1;
            return;
        }
    }
    for (index = 0; index < 3; index++) {
        if ((D_01c94090[index].flags & 1) == 0) {
            break;
        }
    }
    D_01c94090[index].sub = sub;
    D_01c94090[index].id = id;
    D_01c94090[index].flags |= 1;
    name = D_0033caf4;
    if (func_00105c30() == 8) {
        name = D_0036d938;
    }
    func_002fee78(buffer, D_0036d940, name, func_00105ee8(D_0032bae0), sub, D_00350e00[id]);
    func_00168388(buffer, owner, D_001afdd0, index);
    *(volatile s32*)(D_00350df8 + 4) = 1;
    while (*(volatile s32*)(*(u8* volatile*)&D_00350df8 + 4) != 0) {
        func_00102448(D_00350df8, 0);
    }
}
