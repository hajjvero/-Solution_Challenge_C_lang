#include <stdio.h>
#include <string.h>
#include <ctype.h>

char strToUpdate(char c) {
    return toupper(c);
}

int main(void) {
    char word[128], b1ff[128];
    printf("Entrez votre message : ");

    scanf("%[^\n]", word);

    printf("En B1FF-speak : ");

    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        switch (strToUpdate(word[i]))
        {
            case 'A':
                printf("4");
                break;
            case 'B':
                 printf("8");
                break;
            case 'E':
                 printf("3");
                break;
            case 'I':
                 printf("1");
                break;    
            case 'O':
                 printf("0");
                break;
            case 'S':
                 printf("5");
                break;        
            default:
                 printf("%c", strToUpdate(word[i]));
                break;
        }
    }

    for (int j = length; j < length + 10; j++)
    {
         printf("!");
    }

   
    return 0;
}
