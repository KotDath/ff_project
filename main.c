#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

char *pathcat(const char *str1, char *str2);

int main(int argc, char *argv[])
{
    struct dirent *dp;
    char *fullpath;
    char *path = argv[1]; // Directory target
    DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
    while (dp=readdir(dir)) // if dp is null, there's no more content to read
    {
        fullpath = pathcat(path, dp->d_name);
        printf("%s\n", fullpath);
        free(fullpath);
    }
    closedir(dir); // close the handle (pointer)
    return 0;
}

char *pathcat(char *str1, char *str2)
{
    char *res;
    size_t strlen1 = strlen(str1);
    size_t strlen2 = strlen(str2);
    int i, j;
    res = malloc((strlen1+strlen2+1)*sizeof *res);
    strcpy(res, str1);
    for (i=strlen1, j=0; ((i<(strlen1+strlen2)) && (j<strlen2)); i++, j++)
        res[i] = str2[j];
    res[strlen1+strlen2] = '\0';
    return res;
}