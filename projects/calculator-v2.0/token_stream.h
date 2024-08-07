//
// Created by coppolecchia on 1/24/2024.
//

#pragma once
#include <exception>
#include <stdexcept>
#include <iostream>

class Token {
public:
  char kind; // usiamo 8 per indicare il tipo numerico
  double value;
};

class TokenStream {
private:
  bool full{ false };
  Token buffer;
public:
  Token get();
  void putback(Token t);
};
