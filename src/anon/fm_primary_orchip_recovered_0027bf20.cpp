// func_0027bf20: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern u32* D_0035dcfc;
extern s32 D_0035ec94;
extern s32 D_0035ecc0;
extern s32 D_0035ecc4;
extern s32 D_0035eee0;
extern s32 D_0035ef50;
extern s32 D_0035ef54;
extern u16 D_0035ef70;
extern u16 D_0035f090;
extern u16 D_0035f092;
extern u16 D_0035f094;
extern u16 D_0035f096;
extern u16 D_0035f0a8;
extern u16 D_0035f0aa;
extern u16 D_0035f0ac;
extern s32 D_0035f0e4;
extern s32 D_0035f118;
extern s32 D_0035f11c;
extern u8 D_0035f120;
extern s32 D_0035f230;
extern s32 D_0035f2f8;
extern s32 D_0035f2fc;
extern s32 D_0035f304;
extern s32 D_0035f308;
extern s32 D_0035f30c;
extern s32 D_0035f310;
extern u32* D_0035f324;
extern s32 D_0035f404;
extern s32 D_0035f40c;
extern s32 D_0035f4d0;
extern s32 D_0035f4d4;
extern s32 D_0035f5e4;
extern s32 D_0035f620;
extern s32 D_0035f634;
extern s32 D_003616e8;
extern s32 D_00361f60;
extern f32 D_00362d80;
extern f32 D_00362d84;
extern f32 D_00362d88;
extern f32 D_00362d8c;
extern s32 D_003718d0;
extern s16 D_003726d0;
extern s16 D_003741f0;
extern s8 D_003743c0;
extern f32 D_00374438;
extern f32 D_00374fe0;
extern f32 D_00375870;
extern f32 D_00375874;
extern f32 D_00375884;
extern f32 D_00375888;
extern f32 D_0037588c;
extern f32 D_003758ec;
extern f32 D_0037599c;
extern f32 D_003759a0;
extern f32 D_003759a4;
extern f32 D_00375ae0;
extern f32 D_00375ae4;
extern f32 D_00375ae8;
extern f32 D_00375c8c;
extern f32 D_00375e24;
extern f32 D_00375e28;
extern f32 D_00375e2c;
extern f32 D_00375ef8;
extern s32 D_01e2a3c0;
extern s32 D_01e2a5e8;
extern s32 D_01e2a5ec;
extern s32 D_01e2a5f0;
extern s32 D_01e2a5f4;
extern s32 D_01e2a9f8;
extern s32 D_01e2aa78;
extern s32 D_01e2aa80;
extern s32 D_01e2aa84;
extern f32 D_01e2be10;
extern f32 D_01e2be14;
extern s32 D_01e2be18;
extern u8* D_01e2be1c;

int func_0022f4f0(int arg1);


u32 func_00241a00(void);


u32 func_00242418(u8 *arg1,int arg2);


void func_00243190(int arg1);


short * func_00253330(short arg1);


void func_00253888(int arg1);


u32 func_00257fa8(int arg1);


int func_00257ff8(u32 arg1);


void func_00258ce8(u16 *arg1);


void func_00258dc8(void);


u32 func_002671e8(int arg1);


void func_0026dd18(u32 arg1,u32 arg2,s32 arg3);


void func_002799b0(void);


short func_00282c68(short arg1);


u32 func_00285d18(char arg1);


void func_00287d68(void);


void func_00288018(void);


void func_0028d068(u32 arg1,s32 arg2);


void func_0028d188(int arg1);


u32 func_00292a90(int arg1);


void func_002a4990(int arg1);


u32 func_002ad338(void);


bool func_002b16d8(void);


u32 func_002b99a0(void);


void func_002bafb0(int arg1,s32 arg2);


void func_002bb100(int arg1,int arg2,u8 arg3);


int func_002bbda0(int arg1);


void func_002bbe38(void);


void func_002bbed0(void);


void func_002be2d8(int arg1,int arg2,u32 *arg3);


void func_002cb188(int arg1,s32 arg2);


void func_002cb5d8(u32 arg1,u8 *arg2);


void func_002cd260(int arg1);


bool func_002cf1f8(int arg1,int arg2);


float func_002d0e10(float arg1);


float func_002d48b8(float arg1);


void func_002d8d40(int arg1,float *arg2,float *arg3);


float func_002de968(float arg1);


void func_002e1878(int arg1,s32 arg2);

bool func_0027bf20(int arg1)

{
    bool value4;
    s32 value5;
    value4 = true;
    s32 value6;
    value6 = (*(short *)(D_0035f230 + 2) - *(short *)(D_0035f230 + 4));
    value5 = arg1 * 8 + D_0035f230;
    if (value6 < 0)
    {
        value6 = 0;
    }
    if ((*(char *)(value5 + 0xe) == '\0'))
    {
        value4 = *(char *)(0x11 + value5) <= value6;
    }
    return value4;
}
