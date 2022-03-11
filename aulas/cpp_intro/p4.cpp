#include<iostream>
#include<vector>
using namespace std;
int sqr_it(int& x); //assinatura da função tem que estar antes do main
int main (){
    int t = 10;
    cout << sqr_it(t) << endl;
    cout << "valor atual de t = " << t << endl;
    return 0;
}
int sqr_it(int& x){ //implementação da função assinada antes do main, mas implementada após o main
    x = x*x;
    return x;
}