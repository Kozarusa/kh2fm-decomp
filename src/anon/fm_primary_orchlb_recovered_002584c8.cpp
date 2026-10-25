#include "../common/types.h"
extern "C" u8 D_00347f98[];
extern "C" u8 D_0035eb98[];
extern "C" u8* D_0035f078;
extern "C" u32 D_0035f074;
extern "C" u32 D_0035f080;
extern "C" u32 D_0035f084;
extern "C" u8* func_0023ee30(s32);
extern "C" void func_0031a838(u32);
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
extern "C" u32 func_0023f908(...);
extern "C" u32 func_0023f948(...);
// why: the isolated probe linker script defines only the plain symbol; the C++ form of the accepted definition (fm_primary_orchky_recovered_0023eea0.cpp) failed to link in v1
extern "C" void func_0023eea0(u8* object, s32 value, s32 message, s32 graphic, s32 number, s32 extra);
// why: the isolated probe linker script defines only the plain symbol; the C++ form of the accepted definition (fm_primary_close_recovered.cpp) failed to link in v1
extern "C" void func_0023f0c8(s32 object, u32 value);
// why: the isolated probe linker script defines only the plain symbol; the C++ form of the accepted definition (fm_primary_orchdx_recovered_0023ef50.cpp) failed to link in v1
extern "C" void func_0023ef50(u8* object);
// why: the isolated probe linker script defines only the plain symbol; the C++ form of the accepted definition (fm_global_recovered_10.cpp) failed to link in v1
extern "C" void func_0026dd18(u32 first, u32 second, s32 third);

void func_002584c8() {
    u8* object = func_0023ee30(160);
    *(u8**)(object + 0) = D_00347f98;
    func_0031a838((u32)(object + 12));
    *(u8**)(object + 0) = D_0035eb98;
    func_002369a0(object + 24);
    func_0023c008(object + 48);
    D_0035f078 = object;
    s32 graphic = func_0023f948(D_0035f074, 0);
    s32 message = func_0023f908(D_0035f074, 0);
    func_0023eea0(D_0035f078, 30000, graphic, message, 0, 0);
    func_0023f0c8((s32)D_0035f078, (u32)-1);
    func_0023ef50(D_0035f078);
    func_0026dd18(D_0035f080, D_0035f084, -1);
}
