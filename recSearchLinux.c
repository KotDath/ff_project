#include recSearch.h
#include <dirent.h>
#define MAX_PATH 4096

void LinuxRecSearch(char *path, char *pattern, int offset) {
    struct dirent *dp;
    char *fullpath;

    DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
    while (dp = readdir(dir)) // if dp is null, there's no more content to read
    {
        fullpath = pathcat(path, dp->d_name);
        printf("%s\n", fullpath);
        free(fullpath);
    }
    closedir(dir); // close the handle (pointer)
}