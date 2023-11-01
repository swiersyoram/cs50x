#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }

    unsigned char buffer[512];
    char filename[8];
    int counter = 0;
    FILE *img = NULL;

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1)
            {
                if (counter > 0)
                {
                    fclose(img);
                }

                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                counter++;
            }
        }

        if (counter > 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    fclose(file);
    fclose(img);

    return 0;
}