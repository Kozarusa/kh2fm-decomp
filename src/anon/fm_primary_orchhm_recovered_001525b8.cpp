#include "../common/types.h"
extern "C" u32 func_00152598(u32, s32, s32, const void*);
extern "C" u32 func_00152508(u32, u32, u32, u32, u32);
extern u8 D_0034a678, D_0034a698;

u32 func_001525b8(u32 object, s32 kind, u32 third, u32 fourth,
                  u32 fifth, u32 sixth, u32 seventh, u32 eighth) {
    u32 created = 0;
    switch (kind) {
    case 0:
        created = func_00152598(object, seventh, fifth, &D_0034a678);
        break;
    case 1:
        created = func_00152598(object, seventh, fifth, &D_0034a698);
        break;
    }
    *(s32*)(object + 0x1c0) = seventh;
    *(u32*)(object + 0x1bc) = sixth;
    *(s32*)(object + 0x1b8) = fifth;
    *(s32*)(object + 0x1b4) = third;
    return func_00152508(object, created, third, fourth, eighth);
}
