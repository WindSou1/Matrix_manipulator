#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, j, k;
    int new_pil, new_line;       /* line and column for manual matrix */
    int imin, jmin;     /* line and column of min element */
    int min;
    int memory;
    int pillar, line;
    srand(time(NULL));
    pillar = rand() % 10 + 4;
    line = rand() % 10 +3;
    int matrix[line][pillar];
    int delete_matrix[line - 1][pillar - 1];
    min = 101;
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
    for (j = 0; j < pillar / 2; j++)        /* 1 and last string in reverse order */
    {
        memory = matrix[0][j];
        matrix[0][j] = matrix[0][pillar - 1 - j];
        matrix[0][pillar - 1 - j] = memory;

        memory = matrix[line - 1][j];
        matrix[line - 1][j] = matrix[line - 1][pillar - j - 1];
        matrix[line - 1][pillar - j - 1] = memory;
    }
    for (j = 0; j < pillar; j++)        /* swap 1 and last string */
    {
        memory = matrix[0][j];
        matrix[0][j] = matrix[line -1][j];
        matrix[line -1][j] = memory;
    }
    for (i = 0; i < line; i++)      /* output */
    {
        for (j = 0; j < pillar; j++)
            printf ("%d \t", matrix[i][j]);
        printf("\n");
    }
    printf ("\n");
    for (i = 0; i < line; i++)     /* find min element and it's column and string */
    {
        for (j = 0; j < pillar; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                imin = i;
                jmin = j;
            }
        }
    }
    printf("EXTERMINATE\n");
    printf("%d %d %d\n\n", min, imin, jmin);
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < pillar; j++)
        {
            if (i != imin && j != jmin)
            {
                delete_matrix[i][j] = matrix[i][j];
                printf("%d\t ", delete_matrix[i][j]);
            }
        }
         if (i != imin)
             printf("\n");
    }
    printf("\n");
    printf("Enter lines and columns of new matrix: ");      /* manual matrix */
    scanf ("%d %d", &new_line, &new_pil);
    int new_matrix[new_line][new_pil];
    int end_matrix[line][new_pil];
    for (i = 0; i < new_line; i++)
    {
        for (j = 0; j < new_pil; j++)
            scanf("%d", &new_matrix[i][j]);
    }
    printf("\n");
    for (i = 0; i < new_line; i++)      /* output */
    {
        for (j = 0; j < new_pil; j++)
            printf("%d\t", new_matrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
    if (pillar != new_line)     /* multiplication */
        printf ("we can't multiply this matrixes");
    else
    {
        for (i = 0; i < line; i++)
        {
            for (j = 0; j < new_pil; j++)
            {
                end_matrix[i][j] = 0;
                for (k = 0; k < new_line; k++)
                    end_matrix[i][j] += delete_matrix[i][k] * new_matrix[k][j];
            }
        }
        for (i = 0; i < line; i++)      /* output */
        {
            for (j = 0; j < new_pil; j++)
                printf ("%d\t", end_matrix[i][j]);
            printf("\n");
        }
    }
    return 0;
}
