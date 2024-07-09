#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2]=
{
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};
#define train_count sizeof(train)/sizeof(train[0])

float rand_float(void)
{
    return (float)rand()/(float)RAND_MAX;
}

float cost(float w,float b)
{
    float error=0;
    for(int i=0;i<train_count;i++)
    {
        float x=train[i][0];
        float y=x*w+b;
        error+=(y-train[i][1])*(y-train[i][1]);
    }
    error/=train_count;
    return error;
}

int main()
{
    // y=x*w;
    srand(time(0));
    srand(69);

    float w=rand_float()*10.0f;
    float b=rand_float()*5.0f;

    float h=1e-3;
    float rate=1e-2;

    for(int i=0;i<600;i++)
    {
        float dw=(cost(w+h,b)-cost(w,b))/h;
        float db=(cost(w,b+h)-cost(w,b))/h;
        w-=rate*dw;
        b-=rate*db;
    }
    printf("w:%f\tb:%f\terr:%f\n",w,b,cost(w,b));

    return 0;
}