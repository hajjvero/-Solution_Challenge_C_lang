#include <stdio.h>
#include "util/action.h"

void hamza()
{
    printf("Hamza");
}

int main(void)
{
    // Init Action
    initActionCollection();
     
    // Declare action.
    addAction("Quitter le programme", 0, hamza);
    addAction("Ajouter un avion", 1, hamza);
    addAction("Modifier un avion", 2, hamza);
    addAction("Supprimer un avion", 3, hamza);
    addAction("Afficher la liste des avions", 4, hamza);
    addAction("Rechercher un avion", 5, hamza);
    addAction("Trier les avions", 6, hamza);

    // run programe
    run();
    return 0;
}