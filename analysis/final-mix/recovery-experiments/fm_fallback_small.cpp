#include "../common/types.h"

// Provisional field types; original instruction bytes are the acceptance gate.
extern u32 D_0032ba84, D_0033cc3c, D_0033cc38;
extern u32 D_00347f80, D_00347f84, D_00349df0, D_00349de8;
extern u32 D_00349dfc, D_00349dec, D_00349df8;
extern f32 D_00349e0c, D_0036b0ec;
extern u32 D_0034b240;
extern f32 D_004f5268, D_004f526c, D_004f5270;
extern u32 D_004f6288, D_004f6294, D_004f6290;
extern u32 D_004f63a8, D_004f63a0, D_004f63ac;
extern f32 D_01c6053c, D_01c60540;
extern u32 D_01c6cba0, D_01c6cba4;
struct __attribute__((packed)) FmPackedWord { u32 value; };
extern FmPackedWord D_01c6cc48;
extern u32 D_01c6ced0, D_01c6ced4, D_00350cc8, D_00350cd0, D_00350ccc;
extern u32* D_01d49320;
extern "C" u32 func_00106178(void);
extern "C" void func_001024b0(u32);
extern "C" void func_0013dd28(void);
extern "C" u32 func_00140df0(void);
extern "C" void func_0014e658(u32);
extern "C" u32 func_001050c8(void);
extern "C" void func_0023edb0(u32);
extern "C" void func_00139858(u32), func_00139ab0(u32);
extern "C" void func_001398d0(u32), func_00139a38(u32);
extern "C" void func_00188958(u32,u32), func_001b1c10(u32,f32), func_001b1be0(u32,f32);
extern "C" void func_0016aeb8(u32,f32), func_00158870(u32,f32);
extern "C" void func_00140f10(u32), func_00140f20(u32);
extern "C" void func_001d2930(u32,u32), func_001cc9c8(u32,f32);
extern "C" void func_001a48c0(u32,u32), func_0018e0d8(u32,u32), func_0018e108(u32,u32), func_001a6490(u32,f32);
extern "C" void func_001b9c28(u32), func_001b9c58(u32);
extern "C" u32 func_001a80c8(void), func_001a8f10(void);
extern "C" void func_001b8e88(u16), func_001a8b38(u32);

