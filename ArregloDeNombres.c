#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

void mostrarPersonas(char *listaNombres[]);
void BuscarNombre(char *listaNombres[], int id);

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
    int valorBuscado;
    printf("\nIngrese el id a buscar: ");
    scanf("%d", &valorBuscado);
    BuscarNombre(listaNombres, valorBuscado);
    
    return 0;
}

void mostrarPersonas(char *listaNombres[]){
    for (int i = 0; i < N; i++){
        printf("%s\n", listaNombres[i]);
    }
}

void BuscarNombre(char *listaNombres[], int id){
    if(id>=0 && id<N){
        printf("%s", listaNombres[id]);
        
    } else {
        printf("\nNo se encontro el valor buscado");
    }
}