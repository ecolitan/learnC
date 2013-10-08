#include <stdio.h>
#include <stdlib.h>

/* Example 2-1. append-char -- append one file to another character by character */

int main(int argc, char *argv[])
{
    int c;
    FILE *from, *to;

    //  Check our arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s from-file to-file\n", *argv);
        exit(1);
    }

    // Open the from-file for reading.
    from = fopen(argv[1], "r");
    if (from == NULL) {
        perror(argv[1]);
        exit(1);
    }

    // Open the to-file for appending. Create if not exists
    to = fopen(argv[2], "a");
    if (to == NULL) {
        perror(argv[2]);
        exit(1);
    }

    // Read chars from from-file until EOF, append them to to-file
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }

    // close the files
    fclose(from);
    fclose(to);
    return 0;
}
