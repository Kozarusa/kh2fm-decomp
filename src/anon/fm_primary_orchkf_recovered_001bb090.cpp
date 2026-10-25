#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" u32 D_0034f240;
extern "C" f32 D_0036dc08;
// why: accepted C++-linkage definition fails the isolated probe link (v1); same types with C linkage
extern "C" u32 func_001d21c0(u8* object);
// why: accepted C++-linkage definition fails the isolated probe link (v1); same types with C linkage
extern "C" void func_001d7f80(u8* object);
extern "C" bool func_00197920(void);
extern "C" bool func_0019ba60(u64);
// why: no accepted declaration exists; the caller compares the $f0 result with c.le.s
extern "C" f32 func_00197b98(void);
// why: the accepted definition takes eight words, this caller sets only a0; return type kept from that definition
extern "C" u32 func_00195328(s32);
extern "C" u32 func_001bb630(...);
extern "C" u32 func_001bbe18(...);
extern "C" u32 func_001bc0d0(...);
extern "C" u32 func_001d5518(...);
extern "C" void func_002bc798(void);
// why: the accepted asm-label form fails the isolated probe link (v1); same types without the label
extern "C" u32 func_002bc788(...);

typedef s32 (*Method)(void*);

s32 func_001bb090(u8* object) {
    func_001d21c0(object + 0x260);
    switch (*(s32*)(object + 0x2d8)) {
    case 0: {
        s32 target = D_0034e948;
        if (func_00197920()) {
            if (func_0019ba60(target)) {
                Method* vtable = *(Method**)target;
                if (vtable[16]((void*)target) == 0) {
                    return 1;
                }
            }
        }
        if ((*(u32*)(object + 4) & 2) == 0) {
            func_001d7f80(object);
        }
        *(s32*)(object + 0x2d8) = 1;
        break;
    }
    case 2:
        *(s32*)(object + 0x2d8) = 3;
        break;
    case 3: {
        f32 rest = func_00197b98();
        f32* limit = &D_0036dc08;
        asm("" : "+r"(limit)); // why: keeps the full address so the load uses offset 0 as in the original
        if (!(rest <= *limit)) {
            break;
        }
        s32 kind = *(s32*)(object + 0x2dc);
        u32 camera;
        if (kind == 16) {
            camera = func_00195328(2);
        } else {
            if (kind == 156) {
                func_002bc798();
                func_001bbe18(0x1b68);
                func_002bc788();
            }
            camera = func_00195328(1);
        }
        u8* entry = object + 0x84;
        if (*(s32*)(entry + 4) == 0) {
            *(u32*)(entry + 4) = camera;
            *(s32*)(entry + 8) = 566;
        }
        func_001d5518(entry, object + 0xc, 0);
        D_0034f240 |= 8;
        func_001bc0d0(object);
        break;
    }
    case 4:
        if (!func_00197920()) {
            func_001bb630(*(s32*)(object + 0x2dc), *(s32*)(object + 0x2e0));
            return 0;
        }
        break;
    }
    return 1;
}
