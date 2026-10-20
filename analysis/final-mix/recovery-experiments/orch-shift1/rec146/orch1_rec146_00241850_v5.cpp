#include "../common/types.h"
struct Packed { u64 value; } __attribute__((packed));
extern "C" u8* D_0035ec94;
extern "C" u8* D_0035ec9c;
extern "C" u32 func_002fde18(...);
void func_00241850(s32 index,s64 flag) {
 register s64 condition asm("$14")=flag; // why: original preserves flag in t6
 register s32 offset asm("$12")=index*32; // why: original offset uses t4
 register u8* source asm("$13")=D_0035ec9c; // why: original source pointer uses t5
 if (condition) { func_002fde18(D_0035ec94+offset+32,255,8); return; }
 ((Packed*)(D_0035ec94+offset+32))->value=((Packed*)(source+8))->value;
}




