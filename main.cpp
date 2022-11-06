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
  int puntaje;
};

void asignar(competidor datos[20]); //terminada y chequeada
void menu(int &opcion); //terminada y chequeada
void opcionMenu1(competidor datos[20]); //terminada y chequeada
void opcionMenu2(competidor datos[20]); //terminada y chequeada
void opcionMenu3(competidor datos[20]); //en proceso
void opcionMenu4(competidor datos[20]); //terminada y chequeada
void opcionMenu5(competidor datos[20], int categoriasMatrix[3][3]); //terminada y chequeada
void inicializarMenu(); //sin empezar

int main()
{
  competidor datos[20];
  int opcion = 1;
  int categoriasMatrix[3][3];
  asignar(datos);
  opcionMenu4(datos);
}

void asignar(competidor datos[20])
{
  std::ifstream inscriptos("inscriptos.txt");
  std::string tmp;
  if (!inscriptos.is_open())
  {
    std::cout << "Ha ocurrido un error al intentar abrir inscriptos.txt" << '\n';
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

void opcionMenu1(competidor datos[20])
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

void opcionMenu2(competidor datos[20])
{
  int suma;
  std::cout << '\n';
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    std::cout << "El competidor " << datos[i].nombre << " tiene " << suma << " puntos." << '\n';
    datos[i].puntaje = suma;
    //puntajes[i] = suma;
    suma = 0;
  }
  std::cout << '\n';
}

void opcionMenu3(competidor datos[20])
{
  std::ofstream resultados("resultados.txt");
  if (!resultados)
  {
    std::cout << "Ha ocurrido un error al intentar abrir resultados.txt" << '\n';
    exit(EXIT_FAILURE);
  }
  //for int 
}

void opcionMenu4(competidor datos[20])
{
  int suma, puntaje, mayor = 1;
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    datos[i].puntaje = suma;
    suma = 0;
  }
  for (int j = 0; j < 20; ++j)
  {
    if (datos[j].puntaje > mayor)
    {
      mayor = datos[j].puntaje;
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
      if (datos[k].puntaje >= puntaje)
      {
        std::cout << datos[k].nombre << " con " << datos[k].puntaje << " puntos." << '\n';
      }
    }
  }
  std::cout << '\n';
}

void opcionMenu5(competidor datos[20], int categoriasMatrix[3][3])
{
  int tmp0[3] = {0, 0, 0};
  int tmp1[3] = {0, 0, 0};
  int tmp2[3] = {0, 0, 0};
  for (int j = 0; j < 20; ++j)
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
  std::cout << "La cantidad de competidores por categoria son: \n";
  std::cout << '\n';
  for (int o = 0; o < 3; ++o)
  {
    std::cout << "Categoria " << o << ": |";
    for (int p = 0; p < 3; ++p)
    {
      std::cout << " " << categoriasMatrix[o][p] << " ";
    }
    std::cout << "|";
    std::cout << '\n';
  }
  std::cout << '\n';
}