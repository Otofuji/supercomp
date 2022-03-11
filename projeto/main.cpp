#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

typedef struct matrix{
    //  https://www.daniweb.com/programming/software-development/threads/320739/matrix-struct-and-adding-matrices

    int rows;
    int cols;
    float **mat;

} Matrix;

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
    //Criando uma matriz clássica do C++ usando struct, tendo por base https://gist.github.com/AaronGoldsmith/484c18cfb0637a18d1ec344090514fb7
    
    
     
    std::cin >> n >> m;
    x.reserve(n);
    y.reserve(n);
    for (int i = 0; i < n; i++) {
        double xt, yt;
        std::cin >> xt >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    int smith_waterman_max = smith_waterman(mat, x, y);
    
    
    return 0;
}