#include "../common/types.h"

// Preserve original registry aliases.
void func_0014c940(s32 input) asm("_ZN2dk5Timer12setCountDownEj");
extern "C" void func_00133f20(void);
extern "C" u64 func_00134258(void);
extern u32 D_00349df4, D_00349df8, D_00349dfc;
extern u8 D_00349e00;

void func_0010a7d8(u32 first,u32 second,u32 third) {
    register u32 high asm("$14")=0x340000;
    asm volatile("" : "+r"(high), "+r"(first));
    first&=0xff; asm volatile("" : "+r"(first));
    *(u8*)(high+0xed0)=first; asm volatile("" ::: "memory", "$15");
    register u8* base asm("$15")=(u8*)(high+0xed0);
    asm volatile("" : "+r"(base), "+r"(second), "+r"(third) :: "memory");
    second&=0xff; third&=0xff;
    asm volatile("" : "+r"(second), "+r"(third));
    base[2]=third; asm volatile("" ::: "memory"); base[1]=second;
}

u64 func_00134278(void) {
    register u64 result asm("$2");
    asm volatile(".set push; .set noreorder; jal func_00134258; nop; .set pop"
                 : "=r"(result) :: "$3", "$4", "$5", "$6", "$7", "$8", "$9",
                   "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$31", "memory");
    u64 saved=result;
    func_00133f20();
    return saved;
}

void func_0014c940(s32 input) {
    register s32 factor asm("$15")=60;
    register u32 high asm("$14")=0x350000;
    asm volatile("" : "+r"(factor), "+r"(high));
    register s32 value asm("$4")=input*factor;
    register u8 enabled asm("$13")=1;
    register u32 second_high asm("$15")=0x350000;
    asm volatile("" : "+r"(value), "+r"(enabled), "+r"(second_high));
    *(s32*)(high-0x620c)=value;
    *(u8*)(second_high-0x6200)=enabled;
    asm volatile("" ::: "memory", "$14", "$15");
    register u32 last_first asm("$14")=0x350000;
    register u32 last_second asm("$15")=0x350000;
    asm volatile("" : "+r"(last_first), "+r"(last_second));
    *(s32*)(last_first-0x6208)=value;
    *(u32*)(last_second-0x6204)=0;
}
