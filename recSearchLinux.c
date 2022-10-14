#include "recSearch.h"
#include <dirent.h>
#define MAX_PATH 4096

void LinuxRecSearch(char *path, int indent) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[MAX_PATH];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", path, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            LinuxRecSearch(path, indent + 2);
        } else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}