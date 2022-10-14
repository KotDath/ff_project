#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int _CRT_glob = 0;

#if defined(_WIN32) || defined(_WIN64)

#elif defined(linux) || defined(apple)

#endif



int main(int argc, char *argv[])
{
    clock_t begin = clock();
    char *pattern = argv[1];
    printf("pattern is %s\n\n", pattern);
    char *path = NULL;
    if (argc > 2)
    {
        path = argv[2];
    }
    else
    {
        path = (char *)malloc(2 * sizeof(char));
        path[0] = '.';
    }

#if defined(linux) || defined(apple)

#elif defined(_WIN32) || defined(_WIN64)
    printf("size: %d\n", strlen(path));
    WindowsRecSearch(path, strlen(path), pattern, strlen(path));
#endif

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Working time: %f", timeSpent);
    return 0;
}