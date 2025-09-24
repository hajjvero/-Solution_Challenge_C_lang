#include <stdio.h>

int main(void)
{
    int note;
    printf("Entrez une nte numérique : ");
    scanf("%d", &note);

    int chiffreDizaines = note/10;

    char litterale;
    switch (chiffreDizaines)
    {
        case 9:
        case 10:
            litterale = 'A';
            break;
        case 8:
            litterale = 'B';
        break;
        case 7:
            litterale = 'C';
            break;
        case 6:
            litterale = 'D';
        break;
        case 5:
        case 4:
        case 3:
        case 1:
        case 0:
            litterale = 'F';
            break;        
        default:
            printf("erreur si la note est supérieure à 100 ou inférieure à 0.");
            return 0;
    }

    printf("Note Littzrale : %c", litterale);
}