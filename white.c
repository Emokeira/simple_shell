#include "main.h"

void trimWhitespaces(char *str) {
    size_t len;

    while (*str == ' ' || *str == '\t') {
        char *current = str;
        while (*current != '\0') {
            *current = *(current + 1);
            current++;
        }
    }

    len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[--len] = '\0';
    }
}
