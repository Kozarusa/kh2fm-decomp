#include "../common/types.h"
extern "C" u8 D_0035f3a8[];
// why: extern "C" keeps the plain func_ symbol; fixed arguments from a0/a1 set before the jal, u32 result as at accepted call site 002584c8
extern "C" u32 func_0023f948(u8*, u32);
// why: extern "C" keeps the plain func_ symbol; fixed arguments from a0/a1 set before the jal, u32 result as at accepted call site 002584c8
extern "C" u32 func_0023f908(u8*, u32);
// why: copied exactly from accepted call site 002584c8, whose probe found the C++ form of the accepted definition fails the isolated link
extern "C" void func_0023eea0(u8* object, s32 value, s32 message, s32 graphic, s32 number, s32 extra);
// why: extern "C" keeps the plain func_ symbol; declaration copied from accepted call site 002584c8 (accepted definition is void)
extern "C" void func_0023f0c8(s32 object, u32 value);

void func_0028d7f0(u8* object, s32 value, u32 graphicKey, u32 messageKey, s32 number, u32 mode, s32 graphic, s32 message, s32 extra) {
    if (graphic == 0) {
        graphic = func_0023f948(D_0035f3a8, graphicKey);
    }
    if (message == 0) {
        message = func_0023f908(D_0035f3a8, messageKey);
    }
    func_0023eea0(object, value, graphic, message, number, extra);
    func_0023f0c8((s32)object, mode);
}
