#include "../common/types.h"
extern "C" s32 func_00156d20(u8*);
extern "C" s32 func_00157068(u8*);
extern "C" s32 func_001570a0(u8*);
extern "C" s32 func_001570d0(u8*);
extern "C" s32 func_00157100(u8*);
extern "C" s32 func_00157130(u8*);
extern "C" s32 func_001571c0(u8*);
extern "C" s32 func_001574d8(u8*);
extern "C" s32 func_00157758(u8*);
extern "C" s32 func_001577c8(u8*);
extern "C" s32 func_001578d8(u8*);
extern "C" s32 func_00157a00(u8*);
extern "C" s32 func_00157ae0(u8*);
extern "C" s32 func_00157c88(u8*);
extern "C" s32 func_00158300(u8*);

s32 func_00157f08(u8* object) {
    s32 result;
    func_00158300(object);
    func_00157758(object);
    result = func_001577c8(object);
    if (*(s32*)(object + 52) == 0) {
        return result;
    }
    if ((*(u32*)(object + 12) & 0x100) != 0) {
        return result;
    }
    func_001578d8(object);
    func_00157a00(object);
    func_00157ae0(object);
    if (func_00157100(object) != 0) {
        result = func_001571c0(object);
    } else if (func_00157130(object) != 0) {
        func_001574d8(object);
        result = func_00156d20(object);
    } else if (func_001570a0(object) != 0) {
        result = func_00157068(object);
    } else if (func_001570d0(object) != 0) {
        result = func_00156d20(object);
    } else {
        result = func_00157c88(object);
    }
    *(s32*)(object + 15600) = *(u8*)(*(u8**)(*(u8**)(object + 52) + 1164) + 431);
    return result;
}
