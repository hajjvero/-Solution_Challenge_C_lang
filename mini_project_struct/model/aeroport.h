#ifndef AEROPORT_H
#define AEROPORT_H

#include "avion.h"

    // Model Aeroport
    typedef struct 
    {
        int id;         // ID autoincrement
        char* nom;      // Nom string
        Avion* flotte;  // List of avions
        int count;   // count of avions
    } Aeroport;

    typedef struct
    {
        Aeroport* aeroports;    // list of aeroports
        int count;              // count of aeroports (next id)
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

    // this function to get Aeroport by id (Using biniry search).
    Aeroport* findAeroport(int id);

    // This function to display information of aeroport
    void showAeroport(Aeroport* aeroport);
#endif