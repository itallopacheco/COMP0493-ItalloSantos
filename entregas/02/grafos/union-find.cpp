#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    
    // Inicializa os conjuntos: cada elemento é seu próprio pai
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    // Função find com path compression
    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    // União dos conjuntos que contêm u e v utilizando união por rank
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU == rootV)
            return;
        if(rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if(rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};
