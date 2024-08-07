//
// Created by enrico on 12/28/23.
//

#pragma once

#include <iostream>

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
    void print() {
        std::cout << "[ ";
        for (int i=0; i<sz; ++i) {
            std::cout << elem[i] << " ";
        }
        std::cout << "]";
    }
private:
    double* elem;
    int sz;
};



