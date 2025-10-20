// EJERCICIO-HERENCIA-CLINICA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Paciente {
protected:
    string nombre;
    int edad;
    
public:
    Paciente(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    ~Paciente() {}
    string getNombre() {
        return nombre;
    }
    int getEdad() { 
        return edad;
    }
    float calcularDescuento() { 
        return 0;
    }
};

class Externo : public Paciente {
public:
    Externo(string nombre, int edad) : Paciente(nombre, edad) {
    }
    float calcularDescuento() {
        if (edad > 80) {
            return 0.50; 
        }
        if (edad > 65) { 
            return 0.20; 
        }
        return 0.0f;
    }
};

class Asegurado : public Paciente {
public:
    Asegurado(string nombre, int edad) : Paciente(nombre, edad) {
    }
    float calcularDescuento() {
        if (edad < 5 || edad > 50) { 
            return 0.80;
        }
        return 0.50;
    }
};

class Atencion {
protected:
    string fecha;
    int hora;
    Paciente* paciente;
public:
    Atencion(string fecha, int hora, Paciente* paciente) {
        this->fecha = fecha;
        this->hora = hora;
        this->paciente = paciente;
    }
    ~Atencion() {}
    string getFecha() { 
        return fecha; 
    }
    float calcularCostoConsulta() { 
        return 0; 
    }
};

class EnClinica : public Atencion {
public:
    EnClinica(string fecha, int hora, Paciente* paciente) : Atencion(fecha, hora, paciente) {
    }
    float calcularCostoConsulta() {
        int base = 0;
        if (hora >= 8 && hora < 24) { 
            base = 100; 
        }
        else { base = 200; }
        float desc = paciente->calcularDescuento();
        int costoFinal = base - (base * desc);
        return costoFinal;
    }
};

class ADomicilio : public Atencion {
public:
    ADomicilio(string fecha, int hora, Paciente* paciente) : Atencion(fecha, hora, paciente) {
    }
    float calcularCostoConsulta() {
        int base = 0;
        if (hora >= 8 && hora < 18) { 
            base = 250; 
        }
        else { base = 500; }
        float desc = paciente->calcularDescuento();
        int costoFinal = base - (base * desc);
        return costoFinal;
    }
};

class ListaPacientes {
private:
    Paciente** pacientes;
    int contador;
    int capacidad;
public:
    ListaPacientes() {
        capacidad = 10;
        contador = 0;
        pacientes = new Paciente * [capacidad];
    }
    void agregar(Paciente* p) {
        if (contador < capacidad) {
            pacientes[contador] = p;
            contador++;
        }
    }
    void mostrarOrdenados() {
        for (int i = 0; i < contador - 1; i++) {
            for (int j = i + 1; j < contador; j++) {
                if (pacientes[i]->getNombre() > pacientes[j]->getNombre()) {
                    Paciente* temp = pacientes[i];
                    pacientes[i] = pacientes[j];
                    pacientes[j] = temp;
                }
            }
        }
        for (int i = 0; i < contador; i++) {
            cout << pacientes[i]->getNombre() << " - Edad: " << pacientes[i]->getEdad() << endl;
        }
    }
    Paciente* buscarPorNombre(string nombre) {
        for (int i = 0; i < contador; i++) {
            if (pacientes[i]->getNombre() == nombre) {
                return pacientes[i];
            }
        }
        return NULL;
    }
    ~ListaPacientes() {
        for (int i = 0; i < contador; i++) {
            delete pacientes[i];
        }
        delete[] pacientes;
    }
};

class ListaAtenciones {
private:
    Atencion** atenciones;
    int contador;
    int capacidad;
public:
    ListaAtenciones() {
        capacidad = 10;
        contador = 0;
        atenciones = new Atencion * [capacidad];
    }
    void agregar(Atencion* a) {
        if (contador < capacidad) {
            atenciones[contador] = a;
            contador++;
        }
    }
    void mostrarPorFecha() {
        for (int i = 0; i < contador - 1; i++) {
            for (int j = i + 1; j < contador; j++) {
                if (atenciones[i]->getFecha() > atenciones[j]->getFecha()) {
                    Atencion* temp = atenciones[i];
                    atenciones[i] = atenciones[j];
                    atenciones[j] = temp;
                }
            }
        }
        for (int i = 0; i < contador; i++) {
            cout << "Fecha: " << atenciones[i]->getFecha()
                << " - Costo: " << atenciones[i]->calcularCostoConsulta() << endl;
        }
    }
    ~ListaAtenciones() {
        for (int i = 0; i < contador; i++) {
            delete atenciones[i];
        }
        delete[] atenciones;
    }
};

int main() {
    ListaPacientes* listaPac = new ListaPacientes();
    ListaAtenciones* listaAt = new ListaAtenciones();

    listaPac->agregar(new Asegurado("Maria", 45));
    listaPac->agregar(new Asegurado("Pedro", 20));
    listaPac->agregar(new Externo("Luis", 85));

    cout << "Pacientes asegurados ordenados:" << endl;
    listaPac->mostrarOrdenados();
    cout << endl;

    Paciente* p1 = listaPac->buscarPorNombre("Maria");
    Paciente* p2 = listaPac->buscarPorNombre("Pedro");
    Paciente* p3 = listaPac->buscarPorNombre("Luis");

    listaAt->agregar(new EnClinica("2025-10-05", 10, p1));
    listaAt->agregar(new ADomicilio("2025-10-03", 19, p2));
    listaAt->agregar(new EnClinica("2025-10-01", 2, p3));

    cout << "Atenciones ordenadas por fecha:" << endl;
    listaAt->mostrarPorFecha();

    delete listaPac;
    delete listaAt;
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
