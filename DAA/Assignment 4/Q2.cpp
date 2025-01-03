#include <iostream>
#include <vector>
using namespace std;
#define V 5 // Number of vertices
bool isSafe(int graph[][V], const vector<int>& path, int pos, int v) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}
bool hamCycleUtil(int graph[][V], vector<int>& path, int pos) {
    if (pos == V) return graph[path[pos - 1]][path[0]] == 1;
    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, pos, v)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1)) return true;
            path[pos] = -1; // Backtrack
        }
    }
    return false;
}
void hamCycle(int graph[][V]) {
    vector<int> path(V, -1);
    path[0] = 0; // Start from vertex 
    if (!hamCycleUtil(graph, path, 1)) {
        cout << "Solution does not exist\n";
        return;
    }
    cout << "Hamiltonian Circuit: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << " (returns to start)\n"; // Return to start
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    hamCycle(graph);
    return 0;
}