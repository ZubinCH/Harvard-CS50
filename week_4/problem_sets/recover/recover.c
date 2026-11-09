#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

#define BLOCK_SIZE 512
#define FILE_NAME_LENGTH 17
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Correct usage: ./recover [file.raw].\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n = 0;
    char filename[FILE_NAME_LENGTH];
    BYTE bf[BLOCK_SIZE];
    FILE *img = NULL;

    while (fread(bf, 1, BLOCK_SIZE, input) == BLOCK_SIZE) {
        
        if (bf[0] == 0xff &&
            bf[1] == 0xd8 &&
            bf[2] == 0xff && 
            (bf[3] & 0xf0) == 0xe0) 
            {
            if (img != NULL) {
                fclose(img);
            }
            sprintf(filename, "./images/%03i.jpg", n++);
            

            img = fopen(filename, "wb");
            if (!img) {
                printf("New jpg could not be created.\n");
                fclose(input);
                return 1;
            }
        }

        if (img != NULL) {
            fwrite(bf, 1, BLOCK_SIZE, img);
        }
    }

    if (img != NULL) fclose(img);
    fclose(input);
    printf("Number of files created: %i.\n", n);






    return 0;
}