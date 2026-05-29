#include <iostream>
using namespace std;
#include "ProyectConvert.cpp"
#include "OpBinario.cpp"
#include "OpHexadecimal.cpp"
#include "OpOctal.cpp"





int main(){
  int opciones;
  cout << "Seleccione 1:Convert ,2:OpBinarios:, 3:OpOctal, 4:OpHexadecimal " << endl;
  cin >> opciones;
  switch (opciones)
  {  case 1:
      mainConvert();
      break;
      case 2:
      mainBinario();
      break;
      case 3:
      mainOctal();
      break;
      case 4:
      mainHexa();
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
  }
}