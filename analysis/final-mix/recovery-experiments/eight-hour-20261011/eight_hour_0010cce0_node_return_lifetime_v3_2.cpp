#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;s64object;};
extern "C" s64 func_001b9bc8(s64);extern "C" u32 func_00112d28(s64);
s64 func_0010cce0(s64 node){do{node=func_001b9bc8(node);if(!node)return 0;}while(!func_00112d28(node));return node;}
