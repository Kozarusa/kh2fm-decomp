#include "../common/types.h"
extern "C" u16* func_001a8110(u16*);
extern "C" s32 func_001a3570(u32);
extern "C" void func_001a34e0(u32, s32);

u16 func_001a3958(u32 type) {
    u16* entry = 0;
    do {
        entry = func_001a8110(entry);
        if (entry == 0) {
            return 0;
        }
    } while (((u8*)entry)[2] != type || func_001a3570(entry[0]) <= 0);
    func_001a34e0(entry[0], 1);
    return entry[0];
}