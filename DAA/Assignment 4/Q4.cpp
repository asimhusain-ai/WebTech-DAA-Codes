#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int tspUtil(const vector<vector<int>>& graph, vector<bool>& visited, int pos, int n, int count, int cost, int ans) {
    if (count == n && graph[pos][0]) {
        return min(ans, cost + graph[pos][0]); // Return to starting point
    }
    for (int city = 0; city < n; city++) {
        if (!visited[city] && graph[pos][city]) {
            visited[city] = true;
            ans = tspUtil(graph, visited, city, n, count + 1, cost + graph[pos][city], ans);
            visited[city] = false; // Backtrack
        }
    }
    return ans;
}
int tsp(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[0] = true; // Start from the first city
    return tspUtil(graph, visited, 0, n, 1, 0, INT_MAX);
}
int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int result = tsp(graph);
    cout << "Minimum cost of traveling: " << (result == INT_MAX ? -1 : result) << endl;
    return 0;
}