#include <stdio.h>
#include <stdlib.h>

void mapOutsideWalls(int r, int c, char **arr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
            {
                arr[i][j] = 'x';
            }
            else
            {
                arr[i][j] = 'm';
            }
        }
    }
}

void mapInsideWalls(int r, int c, char **arr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i%2==0 && j%2==0)
            {
                arr[i][j] = 'x';
            }

        }
    }
}

void placePlayer(int r, int c, int playerNumber, char **arr)
{
    if (playerNumber == 1)
    {
        arr[1][1] = 'p';
    }
    if (playerNumber == 2)
    {
        arr[1][c - 2] = 'p';
    }
    if (playerNumber == 3)
    {
        arr[r - 2][1] = 'p';
    }
    if (playerNumber == 4)
    {
        arr[r - 2][c - 2] = 'p';
    }
}

void placePlayers(int r, int c, int playerNumber, char **arr)
{
    for (int i = 1; i <= playerNumber; i++)
    {
        placePlayer(r, c, i, arr);
    }
}

int main()
{
    int r = 9, c = 7, i, j;

    // printf("Entrez le nombre de lignes: ");
    // scanf("%d",&r);

    // printf("Entrez le nombre de colonnes: ");
    // scanf("%d",&c);

    char *arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (char *)malloc(c * sizeof(char));

    mapOutsideWalls(r, c, arr);
    mapInsideWalls(r,c,arr);
    placePlayers(r, c, 4, arr);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++)
        free(arr[i]);
    return 0;
}