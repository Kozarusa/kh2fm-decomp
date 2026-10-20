#include "../common/types.h"
// Registry aliases (_Z16wtarget_*) are omitted here: probe_fm_source.py
// locates each definition by func_<addr> in its emitted symbol, and an asm
// label would rename it out of the probe. Aliases are reapplied at curation.

// Preserve original registry aliases.

// Remaining FM static initializers and small control-flow helpers. Registry
// aliases, addresses and instruction equivalence are checked independently.
struct FmInitPair { u32 first, second; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48;
extern FmInitPair D_01d48da0, D_01d48da8, D_01d48db0, D_01c62140;
extern u32 D_01d48db8, D_00351eb8, D_00351ec0, D_00351ec8;
extern u32 D_0032ba84, D_003617e0, D_0035f214;
extern u8 D_0033cb80[], D_0032b930, D_00348638[], D_01c620c8[];
extern u8 D_0034a9e8, D_01d498d0;
extern f32 D_0036b318, D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
struct FmInitFloat { u32 first, second; f32 value; };
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_0035ebf8, D_0035ebfc;
extern u32 D_01dae688[6];
extern u32 D_01c6cf00[44];
extern "C" void func_00104200(u32);
extern "C" void func_00141010(f32);
extern "C" u32 func_00140df0(void);
extern "C" void func_00140dc0(void);
extern "C" void func_0031b9e0(void*);
extern "C" u32 func_00289310(void);
extern "C" u32 func_0028b038(u32);
extern "C" void func_0028be78(u32, u32);
extern "C" void func_00297b30(void);
extern "C" void func_003058a0(u32);
extern "C" u32 func_00308310(void*, u32);
extern "C" s32 func_003059c0(u32);

void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    register s32 current asm("$14") = value;
    asm volatile("" : : "r"(positive), "r"(current));
    register s32 one asm("$12") = 1;
    if (!positive) current = one;
    asm("" : "+r"(current) : "r"(one));
    D_0032ba84 = current;
    register u32 selected asm("$4") = 2;
    asm volatile("" : : "r"(selected));
    if (current != 2) {
        if (current < 3) {
            if (current != one) { asm volatile("" : : "r"(selected)); return; }
            selected = 1;
        }
        else { if (current != 3) return; selected = 3; }
    }
    asm volatile("" : : "r"(selected));
    return func_00104200(selected);
}
void func_00105e68(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32 high asm("$11") = 0x00340000;
        asm("" : "+r"(high));
        register u8* target asm("$13") = (u8*)(high - 0x3480);
        register u32 table asm("$15") = (u32)&D_0032b930;
        asm("" : "+r"(target), "+r"(table) : "r"(high));
        register u32 mode asm("$14") = 0x1000;
        asm volatile("" : : "r"(mode));
        *(u32*)(high - 0x3480) = table;
        *(u32*)(target + 0x28) = mode;
        asm volatile("" ::: "memory");
        register u32 population asm("$12") = 140000;
        asm volatile("" : "+r"(population) : : "memory");
        *(u32*)(target + 4) = 0;
        asm volatile("" ::: "memory");
        register u32 marker asm("$15") = 0x54;
        asm volatile("" : : "r"(marker));
        *(u32*)(target + 0x18) = population;
        asm volatile("" ::: "memory");
        mode = 2;
        asm volatile("" : : "r"(mode));
        target[8] = marker;
        asm volatile("" ::: "memory");
        *(u32*)(target + 0x14) = mode;
        asm volatile("" ::: "memory");
        *(u32*)(target + 0x1c) = 0;
        asm volatile("" ::: "memory");
        *(u32*)(target + 0x20) = 0;
        asm volatile("" ::: "memory");
        *(u32*)(target + 0x24) = 0;
    }
}
void func_0013df48(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u8* base asm("$15") = D_00348638;
        asm("" : "+r"(base));
        u32* target = (u32*)(base + 0xc);
        s32 remaining = 2;
        do { *target = 0; --remaining; ++target; } while (remaining != -1);
    }
}
void func_00158f40(void) {
    register f32* source asm("$15") = &D_0036b318;
    asm("" : "+r"(source));
    func_00141010(*source);
    u32 object = func_00140df0();
    func_00140dc0();
    *(u32*)(object + 0x40) = 6;
    D_0034a9e8 = 1;
}
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
    }
}
void func_001995f8(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) {
            register u32 scheduling_constant asm("$15") = 0xffffu;
            asm volatile("" : : "r"(scheduling_constant));
            u8* base = D_01c620c8;
            u32* target = (u32*)(base + 0x60);
            for (s32 index = 0; index < 4; ++index) *target++ = index;
            *(u32*)(base + 0x70) = 4;
        }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { D_01c62140.first = 0; D_01c62140.second = 0; }
    }
}
void func_001ae788(u32 object) {
    register s32 index asm("$13") = 0;
    register u32 high asm("$15") = 0x01c70000;
    asm("" : "+r"(high));
    register u32* base asm("$12") = (u32*)(high - 0x3100);
    asm volatile("" : : "r"(high), "r"(base));
    register u32* item asm("$14") = base;
    asm volatile("" : : "r"(index), "r"(base), "r"(item));
    for (;;) {
        u32 value = *item;
        item += 11;
        if (value == object) break;
        ++index;
        if (index >= 4) break;
    }
    register s32 stride asm("$15") = 44;
    asm("" : "+r"(stride));
    register u32* destination asm("$15") = (u32*)(index * stride + (u32)base);
    asm volatile("" : : "r"(destination), "r"(index), "r"(base), "r"(item));
    *destination = 0;
    *(u32*)(object + 8) = 0;
}
void func_001ba060(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_01d48db8 = 0;
    }
}
void func_001c7ab8(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) {
            register f32* source asm("$15") = &D_0036dfd4;
            asm volatile("" : "+r"(source)); D_01d498c0 = *source;
        }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) {
            register f32* source asm("$15") = &D_0036dfd8;
            asm volatile("" : "+r"(source)); D_01d498c4 = *source;
        }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) { func_0031b9e0(&D_01d498d0); asm volatile("" ::: "memory"); }
    }
}
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) {
            register f32* source asm("$13") = &D_0036e5ec;
            asm volatile("" : "+r"(source));
            D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = *source;
        }
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) {
            register f32* source asm("$15") = &D_0036e5f0;
            asm volatile("" : "+r"(source));
            D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
        }
    }
}
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32 first asm("$10") = D_0035ebf8;
        register u32 high asm("$12") = 0x01db0000;
        asm("" : "+r"(high));
        register u32* target asm("$13") = (u32*)(high - 0x1978);
        asm("" : "+r"(target) : "r"(first), "r"(high));
        register u32 mode asm("$14") = 0x3c4;
        asm volatile("" : : "r"(mode));
        target[4] = 0;
        asm volatile("" ::: "memory");
        target[1] = mode;
        asm volatile("" ::: "memory");
        register u32 second asm("$11") = D_0035ebfc;
        mode = 0x00010000;
        asm volatile("" : : "r"(mode));
        *(u32*)(high - 0x1978) = first;
        asm volatile("" ::: "memory");
        register u32 marker asm("$15") = 0x8a58;
        asm volatile("" : : "r"(marker));
        target[2] = second;
        asm volatile("" : "+r"(mode) : : "memory");
        mode |= 0xfc0;
        target[3] = marker;
        asm volatile("" ::: "memory");
        target[5] = mode;
    }
}
void func_00297878(u32 object) {
    if (func_00289310() != 0) {
        u32 result = func_0028b038(object);
        func_0028be78(D_0035f214, result);
        func_00297b30();
    }
}
void func_002bd5f8(u32 source, u32 size, s32 index) {
    if (index < 0) index = 0;
    u32 request[4] = {source, D_003617e0 + index * 0x8000, size, 0};
    func_003058a0(0);
    u32 handle;
    do { handle = func_00308310(request, 1); } while (handle == 0);
    while (func_003059c0(handle) >= 0) {}
}
