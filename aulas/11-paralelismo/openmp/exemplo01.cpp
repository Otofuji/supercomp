#include <iostream>
#include <omp.h>
using namespace std;
int main(){
    int iam; 
    //  IMPORTANTE:
    //      Nunca colocar colchete nesta linha quando for pragma.
    //      Tudo que for pragma tem que inicializar o colchete na linha abaixo.
    #pragma omp parallel private (iam) //   Isolamento de variável. 
    { 
        iam = omp_get_thread_num();
        #pragma omp critical //Semáforo de região crítica em que tem que ser sequencial.
        //Sempre será executada a thread mais rápida. Quando coloco crítico, aqui tem a garantia que executaremos uma thread por vez. A ordem de execução pode ser diferente, mas sempre garantiremos que todas as threads rodem sequencialmente.

        //#pragma omp single; //Executa apenas a uma thread mais rápida.
        cout << "Olá. Sou a thread número " << iam << "." << endl;
    }
    
    return 0;
}

//  Compilar com >$ g++ -Wall -g -O3 -fopenmp exemplo01.cpp -o ex1

//  Output varia números entre 4 e 6 se não tiver a linha #pragma omp critical, pois as threads estão concorrendo entre si - output nunca será o mesmo. Threads estão numa região paralela sem um semáforo, entrando em race condition causando condições inconsistentes. Com a adição do #pragma omp critical, o output será padronizado e sempre será 6, pois serão computados em ordem na região crítica paralela. 