#include "../kn/fvector.hpp"
#include "../common/types.h"

// Reuse the established aligned 128-bit assignment primitive. Address and
// register constraints retain original calling and scheduling behavior.
extern kn::FVector D_00347ce0, D_0034a9a0, D_004f3800, D_004f37f0;
extern u32 D_00347d50;
extern u8 D_00347d54, D_00347d55;

void func_00107368(u8* object, kn::FVector* target) {
    register kn::FVector* source asm("$4") = (kn::FVector*)(object + 0x50);
    asm("" : "+r"(source));
    *target = *source;
}
void func_00107478(u8* object, kn::FVector* target) {
    register kn::FVector* source asm("$4") = (kn::FVector*)(object + 0x60);
    asm("" : "+r"(source));
    *target = *source;
}
kn::FVector* func_0011a900(kn::FVector* target, u8* object) {
    register kn::FVector* source asm("$5") = (kn::FVector*)(object + 0x40);
    asm("" : "+r"(source));
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(target), "r"(source) : "$8", "memory");
    return target;
}
void func_0011a918(u8* object, const kn::FVector* source) {
    register kn::FVector* target asm("$4") = (kn::FVector*)(object + 0x40);
    asm("" : "+r"(target));
    *target = *source;
}
void func_0011c138(kn::FVector* target) {
    asm volatile("sq $0,0(%0); sq $0,16(%0); nop" : : "r"(target) : "memory");
}
void func_00134d60(kn::FVector* target, const kn::FVector* source) { *target = *source; }
void func_00134d78(const kn::FVector* source, kn::FVector* target) { *target = *source; }
void func_00134db0(u8* object, kn::FVector* target) {
    register kn::FVector* source asm("$4") = (kn::FVector*)(object + 0x10);
    asm("" : "+r"(source));
    *target = *source;
}
void func_00135670(kn::FVector* target) { *target = D_00347ce0; }
void func_00136a98(void) { D_00347d50 = 0; D_00347d54 = 0; D_00347d55 = 0; }
void func_001391a8(u8* object, const kn::FVector* source) {
    register kn::FVector* target asm("$4") = (kn::FVector*)(object + 0x1a0);
    asm("" : "+r"(target));
    *target = *source;
}
void func_00158920(const kn::FVector* source) { D_0034a9a0 = *source; }
kn::FVector* func_0015cea0(kn::FVector* target) {
    register const kn::FVector* source asm("$15") = &D_004f3800;
    asm("" : "+r"(source));
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(target), "r"(source) : "$8", "memory");
    return target;
}
kn::FVector* func_0015ceb8(kn::FVector* target) {
    register const kn::FVector* source asm("$15") = &D_004f37f0;
    asm("" : "+r"(source));
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(target), "r"(source) : "$8", "memory");
    return target;
}
void func_002f3f88(kn::FVector* target, const kn::FVector* source) {
    asm volatile("lq $6,0(%1); sq $6,0(%0)" : : "r"(target), "r"(source) : "$6", "memory");
}
u32 func_00305dd8(u32 unused, u8* object) {
    register u32 mode asm("$2") = 0x2000;
    asm("" : "+r"(mode));
    *(u64*)(object + 0x48) = 0;
    *(u32*)(object + 4) = mode;
    return 0;
}
u32 func_003060f0(void) {
    register u32 status asm("$2");
    asm volatile("mfc0 %0,$12" : "=r"(status));
    status ^= 1;
    asm("" : "+r"(status));
    return status & 1;
}
bool func_0030ee00(void) {
    register u32 status asm("$2");
    register u32 mask asm("$3");
    // Preserve the CP0 status read before enabling interrupts, including the
    // intervening mask instructions from the original hardware sequence.
    asm volatile("mfc0 %0,$12; lui %1,1; and %0,%0,%1; ei"
        : "=r"(status), "=r"(mask) : : "memory");
    return status != 0;
}
