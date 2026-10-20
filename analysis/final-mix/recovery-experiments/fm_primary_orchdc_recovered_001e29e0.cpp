#include "../common/types.h"
extern "C" u8* func_00102c80(void);
extern "C" u8* func_00102788(...);
extern "C" u8* func_001050d8(u64);
extern "C" u64 func_001e27c0(...);

extern "C" u8 D_001e2938[];
extern "C" u8 D_001e2998[];
extern "C" s32 D_00352bd0;

void func_001e29e0(s32 value) {
    u8* manager = func_00102c80();
    u8* task = func_00102788(*(s32*)(manager + 4), 1, 20500, (s32)D_001e2938);
    *(u8**)(task + 0x30) = D_001e2998;
    u8* object = func_001050d8(3600);
    func_001e27c0(object);
    D_00352bd0 = (s32)object;
    *(s32*)(object + 0xdd0) = value;
}
