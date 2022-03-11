#include <iostream>
#include <vector>
#include<algorithm>//para uso do sort

bool my_compare(float a, float b); //assinatura da função que será usada posteriormente - é declarada antes do main, para ser implementada depois do main;

using namespace std; 

int main () {

    vector<float> nums;
    nums.push_back(10.5); //inclui 10.5 em nums
    cout << nums[0] << endl; //exibe nums[0]
    nums.erase(nums.begin()); //remover algo do vector, passando a posição do vector. Vector tem dois ponteiros: begin e end, porque nunca sabemos o tamanho verdadeiro. Como usamos o nums.begin(), estamos apagando o começo do vetor. 
    cout << "O tamanho do vetor e " << nums.size() << endl; //exibe o tamanho do vetor
    nums.push_back(4.0); //inserindo mais alguns números no vector
    nums.push_back(7.5); //é também possível inserir números naturais, mas isso gerará um warning, e em seguida será transformado para float
    nums.push_back(23.4);
    cout << "O tamanho do vector e " << nums.size() << endl;

    for(auto& e: nums) cout << e << endl;
    cout << "Ordenando" << endl;

    sort(nums.begin(), nums.end(), my_compare); //fazendo o sort do começo de nums até o fim de nums por meio da função my_compare feita por nós
    for(auto& e: nums) cout << e << endl;

    return 0;
}

bool my_compare(float a, float b){ //implementação da função cuja assinatura foi declarada acima, antes do main
    return a > b;
}