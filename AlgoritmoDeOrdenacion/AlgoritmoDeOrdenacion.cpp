// AlgoritmoDeOrdenacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Algoritmo de odenacion Heap Sort-------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Si el hijo izquierdo existe y es mayor que el nodo actual, actualizamos largest
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // Si el hijo derecho existe y es mayor que el nodo actual (o el izquierdo), actualizamos largest
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // Si el nodo mas grande no es la raiz, intercambiamos y continuamos heapificando recursivamente
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // FASE 1: Construir el Max-Heap inicial
    // Empezamos desde el ultimo nodo no hoja (size/2 - 1) hasta la raiz
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    // FASE 2: Extraer elementos del heap uno por uno
    for (int i = size - 1; i >= 0; --i) {
        // Movemos la raiz (elemento maximo) al final del array
        swap(arr[0], arr[i]);

        // Reducimos el tamanio del heap y restauramos la propiedad de Max-Heap
        heapify(arr, i, 0);
    }
}

// Funcion que recorrre el array y lo imprime
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 54, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Lista original: ";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Lista ordenada: ";
    printArray(arr, size);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
