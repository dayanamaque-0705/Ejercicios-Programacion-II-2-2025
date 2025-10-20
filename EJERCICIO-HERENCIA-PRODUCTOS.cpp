// EJERCICIO-HERENCIA-PRODUCTOS.cpp : Este archivo contiene la funcion "main". La ejecucion del programa comienza y termina ahi.
//

#include <iostream>
using namespace std;

class Producto {
protected:
    string nombre;
    string descripcion;
    float precioBase;
    int garantia;
    bool disponible;
public:
    Producto(string nombre, string descripcion, float precioBase, int garantia, bool disponible) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->precioBase = precioBase;
        this->garantia = garantia;
        this->disponible = disponible;
    }
    ~Producto() {}
    void consultarDetalles() {
        cout << "Nombre: " << nombre << ", Descripcion: " << descripcion << ", Precio: " << precioBase << endl;
    }
    void aplicarDescuento() {}
    float calcularPrecioFinal() { return precioBase; }
};

class Electrodomestico : public Producto {
private:
    float descuento;
    float costoEnvio;
public:
    Electrodomestico(string nombre, string descripcion, float precioBase, int garantia, bool disponible)
        : Producto(nombre, descripcion, precioBase, garantia, disponible) {
        descuento = 0.0;
        costoEnvio = 20.0;
    }
    void aplicarDescuento() {
        descuento = 0.15;
        cout << "Aplicando descuento del 15% a " << nombre << endl;
    }
    float calcularPrecioFinal() {
        float precioConDescuento = precioBase - (precioBase * descuento);
        if (precioConDescuento > 500) {
            costoEnvio = 0.0;
        }
        if (costoEnvio == 0.0) {
            cout << "Envio gratis para " << nombre << endl;
        }
        else {
            cout << "Costo de envio de $" << costoEnvio << " para " << nombre << endl;
        }
        return precioConDescuento + costoEnvio;
    }
};

class Ropa : public Producto {
private:
    float descuento;
public:
    Ropa(string nombre, string descripcion, float precioBase, int garantia, bool disponible)
        : Producto(nombre, descripcion, precioBase, garantia, disponible) {
        descuento = 0.0;
    }
    void aplicarDescuento() {
        descuento = 0.10;
        cout << "Aplicando descuento del 10% a " << nombre << endl;
    }
    float calcularPrecioFinal() {
        float precioConDescuento = precioBase - (precioBase * descuento);
        cout << "Envio gratis para " << nombre << endl;
        return precioConDescuento;
    }
};

class Libro : public Producto {
private:
    float descuento;
    float costoEnvio;
    int cantidad;
public:
    Libro(string nombre, string descripcion, float precioBase, int garantia, bool disponible, int cantidad = 1)
        : Producto(nombre, descripcion, precioBase, garantia, disponible) {
        descuento = 0.05;
        costoEnvio = 5.0;
        this->cantidad = cantidad;
    }
    void aplicarDescuento() {
        cout << "Aplicando descuento del 5% a " << nombre << endl;
    }
    float calcularPrecioFinal() {
        float precioConDescuento = precioBase - (precioBase * descuento);
        if (cantidad > 3) {
            costoEnvio = 0.0;
        }
        if (costoEnvio == 0.0) {
            cout << "Envio gratis para " << nombre << endl;
        }
        else {
            cout << "Costo de envio de $" << costoEnvio << " para " << nombre << endl;
        }
        return (precioConDescuento * cantidad) + costoEnvio;
    }
};

class ListaProductos {
private:
    Producto** productos;
    int contador;
    int capacidad;
public:
    ListaProductos() {
        capacidad = 10;
        contador = 0;
        productos = new Producto * [capacidad];
    }
    void agregar_producto(Producto* producto) {
        if (contador < capacidad) {
            productos[contador] = producto;
            contador++;
        }
    }
    void mostrar_productos() {
        for (int i = 0; i < contador; i++) {
            productos[i]->consultarDetalles();
            productos[i]->aplicarDescuento();
            float precioFinal = productos[i]->calcularPrecioFinal();
            cout << "Precio Final: " << precioFinal << endl << endl;
        }
    }
    ~ListaProductos() {
        for (int i = 0; i < contador; i++) {
            delete productos[i];
        }
        delete[] productos;
    }
};

int main() {
    ListaProductos* lista = new ListaProductos();

    lista->agregar_producto(new Electrodomestico("Lavadora", "Lavadora de carga frontal", 350, 2, true));
    lista->agregar_producto(new Ropa("Camiseta", "Camiseta de algodon", 20, 1, true));
    lista->agregar_producto(new Libro("El Gran Gatsby", "Novela clasica de Scott Fitzgerald", 15, 30, true));

    lista->mostrar_productos();

    delete lista;
    return 0;
}
