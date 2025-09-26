#ifndef FUNCTION_H
#define FUNCTION_H

void addAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int* nextIndex);

void allAvions(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);


void showAvion(int id, char modele[100], int capacite, int statut, char dateEntree[10]);

#endif