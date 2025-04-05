// utilizando a heurística do "bad character"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Função para construir a tabela de última ocorrência para o padrão
vector<int> buildLastOccurrence(const string &pattern) {
    const int ALPHABET_SIZE = 256; // Considera todos os caracteres ASCII
    vector<int> last(ALPHABET_SIZE, -1);
    for (int i = 0; i < pattern.size(); i++) {
        last[(unsigned char)pattern[i]] = i;
    }
    return last;
}

// Função de busca utilizando o algoritmo de Boyer-Moore com a heurística "bad character"
void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return; // Padrão vazio não tem significado
    vector<int> last = buildLastOccurrence(pattern);
    
    int shift = 0; // deslocamento do padrão em relação ao texto
    while (shift <= n - m) {
        int j = m - 1; // começa a comparar da última posição do padrão
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        if (j < 0) {
            cout << "Padrão encontrado na posição " << shift << endl;
            // Se desejar encontrar próximas ocorrências, pode ajustar o shift aqui
            shift += (shift + m < n) ? m - last[(unsigned char)text[shift + m]] : 1;
        } else {
            // Calcula o deslocamento baseado na posição da última ocorrência do caractere
            int badCharShift = max(1, j - last[(unsigned char)text[shift + j]]);
            shift += badCharShift;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Digite o texto: ";
    getline(cin, text);
    cout << "Digite o padrão: ";
    getline(cin, pattern);
    
    boyerMooreSearch(text, pattern);
    return 0;
}