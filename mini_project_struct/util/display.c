#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "display.h"

void displayClear()
{
    system("cls");
}

void displayDanger(char *message)
{
    printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, message);
}

void displaySuccess(char *message)
{
    printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, message);
}

void displayPrimary(char *message)
{
    printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, message);
}

void displayAppName(char *appName)
{
    // lenght of app name.
    int lenght = strlen(appName);

    // calculate padding posible in lefth and right to center app name.
    int padding = (appWidth - lenght - 2) / 2;

    // Top border
    printf("\n");
    for (int i = 0; i < appWidth; i++)
    {
        printf("%c", appBorder);
    }
    printf("\n");

    // Empty line
    printf("%c", appBorder);
    for (int i = 0; i < appWidth - 2; i++)
    {
        printf(" ");
    }
    printf("%c\n", appBorder);

    // Text line with centred.
    printf("%c", appBorder);
    // Left space
    for (int i = 0; i < padding - 1; i++)
    {
        printf(" ");
    }

    // Text
    printf("%s", appName);

    // Right space
    // Calculate remaining spaces (handle odd numbers correctly)
    int remainingSpaces = appWidth - 1 - padding - lenght;
    for (int i = 0; i < remainingSpaces; i++)
    {
        printf(" ");
    }
    printf("%c\n", appBorder);

    // Empty line
    printf("%c", appBorder);
    for (int i = 0; i < appWidth - 2; i++)
    {
        printf(" ");
    }
    printf("%c\n", appBorder);

    // Button border
    for (int i = 0; i < appWidth; i++)
    {
        printf("%c", appBorder);
    }
    printf("\n");
}

void displaySubTitle(char* title) {
    // lenght of title.
    int lenght = strlen(title);

    // calculate padding posible in lefth and right to center title.
    int padding = (appWidth - lenght - 2) / 2;

    // Border style on lefth
    printf("\n");
    for (int i = 0; i < padding - 2; i++)
    {
        printf("%c", appBorder);
    }

    // Text with 4 space
    printf("  %s  ", title);

    // Border style on Right
    // Calculate remaining spaces (handle odd numbers correctly)
    int remainingSpaces = appWidth - 2 - padding - lenght;
    for (int i = 0; i < remainingSpaces; i++)
    {
        printf("%c", appBorder);
    }
    
    printf("\n");
}