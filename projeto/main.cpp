#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct matriz { //Com base em exemplo do professor e em https://people.engr.tamu.edu/djimenez/ut/utsa/cs1723/lecture3.html
    int x;
    int y;
    double max;
};

int smith_waterman(int n, int m, string a, string b) {
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
    string tempa = " ";
    string tempb = " ";
    int maximum = 0;
    int maxi = 0;
    int maxj = 0;
 
    tempa.append(a); //https://www.techiedelight.com/append-char-end-string-cpp/
    tempb.append(b);
    a = tempa;
    b = tempb;
    n++;
    m++;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            alinhamento[i][j].max = 0; //Por conveniência, a matriz inteira já foi inicializada com zeros        
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) {
                if (alinhamento[i-1][j-1].max > alinhamento[i][j-1].max && alinhamento[i-1][j-1].max > alinhamento[i-1][j].max) {
                
                    alinhamento[i][j].x = i-1;
                    alinhamento[i][j].y = j-1;

                    cout << endl << "DIAGONAL" << endl << alinhamento[i][j].x << " " << alinhamento[i][j].y << endl << a[i] << " " << b[j] << endl << alinhamento[i][j].max << endl;
                 
                    
                }
                else {
                    if (alinhamento[i][j-1].max > alinhamento[i-1][j].max) {
                        if (j>1) {
                            alinhamento[i][j].x = i;
                            alinhamento[i][j].y = j-1;
                        }
                        
                    }
                    else {
                        if (i>1) {
                            alinhamento[i][j].x = i-1;
                            alinhamento[i][j].y = j;    
                        }
                        
                    }
                }                
                
                alinhamento[i][j].max = alinhamento[alinhamento[i][j].x][alinhamento[i][j].y].max + 2;

                if (alinhamento[i][j].max < 0) {
                    alinhamento[i][j].max = 0;
                }

                
            }

            else {            
                if (alinhamento[i][j].max < alinhamento[i-1][j-1].max) {
                    if (i-1 > 0 && j-1 > 0) {
                        alinhamento[i][j].max = alinhamento[i-1][j-1].max;
                        alinhamento[i][j].x = i-1;
                        alinhamento[i][j].y = j-1;
                    }
                    
                }
                else {
                    if (alinhamento[i][j].max < alinhamento[i][j-1].max) {
                        if (j-1 > 0) {
                            alinhamento[i][j].max = alinhamento[i][j-1].max;
                            alinhamento[i][j].x = i;
                            alinhamento[i][j].y = j-1;
                        }
                        
                    }
                    else {
                        if (i-1 > 0) {
                            alinhamento[i][j].max = alinhamento[i-1][j].max;
                            alinhamento[i][j].x = i-1;
                            alinhamento[i][j].y = j;
                        }
                        
                    }
                }  
            }
                
            if (alinhamento[i][j].max > maximum) {
                maximum = alinhamento[i][j].max;
                maxi = i;
                maxj = j;
            }

            if (alinhamento[i][j].max == 4) {
                cout << endl << "QUATRO" << endl << alinhamento[i][j].x << " " << alinhamento[i][j].y << endl << endl;
            }
        }
    }    
    
    while (alinhamento[maxi][maxj].max != 0){
        if (alinhamento[maxi][maxj].x == maxi-1) {
            if (alinhamento[maxi][maxj].y == maxj-1) {
                notation.append("*");
                cout << "MATCH" << endl;
                maxi--;
                maxj--;
                if (maxi<0) {maxi = 0;}
                if (maxj<0) {maxj = 0;}
            }
            else {
                notation.append("_");
                cout << "GAP" << endl;
                maxi--;
                
                if (maxi<0) {maxi = 0;}
                if (maxj<0) {maxj = 0;}
            }
        }
        else {
            if (alinhamento[maxi][maxj].y == maxj-1) {
                notation.append("_");
                cout << "GAP" << endl;
                maxj--;
                if (maxi<0) {maxi = 0;}
                if (maxj<0) {maxj = 0;}
            }
            else {
                notation.append(" ");
                cout << "MISMATCH" << endl;
                alinhamento[maxi][maxj].max = 0;
                
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j == m-1) {cout << alinhamento[i][j].max << endl;}
            else {cout << alinhamento[i][j].max;}
        }
    }
    
    
    //string result;

    // for (int i = notation.length(); i >= 0; i--) {
    //     result.append(notation.at(i)); //https://www.cplusplus.com/reference/string/string/at/
    // }
    

    std::cout << "****************************" << endl;
    std::cout << a << endl;
    // std::cout << result << endl;
    std::cout << b << endl;
    std::cout << "****************************" << endl;

    //Match = +2
    //Mismatch = -1
    //Gap = -1

    return maximum;
}

int main() {
    int n; int m;
    string a; string b;
    std::cin >> n >> m >> a >> b;
    int smith_waterman_max = smith_waterman(n, m, a, b);
    std::cout << "smith_waterman_max: " << smith_waterman_max << endl;

    return 0;
}
