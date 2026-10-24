#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    Vec4& operator=(const Vec4& other) {
        if (this != &other) {
            register Quad value asm("$8") = *(const volatile Quad*)&other; // why: original copies through t0
            *(Quad*)this = value;
        }
        return *this;
    }
};
struct Actor;
struct ActorVtbl {
    u8 pad0[60];
    s32 (*getId)(Actor*);
    u8 pad1[80];
    void (*start)(Actor*);
};
struct Actor {
    ActorVtbl* vtbl;
    u8 pad0[1960];
    s32 voice;
    u8 pad1[72];
    u32 flags;
    u8 pad2[48];
    u8 motion[16];
};
struct Context {
    s32 mode;
    Actor* actor;
    void* target;
};
extern "C" f32 D_0036daa0[];
extern "C" f32 D_0036daa4[];
extern "C" f32 D_0036daa8[];
extern "C" f32 D_0036daac[];
extern "C" f32 D_0036dab0[];
extern "C" u16 func_0016a070(s32);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001ad990(f32,f32,f32,void*);
extern "C" u32 func_001ba028(...);
extern "C" u32 func_00102448(...);
extern "C" void func_001703a8(s32);
extern "C" void func_001afb80(s32, s32, s32, void*);
extern "C" u32 func_0016ed50(void*,s64,s64);
extern "C" void func_00170888(s32);
extern "C" void func_001c9e50(s32);
extern "C" s32 func_0017e4f8(void*, Vec4*, f32, f32, f32);
extern "C" void func_001617d8();

s32 func_001b5cf8(Context* context, s32 task) {
    register s32 kind asm("$21") = -1; // why: original keeps the kind in s5
    u16 part = func_0016a070((s32)context->actor);
    s32 id = context->actor->vtbl->getId(context->actor);
    s32 voice = context->actor->voice;
    switch (id) {
    case 2410:
        kind = 5;
        break;
    case 2420:
        kind = 6;
        break;
    }
    Vec4 position;
    position = *(Vec4*)func_0016c028((s32)context->actor);
    switch (context->mode) {
    case 0: {
        register Actor* actor asm("$17") = context->actor; // why: original keeps the actor in s1
        if ((actor->flags & 0x10) == 0) {
            // why: original reuses t7 for both constant addresses
            register f32* constant asm("$15") = D_0036daa0;
            asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
            f32 limit = *constant;
            constant = D_0036daa4;
            asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
            func_001ad990(*constant, 0.0f, limit, actor->motion);
        }
        actor->flags = actor->flags | 0x10;
        while (func_001ba028(context->actor) != 0) {
            func_00102448(task, 0);
        }
        func_00102448(task, 1);
        break;
    }
    case 1:
        context->actor->vtbl->start(context->actor);
        break;
    }
    func_001703a8(id);
    func_001703a8(id + 1);
    func_001703a8(id + 2);
    func_001afb80(task, voice, part, context->target);
    func_0016ed50(context->target, id, kind);
    func_00170888(task);
    func_001c9e50(task);
    // why: original reuses t7 for all three constant addresses
    register f32* constant asm("$15") = D_0036daa8;
    asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
    f32 first = *constant;
    constant = D_0036daac;
    asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
    f32 second = *constant;
    constant = D_0036dab0;
    asm("" : "+r"(constant)); // why: keeps lui+addiu then lwc1 0(t7)
    s32 result = func_0017e4f8(context->target, &position, first, second, *constant);
    if (context->mode == 1) {
        func_001617d8();
    }
    return result;
}
