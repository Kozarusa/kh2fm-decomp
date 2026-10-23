#include "../common/types.h"
extern s32 D_0034c768, D_0034c76c;

void func_00161a58(s32 input) {
    register s32 value asm("$14")=input;
    if(input>=0) {
        // Retain the original branch-likely clamp and its conditional delay slot.
        asm volatile(" .set push\n\t.set noreorder\n\tslti $15,%1,129\n\tbeql $15,$0,1f\n\taddiu %0,$0,128\n1:\n\t.set pop" : "+r"(value) : "r"(input) : "$15");
    } else { asm volatile("" ::: "$15"); value=0; }
    asm volatile("" ::: "$15");
    register s32* destination asm("$15")=(s32*)0x350000; asm volatile("" : "+r"(destination)); *(s32*)((u8*)destination-0x3898)=value;
}

void func_00161a80(s32 input) {
    register s32 value asm("$14")=input;
    asm volatile("" : "+r"(value));
    if(input>=0) {
        asm volatile(" .set push\n\t.set noreorder\n\tslti $15,%1,129\n\tbeql $15,$0,1f\n\taddiu %0,$0,128\n1:\n\t.set pop" : "+r"(value) : "r"(input) : "$15");
    } else { asm volatile("" ::: "$15"); value=0; }
    asm volatile("" ::: "$15");
    register s32* destination asm("$15")=(s32*)0x350000; asm volatile("" : "+r"(destination)); *(s32*)((u8*)destination-0x3894)=value;
}
