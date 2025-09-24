#include <stdio.h>

int main(void)
{
    int firtDateM, firtDateD, firtDateY;
    int lastDateM, lastDateD, lastDateY;


    printf("Entrez la première date (mm/jj/aa) : ");
    scanf("%d%*[/]%d%*[/]%d%*[/]", &firtDateM, &firtDateD, &firtDateY);


    printf("Entrez la deuxième date (mm/jj/aa) : ");
    scanf("%d%*[/]%d%*[/]%d%*[/]", &lastDateM, &lastDateD, &lastDateY);

    int isFirstDateGreater;

    // check by year
    if (firtDateY > lastDateY)
    {
        isFirstDateGreater = 1;
    } else if(firtDateY < lastDateY) {
        isFirstDateGreater = 0;
    } else {
        // check by month
        if (firtDateM > lastDateM)
        {
            isFirstDateGreater = 1;
        } else if(firtDateM < lastDateM) {
             isFirstDateGreater = 0;
        } else {
            // check by day
            if (firtDateD > lastDateD)
            {
                isFirstDateGreater = 1;
            } else if(firtDateD < lastDateD) {
                isFirstDateGreater = 0;
            }
        }
        
    }
    
    if (isFirstDateGreater)
    {
        printf("%d/%d/%d est plus tot que %d/%d/%d", lastDateM, lastDateD, lastDateY, firtDateM, firtDateD, firtDateY);
    } else {
        printf("%d/%d/%d est plus tot que %d/%d/%d", firtDateM, firtDateD, firtDateY, lastDateM, lastDateD, lastDateY);
    }
}