// Estrutura para uso na fila de prioridade
struct Node {
    int vertex, weight;
    bool operator>(const Node &other) const {
        return weight > other.weight;
    }
};

void prim(int n, const vector<vector<pair<int, int>>> &adj) {
    // Inicializa os vetores de custos e visitados
    vector<int> key(n, numeric_limits<int>::max());
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    
    // Min-heap para selecionar o vértice com menor key
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    // Inicia com o vértice 0 (poderia ser qualquer outro)
    key[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        int u = pq.top().vertex;
        pq.pop();
        
        if(inMST[u])
            continue;
        
        inMST[u] = true;
        
        // Atualiza os vizinhos de u
        for(auto &neighbor : adj[u]){
            int v = neighbor.first;
            int weight = neighbor.second;
            if(!inMST[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }
    
    int totalWeight = 0;
    cout << "Prim - Arestas da MST:" << endl;
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " (peso " << key[i] << ")" << endl;
        totalWeight += key[i];
    }
    cout << "Prim - Peso total da MST: " << totalWeight << endl;
}

int main() {  
    // Para o Prim, criaremos uma representação por lista de adjacência
    vector<vector<pair<int, int>>> adj(n);
    cout << "\nPrim - Digite o número de vértices e arestas:" << endl;
    cin >> n >> m;
    cout << "Digite cada aresta no formato: u v peso" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        // Grafo não direcionado: insere em ambas as listas
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    prim(n, adj);
    
    return 0;
}