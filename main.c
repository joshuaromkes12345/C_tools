#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // declareerd file
    FILE* file;
    // opent file
    file = fopen(argv[1], "rb");

    // checkt of file bestaat
    if (file == NULL) {
        perror("File bestaat niet");
        return 1;
    } else {
        // gaat naar file einde
        fseek(file, 0, SEEK_END);
        // kijkt hoeveel bytes het bestand is
        long size = ftell(file);
        // gaat terug naar begin van file
        rewind(file);
        // zet de maakt de ruimte vrij in memmory
        char *buffer = malloc(size + 1);

        // kijkt of malloc gelukt is 
        if (buffer == NULL) {
            fclose(file);
            return 1;
            } else {
            // zet de inhoud van de file in buffer
            size_t bytes_read = fread(buffer, 1, size, file);
            // geeft het einde van het bestand aan
            buffer[bytes_read] = '\0';

            // print het bestand uit
            printf("%s", buffer);

            // closed de memmory van malloc en closed het bestand
            free(buffer);
            fclose(file);
        }
    }
    return 0;
}