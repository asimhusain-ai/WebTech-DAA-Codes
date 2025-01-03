#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
void kruskalMST(int vertices, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(vertices);
    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unionSet(edge.u, edge.v);
            cout << edge.u << " -- " << edge.v << " (Weight: " << edge.weight << ")\n";
        }
    }
}
int main() {
    int vertices = 6;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 1},
        {1, 3, 2}, {2, 3, 4}, {1, 4, 2},
        {3, 4, 3}, {4, 5, 5}
    };
    kruskalMST(vertices, edges);
    return 0;
}