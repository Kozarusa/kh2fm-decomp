#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Flags {
    u32 active : 1;
    u32 locked : 1;
    u32 unused : 13;
    u32 pending : 1;
};
struct Object {
    Method* table;
    u8 pad[2936];
    Flags flags;
};
extern "C" s32 D_00341780;
extern "C" u8 D_003a9050[];
extern "C" bool func_001917c0(void);
extern "C" s32 func_00110c90(void*);
extern "C" void func_00111060(void*, u8*);

void func_001110e8(Object* object) {
    if ((u8)object->flags.active) {
        if (object->table[24](object) == 0) {
            object->flags.active = 0;
            object->flags.pending = 0;
        }
        return;
    }
    if (object->flags.locked) {
        return;
    }
    switch (D_00341780) {
    case 0:
        return;
    case 1:
        if (func_001917c0()) {
            return;
        }
        break;
    case 2:
        break;
    }
    s32 index = func_00110c90(object);
    if (index < 0) {
        return;
    }
    func_00111060(object, D_003a9050 + index * 16);
}
