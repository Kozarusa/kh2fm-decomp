#include "../common/types.h"
extern "C" u8* D_00351068;
extern "C" u8 D_00178e80[];
extern "C" u8* func_00176fb0(u8*, s32);
extern "C" s32 func_001a0920(u8*, u8*);
extern "C" void func_001cda88(u8*, u8*, u8*);
extern "C" u8* func_001cde58(u8*);
extern "C" void func_00177008(u8*, u8*, u8*);
extern "C" void func_0017f488(u8*, u32, f32, f32);
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*);
extern "C" s32 func_001bbd58(u8*);

s32 func_00178d28(u8* object) {
    u8 buffer[112];
    u8* sub = object + 0x140;
    u8* party = 0;
    if (*(s32*)(sub + 20) == 42) {
        party = func_00176fb0(object, 39);
        if (party != 0) {
            if (func_001a0920(party, object) == 0) {
                party = 0;
            }
        }
    }
    s32 kind = *(s32*)(*(u8**)(object + 12) + 4);
    if ((kind ^ 0x16) == 0 || (kind ^ 0x1a) == 0) {
        party = func_00176fb0(object, 41);
        if (party != 0) {
            if (func_001a0920(party, object) == 0) {
                party = 0;
            }
        }
    }
    if (party == 0) {
        func_001cda88(buffer, object, *(u8**)(object + 0xb40) + 4);
        party = func_001cde58(buffer);
    }
    func_00177008(object, party, *(u8**)(object + 0xb40) + 4);
    if ((*(u32*)(*(u8**)(object + 12) + 8) & 0x20) != 0) {
        u16 id = *(u16*)(party + 8);
        if (id > 210) {
            f32 zero = 0.0f;
            func_0017f488(D_00351068 + 0x140, id, zero, zero);
            func_0017f5e0(D_00351068 + 0x140, 0, zero, zero, 0);
            *(u8**)(sub + 404) = D_00178e80;
        }
    }
    return func_001bbd58(party);
}
