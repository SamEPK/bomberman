#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <conio.h>


void afficher_carte(int longeur, int largeur, char carte[longeur][largeur])
{
    for (int i = 0; i < longeur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            printf("%c", carte[i][j]);
        }
        printf("\n");
    }
}

void initialiser_carte(int longeur, int largeur, int nb_joueur, char carte[longeur][largeur])
{
    for (int i = 0; i < longeur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            if (i == 0 || i == longeur - 1)
            {
                carte[i][j] = '#';
            }
            else if (j == 0 || j == largeur - 1)
            {
                carte[i][j] = '#';
            }
            else if (i == 1 && j == 1 && nb_joueur >= 1)
            {
                //1 en unicode
                carte[i][j] = 49;
            }
            else if (i == 1 && j == largeur - 2 && nb_joueur >= 2)
            {
                carte[i][j] = 50;
            }
            else if (i == longeur - 2 && j == 1 && nb_joueur >= 3)
            {
                carte[i][j] = 51;
            }
            else if (i == longeur - 2 && j == largeur - 2 && nb_joueur >= 4)
            {
                carte[i][j] = 52;
            }
            else
            {
                carte[i][j] = ' ';
            }
        }
    }
}

void placer_murs_indestructibles(int longeur, int largeur, int nb_joueur, char carte[longeur][largeur])
{
    for (int i = 0; i < longeur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            if (i == 0 || i == longeur - 1)
            {
                carte[i][j] = '#';
            }
            else if (j == 0 || j == largeur - 1)
            {
                carte[i][j] = '#';
            }
            else if (i == 1 && j == 1 && nb_joueur >= 1)
            {
                carte[i][j] = 49;
            }
            else if (i == 1 && j == largeur - 2 && nb_joueur >= 2)
            {
                carte[i][j] = 50;
            }
            else if (i == longeur - 2 && j == 1 && nb_joueur >= 3)
            {
                carte[i][j] = 51;
            }
            else if (i == longeur - 2 && j == largeur - 2 && nb_joueur >= 4)
            {
                carte[i][j] = 52;
            }
            else if (i % 2 == 0 && j % 2 == 0)
            {
                carte[i][j] = '#';
            }
        }
    }
}

void placer_murs_destructibles(int longeur, int largeur, int nb_joueur, char carte[longeur][largeur])
{
    int nb_murs = 0;
    int nb_murs_max = (longeur * largeur) / 10;
    int x, y;
    srand(time(NULL));
    while (nb_murs < nb_murs_max)
    {
        x = rand() % (longeur - 2) + 1;
        y = rand() % (largeur - 2) + 1;
        if (carte[x][y] == ' ')
        {
            carte[x][y] = '|';
            nb_murs++;
        }
    }
}
#define ESPACE 32
#define HAUT 72
#define BAS 80
#define GAUCHE 75
#define DROITE 77
void poser_bombe(int longeur, int largeur, int nb_joueur, char carte[longeur][largeur], int x, int y)
{
    carte[x][y] = 111;

                if (carte[x + 1][y] != '#' && carte[x+1][y] == '|'){
                    carte[x + 1][y] = ' ';   
                }
                if (carte[x - 1][y] != '#' && carte[x-1][y] == '|'){
                    carte[x - 1][y] = ' ';                        
                }
                if (carte[x][y + 1] != '#' && carte[x][y+1] == '|'){
                    carte[x][y + 1] = ' ';
                }
                if (carte[x][y - 1] != '#' && carte[x][y-1] == '|'){
                    carte[x][y - 1] = ' ';              
                }
                if (carte[x+2][y] != '#' && carte[x+1][y] == ' ' && carte[x+2][y] == '|'){
                    carte[x+2][y] = ' ';
                }
                if (carte[x-2][y] != '#' && carte[x+1][y] == ' ' && carte[x-2][y] == '|'){
                    carte[x-2][y] = ' ';

                }
                if (carte[x][y+2] != '#' && carte[x+1][y] == ' ' && carte[x][y+2] == '|'){
                    carte[x][y+2] = ' ';
                }
                if (carte[x][y-2] != '#' && carte[x+1][y] != ' ' && carte[x][y-2] == '|'){
                    carte[x][y-2] = ' ';
                }
}




void deplacer_joueur(int longeur, int largeur, int nb_joueur, char carte[longeur][largeur], int x, int y)
{
    int touche = 0;
    touche = getch();
    switch (touche)
    {
    case HAUT:
            if (carte[x - 1][y] != '#' && carte[x - 1][y] != '|')
            {
                carte[x][y] = ' ';
                x--;
                carte[x][y] = 49;
            }
        break;
    case BAS:
            if (carte[x + 1][y] != '#'  && carte[x+1] [y] != '|')
            {
                carte[x][y] = ' ';
                x++;
                carte[x][y] = 49;
            }
        break;
    case GAUCHE:
            if (carte[x][y - 1] != '#' && carte[x][y - 1] != '|')
            {
                carte[x][y] = ' ';
                y--;
                carte[x][y] = 49;
            }
        break;
    case DROITE:
            if (carte[x][y + 1] != '#' && carte[x][y + 1] != '|')
            {
                carte[x][y] = ' ';
                y++;
                carte[x][y] = 49;
            }
        break;
    case ESPACE:
        poser_bombe(longeur, largeur, nb_joueur, carte, x, y);
        break;
    } 
     system("cls");
}


int main()
{
    int recommencer = 1;
    while (recommencer == 1)
    {
        int longeur = 0;
        int largeur = 0;
        int nb_joueur = 0;
        do
        {
            printf("Entrez la longeur de la carte (7 minimum et forcement impair) : ");
            scanf("%d", &longeur);
        } while (longeur < 7 || longeur % 2 == 0);
        do
        
        {
            printf("\nEntrez la largeur de la carte (7 minimum et forcement impair) : ");
            scanf("%d", &largeur);
        } while (largeur < 7 || largeur % 2 == 0);
        printf("Entrez le nombre de joueur : ");
        scanf("%d", &nb_joueur);
        char carte[longeur][largeur];
        initialiser_carte(longeur, largeur, nb_joueur, carte);
        placer_murs_indestructibles(longeur, largeur, nb_joueur, carte);
        placer_murs_destructibles(longeur, largeur, nb_joueur, carte);
   
        int x = 1;
        int y = 1;
        
        while (1)
        { 
               afficher_carte(longeur, largeur, carte);
               deplacer_joueur(longeur, largeur, nb_joueur, carte, x, y);
              if (carte[x - 1][y] == 49)
            {
                x = x - 1;
            }
            if (carte[x + 1][y] == 49)
            {
                x = x + 1;
            }
            if (carte[x][y - 1] == 49)
            {
                y = y - 1;
            }
            if (carte[x][y + 1] == 49)
            {
                y = y + 1;
            }
        }
        
        printf("Voulez vous recommencer ? 1 = oui 0 = non : ");
        scanf("%d", &recommencer);
       
    }
    return 0;
} 