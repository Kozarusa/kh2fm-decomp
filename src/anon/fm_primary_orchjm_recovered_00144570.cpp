#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Sphere {
    kn::FVector center;
    f32 radius;
};

f32 func_00144570(f32* bounds, Sphere* sphere) {
    kn::FVector center;
    center = sphere->center;
    register f32 radius asm("$f0") = sphere->radius; // why: original keeps the radius in f0, the return register
    f32* lanes = (f32*)&center;
    bounds[0] = lanes[0] - radius;
    bounds[1] = lanes[1] - radius;
    bounds[2] = lanes[2] - radius;
    bounds[3] = lanes[0] + radius;
    bounds[4] = lanes[1] + radius;
    bounds[5] = lanes[2] + radius;
    return radius;
}
