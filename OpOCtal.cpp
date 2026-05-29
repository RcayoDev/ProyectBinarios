#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;
bool validacionOctal(string texto) { // Comprueba que la cadena contiene solo dígitos octales.
    for (int i = 0; i < texto.length(); i++) { // Recorre cada carácter de la cadena.
        if (texto[i] < '0' || texto[i] > '7')  // Verifica si el carácter no está entre 0 y 7.
        {
            return false;  // Devuelve falso si se encuentra un carácter no octal.
        } 
    }
    return true; // Si no se encuentran caracteres inválidos, devuelve verdadero.
}

void sumaOctal (string Bin1, string Bin2){ 
  if (!validacionOctal(Bin1)|| !validacionOctal(Bin2)){ // Valida que ambas cadenas sean octales.
    cout << "Solo se permiten numero octales" << endl; // Mensaje si hay un dígito inválido.
    return;
  }
  while (Bin1.length() < Bin2.length()) { // Alinea las cadenas con ceros a la izquierda.
      Bin1.insert(0, "0");
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; // Acumula el acarreo en base octal.
  vector<int> resultado; // Almacena el resultado en orden inverso.
  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre los dígitos de derecha a izquierda.
  {
    int total = (Bin1[i] - '0') + (Bin2[i] - '0') + carry ; // Suma dígitos y acarreo.
    resultado.push_back(total % 8); // El dígito resultante es total mod 8.
    carry = total / 8;  // El acarreo es total / 8.
    // Si el total es mayor o igual a 8, se obtiene un acarreo para la siguiente posición.
  }
  if (carry ==1){ // Agrega el último acarreo si existe.
    resultado.push_back(carry);
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para mostrarlo en el orden correcto.
  cout << "El resultado de la suma es: ";
  for (int i = 0; i < resultado.size(); i++) { // Imprime cada dígito del resultado.
    cout << resultado[i];
  }
  cout << endl; // Salto de línea para una salida más clara.
}
string OpsumaOctal (string Bin1, string Bin2) // Función auxiliar para sumar sin imprimir el resultado inmediato.
{ 
    while (Bin1.length() < Bin2.length()) { // Alinea las cadenas con ceros a la izquierda.
      Bin1.insert(0, "0");  
  }
  while (Bin2.length() < Bin1.length()) {
      Bin2.insert(0, "0");
  }
  int carry = 0; // Acumula el acarreo en base octal.
  string resultado; // Guarda el resultado como una cadena.
  for (int i = Bin1.length() - 1; i >= 0; i--) // Recorre de derecha a izquierda.
  {
    int total = (Bin1[i] - '0') + (Bin2[i] - '0') + carry ; // Suma dígitos y acarreo.
    resultado.push_back(total % 8 +'0'); // Convierte el dígito resultante a carácter.
    carry = total / 8 ;  // Calcula el acarreo para la siguiente posición.
    // Si el total es 9 o mayor, se genera un acarreo.
  }
  if (carry ==1){ // Añade el último acarreo si es necesario.
    resultado.push_back(carry+'0');
  }
  reverse(resultado.begin(), resultado.end());  // Invierte el resultado para el orden correcto.
  return resultado; // Devuelve la suma como cadena.
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void restaOctal (string Bin1, string Bin2){
  if (!validacionOctal(Bin1)|| !validacionOctal(Bin2)){ // Valida que ambas cadenas sean octales.
    cout << "Solo se permiten numero octales" << endl;
    return;
  }
  while (Bin1.length()< Bin2.length()) // Alinea con ceros a la izquierda.
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
    int total = (Bin1[i]-'0') - (Bin2[i]-'0') - borrow; // Calcula la resta dígito a dígito.
    
    if (total< 0) // Si se necesita pedir prestado.
    {
      resultado.push_back(total+8); // Ajusta el valor sumando 8.
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

void multiplicacionOctal (string Bin1,string Bin2)
{ 
  if (!validacionOctal(Bin1)|| !validacionOctal(Bin2)){ // Valida que ambas cadenas sean octales.
    cout << "Solo se permiten numero octales" << endl;
    return;
  }
  string resultado = "0";
  string fila ;
  
  for (int i = Bin2.length()-1; i >=0 ; i--) // Para cada dígito de Bin2 de derecha a izquierda.
  {
    int digito = Bin2[i] - '0'; // Convierte el carácter a número.
    fila = Bin1; // Inicializa la fila con Bin1.
    for(int k = 0 ; k < Bin2.length() - 1 - i ; k++) // Desplaza la fila añadiendo ceros.
    {
      fila.push_back('0');
    }
    for (int k = 0; k < digito; k++)
    {
      resultado = OpsumaOctal(resultado, fila);
    }
  }
  cout << "El resultado de la multplicacion es: " << resultado <<endl;  // Mensaje final.
}
//*******<<<<<< */
int mainOctal(){
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
    sumaOctal(Bin1, Bin2);
    break;
  case 2:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    restaOctal(Bin1, Bin2);
    break;
  case 3:
    cout << "Ingrese el primer binario: " << endl;
    cin >> Bin1;
    cout << "Ingrese el segundo binario: " << endl;
    cin >> Bin2;
    multiplicacionOctal(Bin1, Bin2);
    break;
  default:
    cout << "Opcion invalida" << endl;
    break;
  }
  return 0;
}