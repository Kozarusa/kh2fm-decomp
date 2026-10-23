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

// Match original predicate value transport; types remain provisional.

u32 func_002ddbb8(u8* object) { register u32 value asm("$15")=*(u32*)(object+0xaf8); asm volatile("" : "+r"(value)); if(value) { asm volatile("lhu %0,18(%0)" : "+r"(value) : : "memory"); return value&1u; } asm volatile("" ::: "$2"); return 0; }
