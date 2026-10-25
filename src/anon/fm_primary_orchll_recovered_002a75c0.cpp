#include "../common/types.h"
extern "C" u32 D_0035f5f8;
extern "C" u8 D_0035f5fc;
extern "C" u8 D_0035f5fd;
// why: no recovered call site; a0 holds the object and a1 an index, v0 is dereferenced as a pointer
extern "C" u32 func_00290948(u32, s32);
extern "C" u32 func_00293d80(s32);
// why: no recovered call site; a0 holds the object, the result is not read here
extern "C" u32 func_002b64d8(u32);
// why: no recovered call site; a0 holds the object, the result is not read here
extern "C" u32 func_002b6530(u32);

// why: every exit leaves a direct result (func_00293d80, or the indirect vtable+4 call), so the last-computed value is returned

u32 func_002a75c0(void) {
    func_002b64d8(D_0035f5f8);
    u32 data = func_00290948(D_0035f5f8, 0);
    s32 count = *(s32*)(data + 8);
    s32 number = 0;
    u32 entry = data + 16;
    if (count > 0) {
        s32 left = count;
        do {
            number++;
            if (*(s16*)(entry + 6) != 0) {
                number++;
            }
            left--;
            entry += 32;
        } while (left != 0);
    }
    D_0035f5fd = number;
    u32 info = func_00290948(D_0035f5f8, 1);
    D_0035f5fc = *(u8*)(info + 8);
    func_002b6530(D_0035f5f8);
    u32 cleared = func_00293d80(5102);
    u32 object = D_0035f5f8;
    if (object != 0) {
        u32 table = *(u32*)object;
        // why: original loads the vtable slot into t7 instead of the free v0
        register u32 slot asm("$15") = *(u32*)(table + 4);
        u32 result = ((u32 (*)(u32))slot)(object);
        D_0035f5f8 = 0;
        return result;
    }
    return cleared;
}
