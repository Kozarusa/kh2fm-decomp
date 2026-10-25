#include "../common/types.h"
extern "C" u8* D_0035f104;
extern "C" u32 D_0035f3d4;
extern "C" u32 D_0035f100;
// why: accepted call sites declare it void with no parameters, but this caller sets a0 to the entry address before the jal
extern "C" void func_00139d78(u8*);
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
extern "C" u32 func_00192048(u64);

void func_0026e140(s32 index, s32 value, s32 item) {
    s32 offset = index * 436;
    func_00139d78(D_0035f104 + offset);
    func_0028d980(D_0035f104 + offset, D_0035f3d4, 0, 0, D_0035f100, value, -1, -1, 0);
    if (item >= 0) {
        u8* entry = D_0035f104;
        *(u32*)(entry + offset + 408) = func_00192048(item);
    }
}
