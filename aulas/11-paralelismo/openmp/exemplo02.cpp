#include <iostream>
#include <omp.h>
using namespace std;
int main(){
    int N = 100;
    int nthreads, tid, idx;
    float a[N], b[N], c[N];
    //  IMPORTANTE:
    //      Nunca colocar colchete nesta linha quando for pragma.
    //      Tudo que for pragma tem que inicializar o colchete na linha abaixo.
    #pragma omp parallel master //   Isolamento de variável. 
    { 
        nthreads = omp_get_num_threads();
        cout << "Número de threads = " << nthreads << "." << endl;
    }

    #pragma omp parallel for
    for(idx = 0; idx < N; idx++) {
        a[idx] = b[idx] = 1.0;
    }
    #pragma omp parallel for private (tid)
    for (idx = 0 ; idx < N ; idx++){
        c[idx] = a[idx] + b[idx];
        tid = omp_get_thread_num();
        cout << "Thread " << tid << "c, c[" << " = " << c[idx] << endl;
    }
    
    return 0;
}

//  Compilar com >$ g++ -Wall -g -O3 -fopenmp exemplo02.cpp -o ex2
