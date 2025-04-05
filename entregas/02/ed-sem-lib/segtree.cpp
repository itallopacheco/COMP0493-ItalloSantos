// Segment Tree com Lazy Propagation SOMA

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;      // Árvore de segmentos para armazenar as somas
    vector<int> lazy;      // Vetor de lazy propagation para atualizacoes em intervalo

    // Função recursiva para construir a árvore
    void buildTree(const vector<int> &data, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = data[left];
        } else {
            int mid = (left + right) / 2;
            buildTree(data, 2 * idx + 1, left, mid);
            buildTree(data, 2 * idx + 2, mid + 1, right);
            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }
    }

    // Propaga as atualizações pendentes para os filhos
    void pushDown(int idx, int left, int right) {
        if (lazy[idx] != 0) {
            int mid = (left + right) / 2;
            // Atualiza os filhos com o valor lazy
            tree[2 * idx + 1] += lazy[idx] * (mid - left + 1);
            tree[2 * idx + 2] += lazy[idx] * (right - mid);
            // Propaga o lazy para os nós filhos
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
            // Zera o lazy do nó atual
            lazy[idx] = 0;
        }
    }

    // Função recursiva para atualizar um intervalo [ql, qr] com incremento 'val'
    void updateRange(int idx, int left, int right, int ql, int qr, int val) {
        if (ql > right || qr < left)
            return; // Sem interseção
        if (ql <= left && right <= qr) {
            tree[idx] += val * (right - left + 1);
            lazy[idx] += val;
            return;
        }
        pushDown(idx, left, right);
        int mid = (left + right) / 2;
        updateRange(2 * idx + 1, left, mid, ql, qr, val);
        updateRange(2 * idx + 2, mid + 1, right, ql, qr, val);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    // Função recursiva para consultar a soma no intervalo [ql, qr]
    int queryRange(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left)
            return 0; // Sem interseção
        if (ql <= left && right <= qr)
            return tree[idx];
        pushDown(idx, left, right);
        int mid = (left + right) / 2;
        int leftSum = queryRange(2 * idx + 1, left, mid, ql, qr);
        int rightSum = queryRange(2 * idx + 2, mid + 1, right, ql, qr);
        return leftSum + rightSum;
    }

public:
    // Construtor: inicializa a segment tree com os dados fornecidos
    SegmentTree(const vector<int> &data) {
        n = data.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        buildTree(data, 0, 0, n - 1);
    }

    // Atualiza o intervalo [l, r] com incremento 'val'
    void update(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    // Consulta a soma do intervalo [l, r]
    int query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
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
    
    SegmentTree st(data);
    
    cout << "Soma do intervalo [0, " << n - 1 << "]: " << st.query(0, n - 1) << endl;
    
    int l, r, val;
    cout << "Digite o intervalo [l, r] e o valor para atualizar:" << endl;
    cin >> l >> r >> val;
    st.update(l, r, val);
    
    cout << "Nova soma do intervalo [0, " << n - 1 << "]: " << st.query(0, n - 1) << endl;
    
    return 0;
}