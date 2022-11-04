/*
Proyecto final de Programacion 1.
Alumnos: Corradi Joaquin I, Borletto Martina.
*/

#include <iostream>
#include <fstream>

struct competidor
{
  int numeroDeInscripcion;
  std::string nombre;
  int categoria, subcategoria;
  int tirosCentro, tirosNoCentro;
};

void menu(int &opcion);
void asignar(competidor datos[20]);
void opcion1(competidor datos[20]);
void opcion2(competidor datos[20], int puntajes[20]);
void opcion4(competidor datos[20], int puntajes[20]);

int main()
{
  int opcion = 1;
  competidor datos[20];
  asignar(datos);
  int puntajes[20];
  opcion4(datos, puntajes);
}

void menu(int &opcion)
{
  std::cout << "\tMENU PRINCIPAL:" << '\n';
  std::cout << "\t\t1. Mostrar competidores inscriptos." << '\n'; //terminada y chequeada
  std::cout << "\t\t2. Mostrar puntaje de competidores." << '\n'; //terminada y chequeada
  std::cout << "\t\t3. Exportar puntajes (.txt)" << '\n'; //falta hacer
  std::cout << "\t\t4. Filtrar competidores por un puntaje maximo." << '\n'; //terminado y chequeado, no a prueba de usuario tonto
  std::cout << "\t\t5. Mostrar cantidad de competidores por categoria y subcategoria." << '\n'; //falta hacer
  std::cout << "\t\t6. Salir." << '\n';
  std::cout << "\tSeleccione una opcion (1 - 6): " << '\n';
  std::cin >> opcion; 
}

void asignar(competidor datos[20])
{
  std::ifstream inscriptos("inscriptos.txt");
  std::string tmp;
  for (int i = 0; i < 8; ++i)
  {
    inscriptos >> tmp;
  }
  for (int i = 0; i < 20; ++i)   
  {
    inscriptos >> datos[i].numeroDeInscripcion;
    inscriptos >> datos[i].nombre;
    inscriptos >> datos[i].categoria;
    inscriptos >> datos[i].subcategoria;
    inscriptos >> datos[i].tirosCentro;
    inscriptos >> datos[i].tirosNoCentro;
  }
  inscriptos.close();
 }


void opcion1(competidor datos[20])
{
  std::cout << '\n';
  std::cout << "Los competidores inscriptos son los siguientes: ";
  std::cout << '\n';
  for (int i = 0; i <= 20; ++i)
  {
    std::cout << datos[i].nombre << '\n';
  }
}

void opcion2(competidor datos[20], int puntajes[20])
{
  int suma;
  std::cout << '\n';
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    std::cout << "El competidor " << datos[i].nombre << " tiene " << suma << " puntos." << '\n';
    puntajes[i] = suma;
    suma = 0;
  }
  std::cout << '\n';
}

void opcion4(competidor datos[20], int puntajes[20])
{
  int suma;
  int puntaje;
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    puntajes[i] = suma;
    suma = 0;
  }
  std::cout << '\n';
  std::cout << "Ingrese el puntaje maximo por el que desea filtrar: ";
  std::cin >> puntaje;
  std::cout << "Los competidores por encima de " << puntaje << " puntos son:" << '\n';
  std::cout << '\n';
  for (int i = 0; i < 20; ++i)
  {
    if (puntajes[i] >= puntaje)
    {
      std::cout << datos[i].nombre << " con " << puntajes[i] << " puntos." << '\n';
    }
  }
  std::cout << '\n';
}