#include <stdio.h>
#include "function.h"

void addAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int* nextIndex) {
    printf("Ajouter avion :\n\n");

    // all property of avoin
    char modele[100], dateEntree[10];
    int capacite, statut;

    printf("Entrez modele : ");
    scanf("%s", modele);

    printf("Entrez capacite : ");
    scanf("%d", &capacite);

    printf("Sélectionnez statut : [0] : Disponible    [1] : En maintenance    [2] : En vol\n");
    scanf("%d", &statut);

    // handle date 
    int month, day, year;
    printf("Entrez date de entree (mm/jj/aaaa): ");
    // separate day and month and year for validation.
    scanf("%d%*[/]%d%*[/]%d", &month,&day,&year);

    // add concatination of date vars in on table char.
    sprintf(dateEntree, "%d/%d/%d", month,day,year);

    modeles[*nextIndex], modele;
    capacites[*nextIndex], capacite;
    statuts[*nextIndex], statut;
    dateEntrees[*nextIndex], dateEntree;
    
    printf("\nAdd aviod saccessffuly.\n\n");
    showAvion(*nextIndex, modele,capacite,statut,dateEntree);

    *nextIndex++;
}


void allAvions(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex) {
    printf("Afficher Avions :\n\n");

    printf("| Id\t| Modele\t| Capacite\t| Statut\t| Date\t|\n");

    showAvion(0,modeles[0],capacites[0],statuts[0],dateEntrees[0]);
    // for (int i = 0; i < nextIndex; i++)
    // {
    //     showAvion(i,modeles[i],capacites[i],statuts[i],dateEntrees[i]);
    // } 
}

void showAvion(int id, char modele[100], int capacite, int statut, char dateEntree[10]) {
    // display row of data of avion.
    printf("| %d\t| %s\t| %d\t| %s\t| %s\t|\n", 
        id+1,
        modele,
        capacite,
        statut == 0 ? "Disponible" : statut == 1 ? "En maintenance" : "En vol",
        dateEntree
    );
}
