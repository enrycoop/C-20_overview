﻿// 4.2-asserzioni.cpp : Defines the entry point for the application.
//

#include "4.2-asserzioni.h"

/*
 * Attualmente non esiste un modo generale e standard di scrivere test opzionali in fase di esecuzione.
 * Tuttavia, per molti programmi di grandi dimensioni, è necessario supportare gli utenti che desiderano basarsi su
 * controlli estesi in fase di esecuzione durante i test, ma che poi distribuiscono il codice con controlli minimi.
 * Per ora dobbiamo affidarci a meccanismi ad hoc, e ce ne sono molti di questo tipo. Devono essere flessibili, generali
 * e non implicare alcun costo se non abilitati. Ciò prevede semplicità di concezione e raffinatezza nell'attuazione.
 * Ecco uno schema che si può usare da Stroustrup.
 *
 */

#include <cassert>
#include <iostream>

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///                                                   ASSERZIONI                                                     ///
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum class ErrorAction { ignore, throwing, terminating, logging };    // alternative per la gestione degli errori

constexpr ErrorAction default_error_action = ErrorAction::throwing;   // un default

enum class ErrorCode { range_error, length_error };                    // singoli errori

std::string error_code_name[]{ "Range error", "Length error" };    // nomi di singoli errori

template<ErrorAction action = default_error_action, class C>
constexpr void expect(C cond, ErrorCode x)
/*
 * Intraprende "action" se la condizione prevista
 * "cond" non e' valida
 */
{
  if constexpr (action == ErrorAction::logging)
    if (!cond()) std::cerr << "expect() failure: " << int(x) << ' ' << error_code_name[int(x)] << '\n';
  if constexpr (action == ErrorAction::throwing)
    if (!cond()) throw x;
  if constexpr (action == ErrorAction::terminating)
    if (!cond()) std::terminate();
  // o nessuna azione
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                   UTILIZZO                                                       ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Vector {
public:
  Vector(int s) : elem{ new double[s] }, sz{ s } {}
  double& operator[](int i);
  int size() noexcept { return sz; } // una funzione che non dovrebbe mai lanciare un eccezione puo essere dichiarata
  //noexcept
  void print() {
    std::cout << "[ ";
    for (int i = 0; i < sz; ++i) {
      std::cout << elem[i] << " ";
    }
    std::cout << "]";
  }
private:
  double* elem;
  int sz;
};

/*
 * Questo controlla se un indice è nell'intervallo e intraprende l'azione predefinita, lanciando un eccezione
 * altrimenti. La condizione che dovrebbe valere, viene passata a expect() come lambda. I test if constexpr vengono
 * eseguiti in fase di compilazione, quindi viene eseguito al massimo un test in fase di esecuzione per ogni chiamata
 * di expect(). Impostate action a Error_action::ignore e non verra' intrapresa alcuna azione ne' generato alcun codice
 * per expect(). Per supportare la registrazione, e' necessario definire una tabella di error_code_name.
 * Le informazioni di registrazione potrebbero essere migliorate utlilizzando source_location (cap 16).
 */

double& Vector::operator[](int i)
{
  // Utilizzo asserzione
  expect<ErrorAction::logging>([i, this] {return 0 < i && i < sz; }, ErrorCode::range_error);
  return elem[i];
}

int main()
{
  Vector v(5);
  v[6];
  assert(v.size() != 0);

  static_assert(4 <= sizeof(int), "Integers are too small!");
  return 0;
}
