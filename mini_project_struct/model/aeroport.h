#ifndef AEROPORT_H
#define AEROPORT_H

#include "avion.h"



typedef struct
{
    Aeroport *aeroports; // list of aeroports
    int count;           // count of aeroports (next id)
} AeroportCollection;

// this function to init list and size of collect aeroports
void initAeroportCollection();

// this function to add new Aeroport
void addAeroport();

// thie function to update Aeroport
void editAeroport();

// this function to delete Aeroport
void deleteAeroport();

// this function to display list of all Aeroport
void allAeroports();

// Thjis fiunction for entre to managment avions of aeroport
void detailsAeroport();

// this function to get Aeroport by id (Using biniry search).
Aeroport *findAeroport(int id);

// This function to display information of aeroport
void showAeroport(Aeroport *aeroport);

// display action avion choices
void displayAvionsActions(Aeroport *aeroport);
#endif