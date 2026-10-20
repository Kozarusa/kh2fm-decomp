#include "../common/types.h"
extern s32 D_0034c768, D_0034c76c;
void func_00161a58(s32 input) {
    register s32 value asm("$14")=input;
    if(input<0) { value=0; goto store; }
    if(input>128) value=128;
store:
    D_0034c768=value;
}
void func_00161a80(s32 input) {
    register s32 value asm("$14")=input;
    if(input<0) { value=0; goto store; }
    if(input>128) value=128;
store:
    D_0034c76c=value;
}
