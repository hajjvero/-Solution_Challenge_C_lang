#include <stdio.h>
#include <stdlib.h>
#include "util/display.h"
#include "util/action.h"
#include "model/aeroport.h"

// this function to clear console and display app name.
void clearApp() {
    // Clear console
    displayClear();

    // Shwo App name
    displayAppName("Gestion des avion et aeroport");
}

// this function to exit programe
void closeApp() {
    exit(1);
}
 
int main(void)
{
    // Init functions
    initActionCollection();

    initAeroportCollection();
     
    // Declare action.
    addAction("Quitter le programme", 0, closeApp);
    addAction("Console claire", 1, clearApp);
    addAction("Ajouter un aeroport", 2, addAeroport);
    addAction("Modifier un aeroport", 3, editAeroport);
    addAction("Supprimer un aeroport", 4, deleteAeroport);
    addAction("Afficher la liste des aeroports", 5, allAeroports);
    addAction("Details aeroport", 6, detailsAeroport);

    // app name
    clearApp();

    // run programe
    run();
    return 0;
}