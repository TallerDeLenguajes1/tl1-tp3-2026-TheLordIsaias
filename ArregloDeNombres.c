#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

void mostrarPersonas(char *listaNombres[]);

int main(){

    char buff[50];
    char *listaNombres[N];
    int tamaCad;
        for (int i = 0; i < N; i++){
            printf("\nIngrese un nombre: ");
            fflush(stdin);
            scanf("%s", buff);
            tamaCad = strlen(buff);
            listaNombres[i] = (char *) malloc(tamaCad * sizeof(char) + 1);
            strcpy(listaNombres[i], buff);
        }
        mostrarPersonas(listaNombres);
        
    
    return 0;
}

void mostrarPersonas(char *listaNombres[]){
    for (int i = 0; i < N; i++){
        printf("%s\n", listaNombres[i]);
    }
}