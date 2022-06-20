#include <iostream>
using namespace std;

class Cjugador{
private:
  string usuario, contrasenia;
  char **tablero;
public:
  Cjugador();
Cjugador(string _u, string _c);
  void set_usuario(string _u);
  string get_usuario();
  string get_contrasenia();
  void set_contrasenia(string _c);
  void set_tablero(char **tablero);
  void get_tablero();
  ~Cjugador(){};
};