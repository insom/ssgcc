#include <stdio.h>
#define BLOG(title, body) int main(void) { printf("<html><head><title>%s</title></head><body>\n", title); parse(body); printf("</body></html>\n"); return 0; }
#define P "\n\n"
static void parse(char *v) {
    char *us = v;
    printf("<p>\n");
    for(;*us != 0; us++) {
        if(*us == '\n' && us != v && *(us-1) == '\n') printf("</p>\n<p>\n");
        putchar(*us);
    }
    printf("</p>\n");
}
