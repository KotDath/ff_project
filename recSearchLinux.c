#include "recSearch.h"
#include <dirent.h>
#define MAX_PATH 4096

void LinuxRecSearch(char *fullName, char *pattern) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(fullName)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[MAX_PATH];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", fullName, entry->d_name);
            LinuxRecSearch(path, pattern);
        } else {
            if (strcmp(entry->d_name, ".") == 0) {
                printf("%s\n", entry->d_name);
            }         
        }
    }
    closedir(dir);
}