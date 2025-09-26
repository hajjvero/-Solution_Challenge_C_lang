#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"

int main() {
    // if this var is true end programe
    bool isExit = false;

    // choice of user
    int operation;

    // information of avion
    char modeles[128][100];
    int capacites[128];
    int statuts[128];
    char dateEntrees[128][10];
    
    int nextIndex = 0;
    do
    {
        printf("=================================================================");
        printf("\n=========");
        printf("\t Gestion des avion et aéroport\t\t");
        printf("=========\n");
        printf("=================================================================\n");

        printf("\n\nLes opération de avion :\n");
        printf("========================\n");
        printf("[0] : Exit    [1] : Afficher Avions    [2] : Ajouter Avion    [3] : Modifier Avion    [4] : Supprimer Avion    [5] : Rechercher Avion");

        printf("\n\nSélectionnez votre opération : ");
        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                // Afficher la liste
                allAvions(modeles,capacites,statuts, dateEntrees, nextIndex);
                break;
            case 2:
                // Ajouter
                addAvion(modeles,capacites,statuts, dateEntrees, &nextIndex);
                break;
            case 3:
                // Modifier
                break;
            case 4:
                // Supprimer
                break;
            case 5:
                // Rechercher
                break;        
            default:
                isExit = true;
                break;
        }
    } while (!isExit);
    
}