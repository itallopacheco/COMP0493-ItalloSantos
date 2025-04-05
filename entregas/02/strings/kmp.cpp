
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Função para calcular o (Longest Prefix Suffix)
vector<int> computeLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // Tamanho do prefixo que é também sufixo
    int i = 1;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                // Tenta encontrar um prefixo menor
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Função que utiliza o algoritmo KMP para buscar o padrão no texto
void KMPSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    
    int i = 0; // Índice para o texto
    int j = 0; // Índice para o padrão
    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        if(j == m) {
            cout << "Padrão encontrado na posição " << i - j << endl;
            // Procura por próximas ocorrências
            j = lps[j - 1];
        } else if(i < n && pattern[j] != text[i]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Digite o texto: ";
    getline(cin, text);
    cout << "Digite o padrão: ";
    getline(cin, pattern);
    
    KMPSearch(text, pattern);
    return 0;
}