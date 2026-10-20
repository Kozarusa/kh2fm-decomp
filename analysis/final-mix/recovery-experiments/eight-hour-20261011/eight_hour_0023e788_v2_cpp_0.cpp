typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
struct __attribute__((aligned(16))) Quad { u32 words[4]; };
Quad* func_0023e788(Quad* out, u8* record, u32 index) {
  register const u8* lookup asm("$6") = record + index;
  asm("" : "+r"(lookup));
  register s32 stride asm("$14") = 320;
  asm("" : "+r"(stride));
  register s32 product asm("$15") = (s32)lookup[2916] * stride;
  register const Quad* input asm("$5") = (const Quad*)(record + product + 1632);
  asm("" : "+r"(input));
  *out = *input;
  return out;
}
