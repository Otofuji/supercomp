#include <iostream>
#include<omp.h>
#include <iomainip>
#define NUM_THREADS 4
using namespace std ;

int main (){
    long num_steps = 10000000000;
    double step;
    int i, nthreads;
    double x, pi, sum[NUM_THREADS];
    double tdata = omp_get_wtime();
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int id ;
        threads = omp_get_num_threads();
        //TERMINAR
    }
    return 0;
}