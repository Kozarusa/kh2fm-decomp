#include "../kn/fvector.hpp"
#include "../common/types.h"

// Preserve original registry aliases.
f32 func_001065a8(f32 first, f32 second) asm("_Z13func_001065a8jjjjjjjj");
void func_0011a430(u32* object) asm("_ZN2kn8Peterpan24acceptNotifyPlayerTargetEv");

extern u32* D_0032b9cc;
extern s32 D_0032bb28;
extern u32 D_003a7b60[];
extern u32 D_0033cc18;
extern u8 D_00340ed0, D_00340ed1, D_00340ed2;
extern u32 D_00340ea8;
extern "C" void func_00106108(u32*);
extern "C" f32 func_00106558(f32);
extern "C" u64 func_001c8cd8(void);
extern "C" void func_00119e60(u64, u64);
extern "C" u64 func_00112740(u32);
extern "C" void func_00112730(u32, u64);
extern "C" void func_0011ee98(u32, u32*);
extern "C" u32* func_00124748(u64, u32);

void func_00102ed8(u64 value) {
    u32* object = D_0032b9cc;
    (*(void (**)(u32*, u64))(*(u32*)object + 4))(object, value);
}

void func_001056e8(u32 value) { D_003a7b60[--D_0032bb28] = value; }

f32 func_001065a8(f32 first, f32 second) { return first + func_00106558(second - first); }

void func_001072d0(u8* object, const kn::FVector* first, const kn::FVector* second) {
    *(kn::FVector*)(object + 0x50) = *first;
    *(kn::FVector*)(object + 0x60) = *second;
}

void func_00107300(f32 value, u8* object, const kn::FVector* first, const kn::FVector* second) {
    *(kn::FVector*)(object + 0x50) = *first;
    *(kn::FVector*)(object + 0x60) = *second;
    *(f32*)(object + 0x80) = value;
}

u32 func_0010abc8(u32 size) { u32 old=D_00340ea8; D_00340ea8 += (size+3)&~3u; return old; }

void func_0010c828(u8* object) {
    u32* inner=*(u32**)(object+0xb60);
    (*(void (**)(u32*))(*(u32*)inner+0x18))(inner);
}

void func_00119c88(u64 value) { func_00119e60(value,func_001c8cd8()); }

void func_0011a430(u32* object) { u64 value=func_00112740(object[1]); func_00112730(object[1],value|0x200); }

void func_0011c798(u8* object, u64 value) {
    u32* inner=*(u32**)(object+0x14);
    (*(void (**)(u32*,u32,u64))(*(u32*)inner+0x34))(inner,*(u32*)(object+0x104),value);
}

void func_0011c7c8(u8* object, u64 value) {
    u32* inner=*(u32**)(object+0x14);
    (*(void (**)(u32*,u32,u64))(*(u32*)inner+0x3c))(inner,*(u32*)(object+0x104),value);
}

void func_0011c7f8(u8* object, u64 value) {
    u32* inner=*(u32**)(object+0x14);
    (*(void (**)(u32*,u32,u64))(*(u32*)inner+0x40))(inner,*(u32*)(object+0x104),value);
}

void func_0011f3b8(u32* object) { (*(void (**)(u32*))(*object))(object); }

void func_00123d10(u64 value) { u32* object=func_00124748(value,0); (*(void (**)(u32*))(*object+0xc))(object); }
