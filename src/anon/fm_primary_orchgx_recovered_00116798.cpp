#include "../common/types.h"
struct Flags { u8 pad[1584]; u32 active : 1; };
extern "C" f32 D_0036a778[];
extern "C" f32 D_0036a77c[];
extern "C" f32 D_0036a780[];
extern "C" f32 D_0036a784[];
extern "C" f32 D_0036a788[];
extern "C" f32 D_0036a78c[];

void func_00116798(u8* object) {
    f32* pointer;
    f32 limit;
    register f32 step asm("$f0"); // why: original keeps the step value in f0
    u8 flag = ((Flags*)object)->active;
    if (flag) {
        pointer = D_0036a778;
        asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
        limit = *pointer;
        if (*(f32*)(object + 1600) < limit && *(f32*)(object + 1616) < limit) {
            pointer = D_0036a77c;
            asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
            step = *pointer;
            *(f32*)(object + 1600) += step;
            *(f32*)(object + 1616) += step;
        }
        pointer = D_0036a780;
        asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
        limit = *pointer;
        if (limit < *(f32*)(object + 1600) && limit < *(f32*)(object + 1616)) {
            pointer = D_0036a77c;
            asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
            step = *pointer;
            *(f32*)(object + 1600) -= step;
            *(f32*)(object + 1616) -= step;
        }
        pointer = D_0036a784;
        asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
        limit = *pointer;
        if (*(f32*)(object + 1604) < limit && *(f32*)(object + 1620) < limit) {
            pointer = D_0036a788;
            asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
            step = *pointer;
            *(f32*)(object + 1604) += step;
            *(f32*)(object + 1620) += step;
        }
        pointer = D_0036a78c;
        asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
        limit = *pointer;
        if (limit < *(f32*)(object + 1604) && limit < *(f32*)(object + 1620)) {
            pointer = D_0036a788;
            asm("" : "+r"(pointer)); // why: forces separate lui/addiu address materialization
            step = *pointer;
            *(f32*)(object + 1604) -= step;
            *(f32*)(object + 1620) -= step;
        }
    }
}
