#include <stdio.h>
#include <stdlib.h>
#define BUFSIZ 32768

int main(int argc, char *argv[])
{
    printf("BUFSIZ is %d\n", BUFSIZ);

    FILE *from, *to;
    char line[BUFSIZ];

    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s from-file to-file\n", *argv);
        exit(1);
    }

    // Open from-file for reading
    from = fopen(argv[1], "r");
    if (from == NULL) {
        perror(argv[1]);
        exit(1);
    }

    // Open to-file for appending. create if not exists
    to = fopen(argv[2], "a");
    if (to == NULL) {
        perror(argv[2]);
        exit(1);
    }

    // Read and Write a line at a time
    while (fread(line, BUFSIZ, 1, from) != NULL) {
        fwrite(line, BUFSIZ, 1, to);
    }

    // Close files
    fclose(from);
    fclose(to);
    
    return 0;
}
