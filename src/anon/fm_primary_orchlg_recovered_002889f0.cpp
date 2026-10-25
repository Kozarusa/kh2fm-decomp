#include "../common/types.h"

struct SelectInit {
    s16 field0;
    s16 field2;
    s16 field4;
    s16 pad6[4];
    s16 field14;
    s16 field16;
    s16 field18;
    s16 field20;
    s16 field22;
    s16 field24;
    s16 field26;
    s16 field28;
    s16 pad30[3];
    u8 field36;
    u8 field37;
    u8 field38;
    u8 field39;
    s32 pad40;
    // why: the original reloads both table pointers on every inner iteration
    s16* volatile table44;
    // why: the original reloads both table pointers on every inner iteration
    s16* volatile table48;
};

// why: the recovered C++ definition (void, int,int) fails the isolated link because the probe linker script defines only the plain symbol; symbols.ld PROVIDEs func_00288c58
extern "C" void func_00288c58(int, int);
extern "C" u32 func_00288f48(s32,u16,u16,u16,u16);
extern "C" u64 func_0028af18(s32,u64);
extern "C" u32 func_0028b1b0(s32,u32);

void func_002889f0(SelectInit* object, s32 count, u8 loop) {
    object->field0 = 0;
    object->field16 = count;
    object->field2 = -1;
    object->field28 = 1;
    object->field36 = loop;
    object->field20 = -1;
    object->field4 = 0;
    object->field18 = 0;
    object->field22 = 0;
    object->field24 = 0;
    object->field26 = 0;
    object->field37 = 0;
    object->field38 = 0;
    object->field39 = 0;
    func_00288c58((int)object, (s16)count);
    func_00288f48((s32)object, 16, 32, 0, 0);
    for (s32 index = 0; index < object->field16; index++) {
        s32 offset = index * 8;
        s32 left = 3;
        do {
            left--;
            // why: the original keeps the first table store ahead of the second table pointer load
            *(volatile s16*)(offset + (s32)object->table44) = -1;
            *(s16*)(offset + (s32)object->table48) = -1;
            offset += 2;
        } while (left >= 0);
    }
    object->field14 = 0;
    func_0028af18((s32)object, 0x73);
    func_0028b1b0((s32)object, 0);
}
