// 1.6-costanti.cpp : Defines the entry point for the application.
// C++ supporta due concetti di immutabilità (un oggetto con uno stato non modificabile).
// - const: in linea di massima significa "prometto di non cambiare questo valore". E' usato
//					principalmente per specificare interfacce, in modo che i dati possano essere passati
//					a funzioni usando puntatori e riferimenti senza timore che siano modificati. 
//					Il compilatore applica la promessa fatta da const. Il valore di una costante può 
//					essere calcolato in fase di esecuzione.
// - constexpr: in linea di massima significa "da valutare all'atto della compilazione". E' usato
//					principalmente per specificare costanti, per consentire il posizionamento dei dati
//					nella memoria di sola lettura (dove esistono meno possibilità che vengono corrotti)
//					e per migliorare le prestazioni. Il valore di una constexpr può essere calcolato
//					dal compilatore.
//

#include "1.6-costanti.h"

using namespace std;

constexpr double square(double x) { return x * x; }

double sum(const vector<double>& v)	// sum non modificherà il suo argomento
{
	double s{};
	for (const auto& i : v) {
		s += i;
	}
	return s;
}

int main()
{
	
	constexpr int dmv = 17;							// dmv è una costante con nome
	int var = 17;												// var non è una costante
	const double sqv = sqrt(var);				// è una costante con nome,
																			// possibilmente calcolata in fase di esecuzione
	

	vector<double> v{ 1.2, 3.4, 4.5 };  // v non è una costante
	const double s1 = sum(v);						// OK: sum(v) è valutato in fase di esecuzione
	//constexpr double s2 = sum(v);     // error: sum(v) non è un'espressione costante
	// per poter essere usata in un espressione costante, ovvero un espressione che sarà valutata dal compilatore,
	// una funzione dev'essere definita constexpr o consteval. per esempio:


	return 0;
}
