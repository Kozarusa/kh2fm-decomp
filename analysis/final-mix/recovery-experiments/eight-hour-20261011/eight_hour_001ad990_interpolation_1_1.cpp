void func_001ad990(float start,float end,float duration,volatile float* output)
{
 register float zero asm("$f0")=0.0f;
 asm("" : "+f"(zero));
 if(zero<duration){
 float difference=end-start;
 output[0]=start;
 output[1]=difference/duration;
 }else{
 output[1]=zero;
 output[0]=end;
 }
}
