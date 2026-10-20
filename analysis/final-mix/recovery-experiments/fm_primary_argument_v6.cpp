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
    register u32 callObject asm("$4") = object;
    asm("" : "+r"(callObject));
    func_002eb6f8(0.0f, callObject, value);
    s32 high = (s32)value + 2;
    value += 1;
    asm("" : "+r"(value) : "r"(high));
    *(s32*)((s32)object + 0x104) = high;
    *(s32*)((s32)object + 0x100) = value;
}

void func_00236bb8(f32 value, s32 object) {
    s32 index = 0;
    if (*(s32*)(object + 0x10) > 0) {
        s32 offset = 0;
        do {
            ++index;
            func_002368e8(value, *(s32*)(object + 0x14) + offset);
            func_002367c8(*(s32*)(object + 0x14) + offset);
            offset += 0x1a0;
        } while (index < *(s32*)(object + 0x10));
    }
}

void func_0028e560(u64 object, const s16* source, s32 count, u64 value) {
    register u64 savedObject asm("$19") = object;
    register u64 savedValue asm("$20") = value;
    asm("" : : "r"(savedObject), "r"(savedValue));
    func_00139d78();
    s32 index = 0;
    if (count > 0) do {
        func_0028e438(savedObject, index, *source, savedValue);
        ++source;
        ++index;
    } while (index < count);
}

void func_00155528(u32 object) {
    func_001581f8();
    register s32 destination asm("$17") = (s32)object + 0x394;
    asm("" : "+r"(destination));
    u64 result = func_00154ee8(object);
    func_00138c10(destination, result);
}

void func_001d7b10(u16* object) {
    *object = 0;
    s32* cursor = (s32*)(object + 2);
    s32 remaining = 3;
    do {
        register s32 value asm("$15") = *cursor;
        asm("" : "+r"(value));
        asm("addiu %0,%0,8" : "+r"(cursor), "+r"(value));
        if (value != 0) {
            value = func_001d7980(value);
            *object |= *(u16*)(value + 2);
        }
        --remaining;
    } while (remaining >= 0);
}
