#include "../common/types.h"

extern u32 D_0033cc18;
extern u8 D_00340ed0, D_00340ed1, D_00340ed2;
extern u8 D_00349e00;
extern u32 D_00349df4, D_00349df8, D_00349dfc;
extern u16 D_0034c874, D_0034c876;
extern u64 D_0036b0d0;
extern f32 D_0036b304, D_0036b360, D_004f3588, D_004f35b0;
extern u32 D_003478f0[];
extern "C" void func_00106108(u32*), func_0011ee98(u32,u32*), func_00133f20(void);
extern "C" u64 func_00134258(void);
extern "C" u32* func_00124748(u64,u32);
extern "C" void func_00143b88(u64,u64,u32*,u32*,u64);

void func_001060b8(u32* object,u32 first,u32 second) { object[0]=(u32)&D_0033cc18; asm volatile("" ::: "memory"); object[2]=second; asm volatile("" ::: "memory"); object[1]=first; func_00106108(object); }
void func_001060e0(u32* object,u32 first,u32 second) { object[0]=(u32)&D_0033cc18; asm volatile("" ::: "memory"); object[2]=second; asm volatile("" ::: "memory"); object[1]=first; func_00106108(object); }
void func_0010a7d8(u8 first,u8 second,u8 third) { register u8* base asm("$14")=&D_00340ed0; asm volatile("" : "+r"(base)); base[0]=first; asm volatile("" ::: "memory"); register u8* next asm("$15")=base; asm volatile("" : "+r"(next)); next[2]=third; next[1]=second; }
void func_0011eef8(u32 first,u32* object) {
    object[2]=0; asm volatile("" ::: "memory");
    register u32* saved asm("$15")=object; asm volatile("" : "+r"(saved));
    saved[5]=first; asm volatile("" ::: "memory"); object[3]=0;
    func_0011ee98(first,object);
}
void func_00123dd0(u64 value) { u32* object=func_00124748(value,0); register u32 table asm("$15")=*object; asm volatile("" : "+r"(table)); register u32* arg asm("$4")=object; asm volatile("" : "+r"(arg)); register void (*callback)(u32*) asm("$2")=*(void (**)(u32*))(table+0x1c); asm volatile("" : "+r"(callback)); callback(arg); }
void func_00123e00(u64 value) { u32* object=func_00124748(value,0); register u32 table asm("$15")=*object; asm volatile("" : "+r"(table)); register u32* arg asm("$4")=object; asm volatile("" : "+r"(arg)); register void (*callback)(u32*) asm("$2")=*(void (**)(u32*))(table+0x20); asm volatile("" : "+r"(callback)); callback(arg); }
u64 func_00134278(void) { asm volatile(".set push; .set noreorder"); u64 result=func_00134258(); func_00133f20(); asm volatile(".set pop"); return result; }
void func_00143b60(u64 first,u64 second,u64 third) { struct { u32 first; u32 second[3]; } local; register u32* first_address asm("$6")=&local.first; asm volatile("" : "+r"(first_address)); local.second[0]=0; func_00143b88(first,second,first_address,local.second,third); }

// R5900 packed loads snapshot all four aligned vectors before any store.
void func_0011b6a8(void* target) {
    const void* source=D_003478f0;
    asm volatile(".set push; .set noreorder; lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1);"
                 "sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0); .set pop;"
                 :: "r"(target), "r"(source) : "$8", "$9", "$10", "$11", "memory");
}
void func_00146680(void* target,const void* source) {
    if(target!=source) {
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1);"
                     "sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0);"
                     :: "r"(target), "r"(source) : "$8", "$9", "$10", "$11", "memory");
    }
}
void func_0014b920(u64* object) { object[3]=0x40; register u64 tag asm("$14")=0x1000000000008001ULL; register u64 count asm("$15")=0xe; asm volatile("" : "+r"(tag), "+r"(count)); object[0]=tag; object[1]=count; object[2]=D_0036b0d0; }
void func_0014c940(s32 value) { D_00349df4=value*60; asm volatile("" ::: "memory"); D_00349e00=1; asm volatile("" ::: "memory"); D_00349df8=value*60; asm volatile("" ::: "memory"); D_00349dfc=0; }
void func_00158000(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036b304; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_004f3588=value; } }
void func_00159728(s32 phase,s64 priority) { if(priority==0xffff && phase==1) { register f32* source asm("$15")=&D_0036b360; asm volatile("" : "+r"(source)); register f32 value asm("$f0")=*source; asm volatile("" : "+f"(value)); D_004f35b0=value; } }
void func_00166c80(s16 first,s16 second) { D_0034c874=first; D_0034c876=second; }
