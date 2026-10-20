#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u64object;};
extern "C" u64 func_001b9bc8(u64);extern "C" u32 func_00112d28(u64);
u64 func_0010cce0(u64 node){do{node=func_001b9bc8(node);if(!node)return 0;}while(!func_00112d28(node));return node;}
