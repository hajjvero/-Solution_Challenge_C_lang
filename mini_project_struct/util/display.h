#ifndef DISPLAY_H
#define DISPLAY_H

#define appWidth 80
#define appBorder '='

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void displayClear();

void displayDanger(char* message);

void displaySuccess(char* message);

void displayPrimary(char* message);

void displayAppName(char* title);

#endif