#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

const int MAX = 100; // Número máximo de vértices
int capacity[MAX][MAX]; // Matriz de capacidades
vector<int> adj[MAX];   // Lista de adjacência
int parent[MAX];        // Array para armazenar o caminho

// BFS para encontrar caminho aumentante
bool bfs(int s, int t, int n) {
    bool visited[MAX];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int edmondsKarp(int s, int t, int n) {
    int maxFlow = 0;
    while (bfs(s, t, n)) {
        int pathFlow = INT_MAX;
        // Encontrar a capacidade mínima no caminho encontrado
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }
        // Atualizar as capacidades residuais
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int n, m, s, t;
    // n: num de nós, m: num de arestas, s: fonte, t: destino
    cout << "Digite o num de nós, arestas, fonte e destino:" << endl;
    cin >> n >> m >> s >> t;
    
    // Leitura das arestas e capacidades
    for (int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] = cap;
        // Adiciona as arestas na lista de adjacência
        adj[u].push_back(v);
        adj[v].push_back(u); // p/ o grafo residual
    }
    cout << "Fluxo máximo: " << edmondsKarp(s, t, n) << endl;
    return 0;
}