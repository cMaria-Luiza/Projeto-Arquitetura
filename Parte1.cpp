#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <iostream>


static long tamanho = 300;


// Programa que soma todos os numeros de uma matriz de tamanho = 300
int main() {


    int matriz[tamanho][tamanho];
    int soma = 0;

    // preenche matriz
    for(int coluna = 0; coluna < tamanho; coluna++) {
        for(int linha = 0; linha < tamanho; linha++) {
            matriz[linha][coluna] = coluna+linha;
        }
    }

   //std::cout << std::fixed << std::setprecision(9) << std::left;


    auto start = std::chrono::system_clock::now();

    // soma elementos da matriz
    for(int coluna = 0; coluna < tamanho; coluna++) {
        for(int linha = 0; linha < tamanho; linha++) {
            soma = soma + matriz[linha][coluna];
        }
    }

    auto final = std::chrono::system_clock::now();
    std::chrono::duration<double> tempo = final - inicio;

    std::cout << "Tempo para o primeiro caso = " << tempo << " segundos" << std::endl;



    soma = 0;

    auto start = std::chrono::system_clock::now();

    // soma elementos da matriz
    for(int coluna = 0; coluna < tamanho; coluna++) {
        for(int linha = 0; linha < tamanho; linha++) {
            soma = soma + matriz[coluna][linha];
        }
    }

    auto final = std::chrono::system_clock::now();
    std::chrono::duration<double> tempo = final - inicio;

    std::cout << "Tempo para o segundo caso = " << tempo << " segundos" << std::endl;

    return 0;


}
