#include <stdio.h>
#include <stdlib.h>
 
 void mapOutsideWalls(int r, int c, char** arr){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(i==0 || j==0 || i==r-1 || j==c-1){
            arr[i][j] = 'x';
            }else{
            arr[i][j] = ' ';
        }
    }
    }
 }

int main()
{
    int r=8, c=7, i, j;
 


    // printf("Entrez le nombre de lignes: ");
    // scanf("%d",&r);

    // printf("Entrez le nombre de colonnes: ");
    // scanf("%d",&c);

    char* arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (char*)malloc(c * sizeof(char));
 
    
    mapOutsideWalls(r,c,arr);
    
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("%c ", arr[i][j]);    
        }printf("\n");  
    }

 
    for (int i = 0; i < r; i++)
        free(arr[i]);
 
    return 0;
}