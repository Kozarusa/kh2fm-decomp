#include "../common/types.h"

// Preserve original registry aliases.
void func_0014d240(u32 phase, u32 priority) asm("_Z16wtarget_0014d240jjjj");
void func_00194710(u32 phase, u32 priority) asm("_Z16wtarget_00194710jjjj");
void func_001c2ad8(u32 phase, u32 priority) asm("_Z16wtarget_001c2ad8jjjj");
void func_0022d2e0(u32 phase, u32 priority) asm("_Z16wtarget_0022d2e0jjjj");
#include "../kn/fvector.hpp"

// Recover native data widths/FPU arguments from instructions, not Ghidra types.
// Vector copies reuse the established FVector hardware primitive; syscall
// veneers necessarily retain explicit kernel-entry instructions.
struct __attribute__((packed)) FmPacked64 { u64 value; };
extern FmPacked64 D_0032b9d0;
extern kn::FVector D_00347ce0;
extern volatile s8* D_0032ba78;
extern u8 D_00347c88;
struct FmInit2Float { u32 first, second; f32 value; };
extern FmInit2Float D_004574b8;
extern f32 D_0036b100;
struct FmFloats4 { f32 first, second, third, fourth; };
extern FmFloats4 D_01c61ae0, D_01d49520;
extern f32 D_0036cf04, D_0036ddd8;
extern u32 D_01dad990[6];
extern "C" void func_00133ba0(void*, u32, u32);
extern "C" f32 func_00166d70(u32);
extern "C" void func_00154de8(u32, f32);
extern "C" f32 func_001065a8(f32, f32);
extern "C" void func_002bc1e8(u32);
extern "C" u32 func_00289310(void);
extern "C" void func_002a8768(void);
extern "C" void func_002a8330(void);
extern "C" void func_002a98a8(void);
extern "C" void func_002a95a8(void);

