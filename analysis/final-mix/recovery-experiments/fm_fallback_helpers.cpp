#include "../common/types.h"

extern s32 D_00351604, D_00351608, D_0035eb48, D_0035eb4c;
extern u32 D_01d49960, D_01d49964, D_01d49968;
extern u32 D_00351eb8, D_00351ec0, D_00351ec8;
extern u8 D_0035dadc;
extern u32 D_0035dae0, D_01dad910, D_01dad914;
extern u32 D_0035db50, D_0035db58, D_0035db54, D_0035db18;
extern u32 D_0035eb34, D_0035eb28, D_01dae680, D_0035f0ec;
extern u16 D_0035f090, D_0035f092, D_0035f096;
extern u32 D_0035f28c;
extern u8 D_0035f299, D_0035f440, D_00363410;
extern u32 D_003617d8, D_003617dc;
extern f32 D_00375f74;
struct __attribute__((packed)) FmPackedWord { u32 value; };
extern u32 D_01e2bf00, D_01e2bf04, D_003660c8;
extern u32 D_01e35980[];
extern "C" void func_0017c660(u32,u32), func_001c6460(void);
extern "C" void func_001d2690(u32*);
extern "C" void func_0014a4b0(void), func_00138480(u32);
extern "C" void func_00258b00(void), func_00258af0(u32), func_00267620(void);
extern "C" u32 func_00287dc0(void), func_00281238(void), func_002b23e0(void);
extern "C" void func_0023d820(u32), func_0016e920(u32), func_002ac678(u8);
extern "C" void func_001a55a8(u32,u32), func_002e9a00(u32,u32), func_002e9b58(u32,u32,u32);
extern "C" void func_0030f620(u32,u64);

