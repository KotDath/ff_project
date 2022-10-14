
#include <windows.h>
#define MAX_PATH 2600

void WindowsRecSearch(char *path, int pathSize, char *pattern, int offset)
{
    char fullPattern[MAX_PATH];
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;
    // first we are going to process any subdirectories
    strcpy(fullPattern, path);
    strcat(fullPattern, "*");
    hFindFile = FindFirstFile(fullPattern, &FindFileData);
    if (hFindFile != INVALID_HANDLE_VALUE)
    {
        do
        {
            if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0)
            {
                memset(fullPattern + pathSize, 0, MAX_PATH - pathSize);
                strcat(fullPattern, FindFileData.cFileName);
                strcat(fullPattern, "\\");
                WindowsRecSearch(fullPattern, pathSize + strlen(FindFileData.cFileName) + 1, pattern, offset);
            }
        } while (FindNextFile(hFindFile, &FindFileData));
        FindClose(hFindFile);
    }

    // Now we are going to look for the matching files
    memset(fullPattern, 0, MAX_PATH);
    strcpy(fullPattern, path);
    strcat(fullPattern, pattern);
    hFindFile = FindFirstFile(fullPattern, &FindFileData);
    if (hFindFile != INVALID_HANDLE_VALUE)
    {
        do
        {        
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                memset(fullPattern + pathSize, 0, MAX_PATH - pathSize);
                strcpy(fullPattern, path);
                strcat(fullPattern, FindFileData.cFileName);
                printf(".\\%s\n", fullPattern + offset);
            }
        } while (FindNextFile(hFindFile, &FindFileData));
        FindClose(hFindFile);
    }
}