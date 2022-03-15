#include<iostream>
#include<vector>
#include <string>

using namespace std;

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

int smith_waterman(int &n, int &m, int &x, int &y) {
    //REFEREÊNCIAS
    //Martin Mann, Mostafa M Mohamed, Syed M Ali, and Rolf Backofen
    //Interactive implementations of thermodynamics-based RNA structure and RNA-RNA interaction prediction approaches for example-driven teaching
    //PLOS Computational Biology, 14 (8), e1006341, 2018.
    //Martin Raden, Syed M Ali, Omer S Alkhnbashi, Anke Busch, Fabrizio Costa, Jason A Davis, Florian Eggenhofer, Rick Gelhausen, Jens Georg, Steffen Heyne, Michael Hiller, Kousik Kundu, Robert Kleinkauf, Steffen C Lott, Mostafa M Mohamed, Alexander Mattheis, Milad Miladi, Andreas S Richter, Sebastian Will, Joachim Wolff, Patrick R Wright, and Rolf Backofen
    //Freiburg RNA tools: a central online resource for RNA-focused research and teaching
    //Nucleic Acids Research, 46(W1), W25-W29, 2018.


    //usar matriz clássica do C++ cm struct
    //Criando uma matriz clássica do C++ usando struct, tendo por base exemplo do professor e https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    matriz alinhamento[n][m];
    
    //Inicializar H[i,0]=0, 0≤i≤n
    //Inicializar H[0,j]=0, 0≤j≤m
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            alinhamento[i][j].max = 0; //Por conveniência, a matriz inteira já foi inicializada com zeros
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            
        }
    }

    //Match = +2
    //Mismatch = -1
    //Gap = -1

    //Para cada 1≤i≤n e 1≤j≤m:
    //          Calcular diagonal = H[i-1,j-1] + w(a[i],b[j]), onde w(a[i],b[j])=2 se houve match,
    //                       w(a[i],b[j])= -1 se houve mismatch e
    //                       w(a[i],b[j])= -1 se houve gap
    //          Calcular deleção  = H[i-1,j] - 1
    //          Calcular inserção = H[i,j-1] - 1
    //          Calcular H[i,j]=máximo (0, diagonal, deleção, inserção)
    //Retornar o máximo de H[_,_]
    
    return max;
}

int main() {
    int n; int m;
    string x; string y;
    cin >> n >> m >> x >> y;
    
    int smith_waterman_max = smith_waterman(&n, &m, &x, &y);

    return 0;
}
