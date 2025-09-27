#ifndef FUNCTION_H
#define FUNCTION_H

// This function to add new avion and return next index.
int addAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);

// This function to display table style to display all avions.
void allAvions(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);

// This function to display information of one avion on row mode.
void showAvionModeRow(int id, char modele[100], int capacite, int statut, char dateEntree[10]);

// This function to display information of one avion on card mode.
void showAvionModeCard(int id, char modele[100], int capacite, int statut, char dateEntree[10]);

// This function to update information of one avion
void editAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex );

// This function to delete one avion by id and return new newt index
int deletAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);

// This function to search avoin by id or modele.
void searchAvion(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);

// this function for sort data by order asc 
void sort(char modeles[128][100], int capacites[128], int statuts[128], char dateEntrees[128][10], int nextIndex);
#endif