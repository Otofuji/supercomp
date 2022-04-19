#include <iostream>
#include<omp.h>
using namespace std;

int main(){
    long num_steps = 10000000;
    double step;

    int i;
    double x, pi, sum = 0.0;
    double tdata = omp_get_wtime();
    step = 1.0/(double) num_steps;
    omp_set_num_threads(4);
    #pragma omp parallel for reduction(+: sum)
    for (i=0; i < num_steps; i++) {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);

    }

    pi = step * sum;
    tdata = omp_get_wtime() - tdata;

    cout << "Valor de PI aproximado: " << pi << endl;
    cout << "Tempo em segundos: " << tdata << endl;


    return 0;
}