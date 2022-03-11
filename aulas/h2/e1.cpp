#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    float x;
    float s;
    cout << "Entre um número: ";
    cin >> x;
    s = 0.0;
    for(int i = 0; i <= x; i++)  s += 1/pow(2, i);
    
    cout << fixed << setprecision(15) << s << endl;
    return 0;
}