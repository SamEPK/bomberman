
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <conio.h>

#define ESPACE 32
#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77


void printMap(int r, int c, char **arr){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}
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

void spaceAroundPlayer(int r, int c, char **arr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'p'){
                if(arr[i-1][j]=='m')arr[i-1][j]=' ';
                if(arr[i][j-1]=='m')arr[i][j-1]=' ';
                if(arr[i+1][j]=='m')arr[i+1][j]=' ';
                if(arr[i][j+1]=='m')arr[i][j+1]=' ';
            }
        }
    }
}

void playerMove(int r, int c, char **arr){
     int touche = 0;
    touche = getch();
    switch (touche)
    {
    case HAUT:
            if (arr[r - 1][c] != 'x' && arr[r - 1][c] != 'm')
            {
                arr[r][c] = ' ';
                r--;
                arr[r][c] = 'p';
            }
        break;
    case BAS:
            if (arr[r + 1][c] != 'x'  && arr[r+1] [c] != 'm')
            {
                arr[r][c] = ' ';
                r++;
                arr[r][c] = 'p';
            }
        break;
    case GAUCHE:
            if (arr[r][c - 1] != 'x' && arr[r][c- 1] != 'm')
            {
                arr[r][c] = ' ';
                c--;
                arr[r][c] = 'p';
            }
        break;
    case DROITE:
            if (arr[r][c+ 1] != 'x' && arr[r][c+ 1] != 'm')
            {
                arr[r][c] = ' ';
                c++;
                arr[r][c] = 'p';
            }
        break;
    // case ESPACE:
        // poser_bombe(longeur, largeur, nb_joueur, arr, r, c);
        // break;
    } 
     system("cls");
     printMap(9,7,arr);
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
    spaceAroundPlayer(r,c,arr);
   


    
         printMap(r,c,arr);

         while(1){
        playerMove(1,1,arr);    }
    
    
    for (int i = 0; i < r; i++)
        free(arr[i]);
    return 0;
}