#ifndef RECSEARCH_H
#define RECSEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WindowsRecSearch(char *path, int pathSize, char *pattern, int offset);
void LinuxRecSearch(char *path, int indent);

#endif