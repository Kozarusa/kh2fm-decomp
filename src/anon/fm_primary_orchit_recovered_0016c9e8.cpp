#include "../common/types.h"
typedef struct Interface {
    void** vtable;
} Interface;
extern "C" Interface* D_004f6288;
extern "C" u8 D_0034dbf8[];
extern "C" void func_001da458(u8*, s32, s32, s32);
extern "C" void func_001da558(u8*, u8*, s32, s32);
extern "C" void func_0016cab8(u8*);
extern "C" void func_0016c7d8(u8*);
extern "C" void func_0016d1f0(s32);
extern "C" s32 func_0016ce90(u8*);

s32 func_0016c9e8(u8* object) {
    s32 value = *(s32*)(object + 0x24);
    if (value != 0) {
        func_001da458(object, value, 0, 0);
        func_001da558(object, D_0034dbf8, 0, 0);
    }
    u8* node = *(u8**)(object + 0x2c);
    while (node != 0) {
        u8* next = *(u8**)(node + 0x28);
        if (node != 0) {
            func_0016cab8(node);
            func_0016c7d8(node);
        }
        node = next;
    }
    ((void (*)(Interface*, s32))D_004f6288->vtable[1])(D_004f6288, *(s32*)(object + 0x14));
    ((void (*)(Interface*, s32))D_004f6288->vtable[1])(D_004f6288, *(s32*)(object + 0x18));
    s32 pending = *(s32*)(object + 0x34);
    if (pending != 0) {
        func_0016d1f0(pending);
    }
    return func_0016ce90(object);
}
