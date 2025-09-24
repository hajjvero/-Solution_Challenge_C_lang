#include <stdio.h>

int main(void)
{
    int gs1, identifiantGroupe, codeEditeur, numeroArticle, chiffreControle;

    printf("Entrez l' ISBN : ");
    scanf("%d%*[-]%d%*[-]%d%*[-]%d%*[-]%d", &gs1, &identifiantGroupe, &codeEditeur, &numeroArticle, &chiffreControle);

    printf("Préfixe GS1 : %d\n", gs1);
    printf("Identifiant Groupe : %d\n", identifiantGroupe);
    printf("code Editeur : %d\n", codeEditeur);
    printf("numero Article : %d\n", numeroArticle);
    printf("chiffre Controle : %d\n", chiffreControle);
}