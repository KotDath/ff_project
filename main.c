#include <time.h>

#include "recSearch.h"

int _CRT_glob = 0;



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
#if defined(_WIN32) || defined(_WIN64)
    WindowsRecSearch(path, strlen(path), pattern, strlen(path));
#else
    LinuxRecSearch(path, 0);
#endif

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nWorking time: %f\n", timeSpent);
    return 0;
}