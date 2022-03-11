#include<iostream>
#include<vector>

using namespace std;
int main(){
    int x;
    int w[] = {1, 2, 3};
    cout << w[0] << endl;
    vector<int> v ;
    cout << "Entre quantos números desejar" << endl;
    while (cin >> x){
        v.push_back(x);
    }
    for (auto& e: v){
        cout << e << endl;
    }

    int max = 0; //size_t
    int min = 999999; //size_t

    for (auto& e: v) {
        if (e > max){
            max = e;
        }
        if (e < min) {
            min = e;
        }
    }

    cout << "O maior número é " << max << endl;
    cout << "O menor número é " << min << endl;

    return 0;
}