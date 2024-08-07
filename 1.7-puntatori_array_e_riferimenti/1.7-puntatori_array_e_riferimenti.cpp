﻿/*
 * La raccolta di elementi piu' elementare e' una sequenza di elementi dello stesso tipo allocata in modo contiguo,
 * chiamata array. Questo e' fondamentalmente quello che l'harware ci offre
 *
 */

#include "1.7-puntatori_array_e_riferimenti.h"

using namespace std;

void for_classica() {
  int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7,8, 9 };
  for (auto i = 0; i != 10; ++i) {
    cout << v[i] << '\n';
  }
}

void range_for() {
  int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for (auto x : v) {
    cout << x << '\n';
  }
  // oppure
  for (auto x : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }) {
    cout << x << '\n';
  }
}

void increment() {
  /*
   * In una dichiarazione, il suffisso unario & significa "riferimento a". Un riferimento e' simile a un puntatore,
   * con la differenza che non e' necessario usare un prefisso * per accedere al valore a cui si fa riferimento.
   * Inoltre, non e' possibile far si che un riferimento si riferisca a un altro oggetto dopo la sua inizializzazione.
   *
   * I riferimenti sono particolarmente utili per specificare gli argomenti di funzioni. Es. void sort(vector<int>&);
   * Quando non vogliamo modificare un argomento ma non vogliamo comunque il costo della copia, usiamo un riferimento
   * const, ovvero un riferimento a una costante. Es. double sum(const vector<int>& v);
   */
  int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for (auto& x : v) {       // in questo modo viene modificato l'elemento dell'array e nono la sua copia
    ++x;
  }
  for (auto i = 0; i != 10; ++i) {
    cout << v[i] << '\n';
  }
}

// IL PUNTATORE NULL
int count_x(const char* p, char x)
// conta il numero di occorrenze di x in p[]
// si presume che p punti a un array di char con termine zero (o a nulla)
{
  if (p == nullptr) {
    return 0;
  }

  int count = 0;
  for (; *p != 0; ++p) {  // E' possibile spostare il puntatore in modo che punti al successivo elemento di un array usando ++
    if (*p == x) {
      ++count;
    }
  }
  return count;
}

int count_x_alt(const char* p, char x)
// conta il numero di occorrenze di x in p[]
// si presume che p punti a un array di char con termine zero (o a nulla)
{
  if (p == nullptr) {
    return 0;
  }

  int count = 0;
  while (*p) {
    if (*p == x) {
      ++count;
    }
    ++p;
  }
  return count;
}

int main() {

  {
    // nelle dichiarazioni [] signifca "array di" e * singifica "puntatore a"
    // La dimensione di un array deve essere un'espressione costante
    char v[6];                                  // array di 6 char
    char* p;                                    // puntatore a carattere
  }

  {
    // In un'espressione, il prefizzo unario * significa "contenuto di" e
    // il prefisso unario & significa "indirizzo di"
    char v[]{ "Madonna" };
    char* p = &v[3];                             // punta al 4 elemento di v
    char x = *p;                                 // *p e' l'oggetto a cui punta p
  }

  //for_classica();

  //range_for();
  //increment();
  {
    /*
     * Quando non disponiamo di un oggetto a cui puntare, o se dobbiamo rappresentare il concetto di
     * "nessun oggetto disponibile", passiamo al puntatore il valore nullptr. Esiste un solo nullptr condiviso da
     * tutti i tipi di puntatori
     */
    double* pd = nullptr;
    vector<double>* list = nullptr;
    //int x = nullptr;  errore: nullptr e' un puntatore, non un intero.
  }

  return 0;
}


