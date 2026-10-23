#include "../common/types.h"
extern "C" u32 func_001069e8(...);
extern "C" u32 func_0013f608(...);
extern "C" void func_00140760(u8* object);
extern "C" void func_001407d0(u8* object);
extern "C" void func_00140850(u8* object);
extern "C" void func_001403b0(u8* object);
extern "C" void func_00140f30(u8* object);
extern "C" void func_001408a0(u8* object, u8 flag);
extern "C" void func_0015a5a8(u8* object);
extern "C" void func_00159070(u8* object);
extern "C" void func_00159b00(u8* object);
extern "C" void func_00159368(u8* object);
extern "C" void func_00158dc0(u8* object);
extern "C" void func_00158708(u8* object);
extern "C" void func_00158658(u8* object);
extern "C" void func_0014e8b8(u8* object);
extern "C" void func_001589d0(u8* object);

extern const void* D_0036ae50[12];

// Preserve original registry aliases.
void func_00140b68(u8* object, u8 flag) asm("_Z16wtarget_00140b68jjjj");

void func_00140b68(u8* object, u8 flag) {
    static const void* targets[12] asm("fm_switch_table_00140b68") = {&&case0,&&case1,&&case2,&&case3,&&case4,&&case5,&&case6,&&case7,&&case8,&&case9,&&case10,&&done};
    u32 index;
    if (*(s32*)(object + 68) == 0) {
        return;
    }
    if (flag == 0 && func_001069e8() != 0) {
        return;
    }
    func_00140850(object);
    index = *(u32*)(object + 64);
    if (index >= 12) goto done;
    goto *D_0036ae50[index];
case0:
    func_001403b0(object);
    goto done;
case1:
    func_00140760(object);
    goto done;
case2:
    func_0015a5a8(object);
    goto done;
case3:
    func_00159070(object);
    goto done;
case4:
    func_00159b00(object);
    goto done;
case5:
    func_00159368(object);
    goto done;
case6:
    func_00158dc0(object);
    goto done;
case7:
    func_00158708(object);
    goto done;
case8:
    func_00158658(object);
    goto done;
case9:
    func_0014e8b8(object);
    goto done;
case10:
    func_001589d0(object);
    goto done;
done:
    func_0013f608(object);
    func_00140f30(object);
    func_001407d0(object);
    func_001408a0(object, flag);
}
