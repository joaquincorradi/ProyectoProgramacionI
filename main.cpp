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

void asignar(competidor datos[20]); 
void calcularPuntaje(competidor datos[20]);
void menu(int &opcion);
void opcionMenu1(competidor datos[20]);
void opcionMenu2(competidor datos[20]);
void opcionMenu3(competidor datos[20]);
void opcionMenu4(competidor datos[20]);
void opcionMenu5(competidor datos[20]);
void inicializarMenu();

int main()
{
  inicializarMenu();
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

void calcularPuntaje(competidor datos[20])
{
  int suma;
  for (int i = 0; i < 20; ++i)
  {
    suma = (datos[i].tirosCentro * 10) + (datos[i].tirosNoCentro * 5);
    datos[i].puntaje = suma;
    suma = 0;
  }
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
  std::cout << " Los competidores inscriptos son los siguientes: " << '\n';
  std::cout << '\n';
  for (int i = 0; i < 20; ++i)
  {
    std::cout << " " << datos[i].nombre << " con numero de inscripcion " << datos[i].numeroDeInscripcion << '\n';
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
    std::cout << " El competidor " << datos[i].nombre << " tiene " << suma << " puntos." << '\n';
    datos[i].puntaje = suma;
    suma = 0;
  }
  std::cout << '\n';
}

void opcionMenu3(competidor datos[20])
{
  competidor copia[20], tmp[20];
  std::ofstream resultados("resultados.txt");
  int suma;
  if (!resultados)
  {
    std::cout << "Ha ocurrido un error al intentar abrir resultados.txt" << '\n';
    exit(EXIT_FAILURE);
  }
  calcularPuntaje(datos);
  for (int i = 0; i < 20; ++i)
  {
    copia[i].numeroDeInscripcion = datos[i].numeroDeInscripcion;
    copia[i].nombre = datos[i].nombre;
    copia[i].categoria = datos[i].categoria;
    copia[i].subcategoria = datos[i].subcategoria;
    copia[i].tirosCentro = datos[i].tirosCentro;
    copia[i].tirosNoCentro = datos[i].tirosNoCentro;
    copia[i].puntaje = datos[i].puntaje;
  }
  for (int j = 0; j < 19; ++j)
  {
    for (int k = 1; k < 20; ++k)
    {
      if (copia[k].puntaje > copia[k - 1].puntaje)
      {
        tmp[k].numeroDeInscripcion = copia[k].numeroDeInscripcion;
        tmp[k].nombre = copia[k].nombre;
        tmp[k].categoria = copia[k].categoria;
        tmp[k].subcategoria = copia[k].subcategoria;
        tmp[k].tirosCentro = copia[k].tirosCentro;
        tmp[k].tirosNoCentro = copia[k].tirosNoCentro;
        tmp[k].puntaje = copia[k].puntaje;

        copia[k].numeroDeInscripcion = copia[k - 1].numeroDeInscripcion;
        copia[k].nombre = copia[k - 1].nombre;
        copia[k].categoria = copia[k - 1].categoria;
        copia[k].subcategoria = copia[k - 1].subcategoria;
        copia[k].tirosCentro = copia[k - 1].tirosCentro;
        copia[k].tirosNoCentro = copia[k - 1].tirosNoCentro;
        copia[k].puntaje = copia[k - 1].puntaje;

        copia[k - 1].numeroDeInscripcion = tmp[k].numeroDeInscripcion;
        copia[k - 1].nombre = tmp[k].nombre;
        copia[k - 1].categoria = tmp[k].categoria;
        copia[k - 1].subcategoria = tmp[k].subcategoria;
        copia[k - 1].tirosCentro = tmp[k].tirosCentro;
        copia[k - 1].tirosNoCentro = tmp[k].tirosNoCentro;
        copia[k - 1].puntaje = tmp[k].puntaje;
      }
    }
  }
  resultados << "Numero de inscripto:" << "\t\tNombre:" << "\t\t\t\tCategoria:" << "\t\t\t\tSubcategoria:" << "\t\tTirosCentro:" << "\t\tTirosNoCentro:" << "\t\tPuntaje:\n";
  for (int l = 0; l < 20; ++l)
  {
    if (copia[l].nombre != "Candelaria" && copia[l].nombre != "Paola")
    {
      resultados << copia[l].numeroDeInscripcion << "\t\t\t\t\t\t\t\t\t\t\t\t" << copia[l].nombre << "\t\t\t\t\t\t\t" << copia[l].categoria << "\t\t\t\t\t\t\t\t" << 
        "\t" << copia[l].subcategoria << "\t\t\t\t\t\t\t" << copia[l].tirosCentro << "\t\t\t\t\t\t\t" << copia[l].tirosNoCentro << "\t\t\t\t\t\t\t" << copia[l].puntaje << '\n';
    }
    else if (copia[l].nombre == "Candelaria")
    {
      resultados << copia[l].numeroDeInscripcion << "\t\t\t\t\t\t\t\t\t\t\t\t" << copia[l].nombre << "\t\t\t\t\t" << copia[l].categoria << "\t\t\t\t\t\t\t" << 
        "\t" << copia[l].subcategoria << "\t\t\t\t\t\t\t" << copia[l].tirosCentro << "\t\t\t\t\t\t\t" << copia[l].tirosNoCentro << "\t\t\t\t\t\t\t" << copia[l].puntaje << '\n';
    }
    else
    {
      resultados << copia[l].numeroDeInscripcion << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << copia[l].nombre << "\t\t\t\t\t\t\t\t" << copia[l].categoria << "\t\t\t\t\t\t\t\t" << 
        "\t" << copia[l].subcategoria << "\t\t\t\t\t\t\t\t" << copia[l].tirosCentro << "\t\t\t\t\t\t\t\t" << copia[l].tirosNoCentro << "\t\t\t\t\t\t\t" << copia[l].puntaje << '\n';
    }
  }
  std::cout << '\n';
  std::cout << "Archivo exportado con exito!"; 
  std::cout << '\n';
}

void opcionMenu4(competidor datos[20])
{
  int suma, puntaje, mayor = 1;
  calcularPuntaje(datos);
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

void opcionMenu5(competidor datos[20])
{
  int categoriasMatrix[3][3] = {0,0,0,0,0,0,0,0,0};
  for (int k = 0; k < 20; ++k)
  {
    ++categoriasMatrix[datos[k].categoria][datos[k].subcategoria];
  }
  std::cout << '\n';
  std::cout << "La cantidad de competidores por categoria son: \n";
  std::cout << '\n';
  for (int i = 0; i < 3; ++i)
  {
    std::cout << "Categoria " << i << ": |";
    for (int j = 0; j < 3; ++j)
    {
      std::cout << " " << categoriasMatrix[i][j] << " ";
    }
    std::cout << "|";
    std::cout << '\n';
  }
  std::cout << '\n';
}

void inicializarMenu()
{
  competidor datos[20];
  int opcion = 1, categoriasMatrix[3][3];
  bool caso6 = false;
  char seleccionUs = 's';
  asignar(datos);
  while (seleccionUs == 'S' || seleccionUs == 's')
  {
    menu(opcion);
    std::cout << std::flush;
    system("cls||clear");
    switch (opcion)
    {
    case 1:
      opcionMenu1(datos);
      break;
    case 2:
      opcionMenu2(datos);
      break;
    case 3:
      opcionMenu3(datos);
      break;
    case 4:
      opcionMenu4(datos);
      break;
    case 5:
      opcionMenu5(datos);
      break;
    case 6:
      caso6 = true;
      break;
    default:
      std::cout << "Opcion invalida\n";
      break;
    }
    if (!caso6)
    {
      std::cout << "¿Desea volver al menu principal? [S/n]: ";
      std::cin >> seleccionUs;
      if (seleccionUs == 's' || seleccionUs == 'S')
      {
        system("cls||clear");
      }
    }
    else
    {
      seleccionUs = 'n';
    }
  }
}
