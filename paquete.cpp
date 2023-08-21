#include "paquete.h"

using namespace std;

Paquete::Paquete() : id(0), origen(""), destino(""), peso(0.0) {}

Paquete::Paquete(int i, const std::string& o, const std::string& d, float p)
    : id(i), origen(o), destino(d), peso(p) {}

void Paquete::setID(const int& i)
{
    id = i;
}

void Paquete::setOrigen(const std::string& o)
{
    origen = o;
}

void Paquete::setDestino(const std::string& d)
{
    destino = d;
}

void Paquete::setPeso(const float& p)
{
    peso = p;
}

int Paquete::getId() const
{
    return id;
}

string Paquete::getOrigen() const
{
    return origen;
}

string Paquete::getDestino() const
{
    return destino;
}

float Paquete::getPeso() const
{
    return peso;
}

string Paquete::toString() const {
    string result;
    result =  "ID: "+ to_string(id) + " || " + "Origen: " + origen + " || " + "Destino: " + destino + " || " + "Peso: " + to_string(peso);

    return result;
}

std::istream& operator>>(std::istream& is, Paquete& paquete) {
    is >> paquete.id >> paquete.origen >> paquete.destino >> paquete.peso;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Paquete& paquete) {
    os << paquete.id, os <<paquete.origen, os <<paquete.destino, os <<paquete.peso;
    return os;
}

