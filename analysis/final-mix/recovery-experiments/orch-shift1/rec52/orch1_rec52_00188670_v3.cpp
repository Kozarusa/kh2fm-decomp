#include "../common/types.h"
struct Entry { s32 first; s32 second; s32 third; };
extern "C" void func_00188550();
extern "C" u32 func_00102788(s32,s32,s32,void (*)());
extern "C" Entry D_01c608c0[];
extern "C" s32 D_01c60bc0;
extern "C" s32 D_00351214;

u32 func_00188670() {
    for (s32 index = 0; index < 64; index++) {
        D_01c608c0[index].first = 0;
    }
    D_01c60bc0 = 0;
    return func_00102788(D_00351214, 0, 0, func_00188550);
}