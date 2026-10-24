#include "../common/types.h"
struct DamageInfo {
    u8 pad0[4];
    u8 kind;
};
struct Damage {
    u8 pad0[0x20];
    DamageInfo* info;
    u8 pad24[2];
    u8 reaction;
    u8 pad27;
    s32 amount;
};
struct Masks {
    u32 set;
    u32 extra;
    u32 clear;
};
struct Object;
struct ObjectVtable {
    u8 pad0[0x60];
    s32 (*check)(Object*);
    u8 pad64[4];
    void (*apply)(Object*, Damage*);
};
struct Object {
    ObjectVtable* vtable;
    u8 pad4[0x7f4];
    u32 flags;
    u8 pad7fc[0x2c0];
    Masks masks;
};
extern "C" void func_001c20e8(u32, Damage*, Object*);
extern "C" void func_00186d48(Object*, Damage*);
extern "C" s32 func_0018ca48(u8);
extern "C" void func_0013de08(Object*);
extern "C" void func_0013de58(Object*);
extern "C" void func_0013dea8(Object*);
extern "C" void func_00186148(Object*, Damage*);

void func_001762f8(Object* object, Damage* damage) {
    register u32 special asm("$15"); // why: original computes the flag in t7
    if ((object->flags & 4) || object->vtable->check(object) != 0) {
        special = (u32)(damage->info->kind - 5) < 2;
        asm("" : "+r"(special)); // why: flag is a byte the original re-masks before testing
        if (!(u8)special) {
            return;
        }
    }
    Masks* masks = &object->masks;
    func_001c20e8((masks->set | masks->extra) & ~masks->clear, damage, object);
    func_00186d48(object, damage);
    special = (u32)(damage->info->kind - 5) < 2;
        asm("" : "+r"(special)); // why: flag is a byte the original re-masks before testing
    if (!(u8)special) {
        if (object->flags & 4) {
            func_0013dea8(object);
        } else {
            switch (func_0018ca48(damage->reaction)) {
            case 3:
                func_0013de58(object);
                break;
            case 4:
                func_0013dea8(object);
                break;
            case 0:
                if (damage->amount <= 0) {
                    break;
                }
            default:
                func_0013de08(object);
                break;
            }
        }
    }
    object->vtable->apply(object, damage);
    func_00186148(object, damage);
}
