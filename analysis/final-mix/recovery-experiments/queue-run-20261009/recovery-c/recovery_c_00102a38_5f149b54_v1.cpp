#include "../common/types.h"
u32 func_00102a38(u8* object,u32 key){u8*prev=0;u8*node;again:node=prev?*(u8**)(prev+56):*(u8**)(object+8);prev=node;if(node)goto present;return 0;present:if(*(u32*)node==key)return 1;goto again;}
