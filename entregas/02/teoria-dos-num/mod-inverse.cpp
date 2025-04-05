// algoritmo Estendido de Euclides

#include <iostream>
using namespace std;

// Retorna o gcd(a, b) e atualiza x e y de forma que: a*x + b*y = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Função para calcular o inverso modular de 'a' módulo 'm'
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    // Se o gcd não é 1, o inverso modular não existe
    if (gcd != 1)
        return -1;
    else {
        // Ajusta x para que seja positivo
        return (x % m + m) % m;
    }
}

int main() {
    int a, m;
    cout << "Digite o valor de a e m:" << endl;
    cin >> a >> m;
    
    int inv = modInverse(a, m);
    if(inv == -1)
        cout << "Inverso modular não existe para " << a << " mod " << m << endl;
    else
        cout << "O inverso modular de " << a << " mod " << m << " é " << inv << endl;
    return 0;
}