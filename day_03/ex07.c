#include <stdio.h>

int main(void) {
    int table[5][5], sum_row[5] = {0}, sum_col[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Entrez la ligne %d : ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            // hadi kifach khadmat ???????????
            scanf("%3d", &table[i][j]);
            sum_row[i] += table[i][j];
            sum_col[j] += table[i][j];
        }
        printf("\n");
    }
    
    printf("Somme des lignes : ");
    for (int a = 0; a < 5; a++) {
        printf("%3d", sum_row[a]);
    }

    printf("\nSomme des colonnes : ");
    for (int a = 0; a < 5; a++) {
        printf("%3d", sum_col[a]);
    }

    return 0;
}
