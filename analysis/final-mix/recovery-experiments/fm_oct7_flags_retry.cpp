#include "../common/types.h"
extern s32 D_0034c768, D_0034c76c;

void func_00161a58(s32 input) {
    register s32 value asm("$14")=input;
    asm volatile("" : "+r"(value));
    if(input<0) value=0;
    else if(input>128) value=128;
    D_0034c768=value;
}
void func_00161a80(s32 input) {
    register s32 value asm("$14")=input;
    asm volatile("" : "+r"(value));
    if(input<0) value=0;
    else if(input>128) value=128;
    D_0034c76c=value;
}
void func_001671e8(s32 input,u32 byte_value) {
    register s32 minimum asm("$15")=15000;
    asm volatile("" : "+r"(minimum) :: "$13", "$12");
    register s32 below asm("$13")=input<15000;
    register u32 high asm("$12")=0x4f0000;
    asm volatile("" : "+r"(minimum), "+r"(below), "+r"(high));
    if(below) input=minimum;
    register u8* base asm("$14");
    asm("addiu %0,%1,0x4240" : "=r"(base) : "r"(high));
    asm volatile("" : "+r"(byte_value));
    byte_value&=0xff; asm volatile("" : "+r"(byte_value));
    register u32 enabled asm("$15")=1; asm volatile("" : "+r"(enabled));
    base[1]=byte_value; asm volatile("" ::: "memory");
    *(u8*)(high+0x4240)=enabled; asm volatile("" ::: "memory");
    *(s32*)(base+4)=input;
}
void func_0020ea70(u32 first,u32 second) {
    first&=0xff; second&=0xff;
    asm volatile("" : "+r"(first), "+r"(second));
    // The original transports integer bits into COP1 before converting them.
    register f32 second_value asm("$f1");
    asm volatile("mtc1 %1,%0" : "=f"(second_value) : "r"(second) : "$15");
    register u32 high asm("$15")=0x360000;
    asm volatile("" : "+r"(high) :: "$f0");
    register f32 first_value asm("$f0");
    asm volatile("mtc1 %1,%0" : "=f"(first_value) : "r"(first));
    register f32* base asm("$15");
    asm("addiu %0,%1,-0x6ef0" : "=r"(base) : "r"(high));
    asm volatile("cvt.s.w %0,%0" : "+f"(second_value));
    asm volatile("cvt.s.w %0,%0" : "+f"(first_value));
    base[2]=second_value; asm volatile("" ::: "memory");
    base[3]=first_value;
}
