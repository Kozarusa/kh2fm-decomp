#include "../common/types.h"
extern "C" s32 D_0035eb88;
extern "C" s32 func_001391c8(u8*, s32, s32);
extern "C" void func_00236a58(...);
extern "C" s32 func_0023c100(...);
// why: extern "C" because the isolated probe linker script defines only the plain func_0023f070 symbol (v1 with the asm-label C++ form of the accepted definition gave an unresolved reference to Tz::Layout::setNum); this is the call-site form used by fm_primary_orchiq_recovered_0024a048.cpp
extern "C" void func_0023f070(...);
// why: no recovered source declares or calls func_0023f168; its original writes v0 on no path of its own (entry v0 or a call chain ending in the void func_0023c598), so it is declared void with the single a0 pointer it reads
extern "C" void func_0023f168(u8*);

void func_0023eea0(u8* object, s32 value, s32 message, s32 graphic, s32 number, s32 extra) {
    func_001391c8(object, value, extra);
    func_00236a58(object + 24, graphic, D_0035eb88);
    func_0023c100(object + 48, message, object + 24, D_0035eb88);
    *(s32*)(object + 152) = -10;
    *(s32*)(object + 156) = -10;
    func_0023f070(object, number, 0xffffffffffffffff);
    *(u8*)(object + 148) = 0;
    func_0023f168(object);
}
