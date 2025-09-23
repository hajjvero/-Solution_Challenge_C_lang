#include <stdio.h>

int main(void)
{
    int montant;
    printf("Entrer un montant en dollars: ");
    
    scanf("%d", &montant);

    // hdi list dyal les billes 
    int billes[4] = {20, 10, 5, 1};

    // had var ghadi nhat fih montant o ghadi nb9a na9so. 
    int rest = montant;
    for (int i = 0; i < 4; i++)
    {
        int bille = rest / billes[i];

        rest = rest - (billes[i] * bille);
        // printf("Bille : %d\n Rest : %d\n\n", bille ,rest);


        printf("Billets de %d$ : %d\n", billes[i], bille);
    } 
}