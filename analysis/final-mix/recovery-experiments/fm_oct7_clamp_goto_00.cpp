#include "../common/types.h"
extern s32 D_0034c768,D_0034c76c;
void func_00161a58(s32 input) { register s32 value asm("$14")=input; asm volatile("" : "+r"(value)); if(__builtin_expect(input<0,0)) goto negative; asm volatile("" ::: "$15"); if(input>128) { value=128; asm volatile("" : "+r"(value)); } store: { D_0034c768=value; } return; negative: value=0; asm volatile("" : "+r"(value)); goto store; }
void func_00161a80(s32 input) { register s32 value asm("$14")=input; asm volatile("" : "+r"(value)); if(__builtin_expect(input<0,0)) goto negative; asm volatile("" ::: "$15"); if(input>128) { value=128; asm volatile("" : "+r"(value)); } store: { D_0034c76c=value; } return; negative: value=0; asm volatile("" : "+r"(value)); goto store; }
