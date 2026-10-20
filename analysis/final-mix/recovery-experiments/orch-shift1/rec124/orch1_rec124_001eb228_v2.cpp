#include "../common/types.h"

struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };

struct Global {
    u8 pad[64];
    f32 value;
};

extern "C" Global* D_01d9e6e0;
extern "C" u8* D_01d9e6e8;
extern "C" void func_002f4000(VUMatrix*);
extern "C" void func_002f3d08(u32, u32, u32);

void func_001eb228(s32 unused, f32* param) {
    VUMatrix matrix;
    f32* cell = (f32*)&matrix;
    func_002f4000(&matrix);
    f32 total = D_01d9e6e0->value + D_01d9e6e0->value * param[1];
    f32 limit = param[2];
    cell[0] = total;
    if (limit < total) {
        cell[0] = limit;
    }
    cell[10] = cell[0];
    cell[5] = cell[0];
    func_002f3d08((u32)(D_01d9e6e8 + 16), (u32)&matrix, (u32)(D_01d9e6e8 + 16));
}
