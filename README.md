#include <iostream> 
#include
using namespace std; 

struct Pasajero {
    char nombre[50];
    int documento;
    int destino; // 1: La Bocana, 2: Piangüita, 3: Ladrilleros
    struct Pasajero* siguiente;
} Pasajero;

Pasajero* crearPasajero(char* nombre, int documento, int destino) {
    Pasajero* nuevoPasajero = (Pasajero*)malloc(sizeof(Pasajero));
    if (nuevoPasajero != NULL) {
        strcpy(nuevoPasajero->nombre, nombre);
        nuevoPasajero->documento = documento;
        nuevoPasajero->destino = destino;
        nuevoPasajero->siguiente = NULL;
    }
    return nuevoPasajero;
}

int registrarPasajero(Pasajero** cabeza) {
    char nombre[50];
    int documento, destino;

    cout << "Ingrese el nombre del pasajero: " << endl;
    cout << "Ingrese el número de documento: ";
    cout << "Ingrese el destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ";
    

    Pasajero* nuevoPasajero = crearPasajero(nombre, documento, destino);
    if (*cabeza == NULL) {
        *cabeza = nuevoPasajero;
    } else {
        Pasajero* temp = *cabeza;
        while (aux->sig != null) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoPasajero;
    }
    cout("Pasajero registrado con éxito.\n");
}

int mostrarPasajeros(Pasajero* cabeza) {
    if (cabeza == NULL) {
        cout <<"No hay pasajeros registrados." << endl;
        return;
    }

    cout << "\n===== Lista de Pasajeros =====" << endl;
    while (aux->sig != null) {


        while (aux != nullptr) {
        // aqui simplemente mostramos cada estudiante en la lista
        cout << "Nombre: " << aux->nombre 
             << "Documento: " << aux->documento
             << "Destino: " << aux->destino << endl;
        aux = aux->sig;
    }
}


int ordenarPasajeros(Pasajero** cabeza) {
    if (*cabeza == NULL || (*cabeza)->siguiente == NULL) {
        return; // No hay nada que ordenar
    }

    Pasajero* temp;
    Pasajero* a;
    Pasajero* b;
    int swapped;

    do {
        swapped = 0;
        a = *cabeza;
        while (a->siguiente != NULL) {
            b = a->siguiente;
            if (a->destino > b->destino || (a->destino == b->destino && a->documento > b->documento)) {
                // Intercambiar a y b
                char nombreTemp[50];
                int docTemp, destTemp;

                // Intercambiar nombres
                strcpy(nombreTemp, a->nombre);
                strcpy(a->nombre, b->nombre);
                strcpy(b->nombre, nombreTemp);

                // Intercambiar documentos
                docTemp = a->documento;
                a->documento = b->documento;
                b->documento = docTemp;

                // Intercambiar destinos
                destTemp = a->destino;
                a->destino = b->destino;
                b->destino = destTemp;

                swapped = 1;
            }
            a = a->siguiente;
        }
    } while (aux2->sig != nullptr) {

int liberarMemoria(Pasajero* cabeza) {
    Pasajero* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp); 
    }
}

int main() {
    string nombre, documento, destino;
    int opcion;
    bool datosRegistrados = false;

    do { 
        cout << "----- Menu de Agenda -" << endl;
        cout<< "1. Registrar pasajeros" << endl;
        cout<< "2. Mostrar pasajeros" <<endl;
        cout<< "3. Ordenar pasajeros" <<endl;
        cout<< "4. Salir" << endl;
        cout<< "Seleccione una opción
        cin >>opcion;

        switch (opcion) {
            case 1:
                registrarPasajero(cab);
                break;
            case 2:
                mostrarPasajeros(cab);
                break;
            case 3:
                ordenarPasajeros(cab);
                cout("Pasajeros ordenados.\n");
                break;
            case 4:
                cout << "Saliendo del programa." <<endl;
                break;
            default:
                cout <<"Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    liberarMemoria(listaPasajeros);
    return 0;
}
