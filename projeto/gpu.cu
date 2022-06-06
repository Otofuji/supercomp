#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<random>
#include <omp.h>

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

struct sw
{
    int m, n;
    sw(int m_) : m(m_) {};
    
    __host__ __device__
    int operator()(const char& a, const char& b) {
            char notation;
            char tempa = " ";
            char tempb = " ";
            int maximum = 0;
            int maxi = 0;
            int maxj = 0;
            a = " " + a;
            b = " " + b; 
            n = n + 1;
            m = m + 1;
        //PRECISAMOS ALOCAR DINAMICAMENTE ESSA MATRIZ PARA NAO HAVER ESTOURO DE MEMORIA
            matriz* alinhamento[m];
            for (int i = 0; i < m; i++)
                alinhamento[i] = (matriz*)malloc(n * sizeof(matriz));
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    alinhamento[i][j].max = 0; //Por conveniência, a matriz inteira já foi inicializada com zeros       
                    alinhamento[i][j].x = 0;
                    alinhamento[i][j].y = 0; 
                }
            }
            for (int i = 1; i < m; i++){
                for (int j = 1; j < n; j++) {
                // cout << "POSICAO " << i << " " << j << " CHARS " << a[i] << " " << b[j] << " VALOR ";
                    if (a[i] == b[j]) {
                        if (alinhamento[i-1][j-1].max +2 >= alinhamento[i][j-1].max - 1 && alinhamento[i-1][j-1].max +2  >= alinhamento[i-1][j].max - 1) {
                            alinhamento[i][j].x = i-1;
                            alinhamento[i][j].y = j-1;                    
                            alinhamento[i][j].max = alinhamento[i-1][j-1].max + 2;
                        }
                        else if (alinhamento[i][j-1].max - 1 > alinhamento[i-1][j].max - 1) {
                                    alinhamento[i][j].x = i;
                                    alinhamento[i][j].y = j-1;
                                    alinhamento[i][j].max = alinhamento[i][j-1].max - 1;
                        } else {
                                    alinhamento[i][j].x = i-1;
                                    alinhamento[i][j].y = j;    
                                    alinhamento[i][j].max = alinhamento[i-1][j].max - 1;
                        }                                
                    }
                    else {            
                        if (alinhamento[i-1][j-1].max -1 >= alinhamento[i][j-1].max -1 && alinhamento[i-1][j-1].max -1 >= alinhamento[i-1][j].max - 1) {
                            alinhamento[i][j].x = i-1;
                            alinhamento[i][j].y = j-1;
                            alinhamento[i][j].max = alinhamento[i-1][j-1].max -1 ;
                        }
                        else if (alinhamento[i][j-1].max - 1 > alinhamento[i-1][j].max - 1) {
                                    alinhamento[i][j].x = i;
                                    alinhamento[i][j].y = j-1;
                                    alinhamento[i][j].max = alinhamento[i][j-1].max - 1;
                        } else {
                                    alinhamento[i][j].x = i-1;
                                    alinhamento[i][j].y = j;    
                                    alinhamento[i][j].max = alinhamento[i-1][j].max - 1;                
                        }                                
                    }
                    if (alinhamento[i][j].max > maximum) {
                        maximum = alinhamento[i][j].max;
                        maxi = i;
                        maxj = j;
                    }
                    if (alinhamento[i][j].max < 0) {
                            alinhamento[i][j].max = 0;
                        }
                }
            }    
            //Match = +2
            //Mismatch = -1
            //Gap = -1
            return maximum;
    }
};

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
    thrust::device_vector<double> a(a);
    thrust::device_vector<double> b(b);
    //inicial do algoritmo de busca exaustiva
    char sa;
    char sb;
    int max_for_now = 0;
    int max = 0;
    //loop da busca exaustiva
    //a ideia aqui é aproveitar a lógica da busca exaustiva, mas implementando em gpu para paralelizar usando thrust

    return max;
}