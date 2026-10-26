#include "../common/types.h"

struct MenuWidget {
    void* table;        // 0x00
    u32 flags;          // 0x04
    u8 base[28];
    u32 allocator;      // 0x24
    u8 first[24];       // 0x28: initialised by 002369a0
    u8 second[92];      // 0x40: initialised by 0023c008
    u8* buffer;         // 0x9c
};

extern "C" u8 D_00363880[];
extern "C" u8 D_003619a8[];
// why: measured MenuWidget* typed global = 2 words off (store order of table and global swapped), swapping the source order also 2 words; void* is exact
extern "C" void* D_00361998;
extern "C" u8 D_002bf308[];

extern "C" u32 func_001050c8(void);
extern "C" void func_002edf28(MenuWidget* object);
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
extern "C" u32 func_002beb90();
extern "C" u8* func_001708f8(u32 name, s32 size);
extern "C" u8* func_00168b38(u8* object, u32 key, s32 skip);
extern "C" void func_002ef1f8(MenuWidget* widget, u32 first, u32 second);
extern "C" u32 func_00102c18(u32, u32, u8*);

u32 func_002bf098(MenuWidget* widget)
{
    u32 allocator = func_001050c8();
    func_002edf28(widget);
    widget->allocator = allocator;
    widget->table = D_00363880;
    func_002369a0(widget->first);
    func_0023c008(widget->second);
    widget->table = D_003619a8;
    D_00361998 = widget;
    widget->buffer = func_001708f8(func_002beb90(), -1);
    u8* left = func_00168b38(widget->buffer, 28, 0);
    u8* right = func_00168b38(widget->buffer, 29, 0);
    func_002ef1f8(widget, *(u32*)(left + 8), *(u32*)(right + 8));
    widget->flags |= 1;
    return func_00102c18(1, 0x19258, D_002bf308);
}
