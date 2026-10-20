#include "../common/types.h"
extern s32 D_0034c768, D_0034c76c;
void func_00161a58(s32 input) {
    register s32 value asm("$14")=input;
    if(input>=0) {
        asm volatile("" : "+r"(input));
        if(input>128) { value=128; asm volatile("" : "+r"(value)); }
        D_0034c768=value;
        return;
    }
    asm volatile("" ::: "memory"); value=0;
    D_0034c768=value;
}
void func_00161a80(s32 input) {
    register s32 value asm("$14")=input;
    if(input>=0) {
        asm volatile("" : "+r"(input));
        if(input>128) { value=128; asm volatile("" : "+r"(value)); }
        D_0034c76c=value;
        return;
    }
    asm volatile("" ::: "memory"); value=0;
    D_0034c76c=value;
}

