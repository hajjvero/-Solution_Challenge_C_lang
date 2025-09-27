#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

int addAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    printf("Ajouter avion :\n\n");

    // all property of avoin
    char modele[100], dateEntree[10];
    int capacite, statut;

    printf("Entrez modele : ");
    // config scanf to read all text with space.
    scanf(" %[^\n]", modele);

    printf("\nEntrez capacite : ");
    scanf("%d", &capacite);

    printf("Sélectionnez statut : [0] : Disponible    [1] : En maintenance    [2] : En vol\n");
    scanf("%d", &statut);

    // handle date
    int month, day, year;
    printf("Entrez date de entree (mm/jj/aaaa): ");
    // separate day and month and year for validation.
    scanf("%d%*[/]%d%*[/]%d", &month, &day, &year);

    // add concatination of date vars in on table char.
    sprintf(dateEntree, "%d/%d/%d", month, day, year);

    strcpy(modeles[nextIndex], modele);
    capacites[nextIndex] = capacite;
    statuts[nextIndex] = statut;
    strcpy(dateEntrees[nextIndex], dateEntree);

    printf("\nAdd aviod saccessffuly.\n\n");
    showAvionModeCard(nextIndex, modele, capacite, statut, dateEntree);

    return ++nextIndex;
}

void allAvions(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    printf("Afficher Avions :\n\n");

    printf("| Id\t| Modele\t| Capacite\t| Statut\t| Date\t\t|\n");
    printf("|_________________________________________________________________________|\n");

    // check if the is found data
    if (!(nextIndex > 0))
    {
        printf("\t\t\tNo result found!\n");
    }
    else
    {
        for (int i = 0; i < nextIndex; i++)
        {
            showAvionModeRow(i, modeles[i], capacites[i], statuts[i], dateEntrees[i]);
        }
    }
    printf("|_______________________________________________________________________|\n");
}

void showAvionModeRow(int id, char modele[100], int capacite, int statut, char dateEntree[10])
{
    // display row of data of avion.
    printf("| %d\t| %s\t| %d\t\t| %s\t| %s\t|\n",
           id + 1,
           modele,
           capacite,
           statut == 0 ? "Disponible" : statut == 1 ? "En maintenance"
                                                    : "En vol",
           dateEntree);
}

void showAvionModeCard(int id, char modele[100], int capacite, int statut, char dateEntree[10])
{
    // display row of data of avion.
    printf("ID\t: %d\n", id + 1);
    printf("Modele\t: %s\n", modele);
    printf("Capacite\t: %d\n", capacite);
    printf("Statut\t: %s\n", statut == 0 ? "Disponible" : statut == 1 ? "En maintenance"
                                                                      : "En vol");
    printf("Date Entree\t: %s\n", dateEntree);
}

void editAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    int id;
    printf("Entre id of avion to update please : ");
    scanf("%d", &id);

    // convert from id to index.
    --id;

    // chack if the index is exist
    if (id >= nextIndex)
    {
        printf("Ops not foun avoid with id : %d \n", id);
    }
    else
    {
        bool isExit = false;

        int property;
        do
        {
            showAvionModeCard(id, modeles[id], capacites[id], statuts[id], dateEntrees[id]);

            printf("\n[0 or other] : Exit    [1] : Modele    [2] : Capacites    [3] : Statut    [4] : Date Entrees\n");
            printf("========================");
            printf("\nSelect property to update : ");
            scanf("%d", &property);

            switch (property)
            {
            case 1:
                // update Modele
                printf("Entre new modele : ");
                // config scanf to read all text with space.
                scanf(" %[^\n]", modeles[id]);
                break;
            case 2:
                // update Capacites
                printf("Entre new capacites : ");
                scanf("%d", &capacites[id]);
                break;
            case 3:
                // update Statut
                printf("Entre new statut : [0] : Disponible    [1] : En maintenance    [2] : En vol\n");
                scanf("%d", &statuts[id]);
                break;
            case 4:
                // update Date Entrees
                int month, day, year;
                printf("Entre new date entrees (mm/jj/aaaa): ");
                // separate day and month and year for validation.
                scanf("%d%*[/]%d%*[/]%d", &month, &day, &year);

                // add concatination of date vars in on table char.
                sprintf(dateEntrees[id], "%d/%d/%d", month, day, year);
                break;
            default:
                isExit = true;
                break;
            }
        } while (!isExit);
    }
}

int deletAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    int id;
    printf("Entre id of avion to delete please : ");
    scanf("%d", &id);

    // convert from id to index.
    --id;

    // chack if the index is exist
    if (id >= nextIndex)
    {
        printf("Ops not foun avoid with id : %d \n", id);
    }
    else
    {

        showAvionModeCard(id, modeles[id], capacites[id], statuts[id], dateEntrees[id]);

        // replace position of avoin deleted by newt avions
        // add condition (i <= nextIndex - 1) => if ther user entre id of the last element  => entre to loop and delete last element, not just decremet nextIndex.
        for (int i = id; i <= nextIndex - 1; i++)
        {
            strcpy(modeles[i], modeles[i + 1]);
            capacites[i] = capacites[i + 1];
            statuts[i] = statuts[i + 1];
            strcpy(dateEntrees[i], dateEntrees[i + 1]);
        }

        printf("\nDelete avoin : %d successfully", id + 1);

        return --nextIndex;
    }

    nextIndex;
}

void searchAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    bool isExit = false;

    int property;
    do
    {
        printf("\n[0 or other] : Exit    [1] : Modele    [2] : Id\n");
        printf("========================");
        printf("\nSelect property to search : ");
        scanf("%d", &property);

        // the var to chack if foun data from search.
        bool isFound = false;
        switch (property)
        {
        case 1:
        {
            // Search by model ( liner search ).
            char modele[100];
            printf("Entre model to search : ");
            scanf(" %[^\n]", modele);

            for (int i = 0; i < nextIndex; i++)
            {
                if (strcmp(modele, modeles[i]) == 0)
                {
                    isFound = true;
                    showAvionModeCard(i, modeles[i], capacites[i], statuts[i], dateEntrees[i]);
                    break;
                }
            }

            if (!isFound)
            {
                printf("\nOps not found result by model : %s\n", modele);

                // reset is found to int value.
                isFound = false;
            }
            break;
        }
        case 2:
        {
            // Search by id ( binary search ).
            int id;
            printf("Entre id to search : ");
            scanf("%d", &id);

            // convert id to index.
            --id;

            // set strat and end keys.
            int start = 0, end = nextIndex - 1, mid;
            while (start != end)
            {
                // got to cente array
                mid = (start + end) / 2;

                // check if ther mid is equls id.
                if (mid == id)
                {
                    isFound = true;
                    showAvionModeCard(mid, modeles[mid], capacites[mid], statuts[mid], dateEntrees[mid]);
                    break;
                }
                // remove left part from array
                else if (id > mid)
                {
                    start = ++mid;
                }
                // remove rightpart of array
                else
                {
                    end = --mid;
                }
            }

            if (!isFound)
            {
                printf("\nOps not found result by id : %d\n", id);

                // reset is found to int value.
                isFound = false;
            }
            break;
        }
        default:
            isExit = true;
            break;
        }
    } while (!isExit);
}

void sort(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex)
{
    printf("\n[0] : Capacite    [1 ou other] : Modele\n");
    printf("========================");
    printf("\nSelect property to sort : ");

    int property;
    scanf("%d", &property);
    switch (property)
    {
    case 0:
        // Sort by capacite (Selection sort)
        for (int i = 0; i < nextIndex; i++)
        {
            int min = i;

            // loop to foun index of min value.
            for (int j = i + 1; j < nextIndex; j++)
            {
                if (capacites[min] > capacites[j])
                {
                    min = j;
                }
            }

            // check if current index not equls min index , and replace values.
            if (min != i)
            {
                // store temp values
                char tempModele[100];
                char tempDate[10];
                int tempCapacite = capacites[i];
                int tempStatu = statuts[i];

                strcpy(tempModele, modeles[i]);
                strcpy(tempDate, dateEntrees[i]);

                // replace values from min to i.
                strcpy(modeles[i], modeles[min]);
                strcpy(dateEntrees[i], dateEntrees[min]);
                capacites[i] = capacites[min];
                statuts[i] = statuts[min];

                // replace values from i to min
                strcpy(modeles[min], tempModele);
                strcpy(dateEntrees[min], tempDate);
                capacites[min] = tempCapacite;
                statuts[min] = tempStatu;
            }
        }

        printf("\nSort by capacite is successfully\n");
        break;
    default:
    {
        // Sort by Modele (Bubble sort)
        for (int i = 0; i < nextIndex; i++)
        {
            for (int j = 0; j < nextIndex - 1 - i; j++)
            {
                // check without tretment upper or lower case.
                if (strcasecmp(modeles[j], modeles[j + 1]) > 0)
                {
                    // store temp values
                    char tempModele[100];
                    char tempDate[10];
                    int tempCapacite = capacites[j];
                    int tempStatu = statuts[j];

                    strcpy(tempModele, modeles[j]);
                    strcpy(tempDate, dateEntrees[j]);

                    // replace values from j+ 1 to j.
                    strcpy(modeles[j], modeles[j + 1]);
                    strcpy(dateEntrees[j], dateEntrees[j + 1]);
                    capacites[j] = capacites[j + 1];
                    statuts[j] = statuts[j + 1];

                    // replace values from j to j +1
                    strcpy(modeles[j +1], tempModele);
                    strcpy(dateEntrees[j +1], tempDate);
                    capacites[j +1] = tempCapacite;
                    statuts[j +1] = tempStatu;
                }
            }
        }

         printf("\nSort by modele is successfully\n");
        break;
    }
    }
}