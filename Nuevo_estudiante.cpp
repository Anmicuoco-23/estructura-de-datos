#include <iostream>
#include <cstdlib> // para malloc y free

using namespace std;

// Estructura para representar a un estudiante en la lista enlazada
struct Estudiante {
    char nombre[50];
    int codigo;
    float nota;
    Estudiante* sig; // apuntador al siguiente nodo en la lista
};

Estudiante *cab, *aux, *aux2;

// funcion para crear un nuevo estudiante
Estudiante* nuevoRegistroEstudiante() {
    Estudiante* aux = (Estudiante*) malloc(sizeof(Estudiante));

    // comprobamos si malloc fallo en asignar memoria
    if (aux == nullptr) {
        cout << "Error al asignar memoria" << endl;
        exit(1); // finaliza el programa en caso de error
    }

    // ingresar los datos del estudiante
    cout << "Ingrese el primer nombre del estudiante: ";
    cin >> aux->nombre;

    cout << "Ingrese el codigo estudiantil: ";
    cin >> aux->codigo;

    cout << "Ingrese la nota del estudiante: ";
    cin >> aux->nota;

    aux->sig = nullptr; // el nuevo nodo apunta a nada por ahora

    return aux; // devolvemos el nuevo nodo
}

// funcion para agregar un nuevo estudiante al final de la lista
void agregarEstudiante(Estudiante*& cab) {
    Estudiante* aux = nuevoRegistroEstudiante(); // creamos al nuevo estudiante

    if (cab == nullptr) {
        // si la lista esta vacia, el nuevo estudiante es el primero
        cab = aux;
    } else {
        // si no esta vacia, recorremos la lista hasta el final
        Estudiante* aux2 = cab;
        while (aux2->sig != nullptr) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux; // enlazamos al nuevo estudiante al final
    }

    cout << "Estudiante agregado correctamente." << endl;
}

// funcion para mostrar la lista de estudiantes
void mostrarEstudiantes(Estudiante* cab) {
    if (cab == nullptr) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    Estudiante* aux = cab;
    cout << "\n===== Lista de Estudiantes =====" << endl;
    while (aux != nullptr) {
        // aqui simplemente mostramos cada estudiante en la lista
        cout << "Nombre: " << aux->nombre 
             << ", Codigo: " << aux->codigo 
             << ", Nota: " << aux->nota << endl;
        aux = aux->sig;
    }
}

// funcion de burbuja para ordenar estudiantes por codigo
void ordenarPorCodigo(Estudiante* cab) {
    if (cab == nullptr) return; // si la lista esta vacia, no hacemos nada

    bool huboIntercambio;
    do {
        huboIntercambio = false;
        Estudiante* aux = cab;
        Estudiante* sig = nullptr;

        while (aux->sig != nullptr) {
            sig = aux->sig;
            if (aux->codigo > sig->codigo) {
                // intercambiamos los estudiantes si el codigo es mayor
                swap(*aux, *sig);
                swap(aux->sig, sig->sig);
                huboIntercambio = true;
            }
            aux = aux->sig;
        }
    } while (huboIntercambio);
}

// funcion de burbuja para ordenar por nota
void ordenarPorNota(Estudiante* cab) {
    if (cab == nullptr) return;

    bool huboIntercambio;
    do {
        huboIntercambio = false;
        Estudiante* aux = cab;
        Estudiante* sig = nullptr;

        while (aux->sig != nullptr) {
            sig = aux->sig;
            if (aux->nota < sig->nota) {
                // aqui ordenamos de mayor a menor
                swap(*aux, *sig);
                swap(aux->sig, sig->sig);
                huboIntercambio = true;
            }
            aux = aux->sig;
        }
    } while (huboIntercambio);
}

// funcion para mostrar estadisticas del curso: mayor, menor y promedio de notas
void mostrarEstadisticas(Estudiante* cab) {
    if (cab == nullptr) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    // vamos a recorrer la lista para sacar la mayor nota, la menor, y calcular el promedio
    float sumaNotas = 0;
    float mayorNota = cab->nota;
    float menorNota = cab->nota;
    int totalEstudiantes = 0;

    Estudiante* aux = cab;
    
    while (aux != nullptr) {
        sumaNotas += aux->nota;
        if (aux->nota > mayorNota) {
            mayorNota = aux->nota; // actualizamos si encontramos una nota mayor
        }
        if (aux->nota < menorNota) {
            menorNota = aux->nota; // lo mismo para la menor
        }
        totalEstudiantes++;
        aux = aux->sig;
    }
    
    float promedio = sumaNotas / totalEstudiantes;

    cout << "\n===== Estadisticas del Curso =====" << endl;
    cout << "Mayor Nota: " << mayorNota << endl;
    cout << "Menor Nota: " << menorNota << endl;
    cout << "Promedio de Notas: " << promedio << endl;
}

// funcion para liberar la memoria al final
void liberarMemoria(Estudiante*& cab) {
    Estudiante* aux = cab;
    while (aux != nullptr) {
        Estudiante* aux2 = aux->sig;
        free(aux); // liberamos la memoria de cada nodo
        aux = aux2;
    }
    cab = nullptr;
}

// menu principal con las opciones disponibles
void mostrarMenu() {
    cout << "\n===== Menu =====" << endl;
    cout << "1. Ingresar datos de estudiantes" << endl;
    cout << "2. Ordenar y mostrar la lista de estudiantes" << endl;
    cout << "3. Mostrar la mayor nota, menor nota y promedio del curso" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Estudiante* cab = nullptr; // lista de estudiantes vacia inicialmente
    int opcion;
    int subopcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEstudiante(cab); // llamamos para agregar un nuevo estudiante
                break;
            case 2:
                cout << "\nSeleccione como desea ordenar la lista: " << endl;
                cout << "1. Ordenar por Codigo Estudiantil (menor a mayor)" << endl;
                cout << "2. Ordenar por Nota (mayor a menor)" << endl;
                cout << "Seleccione una opcion: ";
                cin >> subopcion;

                if (subopcion == 1) {
                    ordenarPorCodigo(cab); // ordenamos por codigo
                    cout << "Estudiantes ordenados por Codigo Estudiantil." << endl;
                } else if (subopcion == 2) {
                    ordenarPorNota(cab); // ordenamos por nota
                    cout << "Estudiantes ordenados por Nota." << endl;
                } else {
                    cout << "Opcion no valida." << endl;
                }
                mostrarEstudiantes(cab); // mostramos la lista ya ordenada
                break;
            case 3:
                mostrarEstadisticas(cab); // calculamos y mostramos las estadisticas
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);

    liberarMemoria(cab); // liberamos la memoria antes de salir

    return 0;
}
