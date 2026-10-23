#include "../common/types.h"

// FM functions omitted from the original range ledger. Names and parameter
// types are provisional; each registered body must match unmodified compiler bytes.
extern s32 D_0032b9d8;
extern u32 D_0032ba80;
extern u8 D_0032ba88;
extern u32 D_0032bac0;
extern u32 D_0032bac4;
extern u32 D_0033cbac;
extern u8 D_0033cb80;
extern u8* D_00348800;
extern u8 D_00349268;
extern u8 D_0034926b;
extern u8 D_0034926c;
extern u32 D_01d49970;
extern u8 D_0035f0b4;
extern u8 D_003617e8;
extern u32 D_003617e4;

u32 func_00103040(void) { return (D_0032b9d8 >> 2) & 1u; }
u32 func_00103058(void) { return (D_0032b9d8 >> 3) & 1u; }
u32 func_001041b0(void) { return D_0032ba80; }
u8 func_001041e0(void) { return D_0032ba88; }
void func_00104200(u32 value) { D_0032ba80 = value; }
void func_00104278(u8 value) { D_0032ba88 = value; }
u32 func_00104610(void) { return D_0032bac0; }
u32 func_00104620(void) { return D_0032bac4; }
u32 func_00105e48(void) { return D_0033cbac; }
void* func_00105e58(void) { return &D_0033cb80; }
void func_00133590(void) {}
void func_00139670(u32* object) { object[3] &= ~0x400u; }
void func_001432b8(void) { D_00348800[0x779] = 1; }
void func_0014a1d0(void) { D_00349268 = 1; }
u8 func_0014a4d0(void) { return D_0034926b; }
u8 func_0014a4e0(void) { return D_0034926c; }
void func_001c8ac8(void) { D_01d49970 = 0; }
void func_001dcd20(u32* object) { object[2] |= 0x01000000u; }
s32 func_0023c3b0(u32* object, s32 index) { return object[11] + index * 0x158; }
bool func_00259680(u32 value) { return value < 0x12u; }
u8 func_0025f568(void) { return D_0035f0b4; }
void func_0025f578(void) { D_0035f0b4 = 0; }
bool func_002bd668(void) { return D_003617e8 == 1; }
bool func_002bd720(void) { return D_003617e4 != 0; }
