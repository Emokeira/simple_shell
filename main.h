#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define MAX_ALIAS_LENGTH 256
#define MAX_ALIASES 100


extern int aliasCount;
extern char **environ;

void trimWhitespaces(char *str);
int handleAlias(char *input);
void writeAlias(const char *str);
void printAliases(void);
void writeError(const char *errMsg);
void checkAliasName(char *name);
void handleAliasDefinitionLogic(char *name, char *value);

int findAliasIndex(const char *name);

void handleSemiColon(char *segment);
void handleSegment(char *segment);
void tokenizeAndHandle(char *segment);
void handleAndOperator(char *segment);
void handleOrOperator(char *segment);
void handleSegment(char *segment);
void updatePWD(void);

void parseCommands(char *commands);

void parseCommand(char *command);
int executeCommand(char *args[]);
void executeChild(char *args[]);
char *searchCommandInPath(char *args[]);
int handleBuiltInCommands(char *args[]);

char *_getline();
char *_getlineHelper();

char *custom_strtok(char *str, const char *delim);

void handleExit(char *args[]);
int processCommandSegments(char *input);


void changeDirectory(char *args[]);
void unsetEnvironmentVariable(char *args[]);
void setEnvironmentVariable(char *args[]);
void printEnvironment(void);
void exitShell(void);

void freeLine(char *line);

void handleNonInteractiveMode(int argc, char *argv[]);
void executeCommandsFromFile(int file_descriptor);
void executeCommandsFromFile(int file_descriptor);
#endif
