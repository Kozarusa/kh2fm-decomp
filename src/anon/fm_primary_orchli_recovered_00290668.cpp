#include "../common/types.h"
// why: return type copied from accepted declarations; the parameter is derived from a0, which still holds the object at the call
extern "C" u32 func_00290740(u8*);
extern "C" u32 func_002362b0(u8*, s32);
extern "C" u32 func_002367c8(u8*);
extern "C" void func_001386e0(u8*, s32, s32, s32, s32, s32);

// Preserve original registry aliases.
void func_00290668(u8* object, s32 first, s32 second, s32 third) asm("_ZN2Tz8Selector13CreateHelpGraEz");

void func_00290668(u8* object, s32 first, s32 second, s32 third) {
    u8* image;
    func_00290740(object);
    image = object + 0x1a0;
    func_002362b0(image, second);
    func_002367c8(image);
    func_001386e0(object, *(s32*)(object + 0x198), first, (s32)image, third, 0);
    register u8* sub asm("$13") = object + 0x18; // why: original keeps the sub-object base (object + 24) in t5
    asm("" : "+r"(sub)); // why: original addresses the flag word through the sub-object base instead of folding the offset
    *(u32*)(sub + 0xb8) |= 8;
    object[0x195] = 1;
}
