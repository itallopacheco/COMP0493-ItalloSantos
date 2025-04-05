#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int MAX = 100; // Número máximo de vértices
int capacity[MAX][MAX]; // Matriz de capacidades
vector<int> adj[MAX];   // Lista de adjacência
int parent[MAX];        // Array para armazenar o caminho

bool dfs(int s, int t, int n, vector<bool>& visited) {
    if(s == t) return true;
    visited[s] = true;
    for(int v : adj[s]) {
        if(!visited[v] && capacity[s][v] > 0) {
            parent[v] = s;
            if(dfs(v, t, n, visited))
                return true;
        }
    }
    return false;
}

int fordFulkerson(int s, int t, int n) {
    int maxFlow = 0;
    while(true) {
        vector<bool> visited(n, false);
        memset(parent, -1, sizeof(parent));
        if(!dfs(s, t, n, visited)) break;
        
        // Encontrar a capacidade mínima no caminho encontrado
        int pathFlow = INT_MAX;
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }
        
        // Atualizar as capacidades residuais
        for(int v = t; v != s; v = parent[v]) {
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
    // n: número de nós, m: num de arestas, s: fonte, t: destino
    cout << "Digite o num de nós, arestas, fonte e destino:" << endl;
    cin >> n >> m >> s >> t;
    
    // Inicializa a matriz de capacidades
    for(int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] = cap;
        // Adiciona as arestas na lista de adjacência
        adj[u].push_back(v);
        adj[v].push_back(u); // p/ o grafo residual
    }
    
    cout << "Fluxo máximo: " << fordFulkerson(s, t, n) << endl;
    return 0;
}