// func_0029e170: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32 D_0035f3d4;
extern "C" s32 D_0035f14c;
extern "C" s32 D_0035f148;
extern "C" s32 D_0035f210;
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[92];
    Node* target;
};
// why: copied from the recovered call site fm_primary_queuekappaprime_recovered_0029e258.cpp
extern "C" u32 func_002766d0();
// why: types copied from the recovered definition fm_primary_orchgl_recovered_00139d78.cpp; extern "C" because
// the asm-label form fails the isolated link (probe linker script defines only the plain symbol, see v1)
extern "C" u32 func_00139d78(Node* wanted);
// why: types copied from the recovered definition fm_primary_orchlh_recovered_0028d8c0.cpp; extern "C" because
// the asm-label form fails the isolated link (probe linker script defines only the plain symbol, see v1)
extern "C" void func_0028d8c0(u8* object, s32 kind, s32 sequence, s32 image, s32 layout, s32 first, s32 value, s32 second);
// why: types copied from the recovered definition in fm_width_recovered_12.cpp (parameters renamed); extern "C"
// because the asm-label form fails the isolated link (probe linker script defines only the plain symbol, see v1)
extern "C" void func_0028dcc0(u32 cursor, u32 sprite);
// why: no recovered call site; a0 sprite, a1/a2 output pointers (written by the tail callee), result unused here
extern "C" void func_00138cb8(u32 sprite, s32* x, s32* y);
// why: copied from the recovered call site fm_primary_orchiw_recovered_001559e8.cpp
extern "C" s32 func_00138c68(u8* sprite, s32 x, s32 y);

void func_0029e170(s32 index) {
    u32 base = func_002766d0();
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    u32 stride = 408;
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    s32 offset = (index + 1) * stride;
    s32 kind = 4 + D_0035f3d4;
    u8 * object = (u8 *)(base + offset + 0x4398);
    if (0 == func_00139d78((Node *) object))
    {
        func_0028d8c0(object, kind, D_0035f14c, D_0035f148, D_0035f210, 7, 8, 0);
        func_0028dcc0(object, base);
    }
    s32 position [2];
    func_00138cb8(base, & position [0], & position [1]);
    if (index == 0)
    {
        func_00138c68(object, 340 -(position [0]), 208 -(position [1]));
    }
    else
    {
        func_00138c68(object, 256 - position [0], 208 - position [1]);
    }
}
