#include "../common/types.h"
extern "C" u8 D_0034af40[];
extern "C" u8 D_0034b0e0[];
extern "C" s32 func_0013ef80();
extern "C" void func_001024a8(u8*);
extern "C" s32 func_0013f048();
extern "C" u32 func_00236788(u8*);
extern "C" u32 func_00239d30(u8*, s32);
extern "C" s32 func_00239d10(u8*);
extern "C" u8* func_0014aba8();
extern "C" u32 func_0023acd8(u8*);
extern "C" u32 func_0023ade0(u8*);

u32 func_0015d5d0(u8* message) {
    if (func_0013ef80() == 0) {
        func_001024a8(message);
        func_0013f048();
    }
    func_00236788(D_0034af40);
    u8* sequence = D_0034b0e0;
    asm("" : "+r"(sequence)); // why: original reads the field from the base register
    if ((u8)func_00239d30(sequence, *(s32*)(sequence + 276)) == 0 && func_00239d10(sequence) == 0 && *(s32*)(func_0014aba8() + 252) == 0) {
        func_001024a8(message);
        func_0013f048();
    }
    u8* object = D_0034b0e0;
    asm("" : "+r"(object)); // why: original stores the fields from the base register
    func_0023acd8(object);
    *(s32*)(object + 328) = 0;
    *(s32*)(object + 332) = 0;
    return func_0023ade0(object);
}
