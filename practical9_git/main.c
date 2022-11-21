#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "magic_square.h"
#define MAX_FILE_NAME 100 // incase of memory issues

int get_num_lines(char filename[MAX_FILE_NAME])
{
    FILE *fp;
    fp = fopen(filename, "r"); //open file
   
    char ch_read;
    int count = 0;
    
    while ((ch_read = fgetc(fp)) != EOF) // end of file
    {
        if (ch_read == '\n')
        {
            count++; // when a new line is found, add to the number of lines
        }
    }
    printf("Number of lines is: %d\n", count);
    fclose(fp);
    return count;
    

}


int main(void)
{
    FILE *f;
    char filename[MAX_FILE_NAME];
    printf("ENTER FILE NAME: ");
    scanf("%s", filename);

    //Get number of lines
    int n = get_num_lines(filename);

    f = fopen(filename, "r");

    int i;
    int **MagicSquare = malloc(n * sizeof(int *)); //allocating memory
    for (i  = 0; i < n; i++);
    {
        MagicSquare[i] = malloc(n * sizeof(int));
    }

    int j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            fscanf(f, "%d", &MagicSquare[i][j]);
        }
    }

    int flag = isMagicSquare(MagicSquare, n);
    if (flag == 1)
    {
        printf("This square is magic!\n");

    }
    else 
    {
        printf("This square is not magic!\n");

    }
    for(i = 0; i < n; i++) // freeing memory
    {
        free(MagicSquare[i]);

    }

    free(MagicSquare);
    fclose(f);
    
    
    return 0;
}