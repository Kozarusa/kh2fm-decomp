#include "../common/types.h"
extern "C" u8 D_00351618[];
extern "C" u8 D_01d49590[];
extern "C" f32 D_0036de34;
extern "C" f32 D_0036de38;
// why: exact types of the accepted definition (fm_primary_queuegammaprime_recovered_001db8f8.cpp); extern "C" because the C++ alias fails the isolated probe link
extern "C" void func_001db8f8(u32* object,u64 second,u64 third,u64 fourth);

void func_001c4498(u32* object, u64 second) {
    func_001db8f8(object, second, 0, 1500);
    object[0] = (u32)D_00351618;
    u8* base = D_01d49590;
    asm volatile("" : "+r"(base)); // why: original materializes the full table address and adds 12 separately; volatile keeps it after the vtable address
    f32* out = (f32*)(base + 12);
    s32 index = 0;
    asm volatile("" : "+r"(out), "+r"(index)); // why: volatile keeps the vtable store, table offset and index setup ahead of the scale addresses
    f32* scale = &D_0036de34;
    asm volatile("" : "+r"(scale)); // why: original forms the full address of the scale and loads with offset 0
    f32 scale_a = *scale;
    scale = &D_0036de38;
    asm volatile("" : "+r"(scale)); // why: original forms the full address of the scale and loads with offset 0
    f32 scale_b = *scale;
    do {
        *out = (f32)index * scale_a * scale_b;
        index++;
        out += 4;
    } while (index < 8);
}
