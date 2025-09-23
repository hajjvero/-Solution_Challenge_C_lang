#include <stdio.h>

int main(void)
{
    float r;

    printf("Entre le rayon de la sphère: \n");
    
    scanf("%f", &r);

    float pi = 3.14;
    float v1 = (4 / 3) * pi * r * r * r;
    float v2 = (4.0f / 3.0f) * pi * r * r * r;

    printf("Volume 1 :%f\n",v1);

    printf("Volume 2 :%f\n",v2);
}