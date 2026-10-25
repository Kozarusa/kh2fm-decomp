#include "../common/types.h"
extern "C" u32 D_0034f240;
extern "C" s32 func_001bb7f8(void);
// why: only placeholder declarations exist; the original passes the object in a0 and uses no result
extern "C" void func_00179e18(u8*);
extern "C" bool func_0017a538(...);
// why: only placeholder declarations exist; the original passes the object in a0 and uses no result
extern "C" void func_001d0eb8(u8*);
extern "C" s32 func_001991a8(s32, s32);
extern "C" void func_001b6c60(u8*);
extern "C" u32 func_001c8b48(void);
extern "C" s32 func_001bbb50(void);
extern "C" void func_001af328(u64);
extern "C" void func_001af360(u64);
extern "C" u32 func_001c8ab0(void);
// why: only placeholder declarations exist; the original passes the object in a0 and uses no result
extern "C" void func_001d1408(u8*);
// why: only placeholder declarations exist; the original passes the object in a0
extern "C" void func_001af290(u8*);

void func_001d0d60(u8* object) {
    if (D_0034f240 & 0x20000) {
        if (func_001bb7f8() == 0) {
            func_00179e18(object);
            if (func_0017a538(object)) goto finish;
            if ((*(s32*)(object + 2896) ^ 12) == 0) goto finish;
            func_001d0eb8(object);
        }
        func_001991a8(90, 0);
        return;
    }
    func_00179e18(object);
    if (func_001c8b48() != 0) {
        if ((*(s32*)(object + 2896) ^ 12) == 0) goto finish;
        func_001d0eb8(object);
        func_001af328((u64)(s32)object);
        return;
    }
    if (func_001bbb50() != 0) {
        func_001d0eb8(object);
        func_001af360((u64)(s32)object);
        return;
    }
    if (func_0017a538(object)) goto finish;
    if ((*(s32*)(object + 2896) ^ 12) == 0) goto finish;
    if (func_001c8ab0() == 2) {
        func_001d1408(object);
    }
    func_001d0eb8(object);
    func_001af290(object);
    return;
finish:
    func_001b6c60(object);
}
