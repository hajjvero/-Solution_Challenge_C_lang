#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "action.h"
#include "display.h"

ActionCollection actionCollection;

void initActionCollection()
{
    actionCollection.actions = (Action *)malloc(1 * sizeof(Action));
    if (actionCollection.actions == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }

    actionCollection.count = 0;
    actionCollection.capacity = 1;
}

void addAction(const char *title, int root, void (*callback)())
{
    // Check if the collection is full
    if (actionCollection.count >= actionCollection.capacity)
    {
        // Increment capacity of action
        Action *newActions = (Action *)realloc(actionCollection.actions, (++actionCollection.capacity) * sizeof(Action));
        if (newActions == NULL)
        {
            displayDanger("Memory allocation failure.\n");
            exit(1);
        }

        actionCollection.actions = newActions;
    }

    // Add the new action
    // Use strdup to dynamically allocate and copy the title string
    actionCollection.actions[actionCollection.count].title = strdup(title);
    if (actionCollection.actions[actionCollection.count].title == NULL)
    {
        displayDanger("Memory allocation failure.\n");
        exit(1);
    }
    actionCollection.actions[actionCollection.count].root = root;
    actionCollection.actions[actionCollection.count].callback = callback;
    actionCollection.count++;
}

void freeActionCollection()
{
    // Free each dynamically allocated title string
    for (int i = 0; i < actionCollection.count; i++)
    {
        free(actionCollection.actions[i].title);
        actionCollection.actions[i].title = NULL;
    }

    // Free the actions array itself
    free(actionCollection.actions);
    actionCollection.actions = NULL;
}

void displayActions()
{
    printf("\n");
    for (int i = 0; i < actionCollection.count; i++)
    {
        printf("[%d] : %s\n", actionCollection.actions[i].root, actionCollection.actions[i].title);
    }
    printf("\n\n");
}

void run()
{
    int choice;
    do
    {
        // display choices
        displayActions();

        displayPrimary("Sélectionnez votre action s'il vous plaît : ");
        scanf("%d", &choice);
        printf("\n");

        // To check if the choice is exist.
        bool isFoundAction = false;
        for (int i = 0; i < actionCollection.count; i++)
        {
            // Found action and run callback of this action.
            if (actionCollection.actions[i].root == choice)
            {
                isFoundAction = true;
                // Check if the collback not null
                if (actionCollection.actions[i].callback != NULL)
                {
                    actionCollection.actions[i].callback();
                }
            }
        }

        // Not found action
        if (!isFoundAction)
        {
            displayDanger("Sélectionnez une action valide s'il vous plaît.\n");
        }
    } while (1);
}