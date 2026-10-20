#include "../common/types.h"

// Provisional initializer signatures; original scalar float instructions decide acceptance.
extern f32 D_00363448;
extern f32 D_003634f0;
extern f32 D_0036c584;
extern f32 D_0036cc20;
extern f32 D_0036d4e4;
extern f32 D_0036e3f8;
extern f32 D_003760d4;
extern f32 D_003760dc;
extern f32 D_01c60520;
extern f32 D_01c60be8;
extern f32 D_01c6cb18;
extern f32 D_01d5ba08;

void func_0017e808(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036c584; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_01c60520=value; } }

void func_0018c868(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036cc20; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_01c60be8=value; } }

void func_001a5b08(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036d4e4; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_01c6cb18=value; } }

void func_001d3060(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036e3f8; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_01d5ba08=value; } }

void func_002ead48(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_003760d4; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_00363448=value; } }

void func_002eaee8(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_003760dc; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_003634f0=value; } }
