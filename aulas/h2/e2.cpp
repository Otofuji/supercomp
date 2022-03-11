#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int n = 0;
    double media = 0.0;
    double desvpad = 0.0;
    cout << "Digite o valor de n: " ;
    cin >> n;
    vector<double> values;
    double input = 0.0;
    for(int i = 0; i < n; i++) {
        cin >> input;
        values.push_back(input);
        media += input;
    }
    media /= n;

    for(auto valor: values) {
        desvpad += ((valor-media)*(valor-media));
    }

    desvpad /= n;
    cout << fixed << setprecision(10) << "média " << media << " desvpad " << desvpad << endl;

    return 0;
}