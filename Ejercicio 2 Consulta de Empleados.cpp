//Segundo Examen Parcial Dylan Reyes | 5090-23-1228 | 17/04/2024

//Variante A Ejercicio 2: Consulta de Empleados

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para buscar y mostrar información de un empleado
void consultarEmpleado(ifstream& archivo, const string& nombreCompleto) {
    string linea;
    bool encontrado = false;

    while (getline(archivo, linea)) {
        size_t pos = linea.find(nombreCompleto);
        if (pos != string::npos) {
            cout << "Información del empleado:" << endl;
            cout << linea << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Empleado no encontrado." << endl;
    }
}

int main() {
    ifstream archivoEntrada("empleados.txt");

    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    cout << "Consulta de Empleados" << endl;
    cout << "Ingrese el nombre completo del empleado a consultar: ";
    string nombreCompleto;
    cin.ignore(); // Limpiar el buffer
    getline(cin, nombreCompleto);

    consultarEmpleado(archivoEntrada, nombreCompleto);

    archivoEntrada.close();

    return 0;
}

