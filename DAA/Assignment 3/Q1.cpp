#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
    int vertices;
    vector<vector<int>> adjList;
public:
    Graph(int v) : vertices(v), adjList(v) {}
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void BFS(int source) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor); 
                }
            }
        }
        cout << endl;
    }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    return 0;
}