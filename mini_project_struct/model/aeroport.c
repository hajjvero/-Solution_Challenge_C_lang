#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroport.h"
#include "../util/display.h"

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
    Aeroport aeroport;

    // Temporary nom to read the input.
    char temp_nom[256];

    // Nom
    printf("\nEntrez le nom de l'aéroport : ");

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

        free(aeroport->nom);          // free old memory (if allocated with malloc/strdup)
        aeroport->nom = strdup(buffer); // allocate new string

        displaySuccess("Nom de l'aéroport mis à jour avec succès !");
    }
}

void deleteAeroport()
{
    printf("\n Entrez id de l'aéroport à supprimer : ");
    int id;
    scanf("%d", &id);

    Aeroport *aeroport = findAeroport(id);

    if (aeroport == NULL)
    {
        displayDanger("\nAucun aéroport trouvé.");
    }

    // free dynamic memory (nom and flotte)
    free(aeroportCollection.aeroports[id - 1].nom);
    free(aeroportCollection.aeroports[id - 1].flotte);

    // shift elements left to fill the gap
    for (int i = id - 1; i < aeroportCollection.count - 1; i++) {
        aeroportCollection.aeroports[i] = aeroportCollection.aeroports[i + 1];
    }

    aeroportCollection.count--;

    displaySuccess("Aéroport supprimé avec succès !");
}

void allAeroports()
{
    if (aeroportCollection.count == 0)
    {
        displayDanger("\nAucun aéroport disponible.");
        return;
    }

    printf("\n====== Liste des aéroports ======\n");

    for (int i = 0; i < aeroportCollection.count - 1 ; i++)
    {
        printf("\n--- Aéroport %d ---\n", i + 1);
        showAeroport(&aeroportCollection.aeroports[i]);
    }

    if (aeroportCollection.count - 1 == 0)
    {
        displayDanger("\nAucun aéroports disponible.");
    }
    

    printf("\n=================================\n");
}

Aeroport *findAeroport(int id)
{
    // Binary Search
    int start = 0, end = aeroportCollection.count - 1, mid;

    // // if the list has one element.
    // if (start == end)
    // {
    //     return &aeroportCollection.aeroports[id];
    // }
    
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

    printf("===== Aeroport =====\n");
    printf("ID: %d\n", aeroport->id);
    printf("Nom: %s\n", aeroport->nom);
    printf("Nombre d'avions: %d\n", aeroport->count - 1);
    printf("====================\n");
}