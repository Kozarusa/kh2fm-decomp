#include "../common/types.h"
extern "C" char D_0032d7c0;
u32 func_00181500(s32 param_1) {
 s32 row = (param_1 >> 10)*32;
 if(param_1 == 0xffff) return 0;
 asm volatile ("" : "+r"(row), "+r"(param_1));
 param_1 &= 0x3ff;
 u32 column = (u32)param_1 >> 5;
 u32 base = (s32)(long)&D_0032d7c0 + row;
 asm volatile ("" : "+r"(base));
 u32 value = *(u32 *)(base + column*4);
 u32 mask = 1U << (param_1 & 31);
 asm volatile ("" : "+r"(mask));
 return (value & mask) != 0;
}
