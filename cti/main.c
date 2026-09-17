#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE_BUF 512
#define OUT_BUF 8192


int main(int argc, char *argv[]) {
    // declareerd file
    FILE* file;
    // opent file
    file = fopen(argv[1], "a");
    // variabelen
    char line[LINE_BUF];
    char out[OUT_BUF];
    size_t len = 0;
    size_t out_sz = 8192;

    // checkt of file bestaat
    if (file == NULL) {
        perror("File bestaat niet");
        return 1;
    } else {
        // mainloop voor Write
        while (1) {
            // checkt of hij vraag om een input
            if (!fgets(line, sizeof(line), stdin)) {
                fclose(file);
                return 0;
            }
            // checkt string of hij close zegt
            if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0) {
                break;
            }

            // checkt of de toevoeging niet te lang is
            size_t line_len = strlen(line);
            if (len + line_len + 1 > out_sz) {
                puts("File toevoeging te lang!");
                fclose(file);
                return 0;
            }
            // kopieert de line naar memmory
            memcpy(out + len, line, line_len);
            len += line_len;
            out[len] = '\0';
        }
        // print de lines naar de file en closed het programma
        fprintf(file, "%s", out);
        fclose(file);
    }
    return 0;
}