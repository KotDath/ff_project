#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif


char *pathcat(char *str1, char *str2);

int main(int argc, char *argv[])
{
    char *path = argv[1]; // Directory target
    #ifdef __linux__ 
        #include <dirent.h>
        struct dirent *dp;
        char *fullpath;
        
        DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
        while (dp=readdir(dir)) // if dp is null, there's no more content to read
        {
            fullpath = pathcat(path, dp->d_name);
            printf("%s\n", fullpath);
            free(fullpath);
        }
        closedir(dir); // close the handle (pointer)
    #elif defined(_WIN32) || defined(_WIN64)
        HANDLE fileHandle;
        WIN32_FIND_DATA ffd;
        LARGE_INTEGER szDir;
        WIN32_FIND_DATA fileData;
        fileHandle = FindFirstFile("C:\\Users\\epida\\Desktop\\markevich\\ff_project\\*.?d", &ffd);
        if (INVALID_HANDLE_VALUE == fileHandle) 
            return 1;

        do
        {
        printf("%s\n", ffd.cFileName);
        }
        while (FindNextFile(fileHandle, &ffd) != 0);

    #endif
    
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
