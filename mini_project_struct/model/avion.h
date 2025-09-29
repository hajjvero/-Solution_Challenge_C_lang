#ifndef AVION_H
#define AVION_H
#include "models.h"

// this function for add avion dans aeroport.
void addAvion(Aeroport *aeroport);

// this function for edit avion.
void editAvion(Aeroport *aeroport);

// this function for delete avion.
void deleteAvion(Aeroport *aeroport);

// this function for display list of all avions
void allAvions(Aeroport *aeroport);

// this function to get avion by id (Using insertion search).
Avion *findAvion(Aeroport *aeroport, int id);

// This function to display information of avion
void showAvion(Avion *avion);
#endif