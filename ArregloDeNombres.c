#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

void mostrarPersonas(char *listaNombres[]);
void BuscarNombrePorId(char *listaNombres[], int id);
char* BuscarNombrePorPalabra(char *listaNombres[], char palabraClave[]);

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
        char palabraClave[50];
        printf("\nIngrese una palabra clave para la busqueda: ");
        fflush(stdin);
        scanf("%s", palabraClave);
        char nombreEncontrado[50];
        strcpy(nombreEncontrado, BuscarNombrePorPalabra(listaNombres, palabraClave));
        printf("Nombre encontrado: %s", nombreEncontrado);
    int valorBuscado;
    printf("\nIngrese el id a buscar: ");
    scanf("%d", &valorBuscado);
    BuscarNombrePorId(listaNombres, valorBuscado);
    
    return 0;
}

void mostrarPersonas(char *listaNombres[]){
    for (int i = 0; i < N; i++){
        printf("%s\n", listaNombres[i]);
    }
}

void BuscarNombrePorId(char *listaNombres[], int id){
    if(id>=0 && id<N){
        printf("%s", listaNombres[id]);
        
    } else {
        printf("\nNo se encontro el valor buscado");
    }
}

char* BuscarNombrePorPalabra(char *listaNombres[], char palabraClave[]){
    char *retorno[50];
    for (int i = 0; i < N; i++){
        if (strstr(palabraClave, listaNombres[i]) != NULL){
            return listaNombres[i];
        }
    }
    return "-1";
}