#include "../common/types.h"

// Instruction-grounded FM recovery. Names and ABI types remain provisional.
void func_00102250(u32 phase, u32 priority) asm("_Z16wtarget_00102250jjjj");
void func_00149f30(u32 phase, u32 priority) asm("_Z13func_00149f30ii");
void func_00165f28(u32 phase, u32 priority) asm("_Z16wtarget_00165f28jjjj");
void func_00167268(u32 phase, u32 priority) asm("_Z16wtarget_00167268jjjj");
void func_00168a58(u32 phase, u32 priority) asm("_Z16wtarget_00168a58jjjj");
void func_0016d0d8(s32 index, void* value) asm("_Z16wtarget_0016d0d8jjjj");
void func_00191ee0(u32 phase, u32 priority) asm("_Z16wtarget_00191ee0jjjj");
void func_001a8570(u32 phase, u32 priority) asm("_Z16wtarget_001a8570jjjj");
void func_001b8290(u32 phase, u32 priority) asm("_Z16wtarget_001b8290jjjj");
void func_001ba798(u32 phase, u32 priority) asm("_Z16wtarget_001ba798jjjj");
void func_001c8d40(u32 phase, u32 priority) asm("_Z16wtarget_001c8d40jjjj");
void func_001d3bc0(u32 phase, u32 priority) asm("_Z16wtarget_001d3bc0jjjj");
void func_001ddc88(u32 phase, u32 priority) asm("_Z16wtarget_001ddc88jjjj");
void func_002ce910(u32 phase, u32 priority) asm("_Z16wtarget_002ce910jjjj");
void func_002e7610(u32 phase, u32 priority) asm("_Z16wtarget_002e7610jjjj");
void func_002ee540(u32 phase, u32 priority) asm("_Z16wtarget_002ee540jjjj");
void func_002ef890(u32 phase, u32 priority) asm("_Z16wtarget_002ef890jjjj");
struct FmWords2 { u32 first, second; };
extern FmWords2 D_0038aa40, D_004f41c0, D_0034d840, D_01c6cba0;
extern FmWords2 D_01d48de0, D_01d5ba20, D_00352ae0, D_01e2be18;
extern FmWords2 D_01e2bf00, D_01e2c080;
extern u32 D_0032b9d8, D_0035ecd8, D_0034f240, D_01d49970, D_003638d0;
extern u8 D_004f4240, D_0035eb80, D_0035eb81, D_003617e8;
extern u32 D_01d48cb8, D_003511b8;
extern f32 D_0036e160, D_00351fe0;
extern u32 D_00352b50, D_00352b54;
extern void* D_0034dbf8[];
extern u32 D_0034d6c0[];
extern u8 D_01d49570;
extern void* D_0032b994;
extern "C" void func_001ae6a8(void);
extern "C" void func_001ae788(void);
extern "C" void func_001ae8d8(void);
extern "C" void func_001dcd88(void);
extern "C" void func_00299290(void);
extern "C" void func_002b8374(void);
extern "C" void func_001c3f58(void);
extern "C" void func_001a1460(u32);
extern "C" void func_001491c0(void*);
extern u8 D_00348d68;

