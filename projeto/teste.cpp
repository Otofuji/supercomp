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
 
    cout << "N = " << n << "\nM = " << m << endl;


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