#ifndef MODELS_H
#define MODELS_H

// had ficher darto bach maykonch 3andi error dyal include inside include ? hhhhhhhhhh


// Enum of status
typedef enum
{
    DISPONIBLE = 1,
    MAINTENANCE,
    VOL
} Statut;

// Model of date
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

// Modale of avion
typedef struct
{
    int id;
    char *modele;
    int capacite;
    Statut statut;
    Date dateEntree;
} Avion;

// Model Aeroport
typedef struct
{
    int id;        // ID autoincrement
    char *nom;     // Nom string
    Avion *flotte; // List of avions
    int count;     // count of avions
} Aeroport;

#endif