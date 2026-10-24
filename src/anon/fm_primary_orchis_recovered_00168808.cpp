#include "../common/types.h"
struct Allocator;
extern "C" u32 func_0014d358(u32,u32,u32,u32);
extern "C" void* func_00102788(Allocator*,s32,s32,s32);
extern "C" u32 func_001adcf8(s64);
extern "C" u8 D_004f5280[], D_001685f0[], D_00168678[];
extern "C" s32 D_0032b91c;
extern "C" u8 D_0034d800[64];

u32 func_00168808(s64 value) {
    if (value == -1) {
        func_0014d358((u32)D_004f5280,4096,(u32)D_001685f0,0);
        func_00102788((Allocator*)D_0032b91c,0,400000,(s32)D_00168678);
        s32 count=3;
        u32 pointer=(u32)D_0034d800;
        pointer+=8;
        do {
            *(u32*)pointer=0;
            --count;
            pointer+=16;
        } while (count>=0);
    }
    return func_001adcf8(value);
}
