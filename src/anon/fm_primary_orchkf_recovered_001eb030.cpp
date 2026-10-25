#include "../common/types.h"

struct Manager {
    u8 pad[64];
    f32 scaleX;
    f32 scaleY;
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

void func_001eb030(u32 unused, Params* params) {
    f32 matrix[16];
    func_002f4000(matrix);
    f32 factor = params->factor;
    Manager* manager = D_01d9e6e0;
    f32 limit = params->limit;
    f32 scaleX = manager->scaleX;
    f32 valueX = scaleX + scaleX * factor;
    matrix[0] = valueX;
    if (limit < valueX) {
        matrix[0] = limit;
    }
    matrix[10] = matrix[0];
    f32 scaleY = manager->scaleY;
    f32 valueY = scaleY + scaleY * factor;
    matrix[5] = valueY;
    if (limit < valueY) {
        matrix[5] = limit;
    }
    u8* target = D_01d9e6e8 + 16;
    func_002f3d08(target, matrix, target);
}
