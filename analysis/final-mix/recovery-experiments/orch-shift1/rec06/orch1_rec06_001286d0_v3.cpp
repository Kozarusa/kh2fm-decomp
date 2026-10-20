#include "../common/types.h"
extern "C" volatile f32 D_0036aa14;
extern "C" volatile f32 D_0036aa18;

f32 func_001286d0(f32 x, f32 p1, f32 a, f32 b, f32 p2, f32 c, f32 d) {
    f32 t = x - p1;
    f32 inv = D_0036aa14 / (p2 - p1);
    f32 sq = t * t;
    f32 cube = sq * t;
    f32 k = sq * D_0036aa18;
    f32 s = sq * inv;
    f32 inv2 = inv * inv;
    cube = cube * inv2;
    k = k * inv2;
    f32 twice = (cube + cube) * inv;
    return a * ((twice - k) + D_0036aa14) + c * (k - twice) + b * ((cube - (s + s)) + t) + d * (cube - s);
}