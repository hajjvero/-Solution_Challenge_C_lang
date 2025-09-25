#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int chiffres[10] = {0,0,0,0,0,0,0,0,0,0};
    int digit;
    long n;

    printf("Entrez un nombre :");
    scanf("%ld", &n);

    while(n > 0) {
        // get last number.
        digit = n % 10;

        if (digit_seen[digit]) {
            chiffres[digit] += 1;
        } else {
            digit_seen[digit] = true;
            chiffres[digit] = 1;
        }
            
        // remove last number
        n /= 10;
    }

    if (n == 0)
    {
        printf("Chiffre :\t\t");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", i);
        }

        printf("\n");
        printf("Occurences :\t\t");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", chiffres[i]);
        }
    } else {
       printf("Aucun chiffre repete. \n"); 
    }
    
    return 0;
}