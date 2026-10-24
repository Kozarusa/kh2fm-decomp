#include "../common/types.h"
typedef s32 (*Method)(...);
typedef void (*VoidMethod)(...);
extern "C" u32 func_001c0298(...);
extern "C" u32 func_0018db38(u32, u32, u32, u32);
extern "C" void func_0018e420(u32*, u8*, u8*, u8*, s32);
extern "C" void func_0018ef68(u32*, u64, u64);
extern "C" u32 func_0018ca10(u32);

u32 func_0018e298(u32* holder, u8* owner, u8* entry) {
    s32 mode;
    if ((*(Method*)(*(u8**)owner + 0x60))(owner) != 0 || func_001c0298(owner + 0xa50, *holder) == 0) {
        mode = 4;
    } else {
        mode = 1;
        *(u32*)((u8*)*holder + 4) |= 0x1000;
    }
    u8* info = *(u8**)(entry + 0xc);
    u8* result = (u8*)func_0018db38(*holder, (u32)owner, *(u16*)(info + 2), info[1]);
    u32* flags = (u32*)(owner + 0xabc);
    if ((((flags[0] | flags[1]) & ~flags[2]) & 0x2000) == 0) {
        func_0018e420(holder, owner, result, entry, mode);
    }
    u8* current = (u8*)*holder;
    u8* target = *(u8**)(current + 0x88);
    (*(VoidMethod*)(*(u8**)target + 0x74))(target, owner, current, *(u32*)(result + 0x20));
    u8* node = (u8*)*holder;
    if (*(u32*)(node + 0x8c) != 0) {
        u32 args[3];
        args[0] = *(u32*)(node + 0x94);
        args[1] = (u32)owner;
        args[2] = (u32)node;
        func_0018ef68((u32*)(node + 0x8c), (u64)(s32)(u32)args, 3);
        node = (u8*)*holder;
    }
    *(u32*)(node + 4) &= ~0x1000;
    u8* last = (u8*)*holder;
    u8 value = (*(u8**)(last + 0x28))[0x2f];
    if (value != 0) {
        u8* child = *(u8**)(last + 0xc);
        (*(Method*)(*(u8**)child + 0x78))(child, value, 0, 0);
    }
    (*(VoidMethod*)(*(u8**)owner + 0x64))(owner, result);
    return func_0018ca10((u32)result);
}
