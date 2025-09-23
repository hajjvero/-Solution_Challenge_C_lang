#include <stdio.h>

int main(void)
{
    float pret, tax, taxMontant, payment, restPremier, restDeuxieme, restTroisieme;
    printf("Entrer le montant du prét: ");
    
    scanf("%f", &pret);


    printf("Entrer le taux d'intérêt: ");
    
    scanf("%f", &tax);


    printf("Entrer le payment mensuel: ");
    
    scanf("%f", &payment);

    taxMontant = ((pret * 6) / 100) / 12;

    restPremier = pret - payment + taxMontant;

    taxMontant = ((restPremier * 6) / 100) / 12;

    restDeuxieme = restPremier - payment + taxMontant;

    taxMontant = ((restDeuxieme * 6) / 100) / 12;

    restTroisieme = restDeuxieme - payment + taxMontant;

    printf("Solde restant apreès le Premier paiment: %.2f\n", restPremier);

    printf("Solde restant apreès le Deuxieme paiment: %.2f\n", restDeuxieme);

    printf("Solde restant apreès le Troisieme paiment: %.2f\n", restTroisieme);
}