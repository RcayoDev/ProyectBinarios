#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;

bool validacionHexa(string texto) { // Comprueba que la cadena contiene solo dígitos hexadecimales.
    for (int i = 0; i < texto.length(); i++) { // Recorre cada carácter en la cadena.
        if ((texto[i] < '0' || texto[i] > '9') && (texto[i] < 'A' || texto[i] > 'F'))  // Si no está entre 0-9 ni A-F.
        {
            return false;  // Devuelve falso para caracteres no válidos.
        } 
    }
    return true;
}
int charAnum(char c){ // Convierte un carácter hexadecimal a su valor numérico.
    if (c >= '0' && c <= '9') { // Si el carácter es un dígito del 0 al 9.
        return c - '0'; // Convierte el carácter a su valor numérico restando '0'.
    } 
    if (c >= 'A' && c <= 'F') {// Si el carácter es una letra mayúscula de A a F.
        return c - 'A' + 10; // Convierte la letra a su valor numérico restando 'A' y sumando 10.
    }
    if (c >= 'a' && c <= 'f') { // Si el carácter es una letra minúscula de a a f.
        return c - 'a' + 10; // Convierte la letra a su valor numérico restando 'a' y sumando 10.
    }
    return -1; // Caracter no válido.
}
char numAchar(int n){ // Convierte un número entre 0 y 15 a su carácter hexadecimal correspondiente.
    if (n >= 0 && n <= 9) { // Si el número es entre 0 y 9.
        return n + '0'; // Convierte el número a su carácter correspondiente sumando '0'.
    }
    if (n >= 10 && n <= 15) { // Si el número es entre 10 y 15.
        return n - 10 + 'A'; // Convierte el número a su letra hexadecimal correspondiente restando 10 y sumando 'A'.
    }
    return '?'; // Número no válido.
}
void sumaHexa (string Bin1, string Bin2){  // Función para sumar dos números hexadecimales representados como cadenas.
  if (!validacionHexa(Bin1)|| !validacionHexa(Bin2)){ // Comprueba que ambas cadenas sean hexadecimales válidas.
    cout << "Solo se permiten numeros hexadecimales" << endl; // Mensaje si hay un carácter inválido.
    return;
  }
  while (Bin1.length() < Bin2.length()) { // Alinea ambas cadenas con ceros a la izquierda.
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; // Acarreo para la suma hexadecimal.
  vector<char> resultado; // Almacena el resultado en orden inverso.

  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre caracteres de derecha a izquierda.
  {
    int total = charAnum(Bin1[i]) + charAnum(Bin2[i]) + carry ; // Suma valores hexadecimales y acarreo.
    resultado.push_back(numAchar(total % 16)); // El dígito resultante es total mod 16.
    carry = total / 16;  // El acarreo es el cociente entero.
  }
  if (carry ==1){ // Si queda acarreo al final, se agrega.
    resultado.push_back(numAchar(carry));
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para el orden correcto.
  cout << "El resultado de la suma es: ";
  for (int i = 0; i < resultado.size(); i++) { // Imprime cada dígito del resultado.
    cout << resultado[i]; // Muestra el dígito actual del resultado.
  }
  cout << endl;
}
string OpsumaHexa (string Bin1, string Bin2)
{ 
    while (Bin1.length() < Bin2.length()) {
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; // Acarreo para la suma hexadecimal.
  string resultado; // Almacena el resultado como cadena.
  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre caracteres de derecha a izquierda.
  {
    int total = charAnum(Bin1[i]) + charAnum(Bin2[i]) + carry ; // Suma valores hexadecimales y acarreo.
    resultado.push_back(numAchar(total % 16)); // Convierte el dígito resultante a carácter.
    carry = total / 16 ;  // Calcula el acarreo para la siguiente posición.
  }
  if (carry ==1){
    resultado.push_back(numAchar(carry));
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para el orden correcto.
  return resultado;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void restaHexa (string Bin1, string Bin2){
  if (!validacionHexa(Bin1)|| !validacionHexa   (Bin2)){ // Comprueba que ambas cadenas sean hexadecimales válidas.
    cout << "Solo se permiten numeros hexadecimales" << endl;
    return;
  }
  while (Bin1.length()< Bin2.length()) // Alinea las cadenas con ceros a la izquierda.
  {
    Bin1.insert(0, "0");
  }
  while (Bin2.length()< Bin1.length()) 
  {
    Bin2.insert(0, "0");
  }
  int borrow = 0; // Indicador de préstamo en la resta.
  vector<char> resultado ; // Almacena el resultado en orden inverso.
  for (int i = Bin1.length()-1; i >= 0; i--)
  {
    int total = charAnum(Bin1[i]) - charAnum(Bin2[i]) - borrow; // Calcula la resta en base 16.
    
    if (total < 0) // Si es necesario pedir prestado.
    {
      resultado.push_back(numAchar(total + 16)); // Ajusta el resultado sumando 16.
      borrow = 1; // Marca el préstamo para la siguiente posición.
    }
    else
    {
      resultado.push_back(numAchar(total));
      borrow = 0;
    }
  }
  
  if (borrow ==1) // Si el resultado quedó negativo.
  {
    cout << "el resultado es negativo,restaste un número mayor";
    return ;
  }
  
  reverse(resultado.begin(), resultado.end()); // Invierte el resultado para el orden correcto.
  cout << "El resultado de la resta es: ";
  for (int i = 0; i < resultado.size(); i++)
  {
    cout << resultado[i];
  }
  cout << endl;
}

void multiplicacionHexa (string Bin1,string Bin2)
{ 
  if (!validacionHexa(Bin1)|| !validacionHexa(Bin2)){ // Comprueba que ambas cadenas sean hexadecimales válidas.
    cout << "Solo se permiten numeros hexadecimales" << endl;
    return;
  }
  string resultado = "0";
  string fila ;
  for (int i = Bin2.length()-1; i >=0 ; i--)
  {
    int digito = charAnum(Bin2[i]); // Convierte el carácter hexadecimal a su valor numérico.
    fila = Bin1; // Inicializa la fila con el valor de Bin1.
    for(int k = 0 ; k < Bin2.length() - 1 - i ; k++) // Desplaza la fila a la izquierda agregando ceros.
    {
      fila.push_back('0'); // Agrega un cero al final de la fila para el desplazamiento.
    }
    for (int k = 0; k < digito; k++) // Suma la fila a sí misma tantas veces como indique el dígito.
    {
      resultado = OpsumaHexa(resultado, fila); // Suma la fila al resultado acumulado utilizando la función de suma hexadecimal.
    }
  }
  cout << "El resultado de la multplicacion es: " << resultado <<endl; 
}
//*******<<<<<< */
int mainHexa(){
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
    sumaHexa(Bin1, Bin2);
    break;
  case 2:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    restaHexa(Bin1, Bin2);
    break;
  case 3:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    multiplicacionHexa(Bin1, Bin2);
    break;
  default:
    cout << "Opcion invalida" << endl;
    break;
  }
  return 0;
}