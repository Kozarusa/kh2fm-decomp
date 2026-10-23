#include "../common/types.h"
extern "C" u64 D_0036ada8;
extern "C" void func_0013eb00(u8*);

void func_0013e940(u8* object) {
    *(u64*)(object + 48) = 0;
    *(u64*)(object + 96) = 0;
    *(u64*)(object + 200) = (u64)object[16] | ((u64)object[17] << 8) | ((u64)object[18] << 16)
        | ((u64)object[19] << 24) | ((u64)1 << 32);
    *(u64*)(object + 32) = 0x8000000000000001ULL;
    *(u64*)(object + 40) = 0xeeeeeeeeULL;
    *(u64*)(object + 56) = 0x3f;
    *(u64*)(object + 64) = 0x800d8;
    *(u64*)(object + 72) = 0x4c;
    *(u64*)(object + 80) = 0x31000070;
    *(u64*)(object + 88) = 0x4e;
    *(u64*)(object + 104) = 6;
    *(u64*)(object + 112) = 0x60;
    *(u64*)(object + 120) = 0x14;
    *(u64*)(object + 128) = 0x30000;
    *(u64*)(object + 136) = 0x47;
    *(u64*)(object + 144) = 0x44;
    *(u64*)(object + 152) = 0x42;
    *(u64*)(object + 160) = 5;
    *(u64*)(object + 168) = 8;
    *(u64*)(object + 176) = 0xa400000000008001ULL;
    u64 value = D_0036ada8;
    *(u64*)(object + 192) = 0x144;
    *(u64*)(object + 184) = value;
    func_0013eb00(object);
}
