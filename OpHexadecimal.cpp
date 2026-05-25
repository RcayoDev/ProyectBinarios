#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;

bool validacion(string texto) { //creamos una funcion booleana
    for (int i = 0; i < texto.length(); i++) { // un bucle para revisar cada digito del binario 
        if ((texto[i] < '0' || texto[i] > '9') && (texto[i] < 'A' || texto[i] > 'F'))  //un if para verificar si 0 es diferente a 0?Si , 0 es diferente a 1?No entonces no entra; porque &&ambas tiene que cumplirse
        {

            return false;  //detenemos la funcion si entra porque ay un numero que no es 0 a 9 y A a F
        } 
        
    }
    return true;
}
int charAnum(char c){
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1; // Caracter no válido
}
char numAchar(int n){
    if (n >= 0 && n <= 9) {
        return n + '0';
    }
    if (n >= 10 && n <= 15) {
        return n - 10 + 'A';
    }
    return '?'; // Número no válido
}
void sumaBin (string Bin1, string Bin2){ //
/// IA >>>>>>
  if (!validacion(Bin1)|| !validacion(Bin2)){ //aqui validamos que bin1 y bin2 solo sean 1s y 0s en caso exista un 2 entrara y mandara un mensaje  , || significa que uno  tiene que cumplirse para entrar 
    cout << "Solo se permiten numeros hexadecimales" << endl;//mensaje porque introdujo un numero que no es 0 o 1
    return;
  }
  while (Bin1.length() < Bin2.length()) { //estos while es para que tengan la misma cantidad de dijitos, porque como ser string y al hacer la operacion 1010 , 10 saldra error
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  ///////<<<<< ///////////////
  int carry = 0; //este carry es un contador para los 1 + 1 
  vector<char> resultado; //hacemos un vector que es un arrays, para almacenar binarios por binario

  for (int i = Bin1.length() - 1; i >= 0; i--) //recorremos desde el ultimo indice hasta quedar en 0 
  {

    int total = charAnum(Bin1[i]) + charAnum(Bin2[i]) + carry ; // aqui hacemos la resta de caracteres el '0' = 48 y el '1'=49 ; la resta seria 49-48 = 1;
    resultado.push_back(numAchar(total % 16)); // sacamod modulo del total , si total tiene suma de 16 su modulo es 0 entonces guardamos el 0.
    carry = total / 16;  //si el total es 16 dividimos entre 16 = 1, entonces le damos el valor de 1 al carry y continuamos el ciclo
    // en dado caso si la suma es 3; pasamos el total = 3   y sacamos el modulo %16 , el mod seria 3 entonces lo guardamos en resultado ; como total es 3 dividimos entre 16  = 0 y ese valor guardamos al carry para la siguiente operacion .
  }
  if (carry ==1){// una vez fuera preguntamos si el que quedo al final del ciclo es 1 o 0  si es 1 entra y lo guardamos en resultado 
    resultado.push_back(numAchar(carry));//aqui con push back  guardamos
  }
  reverse(resultado.begin(), resultado.end());  //una vez tenido todo los digitos lo reverimos lo guardamo de izquierdaa dercha y saldria mal a la hora de leer, entonces revertimos para leerlo de de derecha a izquierda
  cout << "El resultado de la suma es: "; //mostramos el resultado conforme al orden
  for (int i = 0; i < resultado.size(); i++) { // mostramos uno por uno conforme al orden
    cout << resultado[i]; // mostramos de 0 , 1 ,2 ,3 ,4  ... como ya lo tenemos en el orden correcto  
  }
  cout << endl;
}
string Opsuma (string Bin1, string Bin2)
{ 
    while (Bin1.length() < Bin2.length()) {
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; //este carry es un contador para los 1 + 1 
  string resultado; //hacemos un vector que es un arrays, para almacenar binarios por binario
  for (int i = Bin1.length() - 1; i >= 0; i--) //recorremos desde el ultimo indice hasta quedar en 0 
  {
    int total = charAnum(Bin1[i]) + charAnum(Bin2[i]) + carry ; // aqui hacemos la resta de caracteres el '0' = 48 y el '1'=49 ; la resta seria 49-48 = 1;
    resultado.push_back(numAchar(total % 16)); // sacamod modulo del total , si total tiene suma de 16 su modulo es 0 entonces guardamos el 0.
    carry = total / 16 ;  //si el total es 16 dividimos entre 16 = 1, entonces le damos el valor de 1 al carry y continuamos el ciclo
    
    // en dado caso si la suma es 3; pasamos el total = 3   y sacamos el modulo %16 , el mod seria 3 entonces lo guardamos en resultado ; como total es 3 dividimos entre 16  = 0 y ese valor guardamos al carry para la siguiente operacion .
  }
  if (carry ==1){// una vez fuera preguntamos si el que quedo al final del ciclo es 1 o 0  si es 1 entra y lo guardamos en resultado 
    resultado.push_back(numAchar(carry));//aqui con push back  guardamos
  }
  reverse(resultado.begin(), resultado.end());  //una vez tenido todo los digitos lo reverimos lo guardamo de izquierdaa dercha y saldria mal a la hora de leer, entonces revertimos para leerlo de de derecha a izquierda
  return resultado; //mostramos el resultado conforme al orden
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void restaBin (string Bin1, string Bin2){
  if (!validacion(Bin1)|| !validacion(Bin2)){ //aqui validamos que bin1 y bin2 solo sean 1s y 0s en caso exista un 2 entrara y mandara un mensaje  , || significa que uno  tiene que cumplirse para entrar 
    cout << "Solo se permiten numeros hexadecimales" << endl;//mensaje porque introdujo un numero que no es 0 o 1
    return;
  }
  while (Bin1.length()< Bin2.length())//este cliclo es para aumenetar 0 por delante paraque los binarios estes parejos 
  {
    Bin1.insert(0, "0");//con este insert añadimos los 0, el 0 es para la pocision 0 y el "0" es lo que se introducira 
  }
  while (Bin2.length()< Bin1.length()) 
  {
    Bin2.insert(0, "0");
  }
  int borrow = 0; // en la esta el contador lo llamaremos borrow
  vector<char> resultado ; //creamos un vector donde guardaremos 
  for (int i = Bin1.length()-1; i >= 0; i--) //
  {
    int total = charAnum(Bin1[i]) - charAnum(Bin2[i]) - borrow; //aqui esta la formula del mismo modo que suma 
    
    if (total< 0) //verificamos si el total es menor a 0 , si el valor es total es 1 entra por else y se guarda pero en caso de que sea tengamos una resta de 0-1 = -1 que seria menor a 0 entonces entra por else
    {
      resultado.push_back(numAchar(total+16)); //aqui  como el valor es -1 entonces sumamos +16 total = 15; y se guarda con el push back
      borrow = 1; // y aumentamos el contador 1 ya tuvimos un un prestamos
    }
    else //el caso de else cuando el valor es mayor a 0 como 1 o 0 entonces entra 
    {
      resultado.push_back(numAchar(total));  //aqui se guarda porque es 0 o 1
      borrow=0; // y seguimos mantenienod el borrow o prestamos

    }
  } //salimos del bicle 
  
  if (borrow ==1) //verificamos si el en el ultimo digito estuvo pidiendo prestamos sin tener de donde 
  {
    cout << "el resultado es negativo,restaste un número mayor"; //el mensaje porque huba resta en negativo como resultado 
    return ;
  }
  
  reverse(resultado.begin(), resultado.end()); // invertimos el orden por la misma razon de suma
  cout << "El resultado de la resta es: ";  // mensaje
  for (int i = 0; i < resultado.size(); i++) // un for para ir recorrer y mostrar cada digito
  {
    cout << resultado[i]; //aqui se muestra digito por digito 
  }
  cout << endl;
}

void multiplicacion (string Bin1,string Bin2)
{ 
  if (!validacion(Bin1)|| !validacion(Bin2)){ //aqui validamos que bin1 y bin2 solo sean 1s y 0s en caso exista un 2 entrara y mandara un mensaje  , || significa que uno  tiene que cumplirse para entrar 
    cout << "Solo se permiten numeros hexadecimales" << endl;//mensaje porque introdujo un numero que no es 0 o 1
    return;
    
  }
  string resultado = "0";
  string fila ;
  for (int i = Bin2.length()-1; i >=0 ; i--)
  {
    int digito = charAnum(Bin2[i]); //extraer digito = Bin2[i] - '0'
    fila = Bin1; //inicializamos fila con el valor de Bin1
    for(int k = 0 ; k < Bin2.length() - 1 - i ; k++) //desplazar fila a la izquierda agregando un '0' al final
    {
    fila.push_back('0'); //desplazar fila a la izquierda agregando un '0' al final
    }
    for (int k = 0; k < digito; k++)
    {
      resultado = Opsuma(resultado, fila);
    }
  }
  cout << "El resultado de la multplicacion es: " << resultado <<endl;  // mensaje
}
//*******<<<<<< */
int main(){
  string Bin1, Bin2;
  int opciones;
  cout << "Seleccione operacion (1=suma, 2=resta, 3=multiplicacion): " << endl;
  cin >> opciones;
  
  switch (opciones)
  {
  case 1 :
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    sumaBin(Bin1, Bin2);
    break;
  case 2:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    restaBin(Bin1, Bin2);
    break;
  case 3:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    multiplicacion(Bin1, Bin2);
    break;
  default:
    cout << "Opcion invalida" << endl;
    break;
  }
  return 0;
}