#include "../common/types.h"
struct Group { u8 pad0[28]; u16 start; u16 end; };
struct Item { u8 pad0[12]; u16 start; u16 end; u8 flag; u8 pad1[3]; };
struct Entry { u8 pad0[10]; u16 plane; u8 pad1[4]; };
struct Plane { f32 x; f32 y; f32 z; f32 w; };
struct Object {
    u8 pad0[4];
    Group* groups;
    Item* items;
    Entry* entries;
    u8 pad1[8];
    Plane* planes;
    u8 pad2[4];
    s32 count;
};
extern "C" void func_00141988(Object*, Entry*, u8*);
extern "C" void func_001626e0(u8*, u8*);
extern "C" s32 func_001466b0(u32, u8*);
extern "C" void func_00146ab0(u8*, u8*, u8*);

void func_00165f70(Object* object, u8* vector, u8* out, s32* counter, u32 target) {
    u8 matrix[128];
    u8 source[32];
    s32 count = object->count;
    s32 index;
    for (index = 0; index < count; index++) {
        Group* group = &object->groups[index];
        s32 itemEnd = group->end;
        s32 item = group->start;
        for (; item < itemEnd; item++) {
            Item* current = &object->items[item];
            if (current->flag == 0) continue;
            s32 entryEnd = current->end;
            s32 entry = current->start;
            for (; entry < entryEnd; entry++) {
                Entry* pointer = &object->entries[entry];
                Plane* plane = &object->planes[pointer->plane];
                register f32 dot asm("$f0"); // why: original moves the VU dot product into f0
                // why: VU macro dot product; lqc2/vmul.xyz/vaddy.x/vaddz.x/qmfc2 as in accepted 00163168
                asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                             : "=f"(dot) : "r"(vector), "r"(plane) : "$8", "memory");
                if (dot + plane->w < 0.0f) continue;
                func_00141988(object, pointer, source);
                func_001626e0(source, matrix);
                if (func_001466b0(target, matrix)) {
                    func_00146ab0(out, vector, matrix);
                    out += 80;
                    (*counter)++;
                }
            }
        }
    }
    u8* cursor = matrix + 128;
    while (1) {
        // why: original loop body is five nop words
        asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
        if (matrix == cursor) break;
        cursor -= 16;
    }
}
