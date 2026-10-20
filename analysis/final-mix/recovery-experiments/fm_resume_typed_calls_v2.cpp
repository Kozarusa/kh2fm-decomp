#include "../common/types.h"

// Provisional call signatures inferred from original argument and result instructions.
// Every definition requires complete-range compiler equality before registration.
extern "C" void func_0014a9a0(u8*,u64);
extern "C" void func_001b0700(u32,f32);
extern "C" void func_001a2438(u32,u32,u32), func_001a5880(u32,u32,u32), func_001a49a0(u32,u32,u32);
extern "C" void func_00153e28(f32,f32,u32);
extern "C" u64 func_0016a070(void);
extern "C" void func_0019c898(u64);
extern "C" u32* func_001a84b0(void);
extern "C" void func_00138190(u32,u32);
extern "C" s32 func_001a35f8(u16,u8);
extern "C" u8* func_00257770(void), *func_002766d0(void);
extern "C" u16* func_002632d0(void);
extern "C" void func_00139d78(u8*), func_0028da70(u8*,u32), func_0028dac8(u8*,u32), func_001a3888(u16);

void func_0014aa58(u8* object,u64 second,u8 third) {
    asm volatile("" : "+r"(third));
    *(u32*)(object+0xfc)=3;
    asm volatile("" ::: "memory");
    object[0xf4]=third;
    func_0014a9a0(object,second);
}
void func_00172830(u32* object) { func_001b0700(object[1]+0x4a0,*(f32*)(object[0]+4)); }
void func_00175108(u32* object) { register u32 first asm("$15")=object[0]; asm volatile("" : "+r"(first)); func_001a2438(first,object[1],object[2]); }
void func_00175328(u32* object) { register u32 first asm("$15")=object[0]; asm volatile("" : "+r"(first)); func_001a5880(first,object[1],object[2]); }
void func_0018fb70(u32* object) { register u32 first asm("$15")=object[0]; asm volatile("" : "+r"(first)); func_001a49a0(first,object[1],object[2]); }
void func_00175480(u32* object) { register f32 second asm("$f13")=((f32*)object)[2]; asm volatile("" : "+f"(second)); func_00153e28(((f32*)object)[1],second,object[0]); }
void func_0019c8a8(void) { func_0019c898(func_0016a070()); asm volatile("" ::: "memory"); }
void func_001a8548(void) { u32* object=func_001a84b0(); func_00138190(object[0],object[2]); }
bool func_001d4528(u8* object) { return func_001a35f8(*(u16*)(object+0x2a),object[1])>0; }
void func_00256ef0(void) { func_00139d78(func_00257770()+0xb7c); asm volatile("" ::: "memory"); }
void func_00263188(void) { func_0028da70(func_00257770()+0x198,300); }
void func_00263688(void) { func_001a3888(*func_002632d0()); asm volatile("" ::: "memory"); }
void func_00299238(void) { func_0028dac8(func_002766d0()+0x4398,3); }
void func_0029df98(void) { func_0028dac8(func_002766d0()+0x4398,3); }
void func_0029e050(void) { func_0028dac8(func_002766d0()+0x4860,6); }
