#include <iostream>
#include <stack>
using namespace std;
class Graph {
    int vertices;
    int** adjMatrix;
public:
    Graph(int v) : vertices(v) {
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++)
            adjMatrix[i] = new int[vertices]{0};
    }
    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void DFS(int source) {
        bool* visited = new bool[vertices]{false};
        stack<int> s;
        s.push(source);
        visited[source] = true;
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            cout << current << " ";
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    return 0;
}