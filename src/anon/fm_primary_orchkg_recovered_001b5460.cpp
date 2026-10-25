#include "../common/types.h"
typedef s32 (*Method)(s32);
typedef void (*Action)(s32);
extern "C" u8* D_01d48cb0;
extern "C" s32 func_001b5858(u8*);
extern "C" s32 func_001b5cb8(u8*);
extern "C" int func_001b9bc8(s32);
extern "C" u32 func_0016cab8(u32);
extern "C" u32 func_0016c7d8(u32);
extern "C" void func_001de450(void*);
extern "C" void func_001c9770(void);
extern "C" void func_001c9b90();
extern "C" void func_001d1c70(u8*);
extern "C" void func_001d1ed0(u32*);
// why: extern "C" because the isolated probe link resolves only unmangled names (a C++ declaration failed to link in rcfix18 001b4f40 v2)
extern "C" void func_001b57f8(u32);
// why: extern "C" because the isolated probe link resolves only unmangled names (a C++ declaration failed to link in rcfix18 001b4f40 v2)
extern "C" void func_001b5588(u32);

void func_001b5460(u8* object) {
    if (func_001b5858(object) == 0 && func_001b5cb8(object) == 0) {
        s32 item = 0;
        while ((item = func_001b9bc8(item)) != 0) {
            if (((Method)(*(u32*)(*(u32*)item + 0x3c)))(item) == 5000) {
                ((Action)(*(u32*)(*(u32*)item + 0x28)))(item);
            }
        }
    }
    u32 lock = *(u32*)(object + 0x34);
    if (lock != 0) {
        func_0016cab8(lock);
        func_0016c7d8(lock);
        *(u32*)(object + 0x34) = 0;
    }
    u8* list = object + 0x18;
    if (*(u32*)(object + 0x18) != 0) {
        func_001de450(list);
    }
    if (func_001b5858(object) == 0) {
        if ((*(u32*)(object + 0x40) & 0x10) != 0) {
            func_001c9770();
        } else {
            func_001c9b90();
        }
    }
    func_001d1c70(object + 0x68);
    func_001d1ed0((u32*)(object + 0xa8));
    func_001b57f8((u32)object);
    func_001b5588((u32)D_01d48cb0);
}
