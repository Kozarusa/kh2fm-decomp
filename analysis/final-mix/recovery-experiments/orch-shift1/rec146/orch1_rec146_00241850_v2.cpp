#include "../common/types.h"
struct Packed { u64 value; } __attribute__((packed));
extern "C" u8* D_0035ec94;
extern "C" u8* D_0035ec9c;
extern "C" u32 func_002fde18(...);
void func_00241850(s32 index,s64 flag) {
 s64 condition=flag;
 s32 offset=index*32;
 u8* source=D_0035ec9c;
 if (condition) { func_002fde18(D_0035ec94+offset+32,255,8); return; }
 ((Packed*)(D_0035ec94+offset+32))->value=((Packed*)(source+8))->value;
}

