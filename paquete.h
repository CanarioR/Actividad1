#ifndef PAQUETE_H_INCLUDED
#define PAQUETE_H_INCLUDED
#include <iostream>
#include <string>

class Paquete{
private:
    int id;
    std::string origen, destino;
    float peso;
public:
    Paquete();
    Paquete(int i, const std::string& o, const std::string& d, float p);
    //setters de los atributos
    void setID(const int&);
    void setOrigen(const std::string&);
    void setDestino(const std::string&);
    void setPeso(const float&);
    //getters de los atributos
    int getId() const;
    std::string getOrigen() const;
    std::string getDestino()const;
    std::string toString() const;
    float getPeso() const;
    Paquete& operator=(const Paquete&);
    friend std::istream& operator>>(std::istream& is, Paquete& paquete);
    friend std::ostream& operator<<(std::ostream& os, const Paquete& paquete);
};

#endif // PAQUETE_H_INCLUDED

