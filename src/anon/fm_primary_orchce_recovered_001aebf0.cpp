#include "../common/types.h"
extern "C" u8* D_01c94040[];
extern "C" u8* D_01c9408c;

void func_001aebf0(u8* object) {
    u8* pointer = D_01c94040[object[0]];
    s32 index = object[1];
    if (index >= *(s32*)pointer) {
        D_01c9408c = 0;
        return;
    }
    D_01c9408c = pointer + index * 24 + 4;
}
