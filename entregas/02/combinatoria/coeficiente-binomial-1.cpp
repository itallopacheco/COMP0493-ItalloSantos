// Implementação analítica do coeficiente binomial
#include <iostream>
using namespace std;

long long binomialAnalitico(int n, int k) {
    if(k > n) return 0;
    if(k == 0 || k == n) return 1;
    // Utiliza a simetria para reduzir o número de multiplicações
    if(k > n - k) k = n - k;
    long long resultado = 1;
    for(int i = 1; i <= k; i++){
        resultado = resultado * (n - i + 1) / i;
    }
    return resultado;
}

int main() {
    int n, k;
    cout << "Digite n e k:" << endl;
    cin >> n >> k;
    cout << "Coeficiente binomial (analítico) C(" << n << "," << k << ") = " 
         << binomialAnalitico(n, k) << endl;
    return 0;
}