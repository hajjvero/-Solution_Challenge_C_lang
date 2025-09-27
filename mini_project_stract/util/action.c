#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "action.h"
#include "display.h"

static ActionCollection collection;

void initActionCollection()
{
    collection.actions = (Action *)malloc(1 * sizeof(Action));
    if (collection.actions == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }

    collection.count = 0;
    collection.capacity = 1;
}

void addAction(const char *title, int root, void (*callback)())
{
    // Check if the collection is full
    if (collection.count >= collection.capacity)
    {
        // Increment capacity of action
        Action *newActions = (Action *)realloc(collection.actions, (++collection.capacity) * sizeof(Action));
        if (newActions == NULL)
        {
            displayDanger("Memory allocation failure.\n");
            exit(1);
        }

        collection.actions = newActions;
    }

    // Add the new action
    // Use strdup to dynamically allocate and copy the title string
    collection.actions[collection.count].title = strdup(title);
    if (collection.actions[collection.count].title == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }
    collection.actions[collection.count].root = root;
    collection.actions[collection.count].callback = callback;
    collection.count++;
}

void freeActionCollection()
{
    // Free each dynamically allocated title string
    for (int i = 0; i < collection.count; i++)
    {
        free(collection.actions[i].title);
    }

    // Free the actions array itself
    free(collection.actions);
}

void displayActions()
{
    for (int i = 0; i < collection.count; i++)
    {
        printf("%d : %s\n", collection.actions[i].root, collection.actions[i].title);
    }
    printf("\n\n");
}

void run()
{
    bool isExit = false;

    int choice;
    do
    {
        // Clear console
        displayClear();

        // Shwo App name
        displayAppName("Gestion des avion et aeroport");

        // display choices
        displayActions();

        displayPrimary("Sélectionnez votre action s'il vous plaît : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("select 1");
            break;
        case 0:
            isExit = true;
            break;
        }
    } while (!isExit);
}