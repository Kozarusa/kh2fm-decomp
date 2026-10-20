#include "../common/types.h"
extern u8* D_00352130;

void func_00134d10(u8* object) {
    register u32 high asm("$15")=0x370000;
    asm volatile("" : "+r"(high));
    *(u32*)(object+0)=0;
    asm volatile("" : "+r"(high) :: "memory");
    register f32* source asm("$15")=(f32*)(high-0x53b8);
    asm volatile("" : "+r"(source));
    *(u32*)(object+8)=0; asm volatile("" ::: "memory");
    register f32 first asm("$f0")=*source;
    asm volatile("" : "+f"(first));
    high=0x370000; asm volatile("" : "+r"(high));
    *(f32*)(object+0x1c)=first; asm volatile("" : "+r"(high) :: "memory");
    source=(f32*)(high-0x53b4); asm volatile("" : "+r"(source));
    *(f32*)(object+0xc)=first; asm volatile("" ::: "memory");
    register f32 second asm("$f1")=*source;
    asm volatile("" : "+f"(second));
    *(f32*)(object+0x10)=first; asm volatile("" ::: "memory");
    *(f32*)(object+4)=second; asm volatile("" ::: "memory");
    *(f32*)(object+0x14)=first; asm volatile("" ::: "memory");
    *(f32*)(object+0x18)=first;
}

void func_001957e8(u8* object) {
    register u32 high asm("$15")=0x370000;
    asm volatile("" : "+r"(high));
    register f32* source asm("$15")=(f32*)(high-0x2fcc);
    asm volatile("" : "+r"(source));
    register f32 value0 asm("$f0")=*source;
    asm volatile("" : "+f"(value0));
    high=0x370000; asm volatile("" : "+r"(high));
    *(f32*)(object+0)=value0; asm volatile("" : "+r"(high) :: "memory");
    source=(f32*)(high-0x2fc8); asm volatile("" : "+r"(source));
    register f32 value1 asm("$f1")=*source;
    asm volatile("" : "+f"(value1));
    high=0x370000; asm volatile("" : "+r"(high));
    *(f32*)(object+4)=value1; asm volatile("" : "+r"(high) :: "memory");
    source=(f32*)(high-0x2fc4); asm volatile("" : "+r"(source));
    value0=*source; asm volatile("" : "+f"(value0));
    high=0x370000; asm volatile("" : "+r"(high));
    *(f32*)(object+8)=value0; asm volatile("" : "+r"(high) :: "memory");
    source=(f32*)(high-0x2fc0); asm volatile("" : "+r"(source));
    value1=*source; asm volatile("" : "+f"(value1));
    *(f32*)(object+0xc)=value1; asm volatile("" ::: "memory");
    register u8* inner asm("$14")=D_00352130;
    asm volatile("" : "+r"(inner));
    high=0x370000; asm volatile("" : "+r"(high));
    value1=*(f32*)(inner+0x14); asm volatile("" : "+f"(value1));
    source=(f32*)(high-0x2fbc); asm volatile("" : "+r"(source));
    value0=*source; asm volatile("" : "+f"(value0));
    *(f32*)(object+0x10)=value1; asm volatile("" ::: "memory");
    *(f32*)(object+0x18)=value0; asm volatile("" ::: "memory");
    *(u32*)(object+0x20)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x14)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x1c)=0;
}

void func_0028d188(u8* object) {
    register u32 high asm("$15")=0x370000;
    asm volatile("" : "+r"(high));
    *(u32*)(object+0x1b8)=0; asm volatile("" : "+r"(high) :: "memory");
    register f32* source asm("$15")=(f32*)(high+0x4438);
    asm volatile("" : "+r"(source));
    object[0x19c]=0; asm volatile("" ::: "memory");
    register f32 value asm("$f0")=*source;
    asm volatile("" : "+f"(value));
    object[0x19d]=0; asm volatile("" ::: "memory");
    *(f32*)(object+0x1a0)=value; asm volatile("" ::: "memory");
    *(u32*)(object+0x1a4)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x1a8)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x1ac)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x1b0)=0; asm volatile("" ::: "memory");
    *(u32*)(object+0x1b4)=0;
}

void func_002cd260(u8* object) {
    if(object[0x87]!=0) {
        register u32 high asm("$15")=0x370000;
        asm volatile("" : "+r"(high));
        *(u32*)(object+0x18)=0; asm volatile("" : "+r"(high) :: "memory");
        register f32* source asm("$15")=(f32*)(high+0x58ec);
        asm volatile("" : "+r"(source));
        *(u32*)(object+0x88)=0; asm volatile("" ::: "memory");
        register f32 value asm("$f0")=*source;
        asm volatile("" : "+f"(value));
        *(u32*)(object+4)=0; asm volatile("" ::: "memory");
        *(f32*)(object+0x1c)=value; asm volatile("" ::: "memory");
        *(u32*)(object+8)=0;
    }
}
