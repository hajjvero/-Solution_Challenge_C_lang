#include <stdio.h>

int main(void)
{
    int heure, minute;

    printf("Entrez une heure (24) : ");
    scanf("%d%*[:]%d", &heure, &minute);

    // table index 0 = Heure Départ, 1 = Minutes Départ, 2 = Heure Arrive, 3 = Minutes Arrive
    int vols[8][4] = {
        {8,0,10,16},
        {9,43,11,52},
        {11,19,13,31},
        {12,47,15,0},
        {14,0,16,8},
        {15,45,17,55},
        {19,0,21,20},
        {21,45,23,58}
    };

    int userHureEnMinute = (heure * 60) + minute;

    int indexMinVol = 0;
    for (int i = 1; i < 8; i++)
    {
        int currentDepartEnMinute = (vols[i][0] * 60) + vols[i][1]; 

        if (currentDepartEnMinute > userHureEnMinute)
        {
            int prevDepartEnMinute = (vols[i - 1][0] * 60) + vols[i - 1][1];

            // printf("C : %d \n P : %d", currentDepartEnMinute - userHureEnMinute, userHureEnMinute - prevDepartEnMinute);
            
            if ((currentDepartEnMinute - userHureEnMinute) > (userHureEnMinute - prevDepartEnMinute))
            {
                indexMinVol = i - 1;
            } else {
                indexMinVol = i;
            }
            break;
        }
        
    }
    
    printf("L'heure de départ la plus proche est %d:%d , arrivant à %d:%d", vols[indexMinVol][0],vols[indexMinVol][1], vols[indexMinVol][2], vols[indexMinVol][3]);

}