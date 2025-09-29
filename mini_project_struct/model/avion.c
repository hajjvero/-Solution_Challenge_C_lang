#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "avion.h"
#include "../util/display.h"

// Thsi function to validate date
bool dateValide(Date date)
{
    // Year
    if (date.annee < 1900 || date.annee > 2025)
        return false;

    // Month
    if (date.mois < 1 || date.mois > 12)
        return false;

    // day
    if (date.jour < 1 || date.jour > 31)
        return false;

    return true;
}

void addAvion(Aeroport *aeroport)
{
    displaySubTitle("Ajouter un avion");

    // declare object from Avion
    Avion avion;

    // Temporary modele to read the input.
    char temp_modele[256];
    int tempCapacite;
    int choixStatut; // read as int
    Statut tempStatu;
    Date tempDate;

    // Model
    printf("Entrez modele : ");
    // The space before % handles any leading whitespace.
    // The %255[^\n] reads up to 255 characters.
    scanf(" %254[^\n]", temp_modele);

    // Capacite
    printf("\nEntrez capacite : ");
    scanf("%d", &tempCapacite);

    // Statut
    printf("\n\n");
    printf("[%d] : %s\n", DISPONIBLE, "Disponible");
    printf("[%d] : %s\n", MAINTENANCE, "En maintenance");
    printf("[%d] : %s\n", VOL, "En vol");
    printf("\n");

    // input and validation of status
    do
    {
        printf("Selectionnez statut : ");
        scanf("%d", &choixStatut);

        if (choixStatut != DISPONIBLE && choixStatut != MAINTENANCE && choixStatut != VOL)
        {
            displayDanger("Statut invalide, veuillez reessayer\n");
        }
    } while (choixStatut != DISPONIBLE && choixStatut != MAINTENANCE && choixStatut != VOL);

    tempStatu = (Statut)choixStatut;

    // Date
    // input and validation date
    do
    {
        printf("\nEntrez date de mise en service (jj/mm/aaaa): ");
        scanf("%d%*[/]%d*[/]%d", &tempDate.jour, &tempDate.mois, &tempDate.annee);

        if (!dateValide(tempDate))
        {
            displayDanger("Date invalide, veuillez reessayer\n");
        }
    } while (!dateValide(tempDate));

    // Fill the avion struct
    avion.modele = strdup(temp_modele);
    avion.capacite = tempCapacite;
    avion.statut = tempStatu;
    avion.dateEntree = tempDate;

    // Add avion to aeroport
    aeroport->flotte[aeroport->count - 1] = avion;

    // increment size of flotte list.
    Avion *newFlotte = (Avion *)realloc(aeroport->flotte, (++aeroport->count) * sizeof(Avion));

    // check allocate success
    if (newFlotte == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }

    aeroport->flotte = newFlotte;

    printf("\nAvion ajouté avec succès !\n");
}

// This function return statu as string
const char* statutToString(Statut s)
{
    switch (s)
    {
        case DISPONIBLE: return "Disponible";
        case MAINTENANCE: return "En maintenance";
        case VOL: return "En vol";
        default: return "Inconnu";
    }
}

void allAvions(Aeroport *aeroport)
{
    displaySubTitle("Liste des avions");

    if ((aeroport->count - 1) == 0)
    {
        printf("Aucun avion enregistré.\n");

        return;
    }

    for (int i = 0; i < aeroport->count; i++)
    {
        Avion a = aeroport->flotte[i];

        printf("Modèle     : %s\n", a.modele);
        printf("Capacité   : %d\n", a.capacite);
        printf("Statut     : %s\n", statutToString(a.statut));
        printf("Date       : %02d/%02d/%04d\n",
               a.dateEntree.jour,
               a.dateEntree.mois,
               a.dateEntree.annee);
    }
}