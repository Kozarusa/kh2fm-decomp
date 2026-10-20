#include "../common/types.h"

// Original instructions use scalar float stores and unaligned word copies.
// Pointer and structure names remain provisional.
struct __attribute__((packed)) PackedWord { u32 value; };
extern "C" void func_0021fbc0(u8*), func_0021fe28(u8*), func_00220070(u8*);

void func_001da3f8(u8* object,PackedWord* result) {
    register u8* old asm("$14")=*(u8**)(object+0xc);
    asm volatile("" : "+r"(old));
    *(u8**)(object+0xc)=old-4;
    register u32 value asm("$11");
    asm volatile("lwl %0,-1(%1)\n\tlwr %0,-4(%1)" : "=&r"(value) : "r"(old) : "memory");
    asm volatile(".set push\n\t.set noreorder\n\tswl %0,3(%1)\n\tswr %0,0(%1)\n\t.set pop" :: "r"(value), "r"(result) : "memory");
}

void func_001efb18(u8* object,u8* descriptor) {
    register s32* inner asm("$14")=*(s32**)(descriptor+0xc);
    register f32 zero asm("$f0")=0.0f;
    asm volatile("" : "+r"(inner), "+f"(zero));
    register s32 offset asm("$15")=inner[1];
    asm volatile("" : "+r"(offset));
    object+=offset;
    register f32* value asm("$14")=(f32*)(object+0xa0);
    asm volatile("" : "+r"(value));
    *(f32*)(object+0xa0)=zero; value[1]=zero; asm volatile("" ::: "memory"); value[2]=zero;
}

void func_001efd38(u8* object,u8* descriptor) {
    register s32* inner asm("$14")=*(s32**)(descriptor+0xc);
    register f32 zero asm("$f0")=0.0f;
    asm volatile("" : "+r"(inner), "+f"(zero));
    register s32 offset asm("$15")=inner[1];
    asm volatile("" : "+r"(offset));
    object+=offset;
    register f32* value asm("$14")=(f32*)(object+0xa0);
    asm volatile("" : "+r"(value));
    *(f32*)(object+0xa0)=zero; value[1]=zero; asm volatile("" ::: "memory"); value[2]=zero;
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
