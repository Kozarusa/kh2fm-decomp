#include "../common/types.h"
u32 func_00102a08(u8* object){u32 count=0;u8*prev=0;while(true){u8*node=prev?*(u8**)(prev+56):*(u8**)(object+8);prev=node;if(!node)return count;++count;}}
