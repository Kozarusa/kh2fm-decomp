#include "../common/types.h"
extern s32 D_0034c768, D_0034c76c;
void func_00161a58(s32 input) {
    register s32 value asm("$14")=input;
    if(input>=0) {
        // Retain the original branch-likely clamp and its conditional delay slot.
        asm volatile("slti $15,%1,129\n\tbeql $15,$0,1f\n\taddiu %0,$0,128\n1:" : "+r"(value) : "r"(input) : "$15");
    } else { asm volatile("" ::: "$15"); value=0; }
    asm volatile("" ::: "$15");
    D_0034c768=value;
}
void func_00161a80(s32 input) {
    register s32 value asm("$14")=input;
    asm volatile("" : "+r"(value));
    if(input>=0) {
        asm volatile("slti $15,%1,129\n\tbeql $15,$0,1f\n\taddiu %0,$0,128\n1:" : "+r"(value) : "r"(input) : "$15");
    } else { asm volatile("" ::: "$15"); value=0; }
    asm volatile("" ::: "$15");
    D_0034c76c=value;
}
