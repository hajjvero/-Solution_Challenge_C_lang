#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char mot[128];

    printf("Entrez un mot : ");
    scanf("%127s", mot);

    int sum = 0;

    for (int i = 0; i < mot[i] != '\0'; i++)
    {
        switch (toupper(mot[i]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                sum++;
                break;
            case 'D':
            case 'G':
                sum += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                sum += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                sum += 4;
                break;    
            case 'K':
                sum += 5;
                break;  
            case 'J':
            case 'X':
                sum += 8;
                break; 
            case 'Q':
            case 'Z':
                sum += 10;
                break;   
            } 
    }

    printf("Valeur Scrabble %d", sum);
}