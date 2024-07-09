#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// or gate
float train[][3]=
{
    {0,0,0},
    {0,1,1},
    {1,0,1},
    {1,1,1},
};
#define train_count sizeof(train)/sizeof(train[0])

float sigmoidf(float x)
{
    return 1.0f/(1.0f+expf(-x));
}

float rand_float(void)
{
    return (float)rand()/(float)RAND_MAX;
}

float cost(float w1,float w2,float b)
{
    float error=0;
    for(int i=0;i<train_count;i++)
    {
        float x1=train[i][0];
        float x2=train[i][1];
        float y=sigmoidf(x1*w1+x2*w2+b);
        error+=(y-train[i][2])*(y-train[i][2]);
    }
    error/=train_count;
    return error;
}

int main()
{
    srand(time(0));

    float w1=rand_float();
    float w2=rand_float();
    float b=rand_float();

    float h=1e-3;
    float rate=1e-2;

    for(int i=0;i<120000;i++)
    {
        float dw1=(cost(w1+h,w2,b)-cost(w1,w2,b))/h;
        float dw2=(cost(w1,w2+h,b)-cost(w1,w2,b))/h;
        float db=(cost(w1,w2,b+h)-cost(w1,w2,b))/h;
        w1-=rate*dw1;
        w2-=rate*dw2;
        b-=rate*db;
    }
    printf("w1:%f\tw2:%f\tb:%f\terr:%f\n",w1,w2,b,cost(w1,w2,b));

    printf("Truth table:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%zu | %zu = %f\n",i,j,sigmoidf(i*w1+j*w2+b));
        }
    }

    return 0;
}