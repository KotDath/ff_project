#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "recSearch.h"

int _CRT_glob = 0;

#if defined(_WIN32) || defined(_WIN64)

#elif defined(linux) || defined(apple)

#endif



int main(int argc, char *argv[])
{
    clock_t begin = clock();
    char *pattern = argv[1];
    char *path = NULL;
    if (argc > 2)
    {
        path = argv[2];
    }
    else
    {
        path = argv[0];
        int pos = strlen(path);
        while(path[pos] != '\\' && pos > 0) {
            --pos;
        }

        path[pos + 1] = '\0';
        printf(path);
    }

    printf("path %s\npattern %s\n", path, pattern);

#if defined(linux) || defined(apple)
    LinuxRecSearch(path, pattern, strlen(path));
#elif defined(_WIN32) || defined(_WIN64)
    WindowsRecSearch(path, strlen(path), pattern, strlen(path));
#endif

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nWorking time: %f\n", timeSpent);
    return 0;
}