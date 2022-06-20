#include "jugador.h"

Cjugador::Cjugador(){
  usuario=" ";
  contrasenia=" ";
  tablero=nullptr;
}

Cjugador::Cjugador(string _u, string _c){
  usuario = _u;
  contrasenia = _c;
  tablero = nullptr;
}

string Cjugador::get_usuario(){
  return usuario;
}

string Cjugador::get_contrasenia(){
  return contrasenia;
}

void Cjugador::set_usuario(string _u){
  usuario = _u;
}

void Cjugador::set_contrasenia(string _c){
  contrasenia = _c;
}

void Cjugador::set_tablero(char** _tablero){
  tablero = nullptr;
  tablero = new char *[10];
    for(int i=0; i<10; i++){
        tablero[i] = new char [10];
    }
  for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tablero[i][j]='.';
        }
    }
  for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            _tablero[i][j]=tablero[i][j];
        }
    }
}

void Cjugador::get_tablero(){
  for(int i=0; i<10; i++){
    if(i==0){
      cout<<"   0  1  2  3  4  5  6  7  8  9"<<endl;
    }
        for(int j=0; j<10; j++){
          if(j==0){
            cout<<"A)\n";
            cout<<"B)\n";
            cout<<"C)\n";
            cout<<"D)\n";
            cout<<"E)\n";
            cout<<"F)\n";
            cout<<"G)\n";
            cout<<"H)\n";
            cout<<"I)\n";
            cout<<"J)\n"<<endl;
          }
            cout<<" "<<tablero[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
}