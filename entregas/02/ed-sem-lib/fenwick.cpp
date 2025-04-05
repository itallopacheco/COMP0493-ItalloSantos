// Fenwick Tree (Binary Indexed Tree)

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;
public:
    // Construtor: cria uma árvore com n elementos (1-indexada)
    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, 0);
    }
    
    // Função build: constrói a árvore a partir de um vetor de DADOS (0-indexado)
    void build(const vector<int> &data) {
        for (int i = 1; i <= n; i++) {
            tree[i] += data[i - 1];
            int j = i + (i & -i);
            if (j <= n) {
                tree[j] += tree[i];
            }
        }
    }
    
    // Função update: atualiza o valor na posição 'index'  (0-indexado) com um incremento 'delta'
    void update(int index, int delta) {
        index++; // converte para 1-indexado
        while (index <= n) {
            tree[index] += delta;
            index += (index & -index);
        }
    }
    
    // Função query: retorna a soma dos elementos do início até o índice 'index' (0-indexado)
    int query(int index) {
        int sum = 0;
        index++; // converte para 1-indexado
        while (index > 0) {
            sum += tree[index];
            index -= (index & -index);
        }
        return sum;
    }
    
    // Função para consultar a soma de um intervalo [l, r] (0-indexado)
    int rangeQuery(int l, int r) {
        return query(r) - (l == 0 ? 0 : query(l - 1));
    }
};

int main() {
    int n;
    cout << "Digite o número de elementos:" << endl;
    cin >> n;
    
    vector<int> data(n);
    cout << "Digite os elementos:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    FenwickTree ft(n);
    ft.build(data);
    
    cout << "Soma do prefixo (até o último índice): " << ft.query(n - 1) << endl;
    
    int pos, delta;
    cout << "Digite a posição (0-indexado) e o valor delta para atualizar:" << endl;
    cin >> pos >> delta;
    ft.update(pos, delta);
    
    cout << "Nova soma do prefixo (até o último índice): " << ft.query(n - 1) << endl;
    
    return 0;
}