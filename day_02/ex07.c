#include <stdio.h>

int main(void)
{
    int first, last, gcd = 0;

    printf("Entrez udeux entiers : ");
    scanf("%d%*[/]%d", &first, &last);

    int min = first > last ? last : first;
   
    if (first == 0 || last == 0)
    {
        gcd = first > last ? first : last;
    } else {
        for (int i = 1; i <= min; i++)
        {
            if (first % i == 0 && last % i == 0)
            {
                gcd = i;
            } 
        }
    }

    int newF, newL;

    newF = first / gcd;
    newL = last / gcd;

    printf("Sous s forme la plus simple: %d/%d", newF, newL);
}