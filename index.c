#include "blog.h"

#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char *links(void) {
    char *linkss = malloc(640 * (1 << 10)); // Bill told me it's enough for anyone.
    DIR *dir;
    char *linksslocal = linkss;
    int res;
    struct dirent *x;

    res = sprintf(linksslocal, "<ul>");
    linksslocal += res; 
    dir = opendir(".");
    while(x = readdir(dir)) {
        char *name = x->d_name;
        if(name[strlen(name)-2] == '.' && name[strlen(name)-1] == 'c') {
            name[strlen(name)-2] = 0;
            res = sprintf(linksslocal, "<li><a href=\"%s.html\">%s</a>\n", name, name);
            linksslocal += res; 
        }
    }
    res = sprintf(linksslocal, "</ul>");
    return linkss;
}


BLOG("~insom", links());
