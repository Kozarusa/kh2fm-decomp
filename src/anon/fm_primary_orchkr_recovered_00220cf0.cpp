#include "../common/types.h"
struct __attribute__((aligned(16))) FmVector { u32 x,y,z,w; };
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
extern "C" void func_002f3f88(u8*, s32);
extern "C" void func_00222898(u8*, u8*, u8*);
// why: the isolated probe linker script defines only the plain symbols func_002f3f10 and func_00222868, so the C++
// declarations copied from their definitions (fm_fallback_vector.cpp, fm_primary_queuedelta_recovered_00222868.cpp) failed to link in v1
extern "C" void func_002f3f10(FmVector* target,const FmVector* first,const FmVector* second);
extern "C" void func_00222868(VUVector* result,const VUVector* source);
extern "C" f32 D_00370b94;

void func_00220cf0() {
    register u8* entry asm("$2"); // why: v0 is live on entry, not an argument
    asm("" : "=r"(entry)); // why: defines the pointer the caller leaves in v0 before any C++ read
    u8* volatile slot = entry; // why: original spills v0 to 0(sp)
    u8* base = entry;
    u8* pointer = base + 480;
    u8* vector = base + 176;
    // why: volatile read (same as sibling 00220c88) keeps the v0 spill and the s-register saves in the original order; a plain read moved them (v4, 7 words)
    func_002f3f88(pointer, *(volatile s32*)(base + 500));
    func_00222898(vector, base, pointer);
    f32* scale = &D_00370b94;
    asm("" : "+r"(scale)); // why: original materializes the full address (lui+addiu) and loads with offset 0
    *(f32*)(base + 324) = *scale / *(f32*)(base + 188);
    func_002f3f10((FmVector*)pointer, (const FmVector*)vector, (const FmVector*)(base + 160));
    func_00222868((VUVector*)(base + 208), (const VUVector*)pointer);
    *(s32*)(base + 500) += *(s32*)(base + 516);
    *(s32*)(base + 524) -= 1;
}
