#include <stdio.h>

int main(void)
{
    int n;

    printf("Entrez un nombre : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int p = i * i;
        if (p <= n)
        {
            if (p % 2 == 0)
            {
                printf("%d\n",p);
            }      
        }
    }
}