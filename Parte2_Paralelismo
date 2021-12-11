#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <iostream>


static long t = 1200;


int main() {

    // PARALELISMO

    int m[t][t];
    int soma = 0;

    auto inicio = std::chrono::system_clock::now();

    #pragma omp parallel default(none) shared(t, m) private(i, j)
    {
        #pragma omp for
        // preenche matriz
        for (int i = 0; i < t; i++) {/* linha a linha */
            for (int j = 0; j < t; j++) {
                m[i][j] = i*j*2;
            }
        }
    
        #pragma omp for nowait
        // soma elementos da matriz
        for (int i = 0; i < t; i++) { /* linha a linha */
            for (int j = 0; j < t; j++) {
                soma += m[i][j];
            }
        }
    
        auto final = std::chrono::system_clock::now();
        std::chrono::duration<double> tempo2 = final - inicio;
    
        std::cout << "Tempo para o segundo caso = " << tempo2.count() << " segundos" << std::endl;
    }

    return 0;


}
    
