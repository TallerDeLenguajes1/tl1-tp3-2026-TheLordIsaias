#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define N 50

char *TiposProductos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct{
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
                    // “CantidadProductosAPedir”
} Cliente;

void cargaClientes(Cliente *clientes, int cantClientes);
float calcularCostoPorProducto(Producto producto);
void mostrarDatosCargados(Cliente *clientes, int cargaClientes);

int main(){
    srand(time(NULL));
    Cliente *clientes;
    int cantClientes = -1;
    do {
        printf("Ingrese una cantidad de clientes entre 1 y 5: ");
        fflush(stdin);
        scanf("%d", &cantClientes);
    } while (cantClientes < 1 || cantClientes > 5);
    getchar();
    clientes = (Cliente *) malloc(sizeof(Cliente) * cantClientes);
    cargaClientes(clientes, cantClientes);
    mostrarDatosCargados(clientes, cantClientes);
    
}

void cargaClientes(Cliente *clientes, int cantClientes){
    for (int i = 0; i < cantClientes; i++){
        clientes[i].ClienteID = i;
        printf("\nIngrese el nombre del cliente N#%d: ", i+1);
        clientes[i].NombreCliente = malloc(sizeof(char) * N);
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
        
    }
}

float calcularCostoPorProducto(Producto producto){
    float costoTotal = producto.Cantidad * producto.PrecioUnitario;
    return costoTotal;
}

void mostrarDatosCargados(Cliente *clientes, int cargaClientes){
    float totalAPagar;
    for (int i = 0; i < cargaClientes; i++){
        totalAPagar = 0;
        printf("\n\n\n---Cliente ID: %d---", clientes[i].ClienteID);
        printf("\nNombre del cliente: ");
        puts(clientes[i].NombreCliente);
        printf("Cantidad de productos pedidos: %d", clientes[i].CantidadProductosAPedir);
        printf("\n\n-- Productos Pedidos --");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            printf("\n- Producto #%d -", clientes[i].Productos[j].ProductoID + 1);
            printf("\nCantidad de unidades: %d", clientes[i].Productos[j].Cantidad);
            printf("\nTipo de producto: ");
            puts(clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f", clientes[i].Productos[j].PrecioUnitario);
            totalAPagar += calcularCostoPorProducto(clientes[i].Productos[j]);
        }
        printf("\n\nTotal a pagar por el cliente: %.2f", totalAPagar);
        printf("\n\n\n-----------------------------------");
    }
}