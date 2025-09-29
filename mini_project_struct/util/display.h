#ifndef DISPLAY_H
#define DISPLAY_H

#define appWidth 80
#define appBorder '='

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// this function to clear console.
void displayClear();

// this function to display message with color red.
void displayDanger(char* message);

// this function to display message with color green.
void displaySuccess(char* message);

// this function to display message with color blue.
void displayPrimary(char* message);

// this function to display App name
void displayAppName(char* title);

// this function to display title with border and center text
void displaySubTitle(char* title);

#endif