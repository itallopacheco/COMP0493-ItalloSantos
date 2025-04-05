// primalidade otimizado
#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeOptimized(int n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0)
        return false;
    int sqrtN = static_cast<int>(sqrt(n));
    for(int i = 3; i <= sqrtN; i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cout << "Digite um número para testar a primalidade : ";
    cin >> num;
    if(isPrimeOptimized(num))
        cout << num << " é primo." << endl;
    else
        cout << num << " não é primo." << endl;
    return 0;
}