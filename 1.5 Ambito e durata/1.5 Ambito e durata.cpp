// 1.5 Ambito e durata.cpp : Defines the entry point for the application.
// una dichiarazione introduce un nome in un ambito( o campo di visibilità).
// - ambito locale: Un nome dichiarato in una funzione o in una lambda è chiamato nome locale.
//									Il suo ambito si estende dal punto della sua dichiarazione alla fine del 
//									blocco in cui essa avviene. Un blocco è delimitato da una coppia {}. I nomi
//									degli argomenti delle funzioni sono considerati nomi locali.
// - Ambito della clase: Un nome è detto nome del membro (o nome del membro della classe) se è
//									definito in una classe, all'esterno di qualsiasi funzione, lambda o enum class.
//									il suo ambito si estende dalla { di apertura della dichiarazione che
//									la racchiude fina alla } corrispondente.
// - Ambito del namespace: un nome è detto nome del membro del namespace se è definito in un
//									namespace all'esterno di qualsiasi funzione, lambda, classe o enum class.
//									Il suo ambito si estende dal punto di dichiarazione alla fine del suo namespace.
// Un nome non dichiarato all'interno di qualsiasi altro costrutto è detto nome globale e lo si definisce
// come interno al namespace globale.
// Inoltre sono possibili oggetti senza nome, come gli oggetti temporanei e quelli creati usando new.
//

#include "1.5 Ambito e durata.h"
#include <vector>

using namespace std;


vector<int> vec; // vec è globale

void fct(int arg) // fct è globale (una funzione globale)
// arg è locale (un argomento intero)
{
	string motto{ "Who dares wins" }; // motto è locale
	auto p = new Record{ "Hume" };    // p punta a un Record senza nome (creato da new)
}

struct Record {
	string name; // name è un membro di un Record (un membro string)
	// ...
};

int main()
{
	
	return 0;
}
