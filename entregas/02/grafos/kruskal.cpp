struct Edge {
    int u, v, weight;
};

// compara por peso
bool cmpEdge(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}


void kruskal(int n, vector<Edge> &edges) {
    // Ordena as arestas por peso
    sort(edges.begin(), edges.end(), cmpEdge);
    UnionFind uf(n);
    int mstWeight = 0;
    vector<Edge> mstEdges;
    
    for(auto &edge : edges) {
        if(uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            mstEdges.push_back(edge);
            mstWeight += edge.weight;
        }
    }
    
    cout << "Kruskal - Peso total da MST: " << mstWeight << endl;
    cout << "Arestas da MST:" << endl;
    for(auto &edge : mstEdges) {
        cout << edge.u << " - " << edge.v << " (peso " << edge.weight << ")" << endl;
    }
}


int main() {
    // Exemplo para Kruskal
    int n, m;
    cout << "Kruskal - Digite o número de vértices e arestas:" << endl;
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "Digite cada aresta no formato: u v peso" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        // Se o grafo for não direcionado, não há necessidade de inserir a aresta inversa aqui
    }
    kruskal(n, edges);
       
    return 0;
}