#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<random>

using namespace std;

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

int smith_waterman(int m, int n, string a, string b) {
    //REFERÊNCIAS
    //Martin Mann, Mostafa M Mohamed, Syed M Ali, and Rolf Backofen
    //Interactive implementations of thermodynamics-based RNA structure and RNA-RNA interaction prediction approaches for example-driven teaching
    //PLOS Computational Biology, 14 (8), e1006341, 2018.
    //Martin Raden, Syed M Ali, Omer S Alkhnbashi, Anke Busch, Fabrizio Costa, Jason A Davis, Florian Eggenhofer, Rick Gelhausen, Jens Georg, Steffen Heyne, Michael Hiller, Kousik Kundu, Robert Kleinkauf, Steffen C Lott, Mostafa M Mohamed, Alexander Mattheis, Milad Miladi, Andreas S Richter, Sebastian Will, Joachim Wolff, Patrick R Wright, and Rolf Backofen
    //Freiburg RNA tools: a central online resource for RNA-focused research and teaching
    //Nucleic Acids Research, 46(W1), W25-W29, 2018.

    //Usar matriz clássica do C++ cm struct
    //Criando uma matriz clássica do C++ usando struct, tendo por base exemplo do professor e https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
   
    string notation;
    string tempa = " ";
    string tempb = " ";
    int maximum = 0;
    int maxi = 0;
    int maxj = 0;
 
    
    a = " " + a;
    b = " " + b; 

    n = n + 1;

    m = m + 1;
   // matriz alinhamento[m][n]; //ARRUMEI A POSICAO
   
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

         //   cout << alinhamento[i][j].max << " APONTANDO PARA " << alinhamento[i][j].x << " " << alinhamento[i][j].y << endl;
            
        }
    }    
    
    
    //Match = +2
    //Mismatch = -1
    //Gap = -1

    return maximum;
}


int busca_local(int m, int n, string a, string b) {
    //1. Gerar uma subsequencia sb=b[j,j+1,...,j+k] de b, de tamanho aleatório k, 1<=k<=m, e 0<=j<=m 
    default_random_engine generator1;
    uniform_int_distribution<int> distribution1(1, m);
    int k = distribution1(generator1);
    while (k < m*2) k = k*2;
    k = k/3;
    cout << "int k: " << k << endl;
    
    default_random_engine generator2;
    uniform_int_distribution<int> distribution2(0, m);
    int j = distribution2(generator2);
    while (j < m*2) j = j*2;
    j = j/3;
    cout << "int j: " << j << endl;
    

    string sb = b.substr(0, k);
    
    cout << "string b: " << b << endl;
    cout << "string sb: " << sb << endl; 

    //2. Gerar um número aleatório inteiro positivo p
    default_random_engine generator3;
    uniform_int_distribution<int> distribution3(m+n, m*n);
    int p = distribution3(generator3);
    cout << "int p: " << p << endl;
    
    //3. Gerar p subsequencias sa=a[i,i+1,...,i+k] de a, com tamanho k calculado no passo (1), 0<=i<=n

    string sa;
    int max_for_now;
    int max = 0;
    
    for (int q = 0; q < p; q++) {
        if (q+k < a.size()) sa = a.substr(q, q+k); //https://www.tutorialspoint.com/substring-in-cplusplus e https://www.tutorialspoint.com/5-different-methods-to-find-length-of-a-string-in-cplusplus 
        else {
          if (q < a.size())  sa = a.substr(q, a.size()-1);
          else break;
        }
    
    //4. Calcular os scores de cada par (sa,sb) com os pesos wmat, wmis e wgap
    
    //int wmat = 2;
    //int wmis = -1;
    //int wgap = -1;
 
        max_for_now = smith_waterman(sa.size(), sb.size(), sa, sb);
        while (max_for_now > max) {
            max++;
        }    
    }
    
    //5. Devolver o score máximo m entre os scores do passo (4) e as subsequencias associadas a ele
    
    return max;
}

 
int busca_exaustiva(int m, int n, string a, string b) {
    
   

    //ALGORITMO BUSCA EXAUSTIVA
    //Entrada: Duas sequencias de DNA a e b
    //    Pesos wmat, wmis e wgap para match, mismatch e gap respectivamente
    //Saída: Score de um alinhamento das sequencias
    //    Subsequencias alinhadas

    //1. Gerar todas as subsequencias a´ e b´ não-nulas de a e b, respectivamente.
    
    //2. Calcular os alinhamentos de cada par de subsequencias (a´, b´) com os pesos wmat, wmis e wgap


    string sa;
    string sb;
    int max_for_now;
    int max;
    max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m || k < n; k++) {
                sa = a.substr(k,m);
                sb = b.substr(k,n);
                max_for_now = smith_waterman(sa.size(), sb.size(), sa, sb);
                while (max_for_now > max) {
                    max++;
                }
            }
        }
    }
    
     

    //3. Devolver o score máximo m entre os scores do passo (2) e as subsequencias associadas a ele
    
    
   

    return max;
}

 

int main() {
    int n; int m;
    string a; string b;
    std::cin >> m >> n >> a >> b;
    int smith_waterman_max = smith_waterman(m, n, a, b);
    int busca_local_max = busca_local(m, n, a, b);
    int busca_exaustiva_max = busca_exaustiva(m, n, a, b);
    std::cout << "smith_waterman_max: " << smith_waterman_max << endl;
    std::cout << "busca_local_max: " << busca_local_max << endl;
    std::cout << "busca_exaustiva_max: " << busca_exaustiva_max << endl;

    return 0;
}
