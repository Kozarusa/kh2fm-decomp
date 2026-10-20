typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;
struct FmInitPair { u32 first, second; };
struct FmInitFloat { u32 first, second; f32 value; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48, D_01c62140;
extern FmInitPair D_01d48da0, D_01d48da8, D_01d48db0;
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01d48db8, D_00351eb8, D_00351ec0, D_00351ec8;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
extern u8 D_0032b930, D_01d498d0, D_01c620c8[];
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);

void func_001ba060(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
}
