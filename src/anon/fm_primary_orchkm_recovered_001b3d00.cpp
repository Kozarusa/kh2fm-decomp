#include "../common/types.h"

struct DamageSource {
    s32 value;
};

struct DamageTarget {
    u8 pad0[8];
    s32 value;
};

struct Damage {
    u8 pad0[0x18];
    u32 flags;
    s32 target;
    DamageSource* source;
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
    u8 pad4[0x2fc];
    u8 combo[0x184];
    s32 handle;
    u8 pad488[0x100];
    u32 state;
    u8 pad58c[0x26c];
    u32 flags;
    u8 pad7fc[0x2c0];
    Masks masks;
    u8 padac8[0x20];
    s32 sourceValue;
};

// why: copied from the accepted call site in fm_primary_orchiv_recovered_001798d8.cpp
extern "C" void func_0016cce8(s32, s32, void*, s32, s32);
// why: copied from the accepted call site in fm_primary_orchiu_recovered_001762f8.cpp
extern "C" void func_00186148(Object*, Damage*);
// why: copied from the accepted call site in fm_primary_orchiu_recovered_001762f8.cpp
extern "C" void func_00186d48(Object*, Damage*);
// why: types from the accepted definition in fm_primary_orchbh_recovered_001883f8.cpp; extern "C" because that C++-linkage definition is not in the isolated probe link
extern "C" s32 func_001883f8(u8* object, s32 value);
// why: no accepted caller or definition; written from registers (a0 = damage, result tested)
extern "C" bool func_0018cdd0(Damage*);
// why: types from the accepted definition in tiny_auto80_queue.cpp; extern "C" for the isolated probe link
extern "C" void func_001b3cb0(u8* a0, u32 a1);
// why: types from the accepted definition in fm_primary_orchjy_recovered_001b3e88.cpp; extern "C" for the isolated probe link
extern "C" void func_001b3e88(u8* object, u8* damage);
// why: copied from the accepted call site in fm_primary_fiveword_recovered_001b2780.cpp
extern "C" bool func_001b58a8(void);
// why: types from the accepted definition in tiny_auto80_queue.cpp; extern "C" for the isolated probe link
extern "C" void func_001b5ab0();
// why: copied from the accepted call site in fm_primary_orchiu_recovered_001762f8.cpp
extern "C" void func_001c20e8(u32, Damage*, Object*);

void func_001b3d00(Object* object, Damage* damage) {
    Masks* masks = &object->masks;
    if (((masks->set | masks->extra) & ~masks->clear) & 0x2000) {
        func_00186148(object, damage);
        return;
    }
    if (func_001b58a8() && func_0018cdd0(damage)) func_001b5ab0();
    if (!(damage->flags & 4)) func_001b3e88((u8*)object, (u8*)damage);
    if (object->flags & 4) return;
    if (object->vtable->check(object) != 0) return;
    object->sourceValue = damage->source->value;
    func_001b3cb0((u8*)object, ((DamageTarget*)damage->target)->value);
    func_00186d48(object, damage);
    if (!(object->flags & 4) || !(object->state & 0x800)) {
        func_001c20e8((object->masks.set | masks->extra) & ~masks->clear, damage, object);
    }
    if (object->handle != 0) {
        func_001883f8(object->combo, (s32)damage);
        s32 args[1];
        args[0] = (s32)damage;
        func_0016cce8(object->handle, 6, args, 1, 0);
    }
    object->vtable->apply(object, damage);
    func_00186148(object, damage);
}
