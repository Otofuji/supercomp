#include<iostream>
#include<vector>
#include <string>

using namespace std;

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

int smith_waterman(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int max = 0;
    int n = x.size();

    //usar matriz clássica do C++ cm struct
    //Inicializar H[i,0]=0, 0≤i≤n
    for (int i = 0; i < n; i++){

    }

    //Inicializar H[0,j]=0, 0≤j≤m
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
    //Criando uma matriz clássica do C++ usando struct, tendo por base exemplo do professor e https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html


    int n;
    int m;
    string x;
    string y;

    cin >> n >> m >> x >> y;
    matriz alinhamento[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            alinhamento[i][j].max = 0;
        }
    }

    int smith_waterman_max = smith_waterman(&alinhamento.max, &alinhamento.x, &alinhamento.y);

    return 0;
}
