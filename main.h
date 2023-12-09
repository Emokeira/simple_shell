#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void executeCommand(char *args[]);
void handleExit(char *args[]);

char *_getline();
char *_getlineHelper();
void _processLine(char *buffer);

void parseCommand(char *command);

char *custom_strtok(char *str, const char *delim);

void _builtFunctions(char *args[]);

char *trimSpaces(char *str);
void updatePWD(void);

#endif
