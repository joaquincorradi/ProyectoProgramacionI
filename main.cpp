/*
Proyecto final de Programacion 1.
Alumnos: Corradi Joaquin I, Borletto Martina.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

struct competidor
{
  int numeroDeInscripcion;
  std::string nombre;
  int categoria, subcategoria;
  int tirosCentro, tirosNoCentro;
};

void asignar(competidor datos[20]); //terminada y chequeada
void menu(int &opcion); //terminada y chequeada
void opcion1(competidor datos[20]); //terminada y chequeada
void opcion2(competidor datos[20], int puntajes[20]); //terminada y chequeada
void opcion3(); //sin empezar
void opcion4(competidor datos[20], int puntajes[20]); //terminada y chequeada
void opcion5(competidor datos[20], int categoriasMatrix[3][3]); //terminada, faltan detalles de formato en la impresion de la matriz
void inicializarMenu(); //sin empezar

int main()
{
  competidor datos[20];
  int opcion = 1;
  asignar(datos);
  int puntajes[20];
  int categoriasMatrix[3][3];
  opcion5(datos, categoriasMatrix);
}

void asignar(competidor datos[20])
{
  std::ifstream inscriptos("inscriptos.txt");
  std::string tmp;
  if (!inscriptos.is_open())
  {
    std::cout << "Error al abrir inscriptos.txt" << '\n';
    exit(EXIT_FAILURE);
  }
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

void menu(int &opcion)
{
  std::cout << '\n';
  std::cout << "MENU PRINCIPAL:" << '\n';
  std::cout << "\t1. Mostrar competidores inscriptos." << '\n';
  std::cout << "\t2. Mostrar puntaje de competidores." << '\n';
  std::cout << "\t3. Exportar puntajes (.txt)" << '\n';
  std::cout << "\t4. Filtrar competidores por un puntaje maximo." << '\n';
  std::cout << "\t5. Mostrar cantidad de competidores por categoria y subcategoria." << '\n';
  std::cout << "\t6. Salir." << '\n';
  std::cout << "\tSeleccione una opcion [1 - 6]: ";
  std::cin >> opcion; 
}

void opcion1(competidor datos[20])
{
  std::cout << '\n';
  std::cout << "Los competidores inscriptos son los siguientes: " << '\n';
  std::cout << '\n';
  for (int i = 0; i < 20; ++i)
  {
    std::cout << datos[i].nombre << " con numero de inscripcion " << datos[i].numeroDeInscripcion << '\n';
  }
  std::cout << '\n';
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
  int mayor = puntajes[0]; //es necesario asignarle el primer valor del array a esta variable para que funcione pero no se por que
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    puntajes[i] = suma;
    suma = 0;
  }
  for (int j = 0; j < 20; ++j)
  {
    if (puntajes[j] > mayor)
    {
      mayor = puntajes[j];
    }
  }
  std::cout << '\n';
  std::cout << "Ingrese el puntaje maximo por el que desea filtrar: ";
  std::cin >> puntaje;
  if (puntaje > mayor)
  {
    std::cout << "No hay competidores con puntaje mayor a " << puntaje << '\n';
  }
  else if (puntaje < 0)
  {
    std::cout << "El valor ingresado no es valido." << '\n';
  }
  else
  {
    std::cout << "Los competidores por encima de " << puntaje << " puntos son:" << '\n';
    std::cout << '\n';
    for (int k = 0; k < 20; ++k)
    {
      if (puntajes[k] >= puntaje)
      {
        std::cout << datos[k].nombre << " con " << puntajes[k] << " puntos." << '\n';
      }
    }
  }
  std::cout << '\n';
}

void opcion5(competidor datos[20], int categoriasMatrix[3][3])
{
  int tmp0[3] = {0, 0, 0};
  int tmp1[3] = {0, 0, 0};
  int tmp2[3] = {0, 0, 0}; //un array por cada categoria
  for (int j = 0; j < 20; ++j) //estos son los 20 inscriptos
  {
    if (datos[j].categoria == 0)
    {
      if (datos[j].subcategoria == 0)
      {
        ++tmp0[0];
      }
      else if (datos[j].subcategoria == 1)
      {
        ++tmp0[1];
      }
      else if (datos[j].subcategoria == 2)
      {
        ++tmp0[2];
      }
    }
    else if (datos[j].categoria == 1)
    {
      if (datos[j].subcategoria == 0)
      {
        ++tmp1[0];
      }
      else if (datos[j].subcategoria == 1)
      {
        ++tmp1[1];
      }
      else if (datos[j].subcategoria == 2)
      {
        ++tmp1[2];
      }
    }
    else if (datos[j].categoria == 2)
    {
      if (datos[j].subcategoria == 0)
      {
        ++tmp2[0];
      }
      else if (datos[j].subcategoria == 1)
      {
        ++tmp2[1];
      }
      else if (datos[j].subcategoria == 2)
      {
        ++tmp2[2];
      }
    }
  }
  for (int n = 0; n < 3; ++n)
  {
    categoriasMatrix[0][n] = tmp0[n];
    categoriasMatrix[1][n] = tmp1[n];
    categoriasMatrix[2][n] = tmp2[n];
  }
  for (int o = 0; o < 3; ++o)
  {
    for (int p = 0; p < 3; ++p)
    {
      std::cout << " " << categoriasMatrix[o][p] << " ";
    }
    std::cout << '\n';
  }
}