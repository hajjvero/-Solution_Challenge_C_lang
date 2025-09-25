#include <stdio.h>

int main(void)
{
    char phoneString[128];

    printf("Entrez un nombre de téléphone : ");
    scanf("%127s", phoneString);

    char phoneNumber[128];
    for (int i = 0; i < phoneString[i] != '\0'; i++)
    {
        // printf("\n%c\n\n", phoneString[i]);
        switch (phoneString[i])
        {
            case 'A':
            case 'B':
            case 'C':
                phoneNumber[i] = '2';
                break;
            case 'D':
            case 'E':
            case 'F':
                phoneNumber[i] = '3';
                break;
            case 'G':
            case 'H':
            case 'I':
                phoneNumber[i] = '4';
                break;
            case 'J':
            case 'K':
            case 'L':
                phoneNumber[i] = '5';
                break;    
            case 'M':
            case 'N':
            case 'O':
                 phoneNumber[i] = '6';
                break;  
            case 'P':
            case 'R':
            case 'S':
                 phoneNumber[i] = '7';
                break; 
            case 'T':
            case 'U':
            case 'V':
                 phoneNumber[i] = '8';
                break;   
            case 'W':
            case 'X':
            case 'Y':
                 phoneNumber[i] = '9';
                break;              
            default:
                // by defult this is number.
                phoneNumber[i] = phoneString[i];
                break;
            } 
    }

    printf("%s", phoneNumber);
}