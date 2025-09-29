#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroport.h"
#include "../util/display.h"
#include <stdbool.h>

AeroportCollection aeroportCollection;

void initAeroportCollection()
{
    aeroportCollection.count = 1;
    aeroportCollection.aeroports = (Aeroport *)malloc(aeroportCollection.count * sizeof(Aeroport));

    // check allocate success
    if (aeroportCollection.aeroports == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }
}

void addAeroport()
{
    displaySubTitle("Ajouter un aéroport");

    // declare object from Aeroport
    Aeroport aeroport;

    // Temporary nom to read the input.
    char temp_nom[256];

    // Nom
    printf("\nEntrez le nom de l'aeroport : ");

    // The space before % handles any leading whitespace.
    // The %255[^\n] reads up to 255 characters.
    scanf(" %254[^\n]", temp_nom);

    // Use strdup to dynamically allocate and copy the nom string
    aeroport.nom = strdup(temp_nom);
    aeroport.id = aeroportCollection.count;
    aeroport.count = 1;
    aeroport.flotte = (Avion *)malloc(aeroport.count * sizeof(Avion));

    // add aeroport to collection.
    aeroportCollection.aeroports[aeroportCollection.count - 1] = aeroport;

    // increment size of aeroports list.
    Aeroport *newAeroports = (Aeroport *)realloc(aeroportCollection.aeroports, (++aeroportCollection.count) * sizeof(Aeroport));

    // check allocate success
    if (newAeroports == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }

    aeroportCollection.aeroports = newAeroports;

    displaySuccess("\n Ajouter l'aéroport avec succès");
}

void editAeroport()
{
    displaySubTitle("Modifier un aéroport");

    printf("\n Entrez id de aéroport : ");
    int id;
    scanf("%d", &id);

    Aeroport *aeroport = findAeroport(id);

    if (aeroport == NULL)
    {
        displayDanger("\nAucun aéroport trouvé.");
    }
    else
    {
        showAeroport(aeroport);

        char buffer[255];
        printf("\nEntrez le nouveau nom de l'aéroport : ");
        scanf(" %254[^\n]", buffer); // read up to 254 chars including spaces

        free(aeroport->nom);            // free old memory (if allocated with malloc/strdup)
        aeroport->nom = strdup(buffer); // allocate new string

        displaySuccess("Nom de l'aéroport mis à jour avec succès !");
    }
}

void deleteAeroport()
{
    displaySubTitle("Supprimer un aeroport");

    printf("\n Entrez id de l'aeroport à supprimer : ");
    int id;
    scanf("%d", &id);

    Aeroport *aeroport = findAeroport(id);

    if (aeroport == NULL)
    {
        displayDanger("\nAucun aeroport trouvé.");
    }

    // free dynamic memory (nom and flotte)
    free(aeroportCollection.aeroports[id - 1].nom);
    free(aeroportCollection.aeroports[id - 1].flotte);

    // shift elements left to fill the gap
    for (int i = id - 1; i < aeroportCollection.count - 1; i++)
    {
        aeroportCollection.aeroports[i] = aeroportCollection.aeroports[i + 1];
    }

    aeroportCollection.count--;

    displaySuccess("Aéroport supprimé avec succès !");
}

void allAeroports()
{
    displaySubTitle("Afficher la liste des aeroports");

    if (aeroportCollection.count == 0)
    {
        displayDanger("\nAucun aeroport disponible.");
        return;
    }

    for (int i = 0; i < aeroportCollection.count - 1; i++)
    {
        showAeroport(&aeroportCollection.aeroports[i]);
    }

    if (aeroportCollection.count - 1 == 0)
    {
        displayDanger("\nAucun aeroports disponible.");
    }
}

void detailsAeroport()
{
    displaySubTitle("détails aéroport");

    printf("\n Entrez id de l'aéroport pour afficher les détails : ");
    int id;
    scanf("%d", &id);

    Aeroport *aeroport = findAeroport(id);

    if (aeroport == NULL)
    {
        displayDanger("\nAucun aéroport trouvé.");
        return;
    }
    
    // Entre to manage avions of current aeroport.
    displayAvionsActions(aeroport);
}

Aeroport *findAeroport(int id)
{
    // Binary Search
    int start = 0, end = aeroportCollection.count - 1, mid;

    while (start != end)
    {
        mid = (start + end) / 2;

        if (id == aeroportCollection.aeroports[mid].id)
        {
            return &aeroportCollection.aeroports[mid];
        }
        else if (id > aeroportCollection.aeroports[mid].id)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return NULL;
}

void showAeroport(Aeroport *aeroport)
{
    if (aeroport == NULL)
        return;

    // Display information
    printf("ID\t\t: %d\n", aeroport->id);
    printf("Nom\t\t: %s\n", aeroport->nom);
    printf("Nombre d'avions : %d\n", aeroport->count - 1);

    // Add border buttom
    for (int i = 0; i < (appWidth / 2); i++)
    {
        printf("%c", appBorder);
    }

    printf("\n");
}

void displayAvionsActions(Aeroport *aeroport)
{
    // Display information of aeroport.
    showAeroport(aeroport);

    bool isExit = false;
    int choice;
    do
    {
        // Display actions.
        printf("\n\n");
        printf("[%d] : %s\n", 0, "Quitter details aeroport");
        printf("[%d] : %s\n", 1, "Ajouter un avion");
        printf("[%d] : %s\n", 2, "Modifier un avion");
        printf("[%d] : %s\n", 3, "Supprimer un avion");
        printf("[%d] : %s\n", 4, "Afficher la liste des avions");
        printf("[%d] : %s\n", 5, "Rechercher un avion");
        printf("[%d] : %s\n", 6, "Trie les avions");
        printf("\n\n");

        displayPrimary("Selectionnez votre action s'il vous plait : ");

        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            // Add new avion
            addAvion(aeroport);
            break;
        case 2:
            // Edit avion
            break;
        case 3:
            // Delete avion
            break;
        case 4:
            // display list of avions
            allAvions(aeroport);
            break;
        case 5:
            // Search of avions by id or modele
            break;
        case 6:
            // Sort avions by capacite or modele
            break;
        case 0:
            // Exit from details of aeroport.
            isExit = true;
            break;
        default:
            displayDanger("Selectionnez une action valide s'il vous plait.\n");
            break;
        }

    } while (!isExit);
}