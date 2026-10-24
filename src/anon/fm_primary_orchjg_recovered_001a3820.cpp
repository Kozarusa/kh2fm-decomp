#include "../common/types.h"
extern "C" u32 func_001a67b0(s32);
extern "C" u32 func_001a80c8(...);

u32 func_001a3820() {
    u8* command = (u8*)func_001a80c8();
    switch (command[2]) {
    case 0:
        return *(u16*)(command + 16);
    case 18:
        return func_001a67b0(*(u16*)(command + 4));
    }
    return 0;
}
