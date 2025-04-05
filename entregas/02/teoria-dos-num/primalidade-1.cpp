// força bruta
#include <iostream>
using namespace std;

bool isPrimeBrute(int n) {
    if(n < 2) return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cout << "Digite um número para testar a primalidade: ";
    cin >> num;
    if(isPrimeBrute(num))
        cout << num << " é primo." << endl;
    else
        cout << num << " não é primo." << endl;
    return 0;
}