// Unaligned 64-bit copies form one hardware primitive so the compiler cannot
// move half of the store pair into the return delay slot.
void func_00102fb0(const FmPacked64* value) {
    register u32 high asm("$15") = 0x00330000;
    asm volatile("" : "+r"(high));
    register void* target asm("$14") = (void*)(high - 0x4630);
    asm volatile(".set push; .set noreorder; ldl $11, 7(%1); ldr $11, 0(%1); sdl $11, 7(%0); sdr $11, 0(%0); .set pop"
        : : "r"(target), "r"(value) : "$11", "memory");
    asm volatile("" : : "r"(high));
}
void func_00102fd0(FmPacked64* value) {
    register u32 high asm("$15") = 0x00330000;
    asm volatile("" : "+r"(high));
    register const void* source asm("$14") = (void*)(high - 0x4630);
    asm volatile(".set push; .set noreorder; ldl $11, 7(%1); ldr $11, 0(%1); sdl $11, 7(%0); sdr $11, 0(%0); .set pop"
        : : "r"(value), "r"(source) : "$11", "memory");
    asm volatile("" : : "r"(high));
}
void func_001040a8(s8 first, s8 second, s8 third, u32 word) {
    D_0032ba78[0] = first;
    D_0032ba78[1] = second;
    D_0032ba78[2] = third;
    D_0032ba78[3] = -1;
    *(volatile u32*)(D_0032ba78 + 4) = word;
}
void func_00107288(u8* object, const kn::FVector* first, const kn::FVector* second, const kn::FVector* third) {
    *(kn::FVector*)(object + 0x50) = *first;
    *(kn::FVector*)(object + 0x60) = *second;
    *(kn::FVector*)(object + 0x70) = *third;
}
void func_001342f8(u32 first, u32 second) { func_00133ba0(&D_00347c88, first, second); }
void func_00134d90(u8* object, const kn::FVector* value) { *(kn::FVector*)(object + 0x10) = *value; }
void func_00135650(const kn::FVector* value) { D_00347ce0 = *value; }
void func_0014d240(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32 source asm("$13") = 0x00370000;
        register u32 high asm("$15") = 0x00450000;
        asm volatile("" : "+r"(source), "+r"(high));
        source -= 0x4f00;
        asm volatile("" : "+r"(source));
        *(u32*)(high + 0x74b8) = 0;
        register f32 value asm("$f0") = *(f32*)source;
        asm volatile("" : "+r"(high), "+f"(value));
        register FmInit2Float* target asm("$14") = (FmInit2Float*)(high + 0x74b8);
        asm volatile("" : "+r"(target), "+f"(value));
        target->second = 0;
        asm volatile("" ::: "memory");
        target->value = value;
        asm volatile("" : : "r"(high));
    }
}
void func_001556c0(u32 object) { func_00154de8(object, func_00166d70(*(u32*)(object + 0x34))); }
void func_00194710(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036cf04;
        register f32 zero asm("$f1") = 0.0f;
        asm volatile("" : "+r"(source), "+f"(zero));
        register u32 high asm("$14") = 0x01c60000;
        asm volatile("" : "+r"(high));
        register f32 value asm("$f0") = *source;
        *(f32*)(high + 0x1ae0) = zero;
        asm volatile("" : "+r"(high));
        register FmFloats4* target asm("$15") = (FmFloats4*)(high + 0x1ae0);
        asm volatile("" : "+r"(target));
        asm volatile("" ::: "memory");
        target->fourth = value;
        asm volatile("" ::: "memory");
        target->third = zero;
        asm volatile("" ::: "memory");
        target->second = value;
    }
}
void func_001c2ad8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$13") = &D_0036ddd8;
        register f32 zero asm("$f1") = 0.0f;
        asm volatile("" : "+r"(source), "+f"(zero));
        register u32 high asm("$14") = 0x01d50000;
        asm volatile("" : "+r"(high));
        register f32 value asm("$f0") = *source;
        *(f32*)(high - 0x6ae0) = zero;
        register FmFloats4* target asm("$15") = (FmFloats4*)(high - 0x6ae0);
        asm volatile("" : "+r"(target));
        asm volatile("" ::: "memory");
        target->fourth = value;
        asm volatile("" ::: "memory");
        target->third = zero;
        asm volatile("" ::: "memory");
        target->second = zero;
    }
}
void func_001d1820(u32* input) {
    register u32* object asm("$16") = input;
    asm volatile("" : : "r"(object));
    register u32 flags asm("$14") = input[3];
    if ((flags & 4) != 0) {
        register u32 blocked asm("$13") = flags & 8;
        asm volatile("" : "+r"(blocked));
        if (blocked == 0 && input[10] != 0) {
            func_002bc1e8(input[10]);
            flags = object[3];
        }
    }
    register u32 result asm("$15") = flags | 8;
    asm("" : "+r"(result) : "r"(flags));
    object[3] = result;
}
u8* func_001e02b8(u32* descriptor, u32 key) {
    register s32 count asm("$13") = *(s32*)(descriptor[0] + 8);
    register s32 index asm("$14") = 0;
    register u8* result asm("$2");
    if (count > 0) {
        register u8* item asm("$4") = (u8*)descriptor[1];
        do {
            u32 item_key = *(u16*)(item + 2);
            result = item;
            asm volatile("" : : "r"(item), "r"(result), "r"(count), "r"(index));
            if (item_key == key) goto done;
            ++index;
            item += 0x50;
        } while (index < count);
    }
    result = 0;
done:
    asm volatile("" : : "r"(index));
    return result;
}
void func_0022d2e0(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32* target asm("$15") = D_01dad990;
        asm volatile("" : "+r"(target));
        D_01dad990[0] = 0;
        asm volatile("" ::: "memory");
        target[5] = 0;
        asm volatile("" ::: "memory");
        target[1] = 0;
        asm volatile("" ::: "memory");
        target[2] = 0;
        asm volatile("" ::: "memory");
        target[3] = 0;
        asm volatile("" ::: "memory");
        target[4] = 0;
        asm volatile("" ::: "memory");
    }
}
void func_0023e838(u8* object, s32 index, f32 value) {
    u8* key = (u8*)(index + (u32)object);
    u32 slot = (u8)key[0xb64];
    *(f32*)(object + slot * 0x140 + 0x674) = value;
}
void func_002a82f8(void) { if (func_00289310() != 0) { func_002a8768(); func_002a8330(); } }
void func_002a9570(void) { if (func_00289310() != 0) { func_002a98a8(); func_002a95a8(); } }
void func_00305340(void) { asm volatile("li $3, 0x12; syscall" ::: "$3", "memory"); }
void func_00305430(void) { asm volatile("li $3, 0x21; syscall" ::: "$3", "memory"); }
void func_00305470(void) { asm volatile("li $3, 0x25; syscall" ::: "$3", "memory"); }
