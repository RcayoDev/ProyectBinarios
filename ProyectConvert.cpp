// Convierte un número a binario, octal y hexadecimal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdarg>
using namespace std;


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
bool validacion(string texto) { // Comprueba que la cadena contiene solo dígitos hexadecimales.
    for (int i = 0; i < texto.length(); i++) { // Recorre cada carácter en la cadena.
        if ((texto[i] < '0' || texto[i] > '9') && (texto[i] < 'A' || texto[i] > 'F'))  // Si no está entre 0-9 ni A-F.
        {
            return false;  // Devuelve falso para caracteres no válidos.
        } 
    }
    return true;
}
int stringAInt(string texto, int base){ // Convierte una cadena de texto a un número entero según la base especificada.
  int resultado = 0; // Inicializa el resultado a cero.
  for (int i = 0; i < texto.length(); i++){ // Recorre cada carácter en la cadena de texto.
     resultado = resultado * base + charAnum(texto[i]); // Multiplica el resultado actual por la base y suma el valor numérico del carácter actual para construir el número entero final.
    
  }
  return resultado; // Devuelve el número entero convertido.
}
void octal (int numero){ // Convierte un número a octal utilizando el método de residuos.
  vector <int> residuos; // Almacena los residuos de la división por 8, que corresponden a los dígitos octales.
  while (numero>0) // Continúa dividiendo el número por 8 hasta que queda 1 o menos.
  {
    int residuo = numero % 8; /// Calcula el residuo de la división por 8, que representa el dígito octal actual.
    int cociente = numero/8; // Calcula el cociente para la siguiente iteración, que se usará para obtener el siguiente dígito octal.
    residuos.push_back(residuo); // Agrega el residuo al vector de residuos, que se convertirá en los dígitos octales.
    numero = cociente; // Actualiza el número con el cociente para la siguiente iteración del proceso de conversión.
  }
  
  reverse(residuos.begin(), residuos.end()); // Invierte el orden de los residuos para que los dígitos octales estén en el orden correcto (de más significativo a menos significativo).
  cout << "el numero en octal es: "; // Imprime un mensaje explicativo antes de mostrar el resultado.
   for (int i = 0; i < residuos.size(); i++) // Recorre el vector de residuos para imprimir cada dígito octal.
  {
    cout << residuos [i]; // Muestra el dígito octal actual.
  }
}
void hexadecimal(int numero){ // Convierte un número a hexadecimal utilizando el método de residuos.
  vector <int> residuos; // Almacena los residuos de la división por 16, que corresponden a los dígitos hexadecimales.
  while (numero>0) // Continúa dividiendo el número por 16 hasta que queda 0 o menos.
  {
    int residuo = numero % 16; // Calcula el residuo de la división por 16, que representa el dígito hexadecimal actual.
    int cociente = numero / 16; // Calcula el cociente para la siguiente iteración, que se usará para obtener el siguiente dígito hexadecimal.
    residuos.push_back(residuo); // Agrega el residuo al vector de residuos, que se convertirá en los dígitos hexadecimales.
    numero = cociente; // Actualiza el número con el cociente para la siguiente iteración del proceso de conversión.
  }
  
  reverse(residuos.begin(), residuos.end()); // Invierte el orden de los residuos para que los dígitos hexadecimales estén en el orden correcto (de más significativo a menos significativo).
  cout <<"El hexadecimal del numero es: " ; // Imprime un mensaje explicativo antes de mostrar el resultado.
  for (int i = 0; i < residuos.size(); i++) // Recorre el vector de residuos para imprimir cada dígito hexadecimal.
  {
    cout << numAchar(residuos [i]); // Muestra el dígito hexadecimal actual. En una implementación completa, se debería convertir los valores de 10 a 15 a las letras A-F para representar correctamente el sistema hexadecimal.
  }
}
void  binario (int numero){
  vector<int> residuos; // Guarda los residuos y el último cociente.
  while (numero >1 ){ // Divide el número hasta que queda 1.
    int residuo = numero % 2; // Calcula el residuo de la división por 2.
    int cociente = numero / 2; // Calcula el cociente para la siguiente iteración.
    residuos.push_back(residuo); // Agrega el residuo al vector.
    numero = cociente; // Actualiza el número con el cociente.
  }
  residuos.push_back(numero); // Agrega el último valor al vector.
  reverse(residuos.begin(), residuos.end()); // Invierte el orden para mostrar el resultado correcto.
  cout << "El numero en binario es: "; // Mensaje explicativo.
  for (int i = 0; i < residuos.size(); i++){ // Imprime cada bit del resultado.
    cout << residuos[i]; // Muestra el elemento actual del vector.
  }
}
int main(){
  int  opcion;
  string numero;
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
    
    binario(stringAInt(numero, 10));
    break;
  case 2:
    cout<<"introduce el numero que quieres convertir hexadecimal"<< "\n";
    cin >> numero;
    validacion(numero);
    hexadecimal(stringAInt(numero, 10));
    break;
  case 3:
    cout<<"introduce el numero que quieres convertir octal"<< "\n";
    cin >> numero;
    
    octal(stringAInt(numero, 10));
    break;
  default:
    cout << "escoja una de las opciones";
    break;
  }
  

  
}

// Fin del programa

