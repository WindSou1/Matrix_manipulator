#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, j;
    int memory;
    int pillar, line;
    srand(time(NULL));
    pillar = rand() % 10 + 4;
    line = rand() % 10 +3;
    int matrix[line][pillar];
    printf("Random matrix\n\n");
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < pillar; j++)
        {
            matrix[i][j] = rand() % 100;
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Swap the first and the last string\n\n");
    for (j = 0; j < pillar / 2; j++)
    {
        memory = matrix[0][j];
        matrix[0][j] = matrix[0][pillar - 1 - j];
        matrix[0][pillar - 1 - j] = memory;

        memory = matrix[line - 1][j];
        matrix[line - 1][j] = matrix[line - 1][pillar - j - 1];
        matrix[line - 1][pillar - j - 1] = memory;
    }
    for (j = 0; j < pillar; j++)
    {
        memory = matrix[0][j];
        matrix[0][j] = matrix[line -1][j];
        matrix[line -1][j] = memory;
    }
    printf("\n");
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < pillar; j++)
            printf ("%d \t", matrix[i][j]);
        printf("\n");
    }

    return 0;
}

