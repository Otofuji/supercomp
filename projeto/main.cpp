#include<iostream>
#include<vector>
#include <string>

using namespace std;

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

int smith_waterman(int &n, int &m, int &a, int &b) {
    //REFERÊNCIAS
    //Martin Mann, Mostafa M Mohamed, Syed M Ali, and Rolf Backofen
    //Interactive implementations of thermodynamics-based RNA structure and RNA-RNA interaction prediction approaches for example-driven teaching
    //PLOS Computational Biology, 14 (8), e1006341, 2018.
    //Martin Raden, Syed M Ali, Omer S Alkhnbashi, Anke Busch, Fabrizio Costa, Jason A Davis, Florian Eggenhofer, Rick Gelhausen, Jens Georg, Steffen Heyne, Michael Hiller, Kousik Kundu, Robert Kleinkauf, Steffen C Lott, Mostafa M Mohamed, Alexander Mattheis, Milad Miladi, Andreas S Richter, Sebastian Will, Joachim Wolff, Patrick R Wright, and Rolf Backofen
    //Freiburg RNA tools: a central online resource for RNA-focused research and teaching
    //Nucleic Acids Research, 46(W1), W25-W29, 2018.

    //Usar matriz clássica do C++ cm struct
    //Criando uma matriz clássica do C++ usando struct, tendo por base exemplo do professor e https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    matriz alinhamento[n][m];

    string notation;
    string tempa = ' ';
    string tempb = ' ';
    int maximum = 0;

    tempa.append(n, a); //https://www.techiedelight.com/append-char-end-string-cpp/
    tempb.append(m, b);
    a = tempa;
    b = tempb;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            alinhamento[i][j].max = 0; //Por conveniência, a matriz inteira já foi inicializada com zeros
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                alinhamento[i-1][j-1].max++;
                alinhamento[i-1][j-1].max++;
                alinhamento[i-1][j-1].x = i-1;
                alinhamento[i-1][j-1].y = j-1;

                if (alinhamento[i-1][j-1].max > maximum) {
                    maximum = alinhamento[i-1][j-1].max;
                }
            }
            
            else {
                if (a[i] != b[j]) {
                    alinhamento[i-1][j-1].max--;
                    if (alinhamento[i-1][j-1].max < 0) {
                        alinhamento[i-1][j-1].max = 0;
                    }
                }
            }
        }
    }

    cout << '****************************' << endl;
    cout << a << endl;
    cout << notation << endl;
    cout << b << endl;
    cout << '****************************' << endl;

    //Match = +2
    //Mismatch = -1
    //Gap = -1

    return maximum;
}

int main() {
    int n; int m;
    string a; string b;
    cin >> n >> m >> a >> b;
    
    int smith_waterman_max = smith_waterman(&n, &m, &a, &b);

    return 0;
}