void func_00102508(void) { func_001024b0(func_00106178()); }
u32 func_001041c0(void) { if (D_0032ba84 == 0) D_0032ba84 = 1; return D_0032ba84; }
void func_001069b8(u32 value) { D_0033cc3c = D_0033cc38; D_0033cc38 = value; }
void func_0010b550(u8* target) { register u32 invalid asm("$15") = ~0u; asm("" : "+r"(invalid)); target[0] = 0; *(u32*)(target+4) = invalid; asm volatile("" ::: "memory"); target[1] = 0; }
void func_0013a200(void) { D_00347f80 = D_00347f84; D_00347f84 = 0; }
void func_00149ca0(void) { func_0013dd28(); }
void func_0014c9b8(void) { D_00349df0 = D_00349de8; D_00349dfc = 1; }
void func_0014c9d8(u32 value) { D_00349dec |= value; asm volatile("nop" ::: "memory"); }
void func_0014c9f0(u32 value) { D_00349dec &= ~value; asm volatile("nop" ::: "memory"); }
u32 func_0014ca20(void) { D_00349dfc = 0; return D_00349df8; }
void func_0014ce60(void) { register f32* source asm("$15") = &D_0036b0ec; asm("" : "+r"(source)); D_00349e0c = *source; }
void func_0014ec20(void) { func_0014e658(func_00140df0()); }
u32 func_00152598(u32 ignored, s32 index, u32 second, u32 base) { register u32 offset asm("$15") = index*8; asm("" : "+r"(offset)); register u32* target asm("$15") = (u32*)(base+offset); asm("" : "+r"(target)); return second == 0 ? target[0] : target[1]; }
void func_00153c60(void) { func_0023edb0(func_001050c8()); }
void func_0015b780(void) { func_00139858(15); func_00139ab0(15); }
void func_0015b7a0(void) { func_001398d0(15); func_00139a38(15); }
void func_0015e038(void) { if (D_0034b240) *(u8*)(D_0034b240+4) = 0; }
void func_00167638(f32 first, f32 second, f32 third) { D_004f5268 = first; D_004f526c = second; D_004f5270 = third; }
void func_0016c750(u32 value) { register u32 high asm("$13") = 0x004f0000; asm("" : "+r"(high)); register u32 high2 asm("$15") = 0x004f0000; asm("" : "+r"(high2)); register u32* base asm("$14") = (u32*)(high2+0x6290); asm volatile("" : : "r"(high), "r"(high2), "r"(base)); *(u32*)(high2+0x6288) = value; base[1] = 0; *(u32*)(high+0x6290) = 0; }
void func_0016e688(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_00188958(first,object[1]); }
void func_0016f7b0(void) { register u32 high asm("$15") = 0x004f0000; asm("" : "+r"(high)); *(u32*)(high+0x63a8) = 0; register u32* base asm("$13") = (u32*)(high+0x63a8); asm volatile("" : : "r"(base)); D_004f63a0 = 0; base[1] = 0; }
void func_00171910(u32* object) { func_0016aeb8(*(u32*)(object[0]+4),*(f32*)(object+1)); }
void func_00174b28(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_001b1c10(first,*(f32*)(object+1)); }
void func_00174b88(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_001b1be0(first,*(f32*)(object+1)); }
void func_00174ba8(void) { func_00140f10(func_00140df0()); }
void func_00174bc8(void) { func_00140f20(func_00140df0()); }
void func_00174d18(u32* object) { func_00158870(*(u32*)(object[0]+4),*(f32*)(object+1)); }
void func_001751f8(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_001d2930(first,object[1]); }
void func_001752e0(u32* object) { func_001cc9c8(*(u32*)(object[0]+4),*(f32*)(object+1)); }
void func_00177a38(u8* object) { if (object[0xb04] < 100) ++object[0xb04]; }
void func_00177a58(u8* object) { if (object[0xb04]) --object[0xb04]; }
f32 func_001826e0(void) { return D_01c6053c-D_01c60540; }
void func_0018f770(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_001a48c0(first,object[1]); }
void func_0018f8a0(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_0018e0d8(first,object[1]); }
void func_0018fc20(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_0018e108(first,object[1]); }
void func_0018fcc0(u32* object) { register u32 first asm("$15") = object[0]; asm("" : "+r"(first)); func_001a6490(first,*(f32*)(object+1)); }
void func_00197760(void) { func_001b9c28(0); func_001b9c28(1); }
void func_00197780(void) { func_001b9c58(0); func_001b9c58(1); }
void func_001a3868(void) { func_001b8e88(*(u16*)(func_001a80c8()+0x10)); }
void func_001a8498(void) { register u32 high asm("$15") = 0x01c70000; asm("" : "+r"(high)); register u32* base asm("$14") = (u32*)(high-0x3460); asm volatile("" : : "r"(base), "r"(high)); *(u32*)(high-0x3460) = 0; base[1] = 0; }
void func_001a8bb8(u8* object) { object[0] = 0; object[3] = 18; asm volatile("" ::: "memory"); object[1] = 18; asm volatile("" ::: "memory"); object[2] = 18; }
u32 func_001a8bf8(u8* object, s32 index) { return object[index]&31; }
void func_001a90f0(void) { func_001a8b38(func_001a8f10()); }
void func_001a9110(FmPackedWord* source) { register u32 high asm("$15") = 0x01c70000; asm("" : "+r"(high)); register FmPackedWord* target asm("$14") = (FmPackedWord*)(high-0x33b8); asm("" : "+r"(target) : "r"(high)); *target = *source; asm volatile("nop" ::: "memory"); }
void func_001a91f8(u32* object) { register u32 invalid asm("$15") = ~0u; asm("" : "+r"(invalid)); object[5] = 0; asm volatile("" ::: "memory"); object[0] = invalid; asm volatile("" ::: "memory"); object[1] = 0; asm volatile("" ::: "memory"); object[3] = 0; asm volatile("" ::: "memory"); object[4] = 0; }
void func_001ac778(void) { register u32 high asm("$15") = 0x01c70000; asm("" : "+r"(high)); register u32* base asm("$14") = (u32*)(high-0x3130); asm volatile("" : : "r"(base), "r"(high)); *(u32*)(high-0x3130) = 0; base[1] = 0; }
void func_001aeae0(void) { D_00350cc8 = 0; D_00350cd0 = 0; D_00350ccc = 0; }
void func_001b7ff8(u32* object, u32 value) { register u32 current asm("$2") = object[2]; asm("" : "+r"(current)); register u32 increment asm("$5") = value*16; asm("" : "+r"(increment)); increment = current + increment; object[2] = increment; }
u32 func_001bbb08(void) { return D_01d49320 ? *D_01d49320 : 0; }
