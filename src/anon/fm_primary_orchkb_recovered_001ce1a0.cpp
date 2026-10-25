#include "../common/types.h"
extern "C" s32 D_00352134;
extern "C" int D_00352130;
extern "C" int* D_01d5b9d0;
extern "C" int* D_01d5b9d4;
extern "C" int* D_01d5b9d8;
extern "C" int* D_01d5b9dc;
extern "C" u8 D_0036e2c0[];
extern "C" u8 D_0036e2c8[];
extern "C" u8 D_0036e2d0[];
extern "C" u8 D_0036e2d8[];
extern "C" u8 D_0036e2e0[];
extern "C" int* func_001ce248(s32, u8*);
// why: types copied from the accepted definition in fm_scalar_recovered_04.cpp; extern "C" because the C++ alias declaration failed the isolated probe (orch1_lg287_001ce1a0_v1)
extern "C" int func_001ce2a0(int* table, int index, int fallback);

int func_001ce1a0(s32 value) {
    D_00352134 = value;
    D_01d5b9d0 = func_001ce248(2, D_0036e2c0);
    D_01d5b9d4 = func_001ce248(2, D_0036e2c8);
    D_01d5b9d8 = func_001ce248(2, D_0036e2d0);
    D_01d5b9dc = func_001ce248(2, D_0036e2d8);
    int* table = func_001ce248(2, D_0036e2e0);
    return D_00352130 = func_001ce2a0(table, 0, 0);
}
