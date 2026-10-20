#include "../common/types.h"
struct Element {
    u8 data[64];
};
struct Header {
    u8 pad0[16];
    u16 start;
    u16 end;
    u8 pad1[4];
    s32 offset;
};
struct Object {
    void* table;
    Header* header;
    Element* buffer;
    Element* first;
    Element* second;
    Element* third;
};
extern "C" u8 D_00347bb0[];
extern "C" Element D_003a99f0[];
extern "C" void func_00124bb8(Object*);
extern "C" void func_0011ed90(u8*);

void func_00127f40(Object* object) {
    func_00124bb8(object);
    Header* header = object->header;
    object->table = D_00347bb0;
    s32 count = header->end - header->start;
    object->buffer = D_003a99f0;
    // why: keeps store order (header end is reloaded after the origin store)
    asm volatile("" ::: "memory");
    Element* pointer = D_003a99f0 + header->end;
    object->first = pointer;
    pointer += count;
    object->second = pointer;
    pointer += count;
    object->third = pointer;
    func_0011ed90((u8*)header + header->offset);
}
