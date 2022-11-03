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

int main()
{
  int opcion = 1;
  std::ifstream insciptos("inscriptos.txt");
}

void menu(int &opcion)
{
  while (opcion <= 0 || opcion > 6)
  {
    std::cout << "\tMENU PRINCIPAL:" << '\n';
    std::cout << "\t\t1. Competidores inscriptos." << '\n';
    std::cout << "\t\t2. Mostrar puntaje de competidores." << '\n';
    std::cout << "\t\t3. Exportar puntajes (.txt)" << '\n';
    std::cout << "\t\t4. Filtrar competidores por un puntaje maximo." << '\n';
    std::cout << "\t\t5. Mostrar cantidad de competidores por categoria y subcategoria." << '\n';
    std::cout << "\t\t6. Salir." << '\n';
    std::cout << "\tSeleccione una opcion (1 - 6): " << '\n';
    std::cin >> opcion;
  }
}