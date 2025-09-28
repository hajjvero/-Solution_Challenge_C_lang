#ifndef AVION_H
#define AVION_H

// Enum of status
typedef enum {
    DISPONIVLE,
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
typedef struct {
    int id;
    char* modele;
    int capacite;
    Statut statut;
    Date dateEntree;
} Avion;

#endif