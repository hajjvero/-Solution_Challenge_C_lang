#include <stdio.h>
#include <stdbool.h>

bool linerSearch(int * nbrs, int val);

int main(void)
{
    bool digit_seen[10] = {false};
    int repete[10];
    int digit;
    long n = 0;

    printf("Entrez un nombre :");
    scanf("%ld", &n);

    if (n <= 0)
    {
        printf("Le programme se terminer. n = %d",n);
        exit(0);
    }

    int i = 0;
    while(n > 0) {
        // get last number.
        digit = n % 10;

        if (digit_seen[digit] && !linerSearch(repete, digit)) {
            repete[i] = digit;
            i++;
        }
            
        digit_seen[digit] = true;

        // remove last number
        n /= 10;
    }

    if (n == 0)
    {
        printf("Des chiffres sont repetes. \n");
        for (int j = 0; j < i; j++)
        {
            printf("%d\t", repete[j]);
        }
    } else {
       printf("Aucun chiffre repete. \n"); 
    }
    
    return 0;
}

bool linerSearch(int * nbrs, int val) {
    int size = sizeof(nbrs) / sizeof(nbrs[0]);
    for (int i = 0; i < size; i++)
    {
        if (nbrs[i] == val)
        {
            return true;
        }
               
    }
    
    return false;
}