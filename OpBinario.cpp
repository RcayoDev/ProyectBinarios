#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;

bool validacion(string texto) { // Comprueba que la cadena contiene solo 0s y 1s.
    for (int i = 0; i < texto.length(); i++) { // Recorre cada carácter de la cadena.
        if (texto[i] != '0' && texto[i] != '1')  // Si un carácter no es 0 ni 1, no es binario.
        {
            return false;  // Devuelve falso si encuentra un carácter inválido.
        } 
    }
    return true;
}
void sumaBin (string Bin1, string Bin2){
  if (!validacion(Bin1)|| !validacion(Bin2)){ // Comprueba que ambas entradas sean valores binarios.
    cout << "Solo se permiten 0s y 1s" << endl; // Mensaje si hay un carácter inválido.
    return;
  }
  while (Bin1.length() < Bin2.length()) { // Alinea las cadenas con ceros a la izquierda.
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; // Acarreo de la suma binaria.
  vector<int> resultado; // Almacena el resultado en orden inverso.
  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre los bits de derecha a izquierda.
  {
    int total = (Bin1[i] - '0') + (Bin2[i] - '0') + carry ; // Suma los bits y el acarreo.
    resultado.push_back(total % 2); // El bit resultante es total mod 2.
    carry = total / 2;  // El acarreo es total / 2.
    //
  }
  if (carry ==1){ // Añade el último acarreo si existe.
    resultado.push_back(carry);
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para el orden correcto.
  cout << "El resultado de la suma es: ";
  for (int i = 0; i < resultado.size(); i++) { // Imprime cada bit del resultado.
    cout << resultado[i];
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
  int carry = 0; // Acarreo de la suma binaria.
  string resultado; // Guarda el resultado como cadena.
  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre los bits de derecha a izquierda.
  {
    int total = (Bin1[i] - '0') + (Bin2[i] - '0') + carry ; // Suma los bits y el acarreo.
    resultado.push_back(total % 2+'0'); // Convierte el bit resultante en carácter.
    carry = total / 2 ;  // Calcula el acarreo para la siguiente posición.

    // Si la suma es 3, el resultado es 1 y el acarreo también es 1.
  }
  if (carry ==1){
    resultado.push_back(carry+'0'); // Añade el último acarreo si existe.
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para el orden correcto.
  return resultado; // Devuelve la suma como cadena.
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void restaBin (string Bin1, string Bin2){
  if (!validacion(Bin1)|| !validacion(Bin2)){ // Comprueba que ambas entradas sean valores binarios.
    cout << "Solo se permiten 0s y 1s" << endl; // Mensaje si hay un carácter inválido.
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
  vector<int> resultado ; // Almacena el resultado en orden inverso.
  for (int i = Bin1.length()-1; i >= 0; i--)
  {
    int total = (Bin1[i]-'0') - (Bin2[i]-'0') - borrow; // Calcula la resta bit a bit.
    
    if (total< 0) // Si se necesita pedir prestado.
    {
      resultado.push_back(total+2); // Ajusta el valor con base 2.
      borrow = 1; // Marca el préstamo.
    }
    else
    {
      resultado.push_back(total);  // Guarda el resultado del dígito.
      borrow=0; // No hay préstamo pendiente.
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

void multiplicacion (string Bin1,string Bin2)
{ 
  if (!validacion(Bin1)|| !validacion(Bin2)){ // Comprueba que ambas entradas sean valores binarios.
    cout << "Solo se permiten 0s y 1s" << endl; // Mensaje si hay un carácter inválido.
    return;
  }
  string resultado = "0"; // Inicializa el resultado de la multiplicación como cero.
  string fila ; // Almacena la fila de multiplicación actual.
  for (int i = Bin2.length()-1; i >=0 ; i--)
  {
    if ( Bin2[i] =='1') // Si el bit actual es 1, agrega una fila desplazada.
    {
      fila = Bin1; //<<<< Asigna el primer número a la fila.
      for (int j = 0; j < Bin2.length()-1-i; j++)// Agrega ceros a la derecha según la posición del bit.
      {
        fila.push_back('0');
      }
      resultado = Opsuma (resultado, fila);// Suma la fila al resultado acumulado.
    }
  }
  cout << "El resultado de la multplicacion es: " << resultado <<endl;  // Mensaje final.
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