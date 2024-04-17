//Segundo Examen Parcial Dylan Reyes | 5090-23-1228 | 17/04/2024

//Variante A Ejercicio 1: Registro de Empleados

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Creación de la clase Empleado
class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    double salario;

public:
    // Constructor
    Empleado(string n, string a, int e, double s) {
        nombre = n;
        apellido = a;
        edad = e;
        salario = s;
    }

    // Métodos para obtener valores del empleado
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    int getEdad() { return edad; }
    double getSalario() { return salario; }
};

// Función para guardar datos en el archivo
void guardarEmpleado(ofstream& archivo, Empleado& emp) {
    archivo << emp.getNombre() << "," << emp.getApellido() << ","
            << emp.getEdad() << "," << emp.getSalario() << endl;
}

int main() {
    ofstream archivoSalida("empleados.txt", ios::app); // Modo de apertura: agregar al final

    if (!archivoSalida) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    cout << "----Registro de Empleados----" << endl;
    cout << "Ingrese los datos de los empleados (nombre, apellido, edad, salario)." << endl;
    cout << "Escriba 'salir' para finalizar." << endl;

    while (true) {
        string nombre, apellido;
        int edad;
        double salario;

        cout << "Nombre: ";
        cin >> nombre;
        if (nombre == "salir") {
            break;
        }

        cout << "Apellido: ";
        cin >> apellido;
        cout << "Edad: ";
        cin >> edad;
        cout << "Salario: ";
        cin >> salario;

        Empleado empleado(nombre, apellido, edad, salario);
        guardarEmpleado(archivoSalida, empleado);
    }

    archivoSalida.close();

    return 0;
}

