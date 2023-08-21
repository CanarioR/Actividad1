#include <iostream>
#include <string>
#include "paquete.h"
#include "paqueteria.h"

using namespace std;

int main()
{
    Paquete paquete;
    Paqueteria<Paquete> paqueteria;
    int opc, id, pos = 0 ,p;
    float peso;
    string origen, destino, nombreArchivo;
    char op;

    do
    {
        system("cls");
        cout<<"\tMENU"<<endl;
        cout<<"<1>Agregar paquete"<<endl;
        cout<<"<2> Eliminar paquete"<<endl;
        cout<<"<3> Mostrar"<<endl;
        cout<<"<4> Guardar informacion"<<endl;
        cout<<"<5> Recuperar informacion"<<endl;
        cout<<"<0> SALIR"<<endl;
        cout<<"Elija una opcion\n>>> ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 0:
            cout<<"Saliendo..."<<endl;
            break;
        case 1:
            cout<<"Ingrese los datos del paquete..."<<endl;
            cout<<"ID: "; cin>> id;
            cin.ignore();
            cout<<"Origen: "; getline(cin, origen);
            cout<<"Destino: "; getline(cin, destino);
            cout<<"Peso: "; cin>>peso;

            paquete.setID(id);
            paquete.setOrigen(origen);
            paquete.setDestino(destino);
            paquete.setPeso(peso);
            paqueteria.agregarAlInicio(paquete);
            system("pause");
            break;
        case 2:
            cout<<"Estas seguro de eliminar el primer paquete?"<<endl;
            cout<<"(S/N) ? "; cin>>op;
            if(op == 'S'){ paqueteria.eliminarAlInicio(); cout<<"Paquete Eliminado\n";}else{break;}
            system("pause");
            break;
        case 3:
            cout<<"LISTA DE PAQUETES"<<endl;
            paqueteria.mostrarContenido();
            system("pause");
            break;
        case 4:
            cout<<"Ingrese el nombre del archivo: "; cin>> nombreArchivo;
            cout<<"Guardando archivos..."<<endl;
            paqueteria.guardarEnArchivo(nombreArchivo);
            system("pause");
            break;
        case 5:
            cout<<"Ingrese el nombre del archivo: "; cin>> nombreArchivo;
            cout<<"Restaurando archivos..."<<endl;
            paqueteria.recuperarDeArchivo(nombreArchivo);
            cout<<"INFORMACION DEL ARCHIVO"<<endl;
            paqueteria.mostrarContenido();
            system("pause");
            break;
        default:
            cout<<"Ingrese una opcion valida."<<endl;
        }
    }
    while(opc!=0);

        return 0;
}
