#include "../common/types.h"
extern "C" u8 D_00352af1;
extern "C" u8 D_00352af0;
extern "C" u8* D_00352ae0;
extern "C" u32 func_001dc9d0(u32);
extern "C" u64 func_001dc878(...);
extern "C" bool func_001dcc60(...);
extern "C" void func_001e6c00(u32 handle);
extern "C" u32 func_001b81e8();
extern "C" void func_001e6648();
extern "C" void func_001dd6a0(); // why: no accepted declaration; called with no arguments, result unused
extern "C" void func_001e6688(); // why: no accepted declaration; called with no arguments, result unused
extern "C" void func_001dca70(u8* object); // why: no accepted declaration; a0 is the object, result unused
extern "C" void func_001e3330(u32 handle); // why: no accepted declaration; a0 is the handle word, result unused
extern "C" void func_001e6af8(); // why: no accepted declaration; called with no arguments, result unused
extern "C" void func_001b8218(); // why: store-only callee (sb zero to D_003511c1), writes no v0
extern "C" s32 func_001e66e8(u32 handle); // why: no accepted declaration; its v0 is tested with bnez

void func_001dd920() {
    u8* object;
    u8* next;
    s32 pending;

    if (D_00352af1 == 0 && D_00352af0 != 0) {
        pending = 0;
        func_001dd6a0();
        func_001b81e8();
        func_001e6688();
        object = D_00352ae0;
        while (object != 0) {
            next = *(u8**)(object + 0x28);
            if (func_001dc9d0((u32)object) != 0) {
                // why: u8 flag gives the original redundant andi 0xff after the bit extract (same as accepted func_001dda78)
                u8 hidden = (*(s32*)(object + 8) >> 26) & 1;
                if (hidden == 0) {
                    if (*(s32*)(object + 4) == 4) {
                        u8* owner = *(u8**)(object + 0x14);
                        pending = 1;
                        (*(void (**)(u8*))(*(u8**)owner + 8))(owner);
                        func_001dc878(object);
                    } else if (*(u32*)(object + 0x1c) != 0) {
                        if (func_001dcc60(object)) {
                            if (pending) {
                                pending = 0;
                                func_001e6648();
                            }
                            func_001dca70(object);
                            func_001e3330(*(u32*)(object + 0x1c));
                            if (func_001e66e8(*(u32*)(object + 0x1c)) == 0) {
                                func_001e6c00(*(u32*)(object + 0x1c));
                                *(u32*)(object + 0x1c) = 0;
                                *(s32*)(object + 8) |= 0x10000;
                            }
                        }
                    }
                }
            }
            object = next;
        }
        func_001e6af8();
        func_001b8218();
        asm volatile("" ::: "memory"); // why: original calls with jal and returns through the shared epilogue instead of tail calling
    }
}
