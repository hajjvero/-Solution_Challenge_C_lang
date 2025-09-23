#include <stdio.h>

int main(void)
{
    for (int i = 10; i > 4; i--) {
        for (int j = 0; j < i; j++)
        {  
            if((i == 7 && j == 2) || (i == 6 && j == 3)){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("*\n");
    }
}