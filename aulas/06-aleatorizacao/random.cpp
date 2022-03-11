#include<iostream>
#include <random>
using namespace std;

int main() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-2,5); //int, gerando números inteiros aleatórios entre -2 e 5
    //uniform_real_distribution<double> distribution(0.0,1.0); //double, gerando números reais aleatórios entre 0 e 1
    cout << distribution(generator); //gera o número 
    return 0;
}