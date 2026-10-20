#include "../common/types.h"
extern f32 D_00375f78, D_00375fb8, D_00375fbc;

void func_002e3f78(f32* object) {
    register f32* source asm("$15")=&D_00375f78;
    register f32 zero asm("$f0")=0.0f;
    asm volatile("" : "+r"(source), "+f"(zero));
    register f32 value asm("$f1")=*source;
    asm volatile("" : "+f"(value));
    object[0]=zero; object[3]=value; object[2]=zero; object[1]=zero;
}
void func_002e4a08(f32* object) {
    register f32* source asm("$15")=&D_00375fb8;
    asm volatile("" : "+r"(source));
    register f32 first asm("$f0")=*source;
    asm volatile("" : "+f"(first));
    object[0]=first; asm volatile("" ::: "memory", "$15");
    source=&D_00375fbc;
    asm volatile("" : "+r"(source));
    register f32 second asm("$f1")=*source;
    asm volatile("" : "+f"(second));
    object[1]=second;
}
void func_002eac70(f32 first,f32 second,f32 third,f32 fourth) {
    register u32 a asm("$15")=0x360000;
    register u32 b asm("$14")=0x360000;
    asm volatile("" : "+r"(a), "+r"(b));
    *(f32*)(a+0x3440)=first;
    *(f32*)(b+0x3448)=second;
    asm volatile("" ::: "memory", "$14", "$15");
    a=0x360000; b=0x360000;
    asm volatile("" : "+r"(a), "+r"(b));
    *(f32*)(a+0x344c)=third;
    *(f32*)(b+0x3450)=fourth;
}
void func_0016f7b0(void) {
    register u32 a asm("$15")=0x4f0000;
    register u32 b asm("$14")=0x4f0000;
    asm volatile("" : "+r"(a), "+r"(b));
    *(u32*)(a+0x63a8)=0;
    asm volatile("" ::: "memory", "$13");
    register u32* last asm("$13")=(u32*)(a+0x63a8);
    asm volatile("" : "+r"(last));
    *(u32*)(b+0x63a0)=0;
    last[1]=0;
}
void func_00225298(void) {
    register u32 a asm("$15")=0x1db0000;
    register u32 value asm("$14")=0xffffffff;
    asm volatile("" : "+r"(a), "+r"(value));
    *(u32*)(a-0x26f0)=value;
    asm volatile("" ::: "memory", "$13");
    register u32* next asm("$13")=(u32*)(a-0x26f0);
    asm volatile("" : "+r"(next));
    next[1]=value;
}
void func_001e0348(s32 phase,s64 priority) {
    if(priority==0xffff && phase==1) {
        register u32 high asm("$14")=0x1da0000;
        asm volatile("" : "+r"(high));
        register u32* next asm("$15")=(u32*)(high-0x1cb8);
        asm volatile("" : "+r"(next));
        *(u32*)(high-0x1cb8)=0; next[1]=0;
    }
}
void func_00228420(s32 phase,s64 priority) {
    if(priority==0xffff && phase==1) {
        register u32 high asm("$15")=0x360000;
        asm volatile("" : "+r"(high));
        register u32* next asm("$14")=(u32*)(high-0x2500);
        asm volatile("" : "+r"(next));
        *(u32*)(high-0x2500)=0; next[2]=0; asm volatile("" ::: "memory"); next[1]=0;
    }
}
