#include <stdio.h>

int main(void)
{
    float x;
    printf("Entrer une valeur pour x: \n");
    
    scanf("%f", &x);

    float r = (3 * (x*x*x*x*x)) + (2 * (x*x*x*x)) - (5 * (x * x *x)) - (x*x) + (7  * x) - 6;
    printf("%.2f", r);
}