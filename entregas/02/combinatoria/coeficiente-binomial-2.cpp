// Implementação recursiva com memoization
#include <iostream>
#include <vector>
using namespace std;

// Vetor de vetores para armazenar os resultados intermediários
vector<vector<long long>> memo;

long long binomialMemo(int n, int k) {
    if(k > n) return 0;
    if(k == 0 || k == n) return 1;
    // Verifica se o valor já foi calculado
    if(memo[n][k] != -1) return memo[n][k];
    // Armazena o resultado da soma recursiva
    memo[n][k] = binomialMemo(n - 1, k - 1) + binomialMemo(n - 1, k);
    return memo[n][k];
}

int main() {
    int n, k;
    cout << "Digite n e k:" << endl;
    cin >> n >> k;
    
    // Inicializa a matriz de memoization com -1
    memo.assign(n + 1, vector<long long>(n + 1, -1));
    
    cout << "Coeficiente binomial (com memoization) C(" 
         << n << "," << k << ") = " << binomialMemo(n, k) << endl;
    return 0;
}