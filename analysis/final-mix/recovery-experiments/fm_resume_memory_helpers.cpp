#include "../common/types.h"

// Original instructions use scalar float stores and unaligned word copies.
// Pointer and structure names remain provisional.
struct __attribute__((packed)) PackedWord { u32 value; };
extern "C" void func_0021fbc0(u8*), func_0021fe28(u8*), func_00220070(u8*);

void func_001da3f8(u8* object,PackedWord* result) {
    u8* old=*(u8**)(object+0xc);
    *(u8**)(object+0xc)=old-4;
    result->value=((PackedWord*)(old-4))->value;
}
void func_001efb18(u8* object,u8* descriptor) {
    f32* value=(f32*)(object+(*(s32**)(descriptor+0xc))[1]+0xa0);
    value[0]=0.0f; value[1]=0.0f; value[2]=0.0f;
}
void func_001efd38(u8* object,u8* descriptor) {
    f32* value=(f32*)(object+(*(s32**)(descriptor+0xc))[1]+0xa0);
    value[0]=0.0f; value[1]=0.0f; value[2]=0.0f;
}
void func_001fa928(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_0021fbc0(object+inner[0]+0xa0);
}
void func_001facd0(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_0021fe28(object+inner[0]+0xa0);
}
void func_001fae80(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_00220070(object+inner[0]+0xa0);
}
void func_001fb698(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_0021fbc0(object+inner[0]+0xa0);
}
void func_001fba88(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_0021fe28(object+inner[0]+0xa0);
}
void func_001fbc78(u8* object,u8* descriptor) {
    register s32* inner asm("$15")=*(s32**)(descriptor+0xc);
    asm volatile("" : "+r"(inner) :: "memory");
    func_00220070(object+inner[0]+0xa0);
}
