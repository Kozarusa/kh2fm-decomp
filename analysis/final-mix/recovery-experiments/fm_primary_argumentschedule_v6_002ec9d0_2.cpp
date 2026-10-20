#include "../common/types.h"
extern "C" u32 func_0017c4c8(u32, void*);
extern "C" void func_002eb6f8(f32, u32, u32);
extern "C" void func_002368e8(f32, s32);
extern "C" void func_002367c8(s32);
extern "C" void func_00139d78(void);
extern "C" void func_0028e438(u64, s32, s32, u64);
extern "C" void func_001581f8(void);
extern "C" u64 func_00154ee8(u32);
extern "C" void func_00138c10(s32, u64);
extern "C" s32 func_001d7980(s32);
struct __attribute__((aligned(16))) FmArgumentQuad { u32 words[4]; };

void func_002ec9d0(u32 object, const FmArgumentQuad* source, u32 value) {
    FmArgumentQuad copy;
    asm volatile("lq $8,0(%1); sq $8,0($sp)"
                 : "=m"(copy) : "r"(source) : "$8", "memory");
    func_0017c4c8(object, &copy);
    *(u8*)((s32)object + 0x514) = 8;
    func_002eb6f8(0.0f, object, value);
    register s32 next asm("$15") = (s32)value + 2;
    // Preserve the original increment before the first final store.
    asm volatile("addiu %0,%0,1; sw %2,260(%3)" : "+r"(value), "=m"(*(s32*)((s32)object + 0x104)) : "r"(next), "r"(object));
    *(volatile s32*)((s32)object + 0x100) = value;
}
