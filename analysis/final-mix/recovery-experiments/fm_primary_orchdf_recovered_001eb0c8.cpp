#include "../common/types.h"

struct Manager {
    u8 pad[64];
    f32 scale;
};

struct Params {
    u8 pad[4];
    f32 factor;
    f32 limit;
};

extern "C" Manager* D_01d9e6e0;
extern "C" u8* D_01d9e6e8;
extern "C" void func_002f4000(f32*);
extern "C" void func_002f3d08(u8*, f32*, u8*);

void func_001eb0c8(u32 unused, Params* params) {
    f32 matrix[16];
    func_002f4000(matrix);
    f32 scale = D_01d9e6e0->scale;
    f32 value = scale + scale * params->factor;
    f32 limit = params->limit;
    matrix[0] = value;
    if (limit < value) {
        matrix[0] = limit;
    }
    matrix[10] = matrix[0];
    u8* target = D_01d9e6e8 + 16;
    func_002f3d08(target, matrix, target);
}
