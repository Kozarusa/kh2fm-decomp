#include "../common/types.h"
struct Record {
    u16 head;
    u16 kind;
    u8 pad0[8];
    u32 data[5];
    u8 level;
    u8 pad1[3];
};
struct Owner {
    u8 pad0[2244];
    Record records[7]; // why: layout only, places handle at 0x9e0; the code indexes records through a byte base
    u8 pad1[32];
    u32 handle;
};
extern "C" u32 func_001b8e88(...);
extern "C" void func_001bc6a8(u8* object_in, u16* source, u32 arg2, u32 arg3, u32 flag);

Record* func_001bd418(Owner* owner, s32 index, s32 code, u32* data, u32 flag, s32 level) {
    u8* base = (u8*)owner + index * 36;
    Record* record = (Record*)(base + 2244);
    if (record->kind != 0 && level < record->level) {
        return 0;
    }
    u32 info = func_001b8e88(code);
    record->data[0] = data[0];
    record->data[1] = data[1];
    record->data[2] = data[2];
    record->data[3] = data[3];
    record->data[4] = data[4];
    func_001bc6a8((u8*)record, (u16*)info, owner->handle, (u32)(base + 2256), flag);
    record->level = level;
    return record;
}
