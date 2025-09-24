#include <stdio.h>

int main(void)
{
    int n;

    printf("Entrez un nombre à deux chiffres : ");
    scanf("%d", &n);


    printf("Le nomber inversé est : %d%d", n%10,n/10);

}