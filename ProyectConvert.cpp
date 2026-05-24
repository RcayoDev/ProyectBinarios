//convert numero a binario, octal y hexadecimal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdarg>
using namespace std;

void octal (int numero){
  vector <int> residuos;
  while (numero>1)
  {
    int residuo = numero % 8;
    int cociente = numero/8;
    residuos.push_back(residuo);
    numero = cociente;
  }
  residuos.push_back(numero);
  reverse(residuos.begin(), residuos.end());
  cout << "el numero en binario es: ";
  for (int i = 0; i < residuos.size(); i++)
  {
    cout << residuos [i];
  }
}
void hexadecimal(int numero){
  vector <int> residuos;
  while (numero>1)
  {
    int residuo = numero % 16;
    int cociente = numero / 16;
    residuos.push_back(residuo);
    numero = cociente;
  }
  residuos.push_back(numero);
  reverse(residuos.begin(), residuos.end());
  cout <<"El binario del numero es: " ;
  for (int i = 0; i < residuos.size(); i++)
  {
    cout << residuos [i];
  }
}
void  binario (int numero){
  vector<int> residuos; //Inicializamos un vector para poder guardars los residuos y el ultimo cociente.
  while (numero >1 ){ //Un while para que el numero ingresado sea mayor a uno porque es el ultimo numero que quedara, y se añadira luego al residuo
    int residuo = numero % 2; //creamos un contenedor de residuo para guardarlos luego 
    int cociente = numero / 2; //creamos un cociente para que se valla actualizando el numero luego de dividir
    residuos.push_back(residuo); //Aqui con nuestro vector vacio le decimos push back para que se añada el residuo al vector residuos
    numero = cociente; //Aqui es donde le damos le damos el numero valor al numero y asi valla en el ciclo hasta que nuestro numero quede en 1
  }
  residuos.push_back(numero);//una vez termine el ciclo el numero quedara en 1 y ahora podremos añadirlo al nuestro vector residuos el ultimo numero "1"
  reverse(residuos.begin(), residuos.end()); //Lo revertimos el nuestro residuos "1234" a "4321" begin = comienza, end = fin
  cout << "El numero en binario es: "; // mandamos un mensaje explicativo 
  for (int i = 0; i < residuos.size(); i++){ //aqui usamos el ciclo para que se muestren los valores del vector con el metodo size, su funcion es que devuelve el numero de elementos en el vector ///////  funciona diciendo i=0 , 0 es menor a al tamaño del vector (4), Si, entonces entra y hace el cout y imprime el primero y y vuelve , hace lo mismo pero imprime el segund valor 
    cout << residuos[i]; // imprime la casilla actual (0, luego el 1 luego 2...)
  }
}
int main(){
  int numero, opcion;
  cout << "Escoja una opcion: " << "\n" ;
  cout << "Presione 1:Conversion a binario: " << "\n";
  cout << "Presione 2:Conversion a hexadecimal: " << "\n";
  cout << "Presione 3:Conversion a octal: " << "\n";
  cin >> opcion;
  switch (opcion)
  {
  case 1:
    cout<<"introduce el numero que quieres convertir a binario"<< "\n";
    cin >> numero;
    binario(numero);
    break;
  case 2:
    cout<<"introduce el numero que quieres convertir hexadecimal"<< "\n";
    cin >> numero;
    hexadecimal(numero);
    break;
  case 3:
    cout<<"introduce el numero que quieres convertir octal"<< "\n";
    cin >> numero;
    octal(numero);
    break;
  default:
    cout << "escoja una de las opciones";
    break;
  }
  

  
}

//Creamos una funcion////////////////////////////

