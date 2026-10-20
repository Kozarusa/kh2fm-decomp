#include "../common/types.h"
extern "C" void func_0017f380(u8* object);

void func_0017f380(u8* object) {
    u8* child;
    *(s32*)(object + 60) = 0;
    child = 0;
    *(s32*)(object + 64) = 0;
    while (1) {
        if (child == 0) {
            child = *(u8**)(object + 148);
        } else {
            child = *(u8**)(child + 156);
        }
        if (child == 0) {
            break;
        }
        func_0017f380(child);
    }
}
