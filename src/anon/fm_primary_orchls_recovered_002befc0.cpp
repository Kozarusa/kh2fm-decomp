#include "../common/types.h"

struct MenuWidget {
    u32 table;          // 0x00
    u32 flags;          // 0x04
    u8 base[28];
    u32 allocator;      // 0x24
    u8 first[24];       // 0x28: initialised by 002369a0
    u8 second[92];      // 0x40: initialised by 0023c008
    u32 buffer;         // 0x9c
};

// why: table addresses stored as words at offset 0, as the accepted 002eec58 stores D_003637e0
extern "C" u32 D_00363880[];
extern "C" u32 D_003619a8[];
// why: word global that receives the object address (sw), kept as a word like the table
// words; typed as MenuWidget* the scheduler reorders the two stores (v1/v2: 2 words)
extern "C" u32 D_00361998;
// why: task callback address passed as the third argument, as accepted 002be340 passes its D_ address
extern "C" u8 D_002bf308[];

// why: declaration copied from the accepted caller 0014b4b0 (AREA::GetAllocator)
extern "C" u32 func_001050c8(void);
// why: the accepted definition 002edf28 is void(u32)
extern "C" void func_002edf28(u32 object);
// why: declarations copied from the accepted caller 00153f08
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
// why: the original sets no argument register before this call; the accepted definition
// 002beb90 lists four passthrough words, but they would emit argument setup the original lacks
extern "C" u32 func_002beb90();
// why: YS::CACHE_BUFF::Alloc(const char*, int); the accepted callers use a varargs form,
// declared here from the registers (a0 = name word from 002beb90, a1 = -1)
extern "C" u32 func_001708f8(u32 name, s32 size);
// why: type of the accepted definition 00168b38; extern "C" because the probe linker
// script defines only the plain symbol, and the full build resolves plain func_<addr>
// names via alias generation
extern "C" u8* func_00168b38(u8* object, u32 key, s32 skip);
// why: menu::LayoutWidget::initialize(void*, void*); no accepted using site, this in a0
extern "C" void func_002ef1f8(MenuWidget* widget, u32 first, u32 second);
// why: declaration copied from the accepted worldmap caller 002be340 (FIELD::CreateTask)
extern "C" u32 func_00102c18(u32, u32, u32);

// why: returns the task pointer: the only exit is the tail call into 00102c18, whose chain
// (00102788 TASK_MANAGER::create_task) returns the created task in v0

u32 func_002befc0(MenuWidget* widget)
{
    u32 allocator = func_001050c8();
    func_002edf28((u32)widget);
    widget->allocator = allocator;
    widget->table = (u32)D_00363880;
    func_002369a0(widget->first);
    func_0023c008(widget->second);
    widget->table = (u32)D_003619a8;
    D_00361998 = (u32)widget;
    widget->buffer = func_001708f8(func_002beb90(), -1);
    u8* left = func_00168b38((u8*)widget->buffer, 28, 0);
    u8* right = func_00168b38((u8*)widget->buffer, 29, 0);
    func_002ef1f8(widget, *(u32*)(left + 8), *(u32*)(right + 8));
    widget->flags |= 1;
    return func_00102c18(1, 0x19258, (u32)D_002bf308);
}
