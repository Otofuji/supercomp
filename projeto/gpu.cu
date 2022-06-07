#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <thrust/random.h>
#include <thrust/iterator/counting_iterator.h>
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include <omp.h>


int main() {
    // Alocação do vetor na CPU e leitura de dados da entrada-padrão
    int n;
    int m;
    std::cin >> m >> n;
    thrust::host_vector<double> a(m);
    for(int i=0;i<m;i++)
       std::cin>>a[i];
    thrust::host_vector<double> b(n);
    for(int i=0;i<n;i++)
       std::cin>>b[i];
    // Alocação do vetor na GPU e inicialização de dados
    thrust::device_vector<double> aa(a);
    thrust::device_vector<double> bb(b);

    ////1. Gerar uma subsequencia sb=b[j,j+1,...,j+k] de b, de tamanho aleatório k, 1<=k<=m, e 0<=j<=m 
    thrust::default_random_engine generator1(1);
    thrust::uniform_real_distribution<double> distribution1(1, m);
    int k = distribution1(generator1);
    while (k < m*2) k = k*2;
    k = k/3;
    thrust::default_random_engine generator2(1);
    thrust::uniform_real_distribution<double> distribution2(0, m);
    int j = distribution2(generator2);
    while (j < m*2) j = j*2;
    j = j/3;
    
    thrust::default_random_engine generator3(1);
    thrust::uniform_real_distribution<double> distribution3(m+n, m*n);
    int p = distribution3(generator3);
    int max = 0;
    int max_for_now;
    for (int q = 0; q < p; q++) {
        int a_size;
        if (q+k < m-1) {
            a_size = q+k;
        }
        else {
            if (q < m-1) {
                a_size = m-2;
            }
            else break;
        }

        /*
---------------------------------------------------------------------
        */
        
        // thrust::counting_iterator<int>c0(1);
        // thrust::counting_iterator<int>c1(m+1);
        // thrust::device vector<int> calc[2];
        // calc[0].resize(N+1);
        // calc[1].resize(N+1);
        // thrust::fill(calc[0].begin(),calc[0].end(),0);
        // thrust::device_vector<char> d_s(n);
        // for (int i = 0; i < n; i++) {
        //     d_s[i] = s[i];
        // };
        // for (int j = 0; j < m; j++) {
        //     char letradeT = T[j];
        //     thrust::transform(c0, c1, calc[1].begin() + 1, meu_functor(d_s.data(), letradeT, calc[0].data()));
        //     thrust::inclusive_scan(calc[1].begin()+1, calc[1].end(), calc[0].begin()+1, thurst::maximum<int>());
        // };

        // thrust::reduce(calc[0].begin()+1, calc[0].end(), 1, thrust::maximum<int>());

        /*
---------------------------------------------------------------------
        */

        while (max_for_now > max) {
            max++;
        }

        std::cout << max;
    }

    return 0;
}