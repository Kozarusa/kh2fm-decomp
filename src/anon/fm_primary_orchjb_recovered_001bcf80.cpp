#include "../common/types.h"
struct List {
    u8 data[20];
};
struct CommandSlot {
    u16 value;
    u8 pad0[10];
};
struct CommandMenu {
    s32 index;
    void* owner;
    u8 pad0[4];
    CommandSlot slots[8];
    u8 pad1[8];
};
struct Item {
    CommandSlot slot;
    List list;
    u8 pad0[4];
};
struct Triple {
    s32 first;
    s32 second;
    s32 third;
};
struct Sub {
    void* owner;
    u8 pad0[8];
    List pending;
    s32 count;
    CommandSlot cursor;
    u8 pad1[24];
};
struct Panel {
    void* vtable;
    u8 timer[8];
    List list;
    s32 state;
    CommandMenu menus[19];
    u8 pad0[4];
    Item items[7];
    Triple triple;
    List queue;
    s32 head;
    s32 tail;
    u8 pad1[16];
    Sub sub;
    f32 speed;
};
extern "C" u8 D_00351228[];
extern "C" f32 D_0036dc68[];
extern "C" u32 func_00190128(void*);
extern "C" void func_0017bf40(void*);
extern "C" u32 func_001bc688(void*);
extern "C" u32 func_001bc778(...);
extern "C" u32 func_001bc720(...);
extern "C" u32 func_001bde58(...);
extern "C" void func_00320730(void*);
extern "C" u32 func_0019d4f8(...);
extern "C" u32 func_001bd370(...);
extern "C" u32 func_001bd3a0(...);

u32 func_001bcf80(Panel* panel) {
    func_00190128(&panel->list);
    func_0017bf40(panel->timer);
    panel->state = 0;
    panel->vtable = D_00351228;
    CommandMenu* menu = panel->menus;
    s32 count = 18;
    do {
        CommandSlot* slot = menu->slots;
        s32 remaining = 7;
        do {
            slot->value = 0;
            func_001bc688(slot);
            remaining--;
            slot++;
        } while (remaining != -1);
        count--;
        func_001bc778(menu);
        func_001bc720(menu);
        menu++;
    } while (count != -1);
    Item* item = panel->items;
    s32 left = 6;
    do {
        item->slot.value = 0;
        func_001bc688(&item->slot);
        left--;
        func_00190128(&item->list);
        func_001bde58(item);
        item++;
    } while (left != -1);
    Triple* triple = &panel->triple;
    triple->first = 0;
    triple->second = 0;
    triple->third = 0;
    func_00190128(&panel->queue);
    panel->head = 0;
    panel->tail = 0;
    Sub* sub = &panel->sub;
    sub->owner = panel;
    func_00190128(&sub->pending);
    panel->sub.count = 0;
    func_00320730(&sub->cursor);
    func_001bc688(&sub->cursor);
    func_0019d4f8(sub);
    f32* speed = D_0036dc68;
    asm("" : "+r"(speed)); // why: original forms the full address before lwc1 0(t7)
    panel->speed = *speed;
    func_0017bf40(panel->timer);
    for (s32 index = 0; index < 19; index++) {
        panel->menus[index].index = index;
        func_001bc778(&panel->menus[index]);
        func_001bc720(&panel->menus[index]);
        panel->menus[index].owner = panel;
    }
    func_001bd370(panel);
    return func_001bd3a0(panel);
}
