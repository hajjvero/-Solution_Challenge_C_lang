#ifndef HELPER_H
#define HELPER_H

typedef struct {
    char* title; //  Name of action
    int root; // Root to access this action
    void (*callback)(); // Callback to run on choice root ofthis action
} Action;

typedef struct {
    Action * actions;
    int count;
    int capacity;
} ActionCollection;

// Function to initialize the collection
void initActionCollection();

// Function to add an action to the collection
void addAction(const char* title, int root, void (*callback)());

// Function to free the memory used by the collection
void freeActionCollection();

// Display actions title and root.
void displayActions();

// Run Choice action on console.
void run();
#endif