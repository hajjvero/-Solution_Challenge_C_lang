#include <stdio.h>

int main(void)
{
    float montant;
    printf("Entrer un montant en dollars: \n");
    
    scanf("%f", &montant);

    printf("%.2f", montant + ((montant * 5) / 100));
}