void func_00102250(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_0038aa40;
        asm volatile("" : "+r"(base));
        D_0038aa40.first = 0; base->second = 0;
    }
}
void func_00102ff0(u8 value) {
    register u32 original asm("$15") = D_0032b9d8;
    asm volatile("" : "+r"(original));
    register u32 state asm("$4") = value != 0;
    asm volatile("" : "+r"(state));
    D_0032b9d8 = (original & ~4u) | (state << 2);
}
void func_00103018(u8 value) {
    register u32 original asm("$15") = D_0032b9d8;
    asm volatile("" : "+r"(original));
    register u32 state asm("$4") = value != 0;
    asm volatile("" : "+r"(state));
    D_0032b9d8 = (original & ~8u) | (state << 3);
}
void* func_00104318(s32 index) {
    register u32 offset asm("$2") = (u32)index << 10;
    if (index == 0) {
        asm volatile("" ::: "$15");
        register u32 base asm("$15") = 0x003a0000;
        asm volatile("" : "+r"(base));
        return (void*)(base + 0x6b00);
    }
    asm volatile("" ::: "$15");
    register u32 base asm("$15") = 0x003a0000;
    asm volatile("" : "+r"(base));
    base += 0x7300;
    asm volatile("" : "+r"(base));
    base -= 0x400;
    asm volatile("" : "+r"(base));
    return (void*)(offset + base);
}
void func_00149f30(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        func_001491c0(&D_00348d68);
        asm volatile("" ::: "memory");
    }
}
void func_00153c98(u32* object) {
    if (object) ((void (*)(u32*))(*(u32*)(*object + 0x10)))(object);
}
void func_00165f28(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_004f41c0;
        asm volatile("" : "+r"(base));
        D_004f41c0.first = 0; base->second = 0;
    }
}
void func_00167268(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_004f4240 = 0;
}
bool func_00168040(s32 index) {
    u32 object = D_0034d6c0[index * 24 + 17];
    return *(u32*)(object + 0x50) != 0;
}
void func_001689d0(void) { func_001ae6a8(); }
void func_001689e8(void) { func_001ae788(); }
void func_00168a18(void) { func_001ae8d8(); }
void func_00168a58(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_0034d840;
        asm volatile("" : "+r"(base));
        D_0034d840.first = 0; base->second = 0;
    }
}
void func_0016d0d8(s32 index, void* value) { D_0034dbf8[index] = value; }
void func_00177678(u32* object) {
    u32 value = object[0x48c / 4];
    if (value != 0) func_001a1460(value);
}
void func_00191ee0(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_0034f240 = 0;
}
void func_001a8570(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_01c6cba0.first = 0; D_01c6cba0.second = 0; }
}
void func_001b8290(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_01d48cb8 = D_003511b8;
}
void func_001ba798(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_01d48de0;
        asm volatile("" : "+r"(base));
        D_01d48de0.first = 0; base->second = 0;
    }
}
void func_001c4050(void) { func_001c3f58(); D_0032b994 = &D_01d49570; }
void func_001c8d40(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_01d49970 = 0;
}
void func_001cbf20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036e160;
        asm volatile("" : "+r"(source));
        D_00351fe0 = *source;
    }
}
void func_001d3bc0(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_01d5ba20;
        asm volatile("" : "+r"(base));
        D_01d5ba20.first = 0; base->second = 0;
    }
}
void func_001ddc88(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_00352ae0;
        asm volatile("" : "+r"(base));
        D_00352ae0.first = 0; base->second = 0;
    }
}
void func_001de798(void) { func_001dcd88(); }
void func_001e0310(u32 value) { D_00352b54 = D_00352b50; D_00352b50 = value; }
void func_0023ed78(void) { D_0035eb80 = 0; D_0035eb81 = 1; }
void func_00242e58(u8 value) { D_0035ecd8 = (D_0035ecd8 & ~1u) | (u32)(value != 0); }
void func_00242e80(u8 value) {
    register u32 original asm("$15") = D_0035ecd8;
    asm volatile("" : "+r"(original));
    register u32 state asm("$4") = value != 0;
    asm volatile("" : "+r"(state));
    D_0035ecd8 = (original & ~2u) | (state << 1);
}
void func_00242ec0(u8 value) {
    register u32 original asm("$15") = D_0035ecd8;
    asm volatile("" : "+r"(original));
    register u32 state asm("$4") = value != 0;
    asm volatile("" : "+r"(state));
    D_0035ecd8 = (original & ~4u) | (state << 2);
}
void func_00298e20(u32 unused, u32 mode) { if (mode == 4) func_00299290(); }
void func_002bd5a0(void) { func_002b8374(); D_003617e8 = 0; }
void func_002ce910(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_01e2be18;
        asm volatile("" : "+r"(base));
        D_01e2be18.first = 0; base->second = 0;
    }
}
s8* func_002e77f8(s8* object, s32 index) {
    s8* result = 0;
    if (*object == 1) {
        object += 0x160;
        asm volatile("" : "+r"(object));
        result = object + index * 0x710;
    }
    return result;
}
s8* func_002e7820(s8* object, s32 index) {
    s8* result = 0;
    if (*object == 1) {
        register u32 scaled asm("$15") = index * 0x260;
        register u32 base asm("$14") = (u32)object + 0x8080;
        asm volatile("" : "+r"(scaled), "+r"(base));
        result = (s8*)(base + scaled);
    }
    return result;
}
void func_002e7610(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_01e2bf00;
        asm volatile("" : "+r"(base));
        D_01e2bf00.first = 0; base->second = 0;
    }
}
void func_002ee540(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register FmWords2* base asm("$15") = &D_01e2c080;
        asm volatile("" : "+r"(base));
        D_01e2c080.first = 0; base->second = 0;
    }
}
void func_002ef890(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_003638d0 = phase;
}
