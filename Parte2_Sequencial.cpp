#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <iostream>


static long t = 1200;


// Programa que soma todos os numeros de uma matriz de tamanho = 300
int main() {

    int m[t][t];
    int soma = 0;

    // BOM USO

    auto inicio = std::chrono::system_clock::now();

    // preenche matriz
    for (int i = 0; i < t; i++) {/* linha a linha */
        for (int j = 0; j < t; j++) {
            m[i][j] = i*j*2;
        }
    }

    // soma elementos da matriz
    for (int i = 0; i < t; i++) { /* linha a linha */
        for (int j = 0; j < t; j++) {
            soma += m[i][j];
        }
    }

    auto final = std::chrono::system_clock::now();
    std::chrono::duration<double> tempo2 = final - inicio;

    std::cout << "Tempo para o segundo caso = " << tempo2.count() << " segundos" << std::endl;

    return 0;


}
