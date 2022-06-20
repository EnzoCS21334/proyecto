#include <iostream>
#include "jugador.h"

using namespace std;
void menu(int &n){
do{cout<<" -----BIENVENIDO BATALLA NAVAL-----"<<endl;
cout<<"Seleccione una de las siguientes opciones:"<<endl;
cout<<"1. Registrar jugador 1"<<endl;
cout<<"2. Registrar jugador 2"<<endl;
cout<<"3. Crear tablero"<<endl;
cout<<"4. Visualizar tablero"<<endl;
cout<<"5. Iniciar Batalla Naval"<<endl;
cout<<"Ingrese la opcion deseada: ";
cin>>n;
  }while(n>6 || n<1);
}
void visualizar_tablero(Cjugador jugador){
  jugador.get_tablero();
}
void iniciar_batalla(){
  
}
void generar_usuario(Cjugador &jugador){
  string _u;
  cout<<"Ingrese el nombre de usuario:"<<endl;
  cin>>_u;
  string _c;
  cout<<"Ingresar contraseña para jugador: ";
  cin>>_c;
  jugador.set_usuario(_u);
  jugador.set_contrasenia(_c);
  cout<<"Jugador creado exitosamente"<<endl;
}
void confirmar_tablero(Cjugador &jugador){
  int opcion = 0;
  do{cout<<"¿Estas de acuerdo jugar con este tablero?"<<endl;
  cout<<"1.SI / 2.NO"<<endl;
  cin>>opcion;}while(opcion>2 & opcion<1);
  if (opcion==1){
    cout<<"Se guardo el tablero para "<<jugador.get_usuario()<<endl;
  }
  else if (opcion==2){
    
  }
}
void crear_tablero(Cjugador &jugador){
  char **tablero;
  tablero = new char *[10];
    for(int i=0; i<10; i++){
        tablero[i] = new char [10];
    }
  for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tablero[i][j]='.';
        }
    }
  int fila, columna, tamano, orientacion;
  cout<<"Ingresar datos del barco: "<<endl;
  cout<<"Fila: ";
  cin >> fila;
  cout<<"\n";
  cout<<"Columna: ";
  cin >> columna;
  cout<<"\n";
  cout<<"Tamanio del barco: ";
  cin >> tamano;
  cout<<"\n";
  cout<<"Orientacion (0, vertical; 1, horizontal): ";
  cin >> orientacion;
  cout<<"\n";
  if(orientacion==0){
        for(int i=fila; i<fila+tamano; i++){
            if(tablero[i][columna]!='B'){
                tablero[i][columna] = 'B';
            }
        }
    }
    else if(orientacion==1){
        for(int i=columna; i<columna+tamano; i++) {
            if(tablero[fila][i]!='B') {
                tablero[fila][i]='B';
            }
        }
    }
  jugador.set_tablero(tablero);
  confirmar_tablero(jugador);
}
void tiro(char **batallanaval, char fila, int columna){
    if(batallanaval[((int)fila-65)][columna]!='B'){
        batallanaval[((int)fila-65)][columna] = 'O';
      cout<<"Esta vez NO acertaste"<<"\n";
    }
    else if(batallanaval[((int)fila-65)][columna]=='B'){
        batallanaval[((int)fila-65)][columna] = 'X';
      cout<<"Esta vez acertaste"<<"\n";
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
          if(batallanaval[i][j]=='B' or batallanaval[i][j]=='.' )
            cout<<" .";
          else if(batallanaval[i][j]=='O'){
            cout<<" O";
          }
          else{
            cout<<" X";
          }
        }
        cout<<"\n";
    }
};

void batalla_naval();

int main() {
  int opcion;
  Cjugador jugador1("","");
  Cjugador jugador2("","");
  string u, c;
  do{
  menu(opcion);
  switch(opcion){
    case 1:
      generar_usuario(jugador1);
      cout<<jugador1.get_usuario()<<endl;
      cout<<jugador1.get_contrasenia()<<endl;
      break;
    case 2:
      generar_usuario(jugador2);
      cout<<jugador2.get_usuario()<<endl;
      cout<<jugador2.get_contrasenia()<<endl;
      break;
    case 3:
    cout<<"Ingrese usuario: ";
    cin>>u;
    cout<<"Ingrese contrasenia: ";
    cin>>c;
    if(u==jugador1.get_usuario() and c==jugador1.get_contrasenia()){
      cout<<"Crear tablero de "<<jugador1.get_usuario()<<endl;
      crear_tablero(jugador1);
    }
    else if(u==jugador2.get_usuario() and c==jugador2.get_contrasenia()){
      cout<<"Crear tablero de "<<jugador2.get_usuario()<<endl;
      crear_tablero(jugador2);
    }
    else{
        cout<<"Usuario no encontrado "<<endl;
      }
    break;
    case 4:
    cout<<"Ingrese usuario: ";
    cin>>u;
    cout<<"Ingrese contrasenia: ";
    cin>>c;
    if(u==jugador1.get_usuario() and c==jugador2.get_contrasenia()){
      cout<<"Tablero de "<<jugador1.get_usuario()<<": "<<endl;
      jugador1.get_tablero();
    }
    else if(u==jugador2.get_usuario() and c==jugador2.get_contrasenia()){
      cout<<"Tablero de "<<jugador2.get_usuario()<<": "<<endl;
      jugador2.get_tablero();
    }
    break;
    /*case 5:*/
  }
    }while(true);
}