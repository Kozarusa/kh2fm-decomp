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

extern u32 D_0032ba84;
extern "C" void func_00104200(u32);

void func_00104210(s32 value) {
    D_0032ba84 = (0 < value) ? 1u : (u32)value;
    if (D_0032ba84 == 2u) { func_00104200(2u); return; }
    if (D_0032ba84 < 3u) { if (D_0032ba84 != 1u) func_00104200(2u); return; }
    if (D_0032ba84 != 3u) return;
    func_00104200(3u);
}
