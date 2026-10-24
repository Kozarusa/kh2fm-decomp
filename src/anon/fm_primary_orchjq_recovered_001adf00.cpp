#include "../common/types.h"
struct Record {
    u32 word0;
    union {
        u32 flags;
        struct {
            u16 low;
            u16 sectors;
        } count;
    } info;
    u32 sector;
    u32 address;
};
extern "C" u32 D_00350c88;
extern "C" u8 D_00350ca0[];
extern "C" u32 func_001ae460(...);
extern "C" u64 func_002f79c8(...);
extern "C" u32 func_002f7be8(...);
extern "C" u64 func_001ae678(...);
extern "C" void func_001ae620(void);
extern "C" u32 func_002f7dc8(...);
extern "C" void func_001ae650(void);
extern "C" void func_003058a0(u32);
extern "C" u32 func_002efcc0(...);

u32 func_001adf00(u32 name, u32 buffer) {
    Record* record = (Record*)func_001ae460(name);
    if (record == 0) {
        return 0;
    }
    for (;;) {
        if (func_002f79c8(1) != 2 ||
            func_002f7be8(record->sector, (record->info.count.sectors & 0x3fff) + 1, buffer, D_00350ca0) != 1) {
            func_001ae678();
        } else {
            func_001ae620();
            u32 status = func_002f7dc8();
            D_00350c88 = status;
            if (status == 0) {
                break;
            }
            func_001ae650();
        }
    }
    if (record->info.flags & 0x40000000) {
        func_003058a0(0);
        func_002efcc0(buffer, record->address, (record->info.count.sectors & 0x3fff) * 2048 + 2048);
    }
    return record->address;
}
