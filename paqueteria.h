#ifndef PAQUETERIA_H
#define PAQUETERIA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

template <typename T>
class Paqueteria
{
private:
    struct Nodo
    {
        T dato;
        Nodo* siguiente;
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* cabeza;

public:
    Paqueteria();
    ~Paqueteria();

    void agregarAlInicio(const T& valor);
    void eliminarAlInicio();
    void mostrarContenido();
    void guardarEnArchivo(const std::string& nombreArchivo) const;
    void recuperarDeArchivo(const std::string& nombreArchivo);

    friend std::istream& operator>>(std::istream& is, Paqueteria<T>& paquete)
    {
        T valor;
        is >> valor;
        paquete.agregarAlInicio(valor);
        return is;
    }
};

//implemetnación

using namespace std;

template <typename T>
Paqueteria<T>::Paqueteria() : cabeza(nullptr) {}

template <typename T>
Paqueteria<T>::~Paqueteria()
{
    while (cabeza)
    {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

template <typename T>
void Paqueteria<T>::agregarAlInicio(const T& valor)
{
    Nodo* nuevoNodo = new Nodo(valor);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

template <typename T>
void Paqueteria<T>::eliminarAlInicio()
{
    if (cabeza)
    {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

template <class T>
void Paqueteria<T>::mostrarContenido()
{
    Nodo* temp = cabeza;
    while (temp)
    {
        std::cout << temp->dato.toString() + "\n";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

template <typename T>
void Paqueteria<T>::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        Nodo* actual = cabeza;
        while (actual) {
            archivo << actual->dato.getId() << " "
                    << actual->dato.getOrigen() << " "
                    << actual->dato.getDestino() << " "
                    << actual->dato.getPeso() << "\n";
            actual = actual->siguiente;
        }
        archivo.close();
        std::cout << "Datos guardados en el archivo." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}



template <typename T>
void Paqueteria<T>::recuperarDeArchivo(const std::string& nombreArchivo)
{
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        while (cabeza)
        {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }

        std::string linea;
        while (std::getline(archivo, linea))
        {
            std::istringstream iss(linea);
            int id;
            std::string origen, destino;
            float peso;
            iss >> id >> origen >> destino >> peso;
            Paquete paquete(id, origen, destino, peso);
            agregarAlInicio(paquete);
        }


        archivo.close();
    }
    else
    {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
    }
}

#endif //PAQUETERIA_H