void func_001c3cd8(u32 first, u32 object) { *(f32*)(object+0x11c) = *(f32*)(*(u32*)(object+0x12c)+0xc); func_0017c660(first,object); }
s32 func_001c4170(void) { return D_00351604-D_00351608; }
void func_001c6748(u8* object) { object[0x50] = 2; *(void(**)(void))(object+0x54) = func_001c6460; }
void func_001c8a90(void) { D_01d49960=0; D_01d49964=0; D_01d49968=0; }
void func_001c8de0(void) { D_00351eb8=0; D_00351ec0=0; D_00351ec8=0; }
void func_001d1678(u32* object, u32 value) { register u32 one asm("$15")=1; asm("" : "+r"(one)); object[4]=value; object[3]=one; asm volatile("" ::: "memory"); object[10]=0; asm volatile("" ::: "memory"); object[1]=0; asm volatile("" ::: "memory"); object[6]=0; }
void func_001d2110(s32* object, s32 value) { register s32 maximum asm("$13")=object[6]; register u32 positive asm("$14")=value>0; register u32 below asm("$15")=value<maximum; asm volatile("" : : "r"(maximum),"r"(positive),"r"(below)); if(!positive) value=0; asm("xori %0,%0,0" : "+r"(below)); if(!below) value=maximum; object[11]=value; }
void func_001d2648(u32* object) { object[8]=0; asm volatile("" ::: "memory"); object[0]=0; asm volatile("" ::: "memory"); object[1]=0; func_001d2690(object); }
void func_001da3d8(u32* object, FmPackedWord* source) { FmPackedWord* cursor=(FmPackedWord*)object[3]; *cursor=*source; object[3]=(u32)(cursor+1); }
void func_001efc28(u32 base, u32 object) { base+=*(u32*)(*(u32*)(object+0xc)+4); register u32* target asm("$15")=(u32*)(base+0xa0); asm volatile("" : : "r"(target)); *(u32*)(base+0xa0)=0; target[1]=0; asm volatile("" ::: "memory"); target[2]=0; }
void func_00224950(u32 value) { D_0035dadc=1; D_0035dae0=value; }
void func_00225298(void) { register u32 high asm("$15")=0x01db0000; register u32 invalid asm("$14")=~0u; asm("" : "+r"(high),"+r"(invalid)); *(u32*)(high-0x26f0)=invalid; register u32* target asm("$13")=(u32*)(high-0x26f0); asm volatile("" : : "r"(target)); target[1]=invalid; }
void func_00226d88(void) { func_0014a4b0(); func_00138480(0); }
void func_00226f90(void) { register u32 high asm("$15")=0x00360000; asm("" : "+r"(high)); register u32* target asm("$14")=(u32*)(high-0x24b0); asm volatile("" : : "r"(target)); *(u32*)(high-0x24b0)=0; target[2]=0; asm volatile("" ::: "memory"); target[1]=0; }
u32 func_002282d8(void) { register u32 result asm("$2")=25000; asm("" : "+r"(result)); if(D_0035db18) result=15000; return result; }
void func_0023cdb8(void) { D_0035eb34=1; D_0035eb28=0; D_01dae680=0; }
u32 func_0023d2e0(s32* target) { register u32 high asm("$15")=0x00360000; asm("" : "+r"(high)); register u32 value asm("$14")=*(u32*)(high-0x14b8); asm("" : "+r"(value)); register u32 empty asm("$2")=(~value)<1; asm("" : "+r"(empty)); if(empty) value=0; *target=value; empty^=1; asm("" : "+r"(empty)); return empty; }
u32 func_0023d300(s32* target) { register u32 high asm("$15")=0x00360000; asm("" : "+r"(high)); register u32 value asm("$14")=*(u32*)(high-0x14b4); asm("" : "+r"(value)); register u32 empty asm("$2")=(~value)<1; asm("" : "+r"(empty)); if(empty) value=0; *target=value; empty^=1; asm("" : "+r"(empty)); return empty; }
void func_00253480(void) { func_00258b00(); func_00258af0(9); }
void func_00258d58(u32 first, u32 second, u32 third) { D_0035f090=first; D_0035f092=second; D_0035f096=third; }
void func_002675e8(void) { D_0035f0ec=0; func_00267620(); }
void func_0026c450(void) { func_0023d820(func_00287dc0()); }
void func_00281108(void) { func_0016e920(func_00281238()); }
void func_00281e70(u32 value) { D_0035f28c=value; D_0035f299=0; }
s32 func_0028ac98(s16* object, s32 index) { s32 base=index==*object ? *(s32*)(object+0x18) : *(s32*)(object+0x16); return base+index*8; }
void func_0028af90(u8* object, s64 value) { register u64 selected asm("$15")=value; asm("" : "+r"(selected)); if(value<0) selected=*(u16*)(object+4); *(u16*)(object+0x16)=selected; }
void func_0028dfe8(u32* object) { object[14]=0; object[3]=0; object[0]=(u32)&D_0035f440; }
void func_002b3420(void) { func_002ac678(*(u8*)(func_002b23e0()+2)); }
u32 func_002bd230(u32 first, u32 second) { register u32 high asm("$15")=0x00360000; asm("" : "+r"(high)); u32 old=*(u32*)(high+0x17d8); *(u32*)(high+0x17d8)=first; asm volatile("" ::: "memory"); register u32 same asm("$2")=old==first; asm volatile("" : : "r"(same)); D_003617dc=second; return same; }
f32* func_002d5c20(f32* object) { register f32 zero asm("$f0")=0.0f; asm("" : "+f"(zero)); object[3]=zero; asm volatile("" ::: "memory"); object[0]=zero; asm volatile("" ::: "memory"); object[1]=zero; asm volatile("" ::: "memory"); object[2]=zero; return object; }
u32 func_002ddbb8(u8* object) { u32 value=*(u32*)(object+0xaf8); if(!value) return 0; return (u32)*(u16*)(value+0x12)&1u; }
void func_002e3f58(u32* object) { object[0]=0; object[1]=0; register f32* source asm("$15")=&D_00375f74; asm("" : "+r"(source)); f32 value=*source; object[2]=0; *(f32*)(object+3)=value; }
void func_002e7500(void) { register u32 high asm("$15")=0x01e30000; asm("" : "+r"(high)); register u32* target asm("$14")=(u32*)(high-0x4100); asm volatile("" : : "r"(target)); *(u32*)(high-0x4100)=0; target[1]=0; }
void func_002e7b10(u32* object) { register u32 first asm("$15")=object[0]; asm("" : "+r"(first)); func_001a55a8(first,object[1]); }
void func_002e7be0(u32* object) { register u32 first asm("$15")=object[0]; asm("" : "+r"(first)); func_002e9a00(first,object[1]); }
void func_002e9c98(u32 first,u32* object) { register u32 second asm("$15")=object[0]; asm("" : "+r"(second)); func_002e9b58(first,second,object[1]); }
void func_002ea2d8(u32* object) { register u32 table asm("$15")=(u32)&D_00363410; asm("" : "+r"(table)); register u32 one asm("$14")=1; asm("" : "+r"(one)); object[1]=one; object[0]=table; asm volatile("" ::: "memory"); object[2]=0x181; }
void func_00305aa0(void) { register u32 high asm("$2")=0x00360000; asm("" : "+r"(high)); *(u32*)(high+0x60c8)=0; }
u32 func_00308200(s32 index) { register u32 high asm("$2")=0x01e30000; asm("" : "+r"(high)); high+=0x5980; asm("" : "+r"(high)); return *(u32*)(high+index*4); }
void func_00308da0(u32* object) { object[6]=0; object[4]&=~1u; }
void func_0030f690(u64 value) { func_0030f620(0xb0001000,value); }
void func_0030f6a0(u64 value) { func_0030f620(0xb0001010,value); }
void func_0030f6b0(u64 value) { func_0030f620(0xb0001020,value); }
void func_00315458(void(*callback)(void)) { callback(); }
