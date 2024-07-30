/* 
Una dichiarazione è un'istruzione che introduce un'entità nel
programma e ne specifica il tipo:
- un tipo definisce un set di possibili valori e uno di
	possibili operazioni (per un oggetto);
- un oggetto è una porzione di memoria che contiene un valore
  di ualche tipo;
- un valore è un set di bit interpretato secondo un tipo;
- una variabile è un oggetto con un nome.
*/

#include "1.4 Types.h"

using namespace std;

void some_function()
{
	double d = 2.2;
	int i = 7;
	d = d + i;
	i = d * i;
}

int main()
{
	bool b = true; // Booleano, i valori possibili sono true e false
	char c = 'c'; // carattere ascii
	int i = 1;  // intero
	double d = 4.6; // numero in virgola mobile a doppia precisione
	unsigned u = 4; // intero non negativo
	return 0;
}
