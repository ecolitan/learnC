#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    FILE *from, *to;
    char buf[BUFSIZ];

    // Check args
    if (argc != 3) {
        fprintf(stderr, "Usage: %s from-file to-file\n", *argv);
        exit(1);
    }

    // open from-file
    from = fopen(argv[1], "r");
    if (from == NULL) {
        perror(argv[1]);
        exit(1);
    }

    // open to-file
    to = fopen(argv[2], "a");
    if (to == NULL) {
        perror(argv[2]);
        exit(1);
    }

    while ((n = fread(buf, sizeof(char), BUFSIZ, from)) > 0) {
        fwrite(buf, sizeof(char), n, to);
    }

    // close files
    fclose(from);
    fclose(to);

    return 0;
}
